#if ARDUINO >= 100    
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#ifndef Capteurs_INCLUDED
#define Capteurs_INCLUDED


class Capteurs 
{ 
    public: 
        Capteurs(int Transmetteur);
        float Value(); 
        void SetParametre(float tensionMin, float tensionMax, float plageCapteurMin, float plageCapteurMax);
        float Pourcentage();
        float PourcentageInverse();

    private: 
        int transmetteur;
        float TensionMin;
        float TensionMax;
        float PlageCapteurMin;
        float PlageCapteurMax;
};

#endif