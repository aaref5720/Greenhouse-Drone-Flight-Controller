# Greenhouse Drone Flight Controller

This repository contains the flight controller code developed for the Greenhouse Drone as part of a graduation project in the Mechatronics Department. It's important to note that this repository specifically focuses on the flight controller module, which constitutes one part of the entire project. Other components of the project, such as computer vision, AI, data analysis, and various other parts, are not included in this repository.

The purpose of the flight controller is to operate within a greenhouse, providing essential environmental data and scanning the plant status. The flight controller module focuses on implementing the flight control algorithms and interfaces with various sensors and peripherals.

## Features

* **Flight Modes:**
  - Rate mode, self-level mode, heading hold, and altitude hold.
  - Utilizes AUX switches for mode selection.
* **EEPROM Storage:**
  - Stores PID values, calibration data, etc., in EEPROM.
* **Calibration Routines:**
  - Gyro, accelerometer & magnetometer calibration routines.
* **Arm/Disarm Functionality:**
  - Arm and disarm using the rudder.
* **Status Indication:**
  - LEDs for indicating system status.
* **Receiver Support:**
  - Supports CPPM receivers.
* **Sensor Support:**
  - Gyro & accelerometer (MPU-6500 or MPU-9250).
  - Magnetometer (AK8963 inside MPU-9250).
  - Barometer (BMP180).
  - Ultrasound sensor (HC-SR04).

## Pinout

Refer to the following table for pin connections and corresponding hardware peripherals:

| Pin | Connection            | Hardware peripheral |
| --- | --------------------- | ------------------- |
| PA0 | UART RX               | U0RX (UART0 RX)     |
| PA1 | UART TX               | U0TX (UART0 TX)     |
| PA2 | SPI CLK               | SSI0CLK             |
| PA3 | SPI SS                | SSI0Fss             |
| PA4 | SPI MISO              | SSI0Rx              |
| PA5 | SPI MOSI              | SSI0Tx              |
| PA6 | SCL                   | I2C1SCL             |
| PA7 | SDA                   | I2C1SDA             |
| PB4 | Motor 3               | M0PWM2              |
| PB5 | Motor 4               | M0PWM3              |
| PB6 | Motor 1               | M0PWM0              |
| PB7 | Motor 2               | M0PWM1              |
| PC5 | Sonar echo            | WTimer0B (WT0CCP1)  |
| PC6 | CPPM input            | WTimer1A (WT1CCP0)  |
| PD2 | Buzzer                |                     |
| PE0 | Sonar trigger         |                     |
| PE2 | MPU-6500/MPU-9250 INT |                     |
| PF0 | Switch 1              |                     |
| PF1 | Red LED               |                     |
| PF2 | Blue LED              |                     |
| PF3 | Green LED             |                     |
| PF4 | Switch 2              |                     |

Furthermore, WTimer1B is used to turn off motors if the connection to the RX is lost. SysTick counter is used for basic timekeeping functionality.

All pins are defined in [src/Config.h](src/Config.h) and can be overridden by creating a file called "Config_custom.h" in the [src](src) directory allowing you to redefine the values.

## TODO

- Implement support for the HMC5883L magnetometer to make more flexability in choises.
- Integrate the optical flow sensor (ADNS3080) into the system.
- Incorporate support for the Bluetooth module for wireless communication.
- Develop a mobile application for calibrating the accelerometer and magnetometer and tuning PID values.
- Add a documentation for full Greenhouse Drone Flight Controller.

## Contributors

- Abdelrahman Aref - Team Leader & Flight Controller Developer
- Ahmed Emad - AI & Computer Vision - [LinkedIn](https://www.linkedin.com/in/ahmed-emad-056a9b235/)
- Ahmed Ashraf - AI and Data Analysis - [LinkedIn](https://www.linkedin.com/in/ahmed-ashraf-516363199/)

## Acknowledgments

- Special thanks to Cleanflight, Kristian Sloth Lauszus, Multiwii, and other open-source flight controller projects for their valuable contributions and inspiration.
- Portions of code and inspiration may have been derived from these projects, credited within the source files.

