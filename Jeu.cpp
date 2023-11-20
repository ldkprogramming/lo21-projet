//
// Created by Leo on 03/11/2023.
//

#include "Jeu.h"
#include <cstdlib>
Jeu::Handler Jeu::handler = Handler();


/* a definir plus en detail
Jeu& Jeu::getInstance() {
    if (handler.instance == nullptr) {
        handler.instance = new Jeu;
    }
    return *handler.instance;
}

void Jeu::libererInstance() {
    delete handler.instance;
    handler.instance = nullptr;
}
*/

Joueur& definir_premier_joueur(Joueur& un, Joueur& deux) {
    int random_nb = rand() % 2;
    if (random_nb == 0) { return un; }
    else { return deux; }
}
