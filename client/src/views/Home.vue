<template>
  <div class="min-h-screen bg-gray-100 flex">
    <aside
      :class="[
        'fixed inset-y-0 left-0 z-50 w-64 bg-white shadow-lg transform transition-transform duration-300 ease-in-out',
        'md:relative md:translate-x-0',
        sidebarOpen ? 'translate-x-0' : '-translate-x-full'
      ]"
    >
      <div class="p-4">
        <div class="flex justify-between items-center mb-4">
          <h2 class="text-lg font-bold text-gray-800">分类</h2>
          <button
            @click="sidebarOpen = false"
            class="p-2 rounded-lg hover:bg-gray-100 md:hidden"
          >
            ✕
          </button>
        </div>
        <ul class="space-y-2">
          <li>
            <button
              @click="selectCategory(null)"
              :class="[
                'w-full text-left px-4 py-2 rounded-lg transition',
                selectedCategory === null ? 'bg-blue-100 text-blue-700' : 'hover:bg-gray-100'
              ]"
            >
              全部 ({{ credentialStore.credentials.length }})
            </button>
          </li>
          <li
            v-for="cat in categories"
            :key="cat.name"
            class="flex items-center justify-between"
          >
            <button
              @click="selectCategory(cat.name)"
              :class="[
                'flex-1 text-left px-4 py-2 rounded-lg transition',
                selectedCategory === cat.name ? 'bg-blue-100 text-blue-700' : 'hover:bg-gray-100'
              ]"
            >
              {{ cat.name }} ({{ cat.count }})
            </button>
            <button
              @click.stop="deleteCategory(cat.name)"
              class="text-gray-400 hover:text-red-500 ml-2"
              v-if="cat.count === 0"
            >
              ×
            </button>
          </li>
        </ul>
        <div class="mt-4 pt-4 border-t">
          <button
            @click="goToTrash"
            class="w-full text-left px-4 py-2 text-gray-600 hover:bg-gray-100 rounded-lg transition"
          >
            🗑️ 回收站
          </button>
        </div>
      </div>
    </aside>

    <div
      v-if="sidebarOpen"
      @click="sidebarOpen = false"
      class="fixed inset-0 bg-black bg-opacity-50 z-40 md:hidden"
    ></div>

    <main class="flex-1 w-full">
      <nav class="bg-white shadow-lg sticky top-0 z-30">
        <div class="px-4 py-4 flex justify-between items-center">
          <div class="flex items-center gap-3">
            <button
              @click="sidebarOpen = true"
              class="p-2 rounded-lg hover:bg-gray-100 md:hidden"
            >
              ☰
            </button>
            <h1 class="text-xl font-bold text-gray-800">登录信息管理器</h1>
          </div>
          <div class="flex items-center gap-2 sm:gap-4">
            <span class="text-gray-600 text-xs sm:text-sm hidden sm:inline">欢迎</span>
            <span class="text-blue-600 font-medium text-xs sm:text-sm">{{ authStore.user?.username }}</span>
            <button
              @click="showPasswordModal = true"
              class="bg-gray-500 text-white px-2 sm:px-4 py-1 sm:py-2 rounded-lg hover:bg-gray-600 transition text-xs sm:text-sm"
            >
              修改密码
            </button>
            <button
              @click="handleLogout"
              class="bg-red-500 text-white px-2 sm:px-4 py-1 sm:py-2 rounded-lg hover:bg-red-600 transition text-xs sm:text-sm"
            >
              退出
            </button>
          </div>
        </div>
      </nav>

      <div class="p-4 md:p-8">
        <div class="bg-white rounded-lg shadow-md p-4 md:p-6">
          <div class="flex flex-col sm:flex-row justify-between items-start sm:items-center gap-4 mb-6">
            <h2 class="text-xl md:text-2xl font-bold text-gray-800">
              {{ selectedCategory ? selectedCategory : '全部账号' }}
            </h2>
            <button
              @click="testClick"
              class="bg-blue-600 text-white px-6 py-2 rounded-lg hover:bg-blue-700 transition w-full sm:w-auto"
            >
              添加账号
            </button>
          </div>

          <div class="mb-4">
            <input
              v-model="searchQuery"
              type="text"
              placeholder="搜索账号..."
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 focus:border-transparent outline-none"
            />
          </div>

          <div v-if="credentialStore.loading" class="text-center py-8">
            <span class="text-gray-500">加载中...</span>
          </div>

          <div v-else-if="filteredCredentials.length === 0" class="text-center py-8">
            <span class="text-gray-500">暂无账号信息</span>
          </div>

          <div v-else class="grid gap-4 sm:grid-cols-2 lg:grid-cols-3">
            <div
              v-for="cred in filteredCredentials"
              :key="cred.id"
              class="bg-gray-50 p-4 md:p-6 rounded-lg hover:shadow-md transition"
            >
              <div class="flex justify-between items-start mb-4">
                <h3 class="text-lg font-semibold text-gray-800 break-words">{{ cred.platform }}</h3>
                <div class="flex gap-2 flex-shrink-0">
                  <button
                    @click="openEditModal(cred)"
                    class="text-blue-600 hover:text-blue-800 text-sm"
                  >
                    编辑
                  </button>
                  <button
                    @click="handleDelete(cred.id)"
                    class="text-red-600 hover:text-red-800 text-sm"
                  >
                    删除
                  </button>
                </div>
              </div>
              <div class="space-y-2 text-sm">
                <p class="text-gray-600 break-all">
                  <span class="font-medium">用户名:</span> {{ cred.username }}
                </p>
                <p class="text-gray-600">
                  <span class="font-medium">密码:</span>
                  <span v-if="!showPasswords[cred.id]">••••••••</span>
                  <span v-else class="break-all">{{ decryptedPasswords[cred.id] || '解密失败' }}</span>
                  <button
                    @click="togglePassword(cred)"
                    class="ml-2 text-blue-600 hover:underline text-xs"
                  >
                    {{ showPasswords[cred.id] ? '隐藏' : '显示' }}
                  </button>
                </p>
                <p v-if="cred.url" class="text-gray-600 break-all">
                  <span class="font-medium">网址:</span>
                  <a :href="cred.url" target="_blank" class="text-blue-600 hover:underline ml-1 break-words">
                    {{ cred.url }}
                  </a>
                </p>
                <p v-if="cred.category" class="text-gray-600">
                  <span class="font-medium">分类:</span>
                  <span
                    @click="selectCategory(cred.category)"
                    class="text-blue-600 hover:underline cursor-pointer ml-1"
                  >
                    {{ cred.category }}
                  </span>
                </p>
                <p v-if="cred.features" class="text-gray-600">
                  <span class="font-medium">绑定平台:</span>
                  <div class="flex flex-col gap-1 mt-1">
                    <div
                      v-for="(feature, idx) in parseFeatures(cred.features)"
                      :key="idx"
                      class="bg-green-100 text-green-700 px-2 py-1 rounded text-xs"
                    >
                      {{ feature.platform }}: {{ feature.accountName }}
                    </div>
                  </div>
                </p>
                <p class="text-gray-400 text-xs mt-2">
                  创建于: {{ formatDate(cred.createdAt) }} | 修改于: {{ formatDate(cred.updatedAt) }}
                </p>
              </div>
            </div>
          </div>
        </div>
      </div>
    </main>

    <div
      v-if="showAddModal"
      class="fixed inset-0 bg-black bg-opacity-50 z-50 p-4 overflow-y-auto"
      @click="handleBackdropClick('add')"
    >
      <div class="bg-white p-4 sm:p-6 md:p-8 rounded-lg w-full max-w-md max-h-[90vh] overflow-y-auto mx-auto my-4" @click.stop>
        <h3 class="text-xl font-bold mb-4">{{ isEditing ? '编辑账号' : '添加账号' }}</h3>
        <form @submit.prevent="handleSubmit" class="space-y-4">
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">平台名称</label>
            <input
              v-model="formData.platform"
              type="text"
              required
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
            />
          </div>
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">用户名/邮箱</label>
            <input
              v-model="formData.username"
              type="text"
              required
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
            />
          </div>
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">密码</label>
            <div class="relative">
              <input
                v-model="formData.password"
                :type="showFormPassword ? 'text' : 'password'"
                required
                class="w-full px-4 py-2 pr-10 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
              />
              <button
                type="button"
                @click="showFormPassword = !showFormPassword"
                class="absolute right-3 top-1/2 transform -translate-y-1/2 text-gray-500 hover:text-gray-700"
              >
                <svg v-if="showFormPassword" xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M13.875 18.825A10.05 10.05 0 0112 19c-4.478 0-8.268-2.943-9.543-7a9.97 9.97 0 011.563-3.029m5.858.908a3 3 0 114.243 4.243M9.878 9.878l4.242 4.242M9.88 9.88l-3.29-3.29m7.532 7.532l3.29 3.29M3 3l3.59 3.59m0 0A9.953 9.953 0 0112 5c4.478 0 8.268 2.943 9.543 7a10.025 10.025 0 01-4.132 5.411m0 0L21 21" />
                </svg>
                <svg v-else xmlns="http://www.w3.org/2000/svg" class="h-5 w-5" fill="none" viewBox="0 0 24 24" stroke="currentColor">
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
                  <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M2.458 12C3.732 7.943 7.523 5 12 5c4.478 0 8.268 2.943 9.542 7-1.274 4.057-5.064 7-9.542 7-4.477 0-8.268-2.943-9.542-7z" />
                </svg>
              </button>
            </div>
          </div>
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">网址（可选）</label>
            <input
              v-model="formData.url"
              type="text"
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
              placeholder="例如: www.example.com"
            />
          </div>
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">分类</label>
            <div class="relative">
              <input
                v-model="formData.category"
                type="text"
                list="category-list"
                class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
                placeholder="选择或输入新分类"
              />
              <datalist id="category-list">
                <option v-for="cat in categories" :key="cat.name" :value="cat.name">
                  {{ cat.name }}
                </option>
              </datalist>
            </div>
          </div>
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">绑定的其他平台（可选）</label>
            <div class="space-y-2 mb-2">
              <div
                v-for="(feature, index) in formData.features"
                :key="index"
                class="flex items-center gap-2 bg-blue-50 px-3 py-2 rounded-lg"
              >
                <input
                  v-model="feature.platform"
                  type="text"
                  class="flex-1 px-2 py-1 border border-gray-300 rounded text-sm"
                  placeholder="平台名称"
                />
                <span class="text-gray-400">:</span>
                <input
                  v-model="feature.accountName"
                  type="text"
                  class="flex-1 px-2 py-1 border border-gray-300 rounded text-sm"
                  placeholder="账号名"
                />
                <button
                  type="button"
                  @click="removeFeature(index)"
                  class="text-red-500 hover:text-red-700"
                >
                  ×
                </button>
              </div>
            </div>
            <div class="flex gap-2">
              <input
                v-model="newFeature.platform"
                type="text"
                class="w-1/2 px-3 py-2 border border-gray-300 rounded-lg text-sm"
                placeholder="平台名称"
              />
              <input
                v-model="newFeature.accountName"
                @keydown.enter.prevent="addFeature"
                type="text"
                class="w-1/2 px-3 py-2 border border-gray-300 rounded-lg text-sm"
                placeholder="账号名，回车添加"
              />
            </div>
            <div class="mt-2">
              <p class="text-xs text-gray-500">常用平台：</p>
              <div class="flex flex-wrap gap-1 mt-1">
                <button
                  v-for="preset in presetFeatures"
                  :key="preset"
                  type="button"
                  @click="addPresetFeature(preset)"
                  class="text-xs bg-gray-100 hover:bg-gray-200 px-2 py-1 rounded"
                >
                  + {{ preset }}
                </button>
              </div>
            </div>
          </div>
          <div class="flex gap-4">
            <button
              type="submit"
              class="flex-1 bg-blue-600 text-white py-2 rounded-lg hover:bg-blue-700 transition"
            >
              {{ isEditing ? '保存' : '添加' }}
            </button>
            <button
              type="button"
              @click="closeModal"
              class="flex-1 bg-gray-300 text-gray-700 py-2 rounded-lg hover:bg-gray-400 transition"
            >
              取消
            </button>
          </div>
        </form>
      </div>
    </div>

    <div
      v-if="showCategoryModal"
      class="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center z-50 p-4"
      @click="handleBackdropClick('category')"
    >
      <div class="bg-white p-6 md:p-8 rounded-lg w-full max-w-md" @click.stop>
        <h3 class="text-xl font-bold mb-4">添加分类</h3>
        <form @submit.prevent="addCategory" class="space-y-4">
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">分类名称</label>
            <input
              v-model="newCategoryName"
              type="text"
              required
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
              placeholder="例如：社交、购物、工作..."
            />
          </div>
          <div class="flex gap-4">
            <button
              type="submit"
              class="flex-1 bg-blue-600 text-white py-2 rounded-lg hover:bg-blue-700 transition"
            >
              添加
            </button>
            <button
              type="button"
              @click="showCategoryModal = false"
              class="flex-1 bg-gray-300 text-gray-700 py-2 rounded-lg hover:bg-gray-400 transition"
            >
              取消
            </button>
          </div>
        </form>
      </div>
    </div>

    <div
      v-if="showPasswordModal"
      class="fixed inset-0 bg-black bg-opacity-50 flex items-center justify-center z-50 p-4"
      @click="handleBackdropClick('password')"
    >
      <div class="bg-white p-6 md:p-8 rounded-lg w-full max-w-md" @click.stop>
        <h3 class="text-xl font-bold mb-4">修改密码</h3>
        <form @submit.prevent="handleChangePassword" class="space-y-4">
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">旧密码</label>
            <input
              v-model="passwordForm.oldPassword"
              type="password"
              required
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
            />
          </div>
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">新密码</label>
            <input
              v-model="passwordForm.newPassword"
              type="password"
              required
              minlength="6"
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
            />
          </div>
          <div>
            <label class="block text-sm font-medium text-gray-700 mb-1">确认新密码</label>
            <input
              v-model="passwordForm.confirmPassword"
              type="password"
              required
              minlength="6"
              class="w-full px-4 py-2 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-500 outline-none"
            />
          </div>
          <div v-if="passwordError" class="text-red-500 text-sm">{{ passwordError }}</div>
          <div v-if="passwordSuccess" class="text-green-500 text-sm">{{ passwordSuccess }}</div>
          <div class="flex gap-4">
            <button
              type="submit"
              :disabled="passwordLoading"
              class="flex-1 bg-blue-600 text-white py-2 rounded-lg hover:bg-blue-700 transition disabled:opacity-50"
            >
              {{ passwordLoading ? '修改中...' : '确认修改' }}
            </button>
            <button
              type="button"
              @click="showPasswordModal = false; passwordError = ''; passwordSuccess = ''"
              class="flex-1 bg-gray-300 text-gray-700 py-2 rounded-lg hover:bg-gray-400 transition"
            >
              取消
            </button>
          </div>
        </form>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref, computed, onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { useAuthStore } from '../stores/auth'
