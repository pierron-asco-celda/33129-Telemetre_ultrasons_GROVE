/*
    ** Mesure ultrason (2 à plus de 350 cm) module Grove **
    ** Affichage mesure sur afficheur GROVE I2C **
       PIN 7 Module shield GROVE ultrason
       PIN I2C Module shield GROVE afficheur 
       Utilisation bibliothèque Ultrasonic.h & rgb_lcd.h
*/

#include <Wire.h>
#include "rgb_lcd.h"
#include "Ultrasonic.h"
rgb_lcd lcd;
long lDis = 0;

Ultrasonic ultrasonic(7);
void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("PIERRON");
  delay(1000);
  lcd.setCursor(2, 0);
  lcd.print("Telemetre a ");
  lcd.setCursor(3, 1);
  lcd.print("ultrasons");
  delay(1500);
  lcd.clear();
}
void loop()
{
  long RangeInCentimeters;
  RangeInCentimeters = ultrasonic.MeasureInCentimeters();
  lDis = RangeInCentimeters;

  lcd.setCursor(0, 0);
  lcd.print("Distance : ");
  lcd.print(lDis);
  lcd.print("cm");

  if ((lDis > 350) || (lDis < 2 )) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("~ERREUR MESURE !");
    lcd.setCursor(3, 1);
    lcd.print("2cm a 3.5m");
  }

  delay(250);
  lcd.clear();

}
