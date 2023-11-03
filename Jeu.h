//
// Created by Leo on 03/11/2023.
//

#ifndef LO21_PROJET_JEU_H
#define LO21_PROJET_JEU_H

#include "Sac.h"
#include "Pioche.h"


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

    Sac sac = Sac();
    // PlateauJetons ...
    // PlateauCartes
    Pioche pioche = Pioche();


public:


    static Jeu& getInstance();
    static void libererInstance();
    Jeu(const Jeu& j) = delete;
    Jeu& operator=(const Jeu& j) = delete;



};


#endif //LO21_PROJET_JEU_H
