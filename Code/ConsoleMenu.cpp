#include <ctime>
#include "ConsoleMenu.h"
#include "ConsoleColor.h"
#include "Mastermind.h"
#include "ListeDouble.h"

#include <iostream>

ConsoleMenu::ConsoleMenu()
{

}

ConsoleMenu::~ConsoleMenu()
{

}

/// <summary>
/// La méthode Run est le point central de notre programme.
/// </summary>
void ConsoleMenu::run()
{
    ListeDouble<Combinaison>* liste = new ListeDouble<Combinaison>;
    bool partieContinue = true;

    while (partieContinue) {

        Mastermind mastermind(liste);

        Couleur tabCouleurs[4]; //4 couleurs parmi un choix de 8

        if (saisirSequence(tabCouleurs))
        {
            short nbCoups = 0;

            cout << endl << endl << "##############################Debut de la partie##############################" << endl << endl;
            while (true) {

                if (nbCoups == 8) {
                    cout << "Le nombre maximum d'essais a atteint la limite (8). Je perds..." << endl << endl;
                    break;
                }
                int iNbElements = mastermind.getNbElements();
                if (iNbElements == 0) { //Il ne reste plus de combinaison dans la liste, l'utilisateur a fait assurément une erreur car HAL ne se trompe pas!
                    cout << "La liste de combinaisons possibles est epuisee." << endl << endl;;
                    break;
                }
                nbCoups++;
                
                cout << "NbElements:" << iNbElements << endl;

                //Obtention de la combinaison de couleur de référence
                srand((unsigned int)time(NULL));
                int nombreAleatoire = rand() % mastermind.getNbElements();
                Combinaison* tabCouleursRef = mastermind.getElement(nombreAleatoire);

                cout << green << "--------Couleurs a deviner: " << tabCouleurs[0] << " "
                    << tabCouleurs[1] << " "
                    << tabCouleurs[2] << " "
                    << tabCouleurs[3] << " "
                    << "--------"
                    << endl;
                
                cout << blue << endl << "Choix de HAL (" << "essai #" << nbCoups << "):    " << tabCouleursRef->getCouleur(0) << " "
                    << tabCouleursRef->getCouleur(1) << " "
                    << tabCouleursRef->getCouleur(2) << " "
                    << tabCouleursRef->getCouleur(3) << " "
                    << endl << endl;

                short tabVerdicts[4];

                saisirVerdicts(tabCouleursRef, tabVerdicts);

                if (partieEstTerminee(tabVerdicts))
                {
                    afficherResultat(nbCoups);
                    delete liste;
                    return;
                }
                else
                {
                    //------------------------Épuration de la liste des combinaisons qui ne respectent pas les critères-----------------------------
                    cout << mastermind.nettoyerListe(tabCouleursRef, tabVerdicts) << " combinaisons supprimees." << endl;
                }
            }
        }
        else
        {
            partieContinue = false;
            cout << "Au revoir!" << endl;
        }

        delete liste;
    }
}

/// <summary>
/// Permet de choisir une séquence de 4 couleurs afin de débuter le jeu
/// </summary>
/// <param name="tabCouleurs">Tableau des 4 couleurs à choisir pour le jeu</param>
/// <returns>Retourne true si on a choisi une séqunec pour jouer et false si on désire quitter la partie</returns>
bool ConsoleMenu::saisirSequence(Couleur* tabCouleurs)
{
    cout << "Veuillez entrer une sequence de 4 couleurs parmi les suivantes:" << endl << endl;
    cout << "    1-Rouge" << endl;
    cout << "    2-Vert" << endl;
    cout << "    3-Bleu" << endl;
    cout << "    4-Jaune" << endl;
    cout << "    5-Noir" << endl;
    cout << "    6-Orange" << endl;
    cout << "    7-Mauve" << endl;
    cout << "    8-Blanc" << endl;

    string choix;
    do {
        cout << "Entrer la suite de chiffres, 0 pour sortir: ";
        cin >> choix;

        if (choix == "0")
            return false;

        if (choix.length() == 4) {
            tabCouleurs[0].setCouleur(atoi(choix.substr(0, 1).c_str()));
            tabCouleurs[1].setCouleur(atoi(choix.substr(1, 1).c_str()));
            tabCouleurs[2].setCouleur(atoi(choix.substr(2, 1).c_str()));
            tabCouleurs[3].setCouleur(atoi(choix.substr(3, 1).c_str()));
        }
    } while (choix.length() != 4 || tabCouleurs[0] > 8 || tabCouleurs[1] > 8 || tabCouleurs[2] > 8 || tabCouleurs[3] > 8);

    cout << "Couleurs choisies: " << tabCouleurs[0] << " "
        << tabCouleurs[1] << " "
        << tabCouleurs[2] << " "
        << tabCouleurs[3] << " "
        << endl;

    return true;
}

bool ConsoleMenu::partieEstTerminee(short* tabVerdicts)
{
    if (tabVerdicts[0] == 1 && tabVerdicts[1] == 1 && tabVerdicts[2] == 1 && tabVerdicts[3] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ConsoleMenu::saisirVerdicts(Combinaison* tabCouleursRef, short* tabVerdicts)
{
    //Lecteur des 4 verdicts de l'usager
    for (int i = 0; i < 4; i++) {
        do {
            string entree;

            Couleur c = tabCouleursRef->getCouleur(i);

            cout << white << endl << "Couleur " << i + 1 << " - " << tabCouleursRef->getCouleur(i) << endl;
            cout << "Choisir (1-Bonne place 2-Bonne couleur 3-Mauvaise couleur): ";

            cin >> entree;
            tabVerdicts[i] = atoi(entree.c_str());
        } while (tabVerdicts[i] != 1 && tabVerdicts[i] != 2 && tabVerdicts[i] != 3);
    }
}

void ConsoleMenu::afficherResultat(short nbCoups)
{   
    cout << endl << "J'ai trouve la reponse apres " << nbCoups;
    if (nbCoups == 1) {
        cout << " essai. Merci d'avoir joue avec moi." << endl << endl;
    }
    else {
        cout << " essais. Merci d'avoir joue avec moi." << endl << endl;
    }
    cout << "----HAL 9000----" << endl << endl;
}
