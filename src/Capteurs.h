#ifndef CAPTEURS_INCLUDED
#define CAPTEURS_INCLUDED

#ifndef ARDUINO_INCLUDED
#define ARDUINO_INCLUDED

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
#endif