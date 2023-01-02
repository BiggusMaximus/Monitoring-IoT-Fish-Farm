#include "ph.h"

#define pH A0
#define test A1

void setup()
{
    Serial.begin(9600);
    pinMode(pH, INPUT);
    Serial.println("Start");
    for (uint32_t i = 0; i < 1000; i++)
    {
        ph_voltage(read_ph_analog_avg(pH, 1000));
    }
    Serial.println("End");
}

void loop()
{
}