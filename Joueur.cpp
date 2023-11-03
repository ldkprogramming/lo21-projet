//
// Created by Leo on 03/11/2023.
//

#include "Joueur.h"

/*
0 : Blanc
1 : Bleu
2 : Noir
3 : Or
4 : Perle
5 : Rouge
6 : Vert
 */

void Joueur::updateMaxPointsUneCouleur() {
    int max = 0;
    for (int i = 0; i < 7; i++){
        if (bonusParCouleur[i] + jetonsParCouleur[i] > max){
            max = bonusParCouleur[i] + jetonsParCouleur[i];
        }
    }
    maxPointsUneCouleur = max;
}


void Joueur::ajouterCarte(Carte *carte) {
    main.push_back(carte);

    /*
     * ajouter les bonus et tout
     */
}

void Joueur::ajouterJeton(Jeton *jeton) {
    jetons.push_back(jeton);
    switch (jeton->getCouleur()) {
        case Couleur::Blanc :
            jetonsParCouleur[0] += 1;
            break;
        case Couleur::Bleu :
            jetonsParCouleur[1] += 1;
            break;
        case Couleur::Noir :
            jetonsParCouleur[2] += 1;
            break;
        case Couleur::Or :
            jetonsParCouleur[3] += 1;
            break;
        case Couleur::Perle :
            jetonsParCouleur[4] += 1;
            break;
        case Couleur::Rouge :
            jetonsParCouleur[5] += 1;
            break;
        case Couleur::Vert :
            jetonsParCouleur[6] += 1;
            break;

    }
}
void Joueur::ajouterCarteReservee(Carte* carte) {
    cartesReservees.push_back(carte);
}
