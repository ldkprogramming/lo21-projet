//
// Created by Leo on 03/11/2023.
//

#ifndef LO21_PROJET_JOUEUR_H
#define LO21_PROJET_JOUEUR_H

#include "Carte.h"
#include "Jeton.h"
#include <string>
#include <vector>
#include <memory>


/*
0 : Blanc
1 : Bleu
2 : Noir
3 : Or
4 : Perle
5 : Rouge
6 : Vert
 */

class Joueur {
private:

    std::vector<Carte*> main;
    std::vector<Carte*> cartesReservees;
    std::vector<Jeton*> jetons;

    int privileges = 0;
    int pointsCouronnes = 0;
    int maxPointsUneCouleur = 0;

    int jetonsParCouleur[7] = {0, 0, 0, 0, 0, 0, 0};
    int bonusParCouleur[7] = {0, 0, 0, 0, 0, 0, 0};

public:
    void updateMaxPointsUneCouleur();

    inline int getPrivileges() const {
        return privileges;
    }

    inline int getPointsCouronnes() const {
        return pointsCouronnes;
    }

    inline int getMaxPointsUneCouleur() const {
        return maxPointsUneCouleur;
    }

    void ajouterJeton(Jeton* jeton);
    void ajouterCarte(Carte* carte);
    void ajouterCarteReservee(Carte* carte);
};


#endif //LO21_PROJET_JOUEUR_H
