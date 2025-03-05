# Embedded System Timer Interrupt

This project demonstrates how to configure a timer on an ARM Cortex-M microcontroller to generate an interrupt every 1 millisecond. The interrupt toggles an LED connected to GPIO Pin 5 of Port C.

## Requirements
- Keil uVision IDE
- STM32F10x microcontroller (or any ARM Cortex-M series microcontroller)
- STM32F10x Standard Peripheral Library (or equivalent)

## Folder Structure
- `Inc/`: Header files
- `Src/`: Source files
- `Startup/`: Startup files
- `Keil_Project/`: Keil project files

## Steps to Build and Run
1. Open the Keil project (`Keil_Project/project.uvprojx`).
2. Add `main.c` and the startup file to the project.
3. Configure the project settings (e.g., target microcontroller, clock frequency).
4. Build the project.
5. Flash the program to the microcontroller.
6. Observe the LED toggling every 1 millisecond.

## Code Explanation
- The timer is configured to generate an interrupt every 1 millisecond using a prescaler and reload value.
- The interrupt service routine (ISR) toggles the LED.
- The global interrupt and timer interrupt are enabled.
