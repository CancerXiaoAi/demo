import express from 'express'
import { PrismaClient } from '@prisma/client'

const router = express.Router()
const prisma = new PrismaClient()

router.get('/', async (req, res) => {
  try {
    const credentials = await prisma.credential.findMany({
      where: { userId: req.user.id, deletedAt: null },
      orderBy: { createdAt: 'desc' }
    })
    res.json(credentials)
  } catch (error) {
    console.error('获取凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

router.get('/trash', async (req, res) => {
  try {
    const credentials = await prisma.credential.findMany({
      where: { userId: req.user.id, deletedAt: { not: null } },
      orderBy: { deletedAt: 'desc' }
    })
    res.json(credentials)
  } catch (error) {
    console.error('获取回收站错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

router.post('/', async (req, res) => {
  try {
    const { platform, username, password, url, category, features } = req.body

    if (!platform || !username || !password) {
      return res.status(400).json({ message: '平台、用户名和密码不能为空' })
    }

    const credential = await prisma.credential.create({
      data: {
        platform,
        username,
        password,
        url: url || null,
        category: category || null,
        features: features || null,
        userId: req.user.id
      }
    })

    res.status(201).json(credential)
  } catch (error) {
    console.error('创建凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

router.put('/:id', async (req, res) => {
  try {
    const { id } = req.params
    const { platform, username, password, url, category, features } = req.body

    const existingCredential = await prisma.credential.findFirst({
      where: { id: parseInt(id), userId: req.user.id, deletedAt: null }
    })

    if (!existingCredential) {
      return res.status(404).json({ message: '凭证不存在' })
    }

    const credential = await prisma.credential.update({
      where: { id: parseInt(id) },
      data: {
        platform,
        username,
        password,
        url: url || null,
        category: category || null,
        features: features || null
      }
    })

    res.json(credential)
  } catch (error) {
    console.error('更新凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

router.delete('/:id', async (req, res) => {
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

    res.json({ message: '已移入回收站' })
  } catch (error) {
    console.error('删除凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

router.post('/:id/restore', async (req, res) => {
  try {
    const { id } = req.params

    const existingCredential = await prisma.credential.findFirst({
      where: { id: parseInt(id), userId: req.user.id, deletedAt: { not: null } }
    })

    if (!existingCredential) {
      return res.status(404).json({ message: '回收站中不存在此凭证' })
    }

    const credential = await prisma.credential.update({
      where: { id: parseInt(id) },
      data: { deletedAt: null }
    })

    res.json(credential)
  } catch (error) {
    console.error('恢复凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

router.delete('/:id/permanent', async (req, res) => {
  try {
    const { id } = req.params

    const existingCredential = await prisma.credential.findFirst({
      where: { id: parseInt(id), userId: req.user.id, deletedAt: { not: null } }
    })

    if (!existingCredential) {
      return res.status(404).json({ message: '回收站中不存在此凭证' })
    }

    await prisma.credential.delete({
      where: { id: parseInt(id) }
    })

    res.json({ message: '永久删除成功' })
  } catch (error) {
    console.error('永久删除凭证错误:', error)
    res.status(500).json({ message: '服务器错误' })
  }
})

export default router
