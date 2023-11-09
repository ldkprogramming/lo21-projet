#ifndef LO21_PROJET_SPLENDOR_H
#define LO21_PROJET_SPLENDOR_H
#pragma once

#include <iostream>
#include <string>

// Pour l'aléatoire
#include <stdlib.h>
#include <time.h>

// Pour récuperer les cartes depuis la Base de données
#include "sqlite3.h"

// Pour que les différentes classes puissent communiquer entre elles 
#include "carte.h"
#include "controlleur.h"
#include "IA.h"
#include "Jeton.h"
#include "Jeu.h"
#include "Joueur.h"
#include "Pioche.h"
#include "PlateauJetons.h"
#include "Privilege.h"
#include "sac.h"

using namespace std;



namespace Splendor {

    // Classe pour gérer les exceptions
    class SetException {
    public:
        SetException(const string& i) :info(i) {}
        string getInfo() const { return info; }
    private:
        string info;
    };
}

#endif //LO21_PROJET_SPLENDOR_H
