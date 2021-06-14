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

Ressource utilisation : [NU40C16T-R-1](https://github.com/pierron-asco-celda/33132-Haut-parleur_Amplificateur_GROVE/blob/main/src/Datasheet_LM386.pdf)

# Exemple :
### Arduino / C++
```cpp
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
```
## À propos :

PIERRON ASCO-CELDA (https://www.pierron.fr).
