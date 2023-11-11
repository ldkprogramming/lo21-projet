//
// Gere par Jules: Corps de la classe PlateauJetons
//

#include "PlateauJetons.h"
#include <string>

PlateauJetons::PlateauJetons(){
    // Constructeur a changer (voir compte-rendu)
    jetons = new Jeton*[25];
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

void PlateauJetons::affichePlateauJetons(){
    std::cout << " Plateau Jetons:" << std::endl << " ";
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::string s = "";
            if (jetons[i * 5 + j] == nullptr) s = "."; // Case vide
            else {
                switch ((*jetons[i * 5 + j]).getCouleur()) {
                    case Couleur::Blanc: s = "W"; break; //White pour differencier de Bleu
                    case Couleur::Bleu: s = "B"; break;
                    case Couleur::Noir: s = "N"; break;
                    case Couleur::Or: s = "O"; break;
                    case Couleur::Perle: s = "P"; break;
                    case Couleur::Rouge: s = "R"; break;
                    case Couleur::Vert: s = "V"; break;
                }
            }
            std::cout << s << " ";
        }
        std::cout << std::endl << " ";
    }
}

void PlateauJetons::addJeton(const Jeton& j){
    // S'il reste de la place, on ajoute le jeton, sinon erreur
    // Ajout du Jeton dans plateauspirale a implementer!!
    if (nb_jetons < 25) {
        jetons[nb_jetons] = new Jeton(j);
        nb_jetons++;
    }
    else throw std::overflow_error("Le plateau est deja rempli");
}

Jeton& PlateauJetons::removeJeton(int i, int j){
    // Ajouter une erreur si on choisi une case vide
    // Ajouter l'implementation avec plateauspirale
    if (i<0 || i>4 || j<0 || j>4) throw std::overflow_error("Ce n'est pas une coordonnee valide sur le Plateau Jetons");
    Jeton& jeton = *jetons[i * 5 + j];
    jetons[i * 5 + j] = nullptr;
    return jeton;
}
