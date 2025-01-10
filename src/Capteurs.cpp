#ifndef Capteurs_h
#include "Capteurs.h"
#endif


Capteurs::Capteurs(int transmetteur)
  {
      this->_TransmetteurPin = transmetteur ;
      pinMode(this->_TransmetteurPin, INPUT);
  }

  // Modifie les paramètres du Capteur
  void Capteurs::SetParametre(float tensionMin, float tensionMax, float plageCapteurMin, float plageCapteurMax)
  {
    this->_TensionMin = tensionMin ;
    this->_TensionMax = tensionMax ; 
    this->_PlageCapteurMin = plageCapteurMin ; 
    this->_PlageCapteurMax = plageCapteurMax ;
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
    float result = (analogRead(this->_TransmetteurPin) / this->_TENSION_DE_REF_ADC )* this->_TensionDeRef ;
    // Retourne la valeur du Capteurs.
    result = ((result-this->_TensionMin) * (this->_PlageCapteurMax - this->_PlageCapteurMin ) / (this->_TensionMax - this->_TensionMin)) ;
    return max(min(result, this->_PlageCapteurMax), this->_PlageCapteurMin);
  }


  float Capteurs::Pourcentage()
  {
    return ( (Value() * 100) / this->_PlageCapteurMax);
  }


  float Capteurs::PourcentageInverse()
  {
    return ( 100 - Pourcentage() );
  }