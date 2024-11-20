# Smart Monitoring and Control System

The Smart Monitoring and Control System is an embedded system designed for real-time environmental monitoring. It utilizes multiple sensors to measure temperature, light intensity, and flame presence, providing automated control of actuators such as a fan, LEDs, and a buzzer. This system is ideal for safety-critical environments, offering efficient monitoring and response.

---

## Features

1. **Multi-Sensor Monitoring**:
   - Temperature, light intensity, and flame detection.
   - Real-time display on a 16x2 LCD.

2. **Actuator Control**:
   - **Fan**: Automatically adjusts speed based on temperature.
   - **LEDs**: Change states depending on light intensity levels.
   - **Buzzer**: Alerts users to critical flame detection.

3. **Dynamic Alerts**:
   - Flame detection triggers a buzzer and an LCD alert.
   - Fan operation status is displayed on the LCD.

4. **Customizable Thresholds**:
   - Temperature and light intensity thresholds can be adjusted in the code.

---

## Components Required

1. **Microcontroller**:
   - ATmega32.

2. **Sensors**:
   - LM35 (Temperature).
   - LDR (Light Intensity).
   - Flame Sensor.

3. **Actuators**:
   - DC Motor (Fan).
   - RGB LEDs.
   - Buzzer.

4. **Display**:
   - 16x2 LCD.

5. **Other**:
   - Necessary drivers (`gpio.h`, `adc.h`, `pwm.h`).

---

## How It Works

1. **Initialization**:
   - All modules (ADC, PWM, LCD, etc.) are initialized.

2. **Monitoring and Control**:
   - Sensors continuously send data to the microcontroller.
   - Actuators respond dynamically based on sensor inputs:
     - Fan speed adjusts with temperature.
     - LEDs change based on light intensity.
     - Buzzer activates for flame detection.

3. **Real-Time Feedback**:
   - Sensor readings and system status are displayed on the LCD.

---

## Code Overview

The code is written in C and uses AVR libraries for hardware interfacing:

- **Sensor Input**:
  - ADC reads analog signals from LM35 and LDR sensors.
  - Flame sensor provides digital input.

- **Actuator Control**:
  - PWM controls the DC motor speed.
  - GPIO controls LEDs and the buzzer.

- **LCD Display**:
  - Displays real-time sensor readings and system alerts.

- **Custom Functions**:
  - `ADC_init`, `LCD_init`, `FLAME_SENSOR_getValue`, etc., manage hardware-specific tasks.
  - Threshold values are defined in `main.h`.

---

## Pin Configuration

| Port | Pin   | Description                          |
|------|-------|--------------------------------------|
| PORTA | PA0   | ADC Channel 0 for LM35 Sensor        |
| PORTA | PA1   | ADC Channel 1 for LDR Sensor         |
| PORTB | PB0   | LED Red                              |
| PORTB | PB1   | LED Green                            |
| PORTB | PB2   | LED Blue                             |
| PORTC | PC0-PC7 | Data lines for LCD                 |
| PORTD | PD0   | Flame Sensor Input                   |
| PORTD | PD4   | Buzzer Output                        |
| PORTD | PD5   | Fan Motor Control                    |

---

## How to Run

1. **Setup Hardware**:
   - Assemble the circuit as per the pin configuration.
   - Ensure proper connections for sensors, actuators, and the LCD.

2. **Load Code**:
   - Use an AVR programmer to upload the code to the ATmega32 microcontroller.

3. **Power On**:
   - The system will start monitoring and controlling components based on sensor inputs.

---

## Circuit Diagram

Below is the Proteus simulation for the Smart Monitoring and Control System:

<img width="1916" alt="Screenshot 2024-11-20 at 11 41 41 PM" src="https://github.com/user-attachments/assets/fa9e4ee2-91d5-47fa-b136-82284e3caa09">

To explore or edit the circuit, open the included Proteus project file (`project3.pdsprj`) using Proteus Design Suite.

---

## Future Enhancements

- Add a Wi-Fi module for remote monitoring.
- Replace the LCD with a more advanced OLED display.
- Integrate machine learning for predictive hazard detection.

---

## License

This project is open-source under the MIT License. Feel free to modify and share.

---

## Author

Developed by **Hassan Darwish**.
