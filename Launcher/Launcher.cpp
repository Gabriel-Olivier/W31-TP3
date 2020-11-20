#include "pch.h"
#include "ConsoleMenu.h"
#include "ListeDouble.h"

int main()
{
    //ConsoleMenu menu;
    //menu.run();

    Combinaison* combinaison1 = new Combinaison(Couleur(2), Couleur(1), Couleur(1), Couleur(1));
    Combinaison* combinaison2 = new Combinaison(Couleur(1), Couleur(2), Couleur(1), Couleur(1));
    Combinaison* combinaison3 = new Combinaison(Couleur(1), Couleur(1), Couleur(2), Couleur(1));
    Combinaison* combinaison4 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(2));

    ListeDouble<Combinaison> liste;
    liste.ajouter(combinaison1);
    liste.ajouter(combinaison2);
    liste.ajouter(combinaison3);
    liste.ajouter(combinaison4);
    
    std::cout << (liste.getPremierNoeud()->getSuivant()->getSuivant()->getSuivant()->getElement() == combinaison1) << std::endl;
    std::cout << (liste.getPremierNoeud()->getSuivant()->getSuivant()->getElement() == combinaison2) << std::endl;
    std::cout << (liste.getPremierNoeud()->getSuivant()->getElement() == combinaison3) << std::endl;
    std::cout << (liste.getPremierNoeud()->getElement() == combinaison4) << std::endl;

    std::cout << liste.getNbElements() << std::endl;

    liste.retirer(liste.getPremierNoeud()->getSuivant());

    std::cout << (liste.getPremierNoeud()->getSuivant()->getElement() == combinaison3) << std::endl;

    std::cout << liste.getNbElements() << std::endl;

    delete combinaison1;
    delete combinaison2;
    delete combinaison3;
    delete combinaison4;

	system("pause");

    return 0;
}
