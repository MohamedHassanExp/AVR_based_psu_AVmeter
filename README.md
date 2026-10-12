# AVR Based Wattmeter 

[![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=flat-square&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)

An Arduino-based digital wattmeter that measures DC voltage, current, and power consumption in real-time. The system uses a voltage divider for voltage scaling, a shunt-based current sensing amplifier, and displays them on a 16x2 I2C LCD screen.

---

##  Hardware Requirements (Bill of Materials)

To build this project, you will need the following components:

| Component | Description / Spec | Quantity |
| :--- | :--- | :--- |
| **Microcontroller** | Arduino Uno (or compatible) | 1 |
| **Display** | 16x2 LCD Display with I2C Backpack (Address `0x27`) | 1 |
| **Current Sensor** | Current Shunt / Amplifier (Up to 5A max) | 1 |
| **Resistor (R1)** | 1 kΩ (Voltage divider top resistor) | 1 |
| **Resistor (R2)** | 330 Ω (Voltage divider bottom resistor) | 1 |
| **Misc** | Breadboard, Jumper Wires | As needed |

##  Circuit Schematic & Wiring

**Key Pin Connections:**

*   **Voltage Measurement (Voltage Divider):** Connect the center node between R1 (1kΩ) and R2 (330Ω) to **Arduino Analog Pin A0**.
*   **Current Measurement:** Connect the analog output of your current sense amplifier to **Arduino Analog Pin A1**.
*   **I2C LCD Display:**
    *   **GND** -> Arduino GND
    *   **VCC** -> Arduino 5V
    *   **SDA** -> Arduino A4 (or dedicated SDA pin)
    *   **SCL** -> Arduino A5 (or dedicated SCL pin)

> **Note on Voltage Scaling:** The voltage divider (1kΩ and 330Ω) scales the input voltage down so it safely stays under the Arduino's 5V ADC limit.

##  Software & Dependencies

This project is written in C++ for the Arduino framework. 

**Required Libraries:**

*   `LiquidCrystal I2C` by Frank de Brabander (v1.1.2+)

##  Setup & Installation 

1. **Hardware Assembly:** Wire the components according to the pin mapping above. 
2. **Configure Sensor Values:** Open `psu_AVmeter.ino` and update the hardware-specific variables at the top of the file to match your exact current sensor:
   ```cpp
   int gain = 1;                 // Replace with your amplifier's gain
   float minimumShuntVoltage = 0.1; // Replace with your shunt specs
