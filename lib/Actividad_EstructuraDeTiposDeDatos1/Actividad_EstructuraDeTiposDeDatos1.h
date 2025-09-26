#ifndef ACTIVIDAD_ESTRUCTURADETIPOSDEDATOS1_H
#define ACTIVIDAD_ESTRUCTURADETIPOSDEDATOS1_H
#include <stdbool.h>
void pinMode(int pin, bool inOut); //inOut = true: INPUT, inOut = false: OUTPUT
void digitalWrite(int pin, bool estado); //true: HIGH, false: LOW
bool digitalRead(int pin);
#endif