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
              @click="goHome"
              class="w-full text-left px-4 py-2 rounded-lg hover:bg-gray-100 transition"
            >
              返回主页
            </button>
          </li>
          <li>
            <button
              @click="selectCategory(null)"
              :class="[
                'w-full text-left px-4 py-2 rounded-lg transition',
                selectedCategory === null ? 'bg-blue-100 text-blue-700' : 'hover:bg-gray-100'
              ]"
            >
              全部 ({{ credentialStore.trashCredentials.length }})
            </button>
          </li>
        </ul>
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
            <h1 class="text-xl font-bold text-gray-800">回收站</h1>
          </div>
          <div class="flex items-center gap-4">
            <span class="text-gray-600 text-sm">欢迎</span>
            <span class="text-blue-600 font-medium text-sm">{{ authStore.user?.username }}</span>
            <button
              @click="handleLogout"
              class="bg-red-500 text-white px-4 py-2 rounded-lg hover:bg-red-600 transition text-sm"
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
              已删除的账号 ({{ credentialStore.trashCredentials.length }})
            </h2>
            <button
              @click="clearAllTrash"
              :disabled="credentialStore.trashCredentials.length === 0"
              class="bg-red-600 text-white px-6 py-2 rounded-lg hover:bg-red-700 transition disabled:opacity-50 w-full sm:w-auto"
            >
              清空回收站
            </button>
          </div>

          <div v-if="credentialStore.loading" class="text-center py-8">
            <span class="text-gray-500">加载中...</span>
          </div>

          <div v-else-if="credentialStore.trashCredentials.length === 0" class="text-center py-8">
            <p class="text-gray-500 mb-4">回收站是空的</p>
            <button
              @click="goHome"
              class="text-blue-600 hover:underline"
            >
              返回主页
            </button>
          </div>

          <div v-else class="grid gap-4 sm:grid-cols-2 lg:grid-cols-3">
            <div
              v-for="cred in credentialStore.trashCredentials"
              :key="cred.id"
              class="bg-gray-50 p-4 md:p-6 rounded-lg hover:shadow-md transition relative"
            >
              <div class="absolute top-2 right-2 bg-gray-300 text-gray-700 text-xs px-2 py-1 rounded">
                已删除
              </div>
              <div class="flex justify-between items-start mb-4">
                <h3 class="text-lg font-semibold text-gray-800 break-words pr-16">{{ cred.platform }}</h3>
              </div>
              <div class="space-y-2 text-sm">
                <p class="text-gray-600 break-all">
                  <span class="font-medium">用户名:</span> {{ cred.username }}
                </p>
                <p v-if="cred.url" class="text-gray-600 break-all">
                  <span class="font-medium">网址:</span>
                  <a :href="cred.url" target="_blank" class="text-blue-600 hover:underline ml-1 break-words">
                    {{ cred.url }}
                  </a>
                </p>
                <p v-if="cred.deletedAt" class="text-gray-500 text-xs">
                  删除于: {{ formatDate(cred.deletedAt) }}
                </p>
              </div>
              <div class="flex gap-2 mt-4">
                <button
                  @click="handleRestore(cred.id)"
                  class="flex-1 bg-green-500 text-white py-2 rounded-lg hover:bg-green-600 transition text-sm"
                >
                  恢复
                </button>
                <button
                  @click="handlePermanentDelete(cred.id)"
                  class="flex-1 bg-red-500 text-white py-2 rounded-lg hover:bg-red-600 transition text-sm"
                >
                  永久删除
                </button>
              </div>
            </div>
          </div>
        </div>
      </div>
    </main>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue'
import { useRouter } from 'vue-router'
import { useAuthStore } from '../stores/auth'
import { useCredentialStore } from '../stores/credential'

const router = useRouter()
const authStore = useAuthStore()
const credentialStore = useCredentialStore()

const sidebarOpen = ref(false)
const selectedCategory = ref(null)

onMounted(() => {
  credentialStore.fetchTrashCredentials()
})

const goHome = () => {
  router.push('/home')
}

const selectCategory = (name) => {
  selectedCategory.value = name
}

const handleLogout = () => {
  authStore.logout()
  router.push('/login')
}

const handleRestore = async (id) => {
  if (confirm('确定要恢复这个账号吗？')) {
    await credentialStore.restoreCredential(id)
  }
}

const handlePermanentDelete = async (id) => {
  if (confirm('确定要永久删除这个账号吗？此操作不可恢复！')) {
    await credentialStore.permanentDeleteCredential(id)
  }
}

const clearAllTrash = async () => {
  if (confirm('确定要清空回收站吗？此操作不可恢复！')) {
    const ids = credentialStore.trashCredentials.map(c => c.id)
    for (const id of ids) {
      await credentialStore.permanentDeleteCredential(id)
    }
  }
}

const formatDate = (dateString) => {
  const date = new Date(dateString)
  return date.toLocaleString('zh-CN')
}
</script>
