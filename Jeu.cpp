//
// Created by Leo on 03/11/2023.
//

#include "Jeu.h"
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