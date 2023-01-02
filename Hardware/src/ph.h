#include <Arduino.h>

void read_ph_analog(int pin)
{
    uint16_t val = analogRead(pin);
    Serial.println(val);
}

float read_ph_analog_avg(int pin, float sample)
{
    float val = 0;
    for (uint32_t i = 0; i < sample; i++)
    {
        val += analogRead(pin);
        delay(10);
    }
    val = val / sample;
    return val;
}

void ph_voltage(float val)
{
    for (uint32_t i = 0; i < 1000; i++)
    {
        float voltage = 23.190407296245567 - (0.031055233908592963 * val);
        Serial.println(voltage);
    }
}