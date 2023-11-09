//
// Created by Leo on 03/11/2023.
//

#ifndef LO21_PROJET_PIOCHE_H
#define LO21_PROJET_PIOCHE_H

#include "splendor.h"

namespace Splendor{
    //Si une carte sort de la pioche, elle n'y revient pas
    class Pioche{
    private:
        Tas Niveau;
        int nb_cartes_restantes;
        int nb_cartes_max;
        Carte** Paquet;
    public:
        Pioche(const Pioche& p) = delete;
        Pioche& operator=(const Pioche& p) = delete;
    
        Pioche(Tas niveau); //crée une pioche sans la remplir
        ~Pioche();
        void ajoutCarte(Carte* c);
    
        Carte* TirerCarte(); // choisit une carte au hasard dans la pioche, la supprime de la pioche et la retourne
    
        void decremente();
    
        //getter
        Tas getNiveau(){return Niveau;}
        int getNbCartesRestantes(){return nb_cartes_restantes;}
        int getNbMax(){return nb_cartes_max;}
        Carte** getPaquet(){return Paquet;}
    };
    
    //Fonctions qui pourront normalement devenir des méthodes de la classe Jeu (par exemple)
    //Fonctions callback pour la récupération de données depuis la BDD
    int callbackNiv1(void* data, int argc, char* argv[], char* colName[]);
    int callbackNiv2(void* data, int argc, char* argv[], char* colName[]);
    int callbackNiv3(void* data, int argc, char* argv[], char* colName[]);
    int callbackNivRoyal(void* data, int argc, char* argv[], char* colName[]);
    Pioche** RemplirPioche(); //Remplit la pioche depuis la BDD
    void affichePioches(); // Affiche la Pioche
    
    //Initialisation des variables à une portée globale
    extern Pioche p1;
    extern Pioche p2;
    extern Pioche p3;
    extern Pioche pR;
    extern Pioche* Pioches[4];
}

#endif //LO21_PROJET_PIOCHE_H
