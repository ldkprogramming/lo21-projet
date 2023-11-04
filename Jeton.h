//
// Gere par Jules: Definition de la classe Jeton
//

#ifndef LO21_PROJET_JETON_H
#define LO21_PROJET_JETON_H

#include <iostream>

// Enumeration des couleurs, dans l'ordre alphabetique
enum class Couleur {Blanc, Bleu, Noir, Or, Perle, Rouge, Vert};
    std::string toString(Couleur c);
    std::ostream& operator<<(std::ostream& f, Couleur c);

class Jeton {
    Couleur couleur;
public:
    Jeton() { couleur = Couleur::Vert; } // Obligatoire pour la creation de liste de Jetons
    Jeton(Couleur c) : couleur(c) {}
    Jeton& operator=(const Jeton& j) { couleur = j.couleur; return *this; } // Pas encore utilise
    // getter
    Couleur getCouleur() const { return couleur; }
};

std::ostream& operator<<(std::ostream& f, Jeton j);

#endif //LO21_PROJET_JETON_H
