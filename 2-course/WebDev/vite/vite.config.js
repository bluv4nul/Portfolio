import { resolve } from 'path'
import { defineConfig } from 'vite'

export default defineConfig({
    root: "src/",
    build: {
        outDir: '../dist'
    },
    server: {
        port: 8000
    },
    base: '/Web-dev-lab/'
})