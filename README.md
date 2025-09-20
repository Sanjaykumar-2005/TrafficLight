# 🚦 STM32 Traffic Light System

This project demonstrates a **Traffic Light System** using an **STM32C0 microcontroller**.  
It simulates real-world traffic signals by controlling three LEDs (Red, Yellow, Green).  

---
## 📷 Project Overview
- **Red LED (Stop)** – ON for 5 seconds  
- **Yellow LED (Wait)** – ON for 3 seconds  
- **Green LED (Go)** – ON for 5 seconds  
- The cycle repeats continuously.  

---

## 🛠️ Hardware Setup
- **STM32C0 Series MCU** (e.g., STM32C031C6)  
- **LEDs**: Red, Yellow, Green  
- **Resistors**: 220Ω each (for current limiting)  
- **Connections**:  
  - **Red LED** → PA10  
  - **Yellow LED** → PB3  
  - **Green LED** → PB10

---

## ⚡ Working
1. Red LED turns ON for **5 seconds** → vehicles stop.  
2. Yellow LED turns ON for **3 seconds** → prepare to move.  
3. Green LED turns ON for **5 seconds** → vehicles move.  
4. Cycle repeats infinitely.  

---

## 📌 Notes
- Delay is implemented using a simple software loop.  
- Can be improved using **SysTick Timer** for accurate timing.  
- Useful as a **beginner embedded systems project** with STM32.  
