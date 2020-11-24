#include "pch.h"
#include "ConsoleMenu.h"
#include "ListeDouble.h"

int main()
{
    //ConsoleMenu menu;
    //menu.run();
	ListeDouble<Combinaison> liste;
	Combinaison* combinaison1 = new Combinaison(Couleur(3), Couleur(3), Couleur(3), Couleur(3));
	Combinaison* combinaison4 = new Combinaison(Couleur(4), Couleur(4), Couleur(4), Couleur(4));
	Combinaison* combinaison2 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
	Combinaison* combinaison3 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
	liste.ajouter(combinaison1);
	liste.ajouter(combinaison4);
	liste.ajouter(combinaison2);
	liste.ajouter(combinaison3);

	liste.affiche();

	delete combinaison1;
	delete combinaison2;
	delete combinaison3;
	delete combinaison4;

	system("pause");

    return 0;
}
