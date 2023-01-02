#include "ph.h"

#define pH A0
#define test A1

void setup()
{
    Serial.begin(9600);
    pinMode(pH, INPUT);
    read_ph_avg(pH);
}

void loop()
{
}