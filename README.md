# GravityTDSAnalog

This is an modified version of the original GravityTDS Library https://github.com/DFRobot/GravityTDS

This modified version is used for external analog to digital converter which the normal Library didn't support.

This modified version rather than using internal ADC Command (Commonly used on Arduino Uno Library) which limited how many and what
pin to use. The modified version is to simplified the Library by just inputing the voltage in float val rather than get and process it
automaticly by the library. This is to ensured that the library is compatible with all version of Arduino and ESP8266/ESP32 or an external
ADC like the Adafruit ADS1115 16 Bit ADC which has more resolution than the commonly 8 to 12 bit ADC inside the microcontroller
