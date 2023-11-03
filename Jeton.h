//
// Created by Leo on 03/11/2023.
//

#ifndef LO21_PROJET_JETON_H
#define LO21_PROJET_JETON_H

#include <iostream>

enum class Couleur {Vert, Bleu, Rouge, Blanc, Noir, Or, Perle};
    std::string toString(Couleur c);
    std::ostream& operator<<(std::ostream& f, Couleur c);

class Jeton {
    Couleur couleur;
public:
    Jeton() { couleur = Couleur::Vert; } // Obligatoire pour la cr�ation de liste de Jetons
    Jeton(Couleur c) : couleur(c) {}
    Jeton& operator=(const Jeton& j) { couleur = j.couleur; return *this; } // Pas encore utilis�
    // getter
    Couleur getCouleur() const { return couleur; }
};

std::ostream& operator<<(std::ostream& f, Jeton j);

#endif //LO21_PROJET_JETON_H
