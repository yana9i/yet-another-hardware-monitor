# Yet Another Hardware Monitor 

## Introduction
This repository contains the code for an Arduino-based driver that allows an I2C LCD display to interface with [LCDSmartie](https://github.com/LCD-Smartie/LCDSmartie).

## Features
- Compatibility with I2C LCD displays.
- Interface with LCDSmartie -> Matrix Orbital Display DLL.

## Hardware Requirements
- Arduino board.
- I2C LCD display.
- Breadboard and jumper wires for connections.

## Software Requirements
- Arduino IDE for uploading the code to the Arduino board.
- LiquidCrystal_I2C library allows to control I2C displays.
- LCDSmartie software installed on your computer.

## Installation and Configuration
1. Ensure the Arduino board is correctly connected to the I2C LCD screen and the computer.
2. Fill in your LCD_LINES, LCD_COLUMNS and I2C_ADDR in the macro definition, then compile and install the source code onto the Arduino board using the Arduino IDE.
3. Install LCDSmartie and select matrix.dll in the Display Plugin section.
4. Enter the correct COM port number in the Startup Parameters.
