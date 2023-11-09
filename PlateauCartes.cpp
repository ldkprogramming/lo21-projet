#include "PlateauCartes.h"

namespace Splendor{
    //Pour chaque niveau de Cartes du Plateau, on tire le nombre max (de cartes de la rangée) depuis la pioche
    //et on incrémente le nombre de cartes actuellement présentes sur le Plateau de Cartes
    void PlateauCartes::RemplirPlateauInit(Pioche* Nv1, Pioche* Nv2, Pioche* Nv3, Pioche* NvR){
        for(int i=0; i<nb_max_un; i++){
            cartes_niv_un[i] = Nv1->TirerCarte();
            nb_cartes_un++;
        }
        for(int i=0; i<nb_max_deux; i++){
            cartes_niv_deux[i] = Nv2->TirerCarte();
            nb_cartes_deux++;
        }
        for(int i=0; i<nb_max_trois; i++){
            cartes_niv_trois[i] = Nv3->TirerCarte();
            nb_cartes_trois++;
        }
        for(int i=0; i<nb_max_royale; i++){
            cartes_royales[i] = NvR->TirerCarte();
            nb_cartes_royales++;
        }
    }


    // on reçoit le pointeur sur la carte (présente sur le plateau) que le joueur choisit : carte_out
    // on reçoit également le pointeur sur la carte qui remplacera la carte choisie : carte_in
    // la carte remplacante "carte_in" devrait être tirée avec la méthode TirerCarte de la classe Pioche
    // la carte remplacé sera choisie par le joueur
    Carte* PlateauCartes::RemplaceCarte(Carte* carte_out, Carte* carte_in){
        Tas niv = carte_out->getNiveau();
        int nb_max;
        int nb_cartes;
        Carte** rangee;

        //on cherche de quel niveau est la carte choisie pour agir sur la rangée de cartes concernée
        switch(niv) {
            case Tas::un:
                rangee = cartes_niv_un;
                nb_cartes = nb_cartes_un;
                break;
            case Tas::deux:
                rangee = cartes_niv_deux;
                nb_cartes = nb_cartes_deux;
                break;
            case Tas::trois:
                rangee = cartes_niv_trois;
                nb_cartes = nb_cartes_trois;
                break;
            case Tas::royal:
                rangee = cartes_royales;
                nb_cartes = nb_cartes_royales;
                break;
            default:
                throw SetException("Tas inconnu");
        }

        //On parcourt la rangée concernée pour trouvée la carte choisie par le joueur
        int ind = -1;
        for (int i=0; i<nb_cartes; i++){
            if (rangee[i] == carte_out) ind=i;
        }

        //Si la carte n'est pas retrouvée, on lève une exception
        if (ind == -1) {
            throw SetException("Carte Introuvable");
        }

        Carte* out = rangee[ind]; //on récupère la carte choisie par le joueur
        if (carte_in == nullptr){ //si la pioche est vide, on réalise un décalage et on décrémente la taille de la rangée
            for (int j = ind; j<nb_cartes - 1; j++) rangee[j] = rangee[j+1];
            switch(niv) {
                case Tas::un:
                    nb_cartes_un --;
                    break;
                case Tas::deux:
                    nb_cartes_deux --;
                    break;
                case Tas::trois:
                    nb_cartes_trois --;
                    break;
                case Tas::royal:
                    nb_cartes_royales --;
                    break;
            }
        } else { // sinon on remplace simplement par une carte de la pioche
            rangee[ind] = carte_in;
        }
        return out;
    }

    //Affichage primaire du plateau de cartes
    void PlateauCartes::AfficherPlateau(){
        cout << "Cartes de Niveau 1 : \n" << endl;
        for (int i=0; i<nb_cartes_un; i++) cout << i+1 <<" - "<< *cartes_niv_un[i] <<endl;
        cout << "\nCartes de Niveau 2 : \n" << endl;
        for (int i=0; i<nb_cartes_deux; i++) cout << i+1 <<" - "<< *cartes_niv_deux[i] <<endl;
        cout << "\nCartes de Niveau 3 : \n" << endl;
        for (int i=0; i<nb_cartes_trois; i++) cout << i+1 <<" - "<< *cartes_niv_trois[i] <<endl;
        cout << "\nCartes de Niveau Royal : \n" << endl;
        for (int i=0; i<nb_cartes_royales; i++) cout << i+1 <<" - "<< *cartes_royales[i] <<endl;
    }

    PlateauCartes::~PlateauCartes(){
        for(int i=0; i<nb_cartes_un; i++) delete cartes_niv_un[i];
        for(int i=0; i<nb_cartes_deux; i++) delete cartes_niv_deux[i];
        for(int i=0; i<nb_cartes_trois; i++) delete cartes_niv_trois[i];
        for(int i=0; i<nb_cartes_royales; i++) delete cartes_royales[i];
        delete [] cartes_niv_un;
        delete [] cartes_niv_deux;
        delete [] cartes_niv_trois;
        delete [] cartes_royales;
    }
}
