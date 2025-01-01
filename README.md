# Wind Speed Alarm System

This project measures wind speed in different environments using an anemometer, determines high wind speeds, and activates an alarm system when necessary. The system is designed to alert users to high wind speeds via an LCD screen and a blinking LED.

---

## 📜 Overview

The project consists of two main components:
1. **Router**: Collects wind speed data using an anemometer, processes the data, and sends it to the coordinator.
2. **Coordinator**: Receives wind speed data and triggers an alarm if the wind speed exceeds a certain threshold.

---

## 🛠️ Features

- Measures wind speed in real-time.
- Alerts the user with a blinking LED and a message on an LCD when wind speed exceeds 30 km/h.
- Displays "All looks good!" for normal wind conditions.

---

## 🔧 Hardware Requirements

- Arduino UNO (or similar)
- Adafruit Anemometer
- 16x2 I2C LCD Display
- LED
- Connecting wires
- Resistors

---

## 📂 Code Explanation

### **Router**
- Reads analog data from the anemometer.
- Converts voltage to wind speed (in km/h).
- Sends data (`1` for high wind speed, `2` for normal conditions) to the coordinator.

### **Coordinator**
- Receives the data from the router.
- Displays warnings or normal status on the LCD.
- Controls the LED based on the received data.

---

## 🚀 Getting Started

1. **Set up the hardware**: Connect the components as shown in the diagram (add an image in `images/` folder).
2. **Upload the code**:
   - Router code: Upload `router.ino` to the Arduino controlling the anemometer.
   - Coordinator code: Upload `coordinator.ino` to the Arduino managing the alarm system.
3. **Run the system**: Observe real-time wind speed and the alarm system's response.

---

## 📜 Code Files

- [Router Code](router_code/router.ino)
- [Coordinator Code](coordinator_code/coordinator.ino)

---

## 📸 Example Outputs (Optional)

Include images or videos of your system in action, such as:
- LCD showing "ATTENTION HIGH WIND SPEED"
- The LED blinking during high wind speeds.
