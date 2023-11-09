//
// Ce fichier source permet de gérer toutes les classes ayant un rapport avec les cartes
// - Carte ; PlateauCartes ; Pioche
//

#include "Carte.h"

namespace Splendor {
    //on initialiase les variables Pioche (définies comme globales dans "splendor.h")
    Pioche p1(Tas::un);
    Pioche p2(Tas::deux);
    Pioche p3(Tas::trois);
    Pioche pR(Tas::royal);
    Pioche* Pioches[4] = {&p1,&p2,&p3,&pR};
    int compteur = 0;

    //------------------------------------------------------------------------------------------------------------------

    //Constructeur de Carte --> la mémoire pours les prix et les bonus
    Carte::Carte(Tas t, int nb_p, int nb_c, int* p, int* b, Capacite capa, Capacite capa2):niveau(t), nb_points(nb_p),
                                                                                           nb_couronnes(nb_c),capacite(capa),
                                                                                           prix(nullptr), bonus(nullptr),
                                                                                           capacite2(capa2){
        prix = new int[7];
        bonus = new int[7];

        for (int i=0; i<7; i++){
            prix[i] = p[i];
            bonus[i] = b[i];
        }
    }

    string toString(Capacite c) {
            switch (c) {
                case Capacite::Rejoue:
                    return "Rejouer";
                case Capacite::Bonus:
                    return "Bonus";
                case Capacite::PrendJeton:
                    return "Prendre Jeton";
                case Capacite::PrendPrivilege:
                    return "Prendre Privilege";
                case Capacite::VolJeton:
                    return "Voler Jeton";
                case Capacite::Null:
                    return "Pas de capacite";
                default:
                    throw SetException("Capacite inconnue");
            }
        }
        std::ostream& operator<<(std::ostream& f, Capacite c) { f << toString(c); return f; }
    
        string toString(Tas t) {
            switch (t) {
                case Tas::un:
                    return "un";
                case Tas::deux:
                    return "deux";
                case Tas::trois:
                    return "trois";
                case Tas::royal:
                    return "royal";
                default:
                    throw SetException("Tas inconnu");
            }
        }
        std::ostream& operator<<(std::ostream& f, Tas t) { f << toString(t); return f; }
    
        std::ostream& operator<<(std::ostream& f, Carte& c){
            const int* p = c.getPrix();
            const int* b = c.getBonus();
            f<< "Proprietes de la Carte \n"
             << "Niveau : " << c.getNiveau()
             << "\nPoint(s) de Prestige : "<< c.getNbPoints()
             << "\nNombre de Couronnes : "<<c.getNbCouronnes()
             << "\nCapacite 1 : "<<c.getCapacite()
             << "\nCapacite 2 : "<<c.getCapacite2()
             << "\nPrix :"
             << "\nBlanc : "<<p[0]<<" / Bleu : "<<p[1]<<" / Noir : "<<p[2]<<" / Or : "<<p[3]<<" / Perle : "<<p[4]<<" / Rouge : "<<p[5]<<" / Vert : "<<p[6]
    
             << "\nBonus : "
             << "\nBlanc : "<<b[0]<<" / Bleu : "<<b[1]<<" / Noir : "<<b[2]<<" / Or : "<<b[3]<<" / Perle : "<<b[4]<<" / Rouge : "<<b[5]<<" / Vert : "<<b[6]
             <<endl;
    
            return f;
    }

}
