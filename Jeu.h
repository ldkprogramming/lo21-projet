//
// Created by Leo on 03/11/2023.
//
// Hamza


#ifndef LO21_PROJET_JEU_H
#define LO21_PROJET_JEU_H

#include "Sac.h"
#include "Pioche.h"
#include "Jeu.h"
#include "PlateauJetons.h"
#include "PlateauCartes.h"
#include "Privilege.h"
#include "splendor.h"
#include "sqlite3.c"


class Jeu {
private:
    /*
     * On utilise un pattern Singleton, implemente avec un struct internet Handler
     *
     *
     * */
    Jeu();
    ~Jeu();

    struct Handler {
        Jeu* instance;
        Handler() : instance(nullptr){};
        ~Handler() {
            delete instance;
        }
    };
    static Handler handler;

     sac = Sac();
    plateaujetons=PlateauJetons()
    // PlateauCartes
    Pioche pioche = Pioche();


public:


    static Jeu& getInstance();
    static void libererInstance();
    Jeu(const Jeu& j) = delete;
    Jeu& operator=(const Jeu& j) = delete;



};

Joueur& definir_premier_joueur(Joueur& un, Joueur& deux);


#endif //LO21_PROJET_JEU_H


