#ifndef Capteurs_h
#include "Capteurs.h"
#endif


int Transmetteur; // Pin du capteur
float TensionMin = 0 ; // Tension minimum de sortie proportionnel au Capteur (équivalent au 0bar)
float TensionMax = 5.0 ; // Tension maximum de sortie proportionnel au Capteur (équivalent au 10bar)
float PlageCapteurMin = 0 ; // Valeur basse du transmetteur (par défaut capteur 0-10bar)
float PlageCapteurMax = 10 ; // Valeur haute du transmetteur (par défaut capteur 0-10bar)

Capteurs::Capteurs(int transmetteur)
  {
      Transmetteur = transmetteur ;
      pinMode(Transmetteur, INPUT);
  }

  // Modifie les paramètres de calcul de la Capteurs
  void Capteurs::SetParametre(float tensionMin, float tensionMax, float plageCapteurMin, float plageCapteurMax)
  {
    TensionMin = tensionMin ;
    TensionMax = tensionMax ; 
    PlageCapteurMin = plageCapteurMin ; 
    PlageCapteurMax = plageCapteurMax ;
  }


  /**
   * Fonction de calcul de Capteurs
   * Formules : ((Tension mesuré - Tension Minimum) * Ecart de P°) / Ecart de Tension)
   * Parametres :
   * TensionMin : Tension minimum
   * TensionMax : Tension maximum
   * PlageCapteurMin : Plage Basse du capteur
   * PlageCapteurMax : Plage haute du capteur
   * Value : Mesure de l'entrée annalogique
   */
  float Capteurs::Value()
  {
    // Convertie la valeur analogique en Volt.
    float resultVolts = (analogRead(Transmetteur) / 1023.0 )* 5.0 ;
    
    // Returne la valeur du Capteurs.
    return ((resultVolts-TensionMin) * (PlageCapteurMax - PlageCapteurMin ) / (TensionMax - TensionMin)) ;
  }


  float Capteurs::Pourcentage()
  {
    return ( (Value() * 100) / PlageCapteurMax);
  }


  float Capteurs::PourcentageInverse()
  {
    return ( 100 - Pourcentage() );
  }