// Fonctions C exportées vers le code Ada

#include <Arduino.h>

void blink(uint32_t n)
{
    for (int i = 0; i < n; i++)
    {
        digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
        delay(100);                      // wait for a second
        digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
        delay(100);
    }
}

void delai(uint32_t ms)
{
    delay(ms);
}