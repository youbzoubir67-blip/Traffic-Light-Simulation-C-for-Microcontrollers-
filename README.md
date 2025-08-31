# Traffic Light Simulation (Arduino)

A basic traffic light controller using **Arduino** and three LEDs (Red/Yellow/Green).
Demonstrates a simple finite state machine (FSM) and non-blocking timing with `millis()`.

## Hardware
- Arduino Uno/Nano
- 3x LEDs (Red, Yellow, Green)
- 3x 220Ω resistors

**Wiring (Arduino Uno):**
- Red LED → D8 (through 220Ω to GND)
- Yellow LED → D9 (through 220Ω to GND)
- Green LED → D10 (through 220Ω to GND)

## Build
- Open `src/traffic_light.ino` in Arduino IDE
- Select your board/port and upload

## License
MIT
