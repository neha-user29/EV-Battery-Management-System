# Battery Management System (BMS) Simulation in C

## Overview

This project is a simplified **Battery Management System (BMS)** simulation developed in **C** using **Visual Studio Code** and the **GCC compiler**. It demonstrates the core functionalities of an Electric Vehicle (EV) Battery Management System through a modular embedded software architecture.

The application simulates battery charging and discharging, estimates the battery's **State of Charge (SOC)** and **State of Health (SOH)**, monitors battery temperature, and performs basic thermal management by controlling a cooling fan.

---

## Features

* Battery Initialization
* Battery Charging Simulation
* Battery Discharging Simulation
* State of Charge (SOC) Estimation using Coulomb Counting
* State of Health (SOH) Estimation
* Thermal Management
* Automatic Cooling Fan Control
* Battery Status Monitoring
* Menu-Driven Console Application
* Modular Embedded C Programming

---

## Project Structure

```text
EV_BMS_C
│
├── include
│   ├── battery.h
│   ├── soc.h
│   ├── soh.h
│   └── thermal.h
│
├── src
│   ├── main.c
│   ├── battery.c
│   ├── soc.c
│   ├── soh.c
│   └── thermal.c
│
├── build
│   └── bms.exe
│
└── README.md
```

---

## Technologies Used

* C Programming
* Visual Studio Code
* GCC Compiler (MinGW)
* Windows PowerShell / Command Prompt

---

## Battery Specifications

| Parameter           | Value |
| ------------------- | ----- |
| Battery Voltage     | 400 V |
| Battery Capacity    | 50 Ah |
| Initial SOC         | 100%  |
| Initial SOH         | 100%  |
| Initial Temperature | 25°C  |

---

## Modules

### Battery Module

* Initializes battery parameters
* Simulates charging and discharging operations
* Displays battery information

### State of Charge (SOC)

* Implements the Coulomb Counting method
* Updates SOC during charging and discharging
* Maintains SOC between 0% and 100%

### State of Health (SOH)

* Simulates battery aging
* Updates SOH after charging cycles
* Tracks charge cycle count

### Thermal Management

* Monitors battery temperature
* Automatically controls the cooling fan
* Displays battery temperature and fan status

---

## SOC Calculation

The project estimates the battery State of Charge using the Coulomb Counting method:

**SOC Change (%) = (Current × Time ÷ Battery Capacity) × 100**

---

## Build Instructions

Compile the project using:

Compile:
gcc src/main.c src/battery.c src/soc.c src/soh.c src/thermal.c -Iinclude -o build/bms.exe

Run in powershell:
.\build\bms.exe


---

## Run the Program

### Windows PowerShell

```powershell
.\build\bms.exe
```

### Windows Command Prompt

```cmd
build\bms.exe
```

---

## Sample Output

```text
=========================================
          BATTERY STATUS
=========================================
Voltage        : 400.00 V
Current        : 10.00 A
SOC            : 80.00 %
SOH            : 99.95 %
Charge Cycles  : 1
Temperature    : 26.10 °C
Cooling Fan    : OFF
Capacity       : 50.00 Ah
=========================================
```

---

## Learning Outcomes

* Battery Management System (BMS) Fundamentals
* Electric Vehicle Battery Monitoring
* State of Charge (SOC) Estimation
* State of Health (SOH) Estimation
* Thermal Management Concepts
* Modular Embedded C Programming
* Console-Based Simulation Development

---

## Future Enhancements

* Fault Detection
* Active and Passive Cell Balancing
* State of Power (SOP) Estimation
* State of Function (SOF) Estimation
* CAN Bus Communication
* Battery Pack Simulation
* Data Logging
* Graphical Dashboard
* STM32/Arduino Integration

---

## Author

**Neha**

Electronics and Telecommunication Engineering Student


