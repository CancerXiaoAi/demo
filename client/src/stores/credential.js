import { defineStore } from 'pinia'
import axios from 'axios'

const API_URL = '/api'

export const useCredentialStore = defineStore('credential', {
  state: () => ({
    credentials: [],
    trashCredentials: [],
    loading: false
  }),
  actions: {
    async fetchCredentials() {
      this.loading = true
      const token = localStorage.getItem('token')
      try {
        const response = await axios.get(`${API_URL}/credentials`, {
          headers: { Authorization: `Bearer ${token}` }
        })
        this.credentials = response.data
      } finally {
        this.loading = false
      }
    },
    async fetchTrashCredentials() {
      this.loading = true
      const token = localStorage.getItem('token')
      try {
        const response = await axios.get(`${API_URL}/credentials/trash`, {
          headers: { Authorization: `Bearer ${token}` }
        })
        this.trashCredentials = response.data
      } finally {
        this.loading = false
      }
    },
    async addCredential(data) {
      const token = localStorage.getItem('token')
      const response = await axios.post(`${API_URL}/credentials`, data, {
        headers: { Authorization: `Bearer ${token}` }
      })
      this.credentials.push(response.data)
      return response.data
    },
    async updateCredential(id, data) {
      const token = localStorage.getItem('token')
      const response = await axios.put(`${API_URL}/credentials/${id}`, data, {
        headers: { Authorization: `Bearer ${token}` }
      })
      const index = this.credentials.findIndex(c => c.id === id)
      if (index !== -1) {
        this.credentials[index] = response.data
      }
      return response.data
    },
    async deleteCredential(id) {
      const token = localStorage.getItem('token')
      await axios.delete(`${API_URL}/credentials/${id}`, {
        headers: { Authorization: `Bearer ${token}` }
      })
      this.credentials = this.credentials.filter(c => c.id !== id)
    },
    async restoreCredential(id) {
      const token = localStorage.getItem('token')
      const response = await axios.post(`${API_URL}/credentials/${id}/restore`, {}, {
        headers: { Authorization: `Bearer ${token}` }
      })
      this.trashCredentials = this.trashCredentials.filter(c => c.id !== id)
      this.credentials.push(response.data)
      return response.data
    },
    async permanentDeleteCredential(id) {
      const token = localStorage.getItem('token')
      await axios.delete(`${API_URL}/credentials/${id}/permanent`, {
        headers: { Authorization: `Bearer ${token}` }
      })
      this.trashCredentials = this.trashCredentials.filter(c => c.id !== id)
    }
  }
})
