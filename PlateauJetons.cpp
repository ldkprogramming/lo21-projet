//
// Gere par Jules: Corps de la classe PlateauJetons
//

#include "PlateauJetons.h"

//PlateauJetons::PlateauJetons(){
//}

void PlateauJetons::affichePlateauJetons(){
    std::cout << "Plateau Jetons:" << std::endl;
    
    for (int i = 0; i < nb_jetons; i++) {
        std::cout << jetons[i] << std::endl;
    }
}

//void PlateauJetons::addJetons(const Jeton* liste_jetons){
//}