import { useCredentialStore } from '../stores/credential'

const router = useRouter()
const authStore = useAuthStore()
const credentialStore = useCredentialStore()

const sidebarOpen = ref(false)
const searchQuery = ref('')
const selectedCategory = ref(null)
const showAddModal = ref(false)
const showCategoryModal = ref(false)
const newCategoryName = ref('')
const isEditing = ref(false)
const editingId = ref(null)
const formData = ref({
  platform: '',
  username: '',
  password: '',
  url: '',
  category: '',
  features: []
})
const newFeature = ref({ platform: '', accountName: '' })
const presetFeatures = ['微信', '支付宝', '抖音', '淘宝', '京东', 'QQ', '微博', '知乎']
const showPasswords = ref({})
const decryptedPasswords = ref({})
const showFormPassword = ref(false)
const showPasswordModal = ref(false)
const passwordForm = ref({
  oldPassword: '',
  newPassword: '',
  confirmPassword: ''
})
const passwordError = ref('')
const passwordSuccess = ref('')
const passwordLoading = ref(false)

const categories = computed(() => {
  const catMap = {}
  credentialStore.credentials.forEach(cred => {
    if (cred.category) {
      if (!catMap[cred.category]) {
        catMap[cred.category] = 0
      }
      catMap[cred.category]++
    }
  })
  return Object.entries(catMap).map(([name, count]) => ({ name, count }))
})

