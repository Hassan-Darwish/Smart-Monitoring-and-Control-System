# Embedded System: Smart Monitoring and Control System

## Project Overview

This project is a fully integrated embedded system designed to monitor environmental parameters such as temperature, light intensity, and flame presence. It provides real-time feedback and control mechanisms, utilizing various sensors and actuators to ensure efficient monitoring and response. The system is ideal for safety-critical environments, automating responses to environmental changes.

---

## Features

- **Temperature Monitoring and Fan Control**:
  - Utilizes an LM35 temperature sensor.
  - Dynamically adjusts fan speed based on temperature thresholds.
- **Light Intensity Monitoring**:
  - Uses an LDR sensor to measure light intensity.
  - Changes LED states based on predefined intensity thresholds.
- **Flame Detection and Alert**:
  - Incorporates a flame sensor to detect fire hazards.
  - Activates a buzzer and displays a critical alert on the LCD when flames are detected.
- **Real-Time Display**:
  - A 16x2 LCD screen shows sensor readings and system status.
- **Automated Actuation**:
  - Includes a DC motor, RGB LEDs, and a buzzer for visual and audible feedback.

---

## System Components

### Hardware Components
1. **Sensors**:
   - **LM35**: Temperature measurement.
   - **LDR**: Light intensity detection.
   - **Flame Sensor**: Fire detection.
2. **Actuators**:
   - **DC Motor**: Used as a fan for cooling.
   - **RGB LEDs**: Visual indication of light intensity.
   - **Buzzer**: Audible alerts for critical events.
3. **Output Device**:
   - **16x2 LCD Display**: For displaying environmental data and alerts.

### Software Modules
- **`gpio.h`**: Manages general-purpose input/output.
- **`pwm.h`**: Provides pulse-width modulation for controlling motor speed.
- **`adc.h`**: Reads analog signals from sensors.
- **`lcd.h`**: Controls the LCD for data display.
- **`dc_motor.h`**: Controls the fan motor speed and direction.
- **`led.h`**: Manages the RGB LED states.
- **`ldr_sensor.h`**: Reads and processes data from the LDR sensor.
- **`flame_sensor.h`**: Monitors and handles flame sensor data.
- **`lm35_sensor.h`**: Processes temperature data from the LM35 sensor.
- **`buzzer.h`**: Handles buzzer activation for alerts.
- **`bit_manipulation.h`**: Provides macros for efficient bitwise operations.
- **`stdtypes.h`**: Defines standard types (`uint8`, `uint16`, etc.) for consistency.

---

## Functional Flow

1. **Initialization**:
   - Initialize all modules, including ADC, LCD, LEDs, sensors, and actuators.
2. **Monitoring Loop**:
   - Continuously monitor sensor values.
   - Display real-time data on the LCD.
   - Respond to sensor inputs by controlling actuators.
3. **System Behavior**:
   - Adjust fan speed based on temperature thresholds.
   - Change LED states based on light intensity levels.
   - Trigger alerts for flame detection until the hazard is cleared.

---

## Thresholds and Behavior

- **Temperature**:
  - `25°C`: Fan OFF
  - `25°C - 30°C`: Fan at quarter speed
  - `30°C - 35°C`: Fan at half speed
  - `35°C - 40°C`: Fan at three-quarters speed
  - `>40°C`: Fan at full speed
- **Light Intensity**:
  - `<15`: All LEDs ON
  - `15 - 50`: Red and Green LEDs ON
  - `50 - 70`: Only Red LED ON
  - `>70`: All LEDs OFF
- **Flame Detection**:
  - Buzzer ON and critical alert displayed until flame is no longer detected.

---

## How to Use

### Hardware Setup
- Connect the sensors, actuators, and LCD to the microcontroller following the pinout in the source code.
- Ensure proper power supply and wiring for all components.

### Software Setup
1. Include all header files (`modules.h`, `gpio.h`, etc.) in your project.
2. Compile the source code using an AVR-compatible compiler.
3. Upload the compiled program to the microcontroller.

### Operation
1. Power on the system.
2. Observe real-time sensor data and system status on the LCD.
3. Test system responses by varying temperature, light intensity, or introducing a flame.

---

## Proteus Simulation

Below is the Proteus simulation design for the system, showcasing the connections between sensors, actuators, and the microcontroller:

<img width="1916" alt="Screenshot 2024-11-20 at 11 41 41 PM" src="https://github.com/user-attachments/assets/fa9e4ee2-91d5-47fa-b136-82284e3caa09">

---
## File Descriptions

- **`main.c`**: The main source file containing the system logic and monitoring loop.
- **`main.h`**: Defines constants, thresholds, and LCD positions.
- **`modules.h`**: Includes all necessary headers for the project's modules.
- **Module Drivers**:
  - `gpio.h`, `pwm.h`, `adc.h`, etc., provide individual functionalities for hardware components.

---

## Author

- **Hassan Darwish**

This project demonstrates a robust example of embedded system design for monitoring and control applications. Contributions and modifications are welcome!
