## Buzzer Library for Arduino - ezBuzzer
This library is designed for a buzzer to beep or play melody without blocking other code.

**ezBuzzer** stands for **easy buzzer**, which means that the library is easy to use.

Features
----------------------------
* Supports both active and passive buzzers
* Supports active HIGH and active LOW buzzers
* Supports beep with customizable frequency
* Supports melody playback
* Supports manual ON/OFF control
* All functions are non-blocking (no delay() function)
* Cross-platform compatible (all Arduino architectures)


Available Examples
----------------------------
* [Beep](https://arduinogetstarted.com/library/arduino-beep-example)
* [Melody](https://arduinogetstarted.com/library/arduino-melody-example)
* [MelodyRepeat](https://arduinogetstarted.com/library/arduino-melody-repeat-example)

Available Functions
----------------------------
* ezBuzzer(pin, buzzerType, activeLevel) - Constructor with buzzer type and active level
* stop() - Stop buzzer and cancel any ongoing beep/melody
* turnON() - Turn buzzer ON continuously
* turnOFF() - Turn buzzer OFF (same as stop)
* beep(time) - Beep for specified duration
* beep(time, delay) - Beep with delay before starting
* beep(time, delay, frequency) - Beep with custom frequency (passive buzzer)
* playMelody(melody, durations, length) - Play a melody
* setBuzzerType(type) - Set BUZZER_TYPE_ACTIVE or BUZZER_TYPE_PASSIVE
* setBeepFrequency(frequency) - Set default beep frequency for passive buzzer
* getState() - Get current buzzer state
* loop() - Must be called in loop() for non-blocking operation

Buzzer Types
----------------------------
* **BUZZER_TYPE_ACTIVE** - Active buzzer (has internal oscillator, uses digitalWrite)
* **BUZZER_TYPE_PASSIVE** - Passive buzzer (requires PWM signal, uses tone())

Active Levels
----------------------------
* **HIGH** - Buzzer sounds when pin is HIGH (default, most common)
* **LOW** - Buzzer sounds when pin is LOW (some shields like Multi-Function Shield)


Tested Hardware
----------------------------
**Buzzer Modules:**
* [3V-24V Active Piezoelectric Buzzer](https://diyables.io/products/12v-3-24v-active-piezoelectric-buzzer)
* [Active Piezo Buzzer Module](https://diyables.io/products/piezo-buzzer-module-active-buzzer)
* [Passive Piezo Buzzer Module](https://diyables.io/products/passive-buzzer-module)
* [Multi-Function Shield for Arduino](https://diyables.io/products/multi-function-shield-for-arduino-uno-mega) - Built-in active LOW buzzer

**MCU Boards:**

| Board | Tested | Notes |
|-------|--------|-------|
| Arduino Uno R3 | ✅ | Fully supported |
| Arduino Uno R4 WiFi | ✅ | Fully supported |
| Arduino Uno R4 Minima | ✅ | Fully supported |
| Arduino Mega | ✅ | Fully supported |
| Arduino Giga | ✅ | Fully supported |
| [DIYables STEM V3 Board](https://diyables.io/products/diyables-stem-v3-fully-compatible-with-arduino-uno-r3) | ✅ | Fully supported |
| [DIYables STEM V4 IoT Board](https://diyables.io/products/diyables-stem-v4-iot-fully-compatible-with-arduino-uno-r4-wifi) | ✅ | Fully supported |
| [DIYables Compact V3.0 ATMEGA328P](https://diyables.io/products/diyables-compact-v3.0-atmega328p-development-board-compatible-with-arduino-nano-usb-mini) | ✅ | Fully supported |
| [DIYables ESP32](https://diyables.io/products/38-pin-esp32s-esp-wroom-32-wifi-and-bluetooth-development-board-with-usb-type-c-and-cp2102-dual-core-esp32-microcontroller-for-iot-projects-compatible-with-arduino-ide) | ✅ | Fully supported |
| [DIYables ESP8266](https://diyables.io/products/esp8266-nodemcu-wifi-development-board-with-usb-type-c-ch340-compatible-with-arduino-ide) | ✅ | Fully supported |


How To Install the Library
----------------------------
* [ezBuzzer Library Installation Guide](https://arduinogetstarted.com/tutorials/arduino-buzzer-library)

References
----------------------------
* [ezBuzzer Library Reference](https://arduinogetstarted.com/tutorials/arduino-buzzer-library)
