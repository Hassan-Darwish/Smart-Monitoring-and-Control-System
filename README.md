# Smart Monitoring and Control System

## Project Overview

This project implements an embedded system designed to monitor environmental conditions such as temperature, light intensity, and flame presence, and to respond accordingly by controlling actuators (fan, LEDs, buzzer). The system utilizes various sensors and components, displaying real-time data and alerts on an LCD.

---

## Features

- **Temperature Monitoring**: Reads temperature values using an LM35 sensor and adjusts fan speed accordingly.
- **Light Intensity Detection**: Measures light intensity using an LDR sensor and changes LED states based on thresholds.
- **Flame Detection**: Monitors for flames and triggers a critical alert using a buzzer and LCD display.
- **Dynamic Actuator Control**:
  - Fan: Adjusts speed based on temperature thresholds.
  - LEDs: Changes color and combination based on light intensity.
  - Buzzer: Activates upon detecting flames.
- **User-Friendly Interface**: Displays sensor readings and system status on an LCD screen.

---

## System Components

### Hardware
- **Sensors**:
  - LM35 Temperature Sensor
  - LDR (Light Dependent Resistor)
  - Flame Sensor
- **Actuators**:
  - DC Motor (Fan)
  - RGB LEDs
  - Buzzer
- **Output Device**:
  - 16x2 LCD Display

### Software
- Microcontroller programming in C.
- Modules for each component:
  - ADC for analog data conversion.
  - LCD driver for displaying information.
  - LED, Buzzer, and Motor control modules.

---

## Implementation

### Functional Flow
1. **Initialization**: System initializes all modules (ADC, LCD, LEDs, sensors, etc.).
2. **Monitoring Loop**:
   - Continuously reads sensor values.
   - Displays temperature, light intensity, and system status on the LCD.
   - Dynamically controls actuators based on thresholds:
     - **Temperature**: Adjusts fan speed.
     - **Light Intensity**: Adjusts LED states.
     - **Flame Detection**: Triggers alerts and waits for the hazard to clear.
3. **Response**: Updates the system state based on sensor inputs.

### Thresholds and Behavior
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
- **Flame Detection**: Buzzer and alert until flame is gone.

---

## File Descriptions

- **`main.c`**: Contains the main function and system logic. Initializes modules and defines the monitoring loop.
- **`main.h`**: Header file with project-specific constants (e.g., thresholds, LCD positions).
- **Modules**:
  - ADC, LCD, LED, DC Motor, and Flame Sensor drivers (referenced in `modules.h`).

---

## Usage Instructions

1. **Hardware Setup**:
   - Connect the sensors, actuators, and LCD to the microcontroller.
   - Ensure proper power supply and wiring.

2. **Software**:
   - Compile and upload the program to the microcontroller.
   - Adjust thresholds in `main.h` if needed.

3. **Operation**:
   - Power on the system.
   - Observe the LCD for real-time data and alerts.
   - Test sensor responses by varying temperature, light intensity, and introducing a flame.

---

## Author

- **Hassan Darwish**

Feel free to adapt and expand this project for your specific needs.
