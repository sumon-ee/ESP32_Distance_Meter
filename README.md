# 📏 ESP32 Distance Meter with OLED, LED & Buzzer

An embedded IoT project that measures distance using an **HC-SR04 Ultrasonic Sensor** and displays the output in real-time on a **0.96" I2C OLED display**. The system triggers a **Buzzer** and **LED alert** when an object comes within a defined threshold distance.

---

## 📌 Features
* Real-time distance measurement in centimeters (cm).
* Clean visual output on a 128x64 I2C OLED Display.
* Audio-visual alert (LED + Buzzer) when an object is closer than 20 cm.
* Built with ESP32 DevKit V1.

---

## 🛠 Hardware Required
* ESP32 DevKit V1
* HC-SR04 Ultrasonic Sensor
* 0.96" SSD1306 I2C OLED Display
* 5V Active/Passive Buzzer
* 5mm LED & 220Ω Resistor
* Breadboard & Jumper Wires

---

## 🔌 Pin Mapping

| Component | Pin | ESP32 Pin |
| :--- | :--- | :--- |
| **HC-SR04** | VCC | VIN (5V) |
| | GND | GND |
| | Trig | GPIO 5 |
| | Echo | GPIO 18 |
| **OLED Display** | VCC | 3.3V |
| | GND | GND |
| | SCL | GPIO 22 |
| | SDA | GPIO 21 |
| **LED** | Anode (+) | GPIO 2 |
| | Cathode (-) | GND (via 220Ω Resistor) |
| **Buzzer** | Positive (+) | GPIO 4 |
| | Negative (-) | GND |

---

## 💻 Software & Libraries Required

### **IDE:**
* Arduino IDE (with ESP32 board support installed)

### **Libraries:**
* `Adafruit_SSD1306`
* `Adafruit_GFX`
* `Wire` (Built-in)

---

## 🚀 How to Run
1. Clone this repository or download the source code.
2. Open the `.ino` file in Arduino IDE.
3. Install the required libraries via **Sketch -> Include Library -> Manage Libraries**.
4. Connect your ESP32 board to your computer.
5. Select Board as **ESP32 Dev Module** and choose the correct **COM Port**.
6. Upload the code and power up the circuit!

---

## 📜 License
This project is licensed under the [MIT License](LICENSE).
