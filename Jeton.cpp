//
// Created by Leo on 03/11/2023.
//

#include "Jeton.h"
#include <iostream>

std::string toString(Couleur c) {
    switch (c) {
        case Couleur::Vert: return "Vert";
        case Couleur::Bleu: return "Bleu";
        case Couleur::Rouge: return "Rouge";
        case Couleur::Blanc: return "Blanc";
        case Couleur::Noir: return "Noir";
        case Couleur::Or: return "Or";
        case Couleur::Perle: return "Perle";
        default: throw std::invalid_argument("Couleur inconnue");
    }
}

std::ostream& operator<<(std::ostream& f, Couleur c) { f << toString(c); return f; }
std::ostream& operator<<(std::ostream& f, Jeton j) { f << "Jeton " << j.getCouleur(); return f; }