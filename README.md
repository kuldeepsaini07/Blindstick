# 🦯 Smart Blind Stick using ESP32 (GPS + Ultrasonic Sensors)

## 📌 Overview

This project is a **Smart Blind Stick** designed to assist visually impaired individuals by providing real-time obstacle detection and location tracking.

It uses:

* **ESP32** as the main controller
* **2 Ultrasonic Sensors** for obstacle & ground detection
* **GPS Module (NEO-6M)** for location tracking
* **Buzzer** for alert feedback

---

## 🚀 Features

* 🚧 **Obstacle Detection (Front Sensor)**
  Alerts user when an object is detected ahead

* 🕳️ **Ground/Pit Detection (Down Sensor)**
  Detects stairs, holes, or sudden drops

* 📍 **Live GPS Tracking**
  Displays real-time latitude & longitude

* 🔊 **Audio Alert System**
  Different beep patterns for different dangers

---

## 🛠️ Hardware Components

* ESP32 Development Board
* 2 × HC-SR04 Ultrasonic Sensors
* NEO-6M GPS Module
* Buzzer
* Jumper Wires
* Power Supply (Battery)

---

## 🔌 Pin Configuration

### Ultrasonic Sensors

| Sensor | TRIG    | ECHO    |
| ------ | ------- | ------- |
| Front  | GPIO 5  | GPIO 18 |
| Down   | GPIO 19 | GPIO 21 |

### GPS Module

| GPS Pin | ESP32   |
| ------- | ------- |
| TX      | GPIO 16 |
| RX      | GPIO 17 |

### Buzzer

| Component | Pin     |
| --------- | ------- |
| Buzzer +  | GPIO 23 |

---

## ⚙️ Working Principle

1. The **front ultrasonic sensor** detects obstacles within a threshold distance (e.g., 100 cm).
2. The **downward sensor** continuously measures ground distance:

   * Normal → small distance
   * Pit/Stairs → sudden increase
3. The **buzzer** provides alerts:

   * Short beep → obstacle
   * Long beep → pit/stairs
4. The **GPS module** continuously updates location data.

---

## 💻 Software Requirements

* Arduino IDE
* ESP32 Board Package
* Libraries:

  * TinyGPS++

---

## 📥 Installation & Setup

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/smart-blind-stick.git
   ```

2. Open the code in Arduino IDE

3. Install required library:

   * TinyGPS++ (via Library Manager)

4. Select Board:

   ```
   ESP32 Dev Module
   ```

5. Upload the code to ESP32

---

## ▶️ Usage

* Power ON the device
* Hold the stick normally
* The system will:

  * Detect obstacles ahead
  * Detect pits/stairs below
  * Provide audio alerts
  * Output GPS data via Serial Monitor

---

## 📊 Output Example

```
Latitude: 28.6139
Longitude: 77.2090
```

---

## 🔧 Future Improvements

* 📱 GSM module for emergency SMS
* 🎧 Voice alerts instead of buzzer
* 📳 Vibration motor feedback
* 📡 Mobile app integration
* 🔋 Rechargeable battery system

---

## 🤝 Contributing

Contributions are welcome!
Feel free to fork this repo and improve the project.

---

## 📜 License

This project is open-source and available under the MIT License.

---

## 🙌 Acknowledgment

This project is inspired by the need to make assistive technology more affordable and accessible.

---

## 👨‍💻 Author

**Kuldeep Saini**
Embedded Systems Enthusiast 🚀

