#if ARDUINO >= 100    
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif


class Capteurs 
{ 
    public: 
        Capteurs(int Transmetteur); // Initialise le capteur
        void SetParametre(float tensionMin, float tensionMax, float plageCapteurMin, float plageCapteurMax); // Paramétrage du Capteur
        float Value(); // Lecture en décimal du Capteur 
        float Pourcentage(); // Lecture en Pourcentage du Capteur 
        float PourcentageInverse(); // Lecture en Pourcentage inverse du Capteur 

    private: 
        const int _TENSION_DE_REF_ADC = 1023 ;
        int _TransmetteurPin; // Pin du capteur
        float _TensionMin = 0 ; // Tension minimum de sortie proportionnel au Capteur (équivalent au 0bar)
        float _TensionMax = 5.0 ; // Tension maximum de sortie proportionnel au Capteur (équivalent au 10bar)
        float _PlageCapteurMin = 0 ; // Valeur basse du transmetteur (par défaut capteur 0-10bar)
        float _PlageCapteurMax = 10 ; // Valeur haute du transmetteur (par défaut capteur 0-10bar)
        float _TensionDeRef = 5.0 ; // Tension Alimentation du capteur
};