# Capteurs
**Année :** 2022   
**Contributeur(s):** Moi-même   
**Version Actuel :** 0.0.1   
**Status :** Actif   
**Page GitHub:** https://github.com/boby15000/   

## Description
Librairie Arduino pour Capteurs Analogiques.
Suite à l'utilisation récurrent de différent capteurs (pression, conductivité...), j'ai conçu une librairie pour Arduino afin de faciliter la gestion de ces capteurs au sein de la programmation.

## Installation
Télécharger le ZIP est installé la avec Arduino `Croquis` - `Inclure une Bibliothéque` - `Ajouter la Bibliothéque ZIP`.

## Utilisation
```
// Initialise l'objet avec la PIN du capteurs.
Capteurs Conductivite(PIN_SONDE_CONDUCTIVITE);
// Configuration du capteur.
Conductivite.SetParametre(0,2.3,0,1000); 

// Renvoie la valeur brute.
Serial.println(Conductivite.Value());

// Renvoie la valeur en pourcentage (le minimum de la gamme vaut 0%).
Serial.println(Conductivite.PourcentageInverse());

// Renvoie la valeur en pourcentage inversé (le minimum de la gamme vaut 100%).
Serial.println(Conductivite.PourcentageInverse()); 
```

## Changelog
### v 0.0.1
- Initiale Release