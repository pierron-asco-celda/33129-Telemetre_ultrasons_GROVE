/*
    ** Mesure ultrason (1 à 500 cm) module Grove **
       PIN 7 Module shield GROVE
       Moniteur série -> Baud rate 9600.
       Utilisation bibliothèque seed_arduino_ultrasonicranger-master 
*/


#include "Ultrasonic.h"
 
Ultrasonic ultrasonic(7);
void setup()
{
    Serial.begin(9600);
}
void loop()
{
    long RangeInInches;
    long RangeInCentimeters;
 
    Serial.println("Distance : "); 
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); 
    Serial.print(RangeInCentimeters);
    Serial.println(" cm");
    delay(250);
}
