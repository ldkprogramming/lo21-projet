//
// Gere par Jules: Definition de la classe PlateauJetons
//

#ifndef LO21_PROJET_PLATEAUJETONS_H
#define LO21_PROJET_PLATEAUJETONS_H

#include "Jeton.h"

class PlateauJetons {

    Jeton** jetons;
    int nb_jetons = 0;

public:
    PlateauJetons();
    void affichePlateauJetons();

    void addJeton(const Jeton& liste_jetons);
    Jeton& removeJeton(int i, int j);
    //Jeton* distribue();

    // getters
    Jeton** getJetons() const { return jetons; }
    int getNbJetons() const { return nb_jetons; }
};


#endif //LO21_PROJET_PLATEAUJETONS_H