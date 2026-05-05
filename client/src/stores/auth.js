import { defineStore } from 'pinia'
import axios from 'axios'

const API_URL = '/api'

export const useAuthStore = defineStore('auth', {
  state: () => ({
    user: JSON.parse(localStorage.getItem('user') || 'null'),
    token: localStorage.getItem('token') || null
  }),
  getters: {
    isAuthenticated: (state) => !!state.token
  },
  actions: {
    async login(username, password) {
      const response = await axios.post(`${API_URL}/auth/login`, { username, password })
      this.token = response.data.token
      this.user = response.data.user
      localStorage.setItem('token', this.token)
      localStorage.setItem('user', JSON.stringify(this.user))
      return response.data
    },
    async register(username, password) {
      const response = await axios.post(`${API_URL}/auth/register`, { username, password })
      return response.data
    },
    logout() {
      this.token = null
      this.user = null
      localStorage.removeItem('token')
      localStorage.removeItem('user')
    },
    async changePassword(oldPassword, newPassword) {
      const token = localStorage.getItem('token')
      const response = await axios.post(
        `${API_URL}/auth/change-password`,
        { oldPassword, newPassword },
        { headers: { Authorization: `Bearer ${token}` } }
      )
      return response.data
    }
  }
})