const filteredCredentials = computed(() => {
  let creds = credentialStore.credentials
  if (selectedCategory.value) {
    creds = creds.filter(c => c.category === selectedCategory.value)
  }
  if (searchQuery.value) {
    const query = searchQuery.value.toLowerCase()
    creds = creds.filter(
      cred =>
        cred.platform.toLowerCase().includes(query) ||
        cred.username.toLowerCase().includes(query)
    )
  }
  return creds
})

onMounted(() => {
  credentialStore.fetchCredentials()
})

const selectCategory = (name) => {
  selectedCategory.value = name
  sidebarOpen.value = false
}

const handleLogout = () => {
  if (confirm('确定要退出登录吗？')) {
    authStore.logout()
    router.push('/login')
  }
}

const goToTrash = () => {
  router.push('/trash')
}

const testClick = () => {
  console.log('Test click worked!')
  openAddModal()
}

const openAddModal = () => {
  console.log('Opening add modal')
  isEditing.value = false
  editingId.value = null
  formData.value = {
    platform: '',
    username: '',
    password: '',
    url: '',
    category: selectedCategory.value || '',
    features: []
  }
  newFeature.value = { platform: '', accountName: '' }
  showFormPassword.value = false
  showAddModal.value = true
  console.log('showAddModal set to:', showAddModal.value)
}

