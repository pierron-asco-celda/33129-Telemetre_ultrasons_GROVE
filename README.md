# 33129-Télémètre ultrasons GROVE

Télémètre ultrasons GROVE [33129](https://www.pierron.fr/interface-arduino-uno-5968.html)

<div style="text-align: justify">Module télémètre compatible Grove permettant de mesurer une distance, sans contact, à l'aide de transducteurs à ultrasons. Ce module se raccorde sur une entrée analogique de la Base Shield via un câble 4 conducteur.</div>

Caractéristiques techniques :
- Alimentation 3,3 à 5 V
- Consommation : 8 mA
- Fréquence : 40 kHz
- Portée de détection : 2 cm à 3,5 m
- Résolution : 1 cm

![L-33129](/img/L-33129.jpg)

# Installation des fichiers dans IDE Arduino:
<div style="text-align: justify">Créer un nouveau répertoire nommé "Pierron..." dans le dossier "libraries" de votre dossier Arduino.
Y placer tous les fichiers.</div>
Ou
<div style="text-align: justify">télécharger le dépôt en ZIP et dans l'IDE Arduino : Croquis / inclure bibliothèque / ajouter la bibliothèque ZIP.</div>

<div style="text-align: justify">Pour utiliser la librairie dans votre propre projet, importez-la avec  Sketch > Import Library.</div>

# Usage :
Pour l’utilisation de ce module référez-vous aux indications présentes sur le circuit imprimé GROVE.

# Schéma :

![SCH-33129](/img/SCH-33129.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [NU40C16T-R-1](https://github.com/pierron-asco-celda/33129-Telemetre_ultrasons_GROVE/blob/main/src/Datasheet_NU40C16T-R-1.pdf)

# Exemples :
### Arduino / C++
```cpp
/*
    ** Mesure ultrason (2 à plus de 350 cm) module Grove **
       PIN 7 Module shield GROVE
       Moniteur série -> Baud rate 9600.*
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
    long RangeInCentimeters;
 
    Serial.println("Distance : "); 
    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); 
    Serial.print(RangeInCentimeters);
    Serial.println(" cm");
    delay(250);
}
```
### Arduino / C++
<br>

Afficheur I2C GROVE [33103](https://www.pierron.fr/interface-arduino-uno-5944.html)

![L-33103](/img/L-33103.jpg)

```cpp
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
```
![C-33103+33129](/img/C-33103+33129.jpg)

## À propos :
<div style="text-align: justify">*Le débit en bauds est un taux de transfert de données en unités de bits par seconde (bps). Si le débit en bauds est de 9600, cela signifie que la possibilité d’envoyer des données est de 9600 bits en une seconde. 1 caractère est identique à 1 octet.</div>
<br>
PIERRON ASCO-CELDA (https://www.pierron.fr).
