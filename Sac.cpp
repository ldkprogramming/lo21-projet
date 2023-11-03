//
// Created by Leo on 03/11/2023.
//

#include "Sac.h"
#include <iostream>

Sac::Sac() {
    jetons = nullptr;
    for (int i = 0; i < 25; i++) {
        if (i < 4) addJeton(Couleur::Vert);
        else if (i < 8) addJeton(Couleur::Bleu);
        else if (i < 12) addJeton(Couleur::Rouge);
        else if (i < 16) addJeton(Couleur::Blanc);
        else if (i < 20) addJeton(Couleur::Noir);
        else if (i < 23) addJeton(Couleur::Or);
        else  addJeton(Couleur::Perle);
    }
}

void Sac::afficheSac() {
    if (nb_jetons == 0) std::cout << "Sac Vide!" << std::endl;
    else {
        std::cout << "Contenu du Sac:" << std::endl;
        for (int i = 0; i < nb_jetons; i++) {
            std::cout << jetons[i] << std::endl;
        }
    }
}

void Sac::addJeton(const Jeton& j) {
    if (jetons == nullptr) {
        jetons = new Jeton[25];
        nb_jetons = 0;
    }
    if (nb_jetons < 25) {
        jetons[nb_jetons] = j;
        nb_jetons++;
    }
    else throw std::overflow_error("Le sac est d�j� rempli");
}


Jeton* Sac::distribue() {
    // Seed al�atoire pour un r�sultat toujours diff�rent
    srand(time(NULL));
    std::cout << "Jetons distribu�s:" << std::endl;
    Jeton* liste_jetons = new Jeton[nb_jetons]; // Liste des jetons m�lang�s
    int i = 0;
    while (nb_jetons > 0) {
        int indice_jeton = rand() % nb_jetons;
        liste_jetons[i] = jetons[indice_jeton];	// On prend un jeton al�atoire
        std::cout << liste_jetons[i] << std::endl;
        for (int j = indice_jeton; j < nb_jetons - 1; j++) {
            jetons[j] = jetons[j + 1];	// On d�cale tous les autres jetons
        }
        nb_jetons--;
        i++;
    }
    delete[] jetons;
    jetons = nullptr;
    nb_jetons = 0;
    return liste_jetons;
}