#include <Arduino.h>
#include <Capteurs.h>

// DECLARATION DES PINS
const int PIN_SONDE_CONDUCTIVITE = A1;

// DECLARATION DES CONSTANTES
const int QUALITE_EAU_LIMITE = 75; // 0% => Eau extrement sale ; 100% => Eau de source ;

// INITIALISE LES OBJETS
Capteurs Conductivite(PIN_SONDE_CONDUCTIVITE);

void setup() {
  
  // Paramétrage des Capteurs
  Conductivite.SetParametre(0,2.3,0,1000);
 
  // Pour le Debug
  Serial.begin(9600);
}

void loop() {

  Serial.println(Conductivite.Value()); // Renvoie la valeur brute.
  Serial.println(Conductivite.PourcentageInverse()); // Renvoie la valeur en pourcentage (le minimum de la gamme vaut 0%).
  Serial.println(Conductivite.PourcentageInverse()); // Renvoie la valeur en pourcentage inversé (le minimum de la gamme vaut 100%).
 
  delay(1000);
   
}