import express from 'express'
import cors from 'cors'
import dotenv from 'dotenv'
import { PrismaClient } from '@prisma/client'
import { fileURLToPath } from 'url'
import { dirname, join } from 'path'
import bcrypt from 'bcryptjs'
import jwt from 'jsonwebtoken'
import crypto from 'crypto'

const __filename = fileURLToPath(import.meta.url)
const __dirname = dirname(__filename)

dotenv.config({ path: join(__dirname, '..', '.env') })

const app = express()
const prisma = new PrismaClient()
const PORT = process.env.PORT || 3000
const JWT_SECRET = process.env.JWT_SECRET || 'your-256-bit-secret-key-here-change-in-production'
const JWT_EXPIRES_IN = '24h'

const ENCRYPTION_KEY = process.env.ENCRYPTION_KEY || 'your-32-character-encryption-key-here'
const IV_LENGTH = 16

function encrypt(text) {
  if (!text) return null
  const iv = crypto.randomBytes(IV_LENGTH)
  const key = Buffer.from(ENCRYPTION_KEY.padEnd(32, ' ').slice(0, 32), 'utf8')
  const cipher = crypto.createCipheriv('aes-256-cbc', key, iv)
  let encrypted = cipher.update(text, 'utf8', 'hex')
  encrypted += cipher.final('hex')
  return `${iv.toString('hex')}:${encrypted}`
}

function decrypt(text) {
  if (!text) return null
  try {
    const parts = text.split(':')
    if (parts.length !== 2) {
      return text
    }
    const [ivHex, encryptedText] = parts
    const iv = Buffer.from(ivHex, 'hex')
    const key = Buffer.from(ENCRYPTION_KEY.padEnd(32, ' ').slice(0, 32), 'utf8')
    const decipher = crypto.createDecipheriv('aes-256-cbc', key, iv)
    let decrypted = decipher.update(encryptedText, 'hex', 'utf8')
    decrypted += decipher.final('utf8')
    return decrypted
  } catch (error) {
    console.warn('Decryption failed, returning original text:', error.message)
    return text
  }
}

const allowedOrigins = [
  'http://127.0.0.1',
  'http://localhost',
  'http://localhost:5173',
  'http://cancerai.top',
  'https://cancerai.top'
]

const corsOptions = {
  origin: (origin, callback) => {
    if (!origin || allowedOrigins.includes(origin)) {
      callback(null, true)
    } else {
      callback(new Error('不允许的来源'))
    }
  },
  methods: ['GET', 'POST', 'PUT', 'DELETE', 'OPTIONS'],
  allowedHeaders: ['Content-Type', 'Authorization'],
  credentials: true,
  maxAge: 86400
}

app.disable('x-powered-by')

app.use(cors(corsOptions))

app.use((req, res, next) => {
  res.setHeader('X-Content-Type-Options', 'nosniff')
  res.setHeader('X-Frame-Options', 'DENY')
  res.setHeader('X-XSS-Protection', '1; mode=block')
  res.setHeader('Strict-Transport-Security', 'max-age=31536000; includeSubDomains')
  res.setHeader('Content-Security-Policy', "default-src 'self'; script-src 'self' 'unsafe-inline'; style-src 'self' 'unsafe-inline'")
  next()
})

app.use(express.json({
  limit: '10kb',
  verify: (req, res, buf) => {
    try {
      JSON.parse(buf)
    } catch (e) {
      res.status(400).json({ message: '无效的请求体格式' })
      throw new Error('Invalid JSON')
    }
  }
}))

app.use(express.urlencoded({ extended: true, limit: '10kb' }))

const authMiddleware = async (req, res, next) => {
  try {
    const authHeader = req.headers.authorization
    if (!authHeader || !authHeader.startsWith('Bearer ')) {
      return res.status(401).json({ message: '未授权访问' })
    }

    const token = authHeader.split(' ')[1]
    const decoded = jwt.verify(token, JWT_SECRET)
    
    const user = await prisma.user.findUnique({
      where: { id: decoded.userId }
    })

    if (!user) {
      return res.status(401).json({ message: '用户不存在' })
    }

    req.user = { id: user.id, username: user.username }
    next()
  } catch (error) {
    if (error.name === 'TokenExpiredError') {
      return res.status(401).json({ message: '登录已过期，请重新登录' })
    }
    return res.status(401).json({ message: '无效的认证令牌' })
  }
}

