//
// Ce fichier source permet de gérer toutes les classes ayant un rapport avec les cartes
// - Carte ; PlateauCartes ; Pioche
//

#include "Carte.h"
#include "splendor.h"

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
    };

    //------------------------------------------------------------------------------------------------------------------

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

    //----------------------------------------------------------------------------------------------

    // Constructeur : allocation dynamique du Paquet de Carte et affectation de sa taille en fonction du tas passé en paramètre
    Pioche::Pioche(Tas niveau):Niveau(niveau),nb_cartes_restantes(0),nb_cartes_max(0),Paquet(nullptr){
        switch(Niveau) {
            case Tas::un:
                nb_cartes_max = 30;
                break;
            case Tas::deux:
                nb_cartes_max = 24;
                break;
            case Tas::trois:
                nb_cartes_max = 13;
                break;
            case Tas::royal:
                nb_cartes_max = 4;
                break;
            default:
                throw SetException("Tas inexistant");
        }
        Paquet = new Carte*[nb_cartes_max];
    }

    // Fonction qui ne sera peut-être pas utile
    void Pioche::decremente(){
        if(nb_cartes_restantes>0){
            nb_cartes_restantes--;
        }else{
            throw SetException("Paquet vide");
        }
    }

    //Tire une carte au hasard de la Pioche et décale les cartes suivantes tout en décrémentant la taille du paquet
    Carte* Pioche::TirerCarte(){
        if (nb_cartes_restantes == 0) return nullptr;

        int ind = rand() % nb_cartes_restantes;
        Carte* carteTiree = Paquet[ind]; //vérifier que la valeur récupérée est la bonne sinon passage par référence
        for (int i=ind; i<nb_cartes_restantes-1; i++){
            Paquet[i] = Paquet[i+1];
        }
        nb_cartes_restantes--;
        return carteTiree;
    }

    //ajoute une carte à la pioche si elle n'est pas déjà pleine; sinon, une exception est levée
    void Pioche::ajoutCarte(Carte* c){
        if(nb_cartes_restantes == nb_cartes_max) throw SetException("Pioche pleine");
        Paquet[nb_cartes_restantes] = c;
        nb_cartes_restantes++;
    }


    // si royale --> cas à part
    // sinon, juste on emprunte la table en question avec le raisonnement général...
    Pioche** RemplirPioche(){ //utiliser toString pour comparer et chaîne de caractère et ne pas faire 4 f° ?
        sqlite3* db;
        char* sql;
        char* msgErreur;
        int rc;
        Tas Niveau = Pioches[1]->getNiveau();

        //ouverture de la BDD
        //Aucune idée de pourquoi le chemin absolu est nécessaire
        rc = sqlite3_open("C:\\Users\\Tareq\\Desktop\\Tareq\\UTC\\GI01\\SplendorDuel\\cartes.sqlite", &db);
        if (rc) {
            std::cerr << "Impossible d'ouvrir la base de donnees: " << sqlite3_errmsg(db) << std::endl;
        } else {
            std::cout << "Base de donnees ouverte avec succes." << std::endl;
        }

        //Remplissage Pioche des Cartes de Niveau 1
        sql = "SELECT * FROM niveau1;";
        rc = sqlite3_exec(db, sql, callbackNiv1, nullptr, &msgErreur);
        if (rc != SQLITE_OK) cout<<msgErreur<<endl;
        else cout<<"Remplissage Pioche des Cartes de Niveau 1"<<endl;


        //Remplissage Pioche des Cartes de Niveau 2
        sql = "SELECT * FROM niveau2;";
        rc = sqlite3_exec(db, sql, callbackNiv2, nullptr, &msgErreur);
        if (rc != SQLITE_OK) cout<<msgErreur<<endl;
        else cout<<"Remplissage Pioche des Cartes de Niveau 2"<<endl;

        //Remplissage Pioche des Cartes de Niveau 3
        sql = "SELECT * FROM niveau3;";
        rc = sqlite3_exec(db, sql, callbackNiv3, nullptr, &msgErreur);
        if (rc != SQLITE_OK) cout<<msgErreur<<endl;
        else cout<<"Remplissage Pioche des Cartes de Niveau 3"<<endl;

        //Remplissage Pioche des Cartes de Niveau Royal
        sql = "SELECT * FROM royales;";
        rc = sqlite3_exec(db, sql, callbackNivRoyal, nullptr, &msgErreur);
        if (rc != SQLITE_OK) cout<<msgErreur<<endl;
        else cout<<"Remplissage Pioche des Cartes de Niveau Royal"<<endl;


        sqlite3_close(db);
        cout<<"Fichier Ferme"<<endl;

        return Pioches;
    }

    //transforme une chaîne de caractères en un objet Capacite
    Capacite toCapacite(string c){
        if (c == "Rejoue") return Capacite::Rejoue;
        else if (c == "Bonus") return Capacite::Bonus;
        else if (c == "PrendJeton") return Capacite::PrendJeton;
        else if (c == "PrendPrivilege") return Capacite::PrendPrivilege;
        else if (c == "VolJeton") return Capacite::VolJeton;
        else return Capacite::Null;
    }

    //Fonction callback pour la récuperation des cartes de niveau 1 depuis la base de donnée
    int callbackNiv1(void *NotUsed, int argc, char **argv, char **azColName) {
        int j = 1;
        compteur = 0;

        int prix[7] = {0};
        for(int i=0; i<7; i++){ //récupération du prix
            prix[i] = atoi(argv[j]);
            j++;
        }

        int bonus[7] = {0};
        for(int i=0; i<7; i++){ //récupération du bonus
            bonus[i] = atoi(argv[j]);
            j++;
        }

        int pts_prestiges = atoi(argv[15]); //récupération des points de prestige
        int couronnes = atoi(argv[16]); //récupération des couronnes
        Capacite capa = Capacite::Null; //récupération des capacités
        if (argv[17]) capa= toCapacite(argv[17]);
        Capacite capa2 = Capacite::Null;
        if (argv[18]) capa= toCapacite(argv[18]);

        Carte* c = new Carte(Tas::un, pts_prestiges, couronnes, prix, bonus, capa, capa2);
        //cout<<*c<<endl;

        Pioches[0]->ajoutCarte(c);

        compteur++;
        return 0;
    }

    //Fonction callback pour la récuperation des cartes de niveau 2 depuis la base de donnée
    int callbackNiv2(void *NotUsed, int argc, char **argv, char **azColName) {
        int j = 1;
        compteur = 0;

        int prix[7] = {0};
        for(int i=0; i<7; i++){ //récupération du prix
            prix[i] = atoi(argv[j]);
            j++;
        }

        int bonus[7] = {0};
        for(int i=0; i<7; i++){ //récupération du bonus
            bonus[i] = atoi(argv[j]);
            j++;
        }

        int pts_prestiges = atoi(argv[15]); //récupération des points de prestige
        int couronnes = atoi(argv[16]); //récupération des couronnes
        Capacite capa = Capacite::Null; //récupération des capacités
        if (argv[17]) capa= toCapacite(argv[17]);
        Capacite capa2 = Capacite::Null;
        if (argv[18]) capa= toCapacite(argv[18]);

        Carte* c = new Carte(Tas::deux, pts_prestiges, couronnes, prix, bonus, capa, capa2);
        //cout<<*c<<endl;

        Pioches[1]->ajoutCarte(c);

        compteur++;
        return 0;
    }

    //Fonction callback pour la récuperation des cartes de niveau 3 depuis la base de donnée
    int callbackNiv3(void *NotUsed, int argc, char **argv, char **azColName) {
        int j = 1;
        compteur = 0;

        int prix[7] = {0};
        for(int i=0; i<7; i++){ //récupération du prix
            prix[i] = atoi(argv[j]);
            j++;
        }

        int bonus[7] = {0};
        for(int i=0; i<7; i++){ //récupération du bonus
            bonus[i] = atoi(argv[j]);
            j++;
        }

        int pts_prestiges = atoi(argv[15]); //récupération des points de prestige
        int couronnes = atoi(argv[16]); //récupération des couronnes
        Capacite capa = Capacite::Null; //récupération des capacités
        if (argv[17]) capa= toCapacite(argv[17]);
        Capacite capa2 = Capacite::Null;
        if (argv[18]) capa= toCapacite(argv[18]);

        Carte* c = new Carte(Tas::trois, pts_prestiges, couronnes, prix, bonus, capa, capa2);
        //cout<<*c<<endl;

        Pioches[2]->ajoutCarte(c);

        compteur++;
        return 0;
    }

    //Fonction callback pour la récuperation des cartes de niveau royal depuis la base de donnée
    int callbackNivRoyal(void *NotUsed, int argc, char **argv, char **azColName) {
        compteur = 0;

        int prix[7] = {0};
        int bonus[7] = {0};
        int pts_prestiges = atoi(argv[1]); //récupération des points de prestige
        Capacite capa = Capacite::Null; //récupération des capacités
        if (argv[2]) capa = toCapacite(argv[2]);

        Carte* c = new Carte(Tas::royal, pts_prestiges, 0, prix, bonus, capa, Capacite::Null);

        Pioches[3]->ajoutCarte(c);

        compteur++;
        return 0;
    }

    //Affichage complet de toutes les pioches - plutôt pour une vérification des admins que pour l'utilisateur
    void affichePioches(){
        cout<<"\nAffichage Pioche 1"<<endl;
        for (int i=0; i<Pioches[0]->getNbCartesRestantes(); i++) cout<<Pioches[0]->getPaquet()[i]<<endl;
        cout<<"\nAffichage Pioche 2"<<endl;
        for (int i=0; i<Pioches[1]->getNbCartesRestantes(); i++) cout<<*(Pioches[1]->getPaquet()[i])<<endl;
        cout<<"\nAffichage Pioche 3"<<endl;
        for (int i=0; i<Pioches[2]->getNbCartesRestantes(); i++) cout<<*(Pioches[2]->getPaquet()[i])<<endl;
        cout<<"\nAffichage Pioche Royale"<<endl;
        for (int i=0; i<Pioches[3]->getNbCartesRestantes(); i++) cout<<*(Pioches[3]->getPaquet()[i])<<endl;
    }

    Pioche::~Pioche(){
        for(int i=0;i<nb_cartes_restantes;i++) delete Paquet[i];
        delete [] Paquet;
    }

}
