#ifndef LO21_PROJET_PLATEAUCARTES_H
#define LO21_PROJET_PLATEAUCARTES_H

#include "splendor.h"


namespace Splendor{

    class PlateauCartes{
    private:
        //Tableaux de pointeurs de Cartes
        Carte** cartes_niv_un; // 5 cartes
        Carte** cartes_niv_deux; // 4 cartes
        Carte** cartes_niv_trois; // 3 cartes
        Carte** cartes_royales; // 4 cartes
        const int nb_max_un; //Nombre de cartes maximum par niveau de rangée
        const int nb_max_deux;
        const int nb_max_trois;
        const int nb_max_royale;
        int nb_cartes_un; //Nombre de cartes actuellement par niveau de rangée
        int nb_cartes_deux;
        int nb_cartes_trois;
        int nb_cartes_royales;
    public:
        PlateauCartes(const PlateauCartes& PC) = delete;
        PlateauCartes& operator=(const PlateauCartes& PC) = delete;

        PlateauCartes():cartes_niv_un(new Carte*[5]), cartes_niv_deux(new Carte*[4]), cartes_niv_trois(new Carte*[3]),
                        cartes_royales(new Carte*[4]), nb_max_un(5), nb_max_deux(4), nb_max_trois(3),
                        nb_max_royale(4), nb_cartes_un(0), nb_cartes_deux(0), nb_cartes_trois(0),
                        nb_cartes_royales(0){};
        ~PlateauCartes();

        void RemplirPlateauInit(Pioche* Nv1, Pioche* Nv2, Pioche* Nv3, Pioche* NvR); //Pioches passées en paramètre
        Carte* RemplaceCarte(Carte* carte_out, Carte* carte_in); //Remplace une carte du plateau par une de la rangée
        void AfficherPlateau(); //Affichage primaire du plateau

        //getter
        Carte** getCartesUn(){return cartes_niv_un;}
        Carte** getCartesDeux(){return cartes_niv_deux;}
        Carte** getCartesTrois(){return cartes_niv_trois;}
        Carte** getCartesRoyales(){return cartes_royales;}
        int getNbUn(){return nb_cartes_un;}
        int getNbDeux(){return nb_cartes_un;}
        int getNbTrois(){return nb_cartes_un;}
        int getNbRoyales(){return nb_cartes_royales;}

    };
}

#endif //LO21_PROJET_PLATEAUCARTES_H
