//
// Gere par Jules: Corps de la classe Sac
//

#include "Sac.h"
#include <iostream>

Sac::Sac() {
    // Constructeur a changer (voir compte-rendu)
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
    // Fonction qui affiche le contenu du sac dans la console
    if (nb_jetons == 0) std::cout << "Sac Vide!" << std::endl; // Si le sac est vide, on n'affiche rien
    else {
        std::cout << "Contenu du Sac:" << std::endl;
        for (int i = 0; i < nb_jetons; i++) {
            std::cout << jetons[i] << std::endl;
        }
    }
}

void Sac::addJeton(const Jeton& j) {
    // a changer, j'aime pas trop l'idée qu'on puisse avoir un nullptr ou une liste de 25 jetons
    // il faudrait peut-etre passer a un attribut Jeton** comme pour PlateauJetons
    if (jetons == nullptr) { 
        jetons = new Jeton[25];
        nb_jetons = 0;
    }
    // S'il reste de la place, on ajoute le jeton, sinon erreur
    if (nb_jetons < 25) {
        jetons[nb_jetons] = j;
        nb_jetons++;
    }
    else throw std::overflow_error("Le sac est deja rempli");
}


Jeton* Sac::distribue() {
    std::cout << "Jetons distribues:" << std::endl;
    // Seed aleatoire pour un resultat toujours different
    srand(time(NULL));

    Jeton* liste_jetons = new Jeton[nb_jetons]; // Liste qui contiendra les jetons melanges
    
    int i = 0;
    while (nb_jetons > 0) {
        // On prend un jeton aleatoire
        int indice_jeton = rand() % nb_jetons;
        liste_jetons[i] = jetons[indice_jeton];
        std::cout << liste_jetons[i] << std::endl;

        // On decale tous les autres jetons
        for (int j = indice_jeton; j < nb_jetons - 1; j++) {
            jetons[j] = jetons[j + 1];	
        }

        nb_jetons--;
        i++;
    }

    // On supprime la liste initiale (on vide le sac)
    delete[] jetons;
    jetons = nullptr;
    nb_jetons = 0;
    return liste_jetons;
}