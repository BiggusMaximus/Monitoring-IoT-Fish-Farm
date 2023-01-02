#include "ph.h"

#define pH A0
#define test A1

void setup()
{
    Serial.begin(9600);
    pinMode(pH, INPUT);
}

void loop()
{
    ph_voltage(read_ph_analog_avg(pH, 10.0));
}