const openEditModal = (cred) => {
  isEditing.value = true
  editingId.value = cred.id
  let features = []
  if (cred.features) {
    try {
      features = JSON.parse(cred.features)
    } catch (e) {
      features = []
    }
  }
  formData.value = {
    platform: cred.platform,
    username: cred.username,
    password: cred.password,
    url: cred.url || '',
    category: cred.category || '',
    features: features
  }
  newFeature.value = { platform: '', accountName: '' }
  showFormPassword.value = false
  showAddModal.value = true
}

const closeModal = () => {
  showAddModal.value = false
  isEditing.value = false
  editingId.value = null
}

const handleBackdropClick = (type) => {
  if (type === 'add') closeModal()
  else if (type === 'category') showCategoryModal.value = false
  else if (type === 'password') showPasswordModal.value = false
}

const handleSubmit = async () => {
  console.log('Submitting form data:', formData.value)
  try {
    const duplicateCredential = credentialStore.credentials.find(
      c => c.username === formData.value.username && c.id !== editingId.value
    )
    if (duplicateCredential) {
      alert('账号名冲突，不能添加')
      return
    }

    const validFeatures = formData.value.features.filter(f => f.platform.trim())

    const data = {
      ...formData.value,
      features: validFeatures.length > 0 ? JSON.stringify(validFeatures) : null
    }
    console.log('Data to submit:', data)
    if (data.url && !data.url.match(/^https?:\/\//i)) {
      data.url = 'http://' + data.url
    }
    if (isEditing.value) {
      await credentialStore.updateCredential(editingId.value, data)
    } else {
      await credentialStore.addCredential(data)
    }
    closeModal()
    window.location.reload()
  } catch (error) {
    console.error('保存失败:', error)
    alert('保存失败: ' + (error.response?.data?.message || error.message))
  }
}

const handleChangePassword = async () => {
  passwordError.value = ''
  passwordSuccess.value = ''

  if (passwordForm.value.newPassword !== passwordForm.value.confirmPassword) {
    passwordError.value = '两次输入的新密码不一致'
    return
  }

  if (passwordForm.value.newPassword.length < 6) {
    passwordError.value = '新密码长度至少6位'
    return
  }

  if (passwordForm.value.oldPassword === passwordForm.value.newPassword) {
    passwordError.value = '新密码不能与旧密码相同'
    return
  }

  passwordLoading.value = true
  try {
    await authStore.changePassword(
      passwordForm.value.oldPassword,
      passwordForm.value.newPassword
    )
    passwordSuccess.value = '密码修改成功'
    passwordForm.value = { oldPassword: '', newPassword: '', confirmPassword: '' }
    setTimeout(() => {
      showPasswordModal.value = false
    }, 1500)
  } catch (error) {
    passwordError.value = error.response?.data?.message || '修改失败'
  } finally {
    passwordLoading.value = false
  }
}

const handleDelete = async (id) => {
  if (confirm('确定要删除这个账号吗？')) {
    await credentialStore.deleteCredential(id)
  }
}

const togglePassword = async (cred) => {
  if (showPasswords.value[cred.id]) {
    showPasswords.value[cred.id] = false
    return
  }
  showPasswords.value[cred.id] = true
  decryptedPasswords.value[cred.id] = cred.password
}

const parseFeatures = (featuresStr) => {
  try {
    return JSON.parse(featuresStr)
  } catch (e) {
    return []
  }
}

const formatDate = (dateString) => {
  if (!dateString) return '-'
  const date = new Date(dateString)
  return date.toLocaleString('zh-CN', {
    year: 'numeric',
    month: '2-digit',
    day: '2-digit',
    hour: '2-digit',
    minute: '2-digit'
  })
}

const addCategory = () => {
  console.log('addCategory called, newCategoryName:', newCategoryName.value)
  if (newCategoryName.value.trim()) {
    formData.value.category = newCategoryName.value.trim()
    showCategoryModal.value = false
    newCategoryName.value = ''
    console.log('Category added successfully')
  } else {
    console.log('Category name is empty')
  }
}

const addFeature = () => {
  if (!newFeature.value.platform.trim() || !newFeature.value.accountName.trim()) {
    return
  }
  const duplicateExists = formData.value.features.some(
    f => f.platform.toLowerCase() === newFeature.value.platform.trim().toLowerCase()
      || f.accountName.toLowerCase() === newFeature.value.accountName.trim().toLowerCase()
  )
  if (duplicateExists) {
    alert('平台名和用户名已存在')
    return
  }
  formData.value.features.push({
    platform: newFeature.value.platform.trim(),
    accountName: newFeature.value.accountName.trim()
  })
  newFeature.value = { platform: '', accountName: '' }
}

const addPresetFeature = (preset) => {
  const platformExists = formData.value.features.some(
    f => f.platform.toLowerCase() === preset.toLowerCase()
  )
  if (platformExists) {
    alert('平台名和用户名已存在')
    return
  }
  formData.value.features.push({
    platform: preset,
    accountName: newFeature.value.accountName.trim() || ''
  })
  newFeature.value = { platform: '', accountName: '' }
}

const removeFeature = (index) => {
  formData.value.features.splice(index, 1)
}

const deleteCategory = (name) => {
  if (confirm(`确定要删除分类"${name}"吗？`)) {
  }
}
</script>