app.post('/api/auth/register', async (req, res) => {
  try {
    const { username, password } = req.body

    if (!username || !password) {
      return res.status(400).json({ message: '用户名和密码不能为空' })
    }

    if (username.length < 3 || username.length > 50) {
      return res.status(400).json({ message: '用户名长度必须在3-50字符之间' })
    }

    if (password.length < 6 || password.length > 100) {
      return res.status(400).json({ message: '密码长度必须在6-100字符之间' })
    }

    const existingUser = await prisma.user.findUnique({
      where: { username }
    })

    if (existingUser) {
      return res.status(400).json({ message: '用户名已存在' })
    }

    const hashedPassword = await bcrypt.hash(password, 12)

    const user = await prisma.user.create({
      data: {
        username,
        password: hashedPassword
      }
    })

    const token = jwt.sign({ userId: user.id }, JWT_SECRET, { expiresIn: JWT_EXPIRES_IN })

    res.status(201).json({
      message: '注册成功',
      userId: user.id,
      username: user.username,
      token
    })
  } catch (error) {
    console.error('注册错误:', error)
    res.status(500).json({ message: '服务器内部错误' })
  }
})

app.post('/api/auth/login', async (req, res) => {
  try {
    const { username, password } = req.body

    if (!username || !password) {
      return res.status(400).json({ message: '用户名和密码不能为空' })
    }

    const user = await prisma.user.findUnique({
      where: { username }
    })

    if (!user) {
      return res.status(401).json({ message: '用户名或密码错误' })
    }

    const isPasswordValid = await bcrypt.compare(password, user.password)

    if (!isPasswordValid) {
      return res.status(401).json({ message: '用户名或密码错误' })
    }

    const token = jwt.sign({ userId: user.id }, JWT_SECRET, { expiresIn: JWT_EXPIRES_IN })

    res.json({
      message: '登录成功',
      userId: user.id,
      username: user.username,
      token
    })
  } catch (error) {
    console.error('登录错误:', error)
    res.status(500).json({ message: '服务器内部错误' })
  }
})

app.post('/api/auth/change-password', authMiddleware, async (req, res) => {
  try {
    const { oldPassword, newPassword } = req.body

    if (!oldPassword || !newPassword) {
      return res.status(400).json({ message: '请输入旧密码和新密码' })
    }

    if (newPassword.length < 6 || newPassword.length > 100) {
      return res.status(400).json({ message: '新密码长度必须在6-100字符之间' })
    }

    const user = await prisma.user.findUnique({
      where: { id: req.user.id }
    })

    if (!user) {
      return res.status(401).json({ message: '用户不存在' })
    }

    const isPasswordValid = await bcrypt.compare(oldPassword, user.password)

    if (!isPasswordValid) {
      return res.status(401).json({ message: '旧密码错误' })
    }

    const hashedPassword = await bcrypt.hash(newPassword, 12)

    await prisma.user.update({
      where: { id: req.user.id },
      data: { password: hashedPassword }
    })

    res.json({ message: '密码修改成功' })
  } catch (error) {
    console.error('修改密码错误:', error)
    res.status(500).json({ message: '服务器内部错误' })
  }
})

