//
// Created by Leo on 03/11/2023.
//

#ifndef LO21_PROJET_CARTE_H
#define LO21_PROJET_CARTE_H

#include "splendor.h"

namespace Splendor{
        enum class Capacite {Rejoue, Bonus, PrendJeton, PrendPrivilege, VolJeton, Null};
        string toString(Capacite c); //surcharge toString pour affichage d'une capacité
        ostream& operator<<(ostream& f, Capacite c);
        Capacite toCapacite(string c);
        
        enum class Tas {un, deux, trois, royal};
        string toString(Tas t); //surcharge toString pour affichage d'un tas
        ostream& operator<<(ostream& f, Tas t);
        
        class Carte {
        private:
                const Tas niveau;
                const int nb_points;
                const int nb_couronnes;
                int* prix; // dans l'ordre, coût en : Blanc / Bleu / Noir / Or / Perle / Rouge / Vert
                int* bonus; // Pareil, ordre alphabétique
                const Capacite capacite;
                const Capacite capacite2;
            public:
                Carte& operator=(const Carte& c) = delete; //on ne veut pas de recopie de carte
                Carte(const Carte& c) = delete; //Le jeu de carte reste identique du début à la fin
        
                Carte(Tas t, int nb_p, int nb_c, int* p, int* b, Capacite capa, Capacite capa2);
        
                //Destruceur
                ~Carte(){delete [] prix; delete [] bonus;}
        
                //getter
                const Tas getNiveau() const {return niveau;}
                const int getNbPoints() const {return nb_points;}
                const int getNbCouronnes() const {return nb_couronnes;}
                const int* getPrix() const {return prix;}
                const int* getBonus() const {return bonus;}
                const Capacite getCapacite() const {return capacite;}
                const Capacite getCapacite2() const {return capacite2;}
        };
        
        ostream& operator<<(ostream& f, Carte& c);
}

#endif //LO21_PROJET_CARTE_H
