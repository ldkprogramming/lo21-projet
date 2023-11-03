//
// Created by Leo on 03/11/2023.
//

#ifndef LO21_PROJET_SAC_H
#define LO21_PROJET_SAC_H

#include "Jeton.h"

class Sac {

    Jeton* jetons;
    int nb_jetons = 0;

public:
    Sac();
    void afficheSac();

    void addJeton(const Jeton& j);
    Jeton* distribue();

    // getters
    Jeton* getJetons() const { return jetons; }
    int getNbJetons() const { return nb_jetons; }
};


#endif //LO21_PROJET_SAC_H