app.get('/api/credentials', authMiddleware, async (req, res) => {
  try {
    const credentials = await prisma.credential.findMany({
      where: { userId: req.user.id, deletedAt: null },
      orderBy: { createdAt: 'desc' }
    })

    const decryptedCredentials = credentials.map(cred => ({
      ...cred,
      password: decrypt(cred.password)
    }))

    res.json(decryptedCredentials)
  } catch (error) {
    console.error('获取凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.get('/api/credentials/trash', authMiddleware, async (req, res) => {
  try {
    const credentials = await prisma.credential.findMany({
      where: { userId: req.user.id, deletedAt: { not: null } },
      orderBy: { deletedAt: 'desc' }
    })

    const decryptedCredentials = credentials.map(cred => ({
      ...cred,
      password: decrypt(cred.password)
    }))

    res.json(decryptedCredentials)
  } catch (error) {
    console.error('获取回收站错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.post('/api/credentials', authMiddleware, async (req, res) => {
  try {
    const { platform, username, password, category, features, baseType, baseId, softwareName, softwareId, useBaseCredentials, remark } = req.body

    if (!baseType) {
      return res.status(400).json({ message: '请选择基础验证类型' })
    }

    if (!['phone', 'email', 'software', 'none'].includes(baseType)) {
      return res.status(400).json({ message: '无效的基础验证类型' })
    }

    if (baseType !== 'none') {
      if (!platform || !username) {
        return res.status(400).json({ message: '平台和用户名不能为空' })
      }
    }

    let processedBaseId = baseId
    if (baseType === 'phone') {
      if (!/^1[3-9]\d{9}$/.test(baseId)) {
        return res.status(400).json({ message: '请输入有效的手机号' })
      }
    } else if (baseType === 'email') {
      if (!/^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(baseId)) {
        return res.status(400).json({ message: '请输入有效的邮箱地址' })
      }
    }

    if (remark && remark.length > 100) {
      return res.status(400).json({ message: '备注不能超过100字' })
    }

    const credential = await prisma.credential.create({
      data: {
        platform: platform || null,
        username: username || null,
        password: encrypt(password) || null,
        category: category || null,
        features: features || null,
        baseType,
        baseId: processedBaseId || null,
        softwareName: softwareName || null,
        softwareId: softwareId || null,
        useBaseCredentials: useBaseCredentials || false,
        remark: remark || null,
        userId: req.user.id
      }
    })

    const sanitizedCredential = {
      ...credential,
      password: '***'
    }

    res.status(201).json(sanitizedCredential)
  } catch (error) {
    console.error('创建凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.put('/api/credentials/:id', authMiddleware, async (req, res) => {
  try {
    const { id } = req.params
    const { platform, username, password, category, features, baseType, baseId, softwareName, softwareId, useBaseCredentials, remark } = req.body

    const existingCredential = await prisma.credential.findFirst({
      where: { id: parseInt(id), userId: req.user.id, deletedAt: null }
    })

    if (!existingCredential) {
      return res.status(404).json({ message: '凭证不存在' })
    }

    if (baseType && !['phone', 'email', 'software', 'none'].includes(baseType)) {
      return res.status(400).json({ message: '无效的基础验证类型' })
    }

    if (baseType && baseType !== 'none') {
      if (!platform || !username) {
        return res.status(400).json({ message: '平台和用户名不能为空' })
      }
    }

    if (remark && remark.length > 100) {
      return res.status(400).json({ message: '备注不能超过100字' })
    }

    const credential = await prisma.credential.update({
      where: { id: parseInt(id) },
      data: {
        platform: platform || null,
        username: username || null,
        password: password ? encrypt(password) : existingCredential.password,
        category: category || null,
        features: features || null,
        baseType: baseType || existingCredential.baseType,
        baseId: baseId || null,
        softwareName: softwareName || null,
        softwareId: softwareId || null,
        useBaseCredentials: useBaseCredentials || false,
        remark: remark || null
      }
    })

    credential.password = decrypt(credential.password)

    res.json(credential)
  } catch (error) {
    console.error('更新凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.delete('/api/credentials/:id', authMiddleware, async (req, res) => {
  try {
    const { id } = req.params

    const existingCredential = await prisma.credential.findFirst({
      where: { id: parseInt(id), userId: req.user.id, deletedAt: null }
    })

    if (!existingCredential) {
      return res.status(404).json({ message: '凭证不存在' })
    }

    await prisma.credential.update({
      where: { id: parseInt(id) },
      data: { deletedAt: new Date() }
    })

    res.json({ message: '移入回收站成功' })
  } catch (error) {
    console.error('删除凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.post('/api/credentials/:id/restore', authMiddleware, async (req, res) => {
  try {
    const { id } = req.params

    const existingCredential = await prisma.credential.findFirst({
      where: { id: parseInt(id), userId: req.user.id, deletedAt: { not: null } }
    })

    if (!existingCredential) {
      return res.status(404).json({ message: '回收站中不存在该凭证' })
    }

    await prisma.credential.update({
      where: { id: parseInt(id) },
      data: { deletedAt: null }
    })

    res.json({ message: '恢复成功' })
  } catch (error) {
    console.error('恢复凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.delete('/api/credentials/:id/force', authMiddleware, async (req, res) => {
  try {
    const { id } = req.params

    const existingCredential = await prisma.credential.findFirst({
      where: { id: parseInt(id), userId: req.user.id }
    })

    if (!existingCredential) {
      return res.status(404).json({ message: '凭证不存在' })
    }

    await prisma.credential.delete({
      where: { id: parseInt(id) }
    })

    res.json({ message: '彻底删除成功' })
  } catch (error) {
    console.error('彻底删除凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.get('/api/categories', authMiddleware, async (req, res) => {
  try {
    const credentials = await prisma.credential.findMany({
      where: { userId: req.user.id, deletedAt: null, category: { not: null } }
    })

    const categories = [...new Set(credentials.map(c => c.category))]
    res.json(categories)
  } catch (error) {
    console.error('获取分类错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

app.get('/api/health', (req, res) => {
  res.json({ status: 'ok', timestamp: new Date().toISOString() })
})

app.use((req, res) => {
  res.status(404).json({ message: '未找到该接口' })
})

app.use((error, req, res, next) => {
  console.error('服务器错误:', error)
  if (error.message === 'Invalid JSON') {
    return
  }
  res.status(500).json({ message: '服务器内部错误' })
})

process.on('SIGINT', async () => {
  await prisma.$disconnect()
  process.exit(0)
})

process.on('SIGTERM', async () => {
  await prisma.$disconnect()
  process.exit(0)
})

app.listen(PORT, () => {
  console.log(`Server running on http://localhost:${PORT}`)
})