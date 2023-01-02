#include <Arduino.h>

void read_ph(int pin)
{
    uint16_t val = analogRead(pin);
    Serial.println(val);
}

void read_ph_avg(int pin)
{
    float val = 0;
    for (uint32_t i = 0; i < 1000; i++)
    {
        val += analogRead(pin);
        delay(10);
    }
    val = val / 1000.0;
    Serial.println(val);
}

void ph_voltage(int pin)
{
    uint16_t val = analogRead(pin);
    float voltage = (val / 1023.0) * 5.0;
    Serial.println(voltage);
}