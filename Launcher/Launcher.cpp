#include "pch.h"
#include "ConsoleMenu.h"
#include "ListeDouble.h"

int main()
{
    //ConsoleMenu menu;
    //menu.run();

	ListeDouble<Combinaison> liste;
	Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
	Combinaison* combinaison2 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
	Combinaison* combinaison3 = new Combinaison(Couleur(3), Couleur(3), Couleur(3), Couleur(3));
	Combinaison* combinaison4 = new Combinaison(Couleur(4), Couleur(4), Couleur(4), Couleur(4));
	Combinaison* combinaison5 = new Combinaison(Couleur(5), Couleur(5), Couleur(5), Couleur(5));
	Combinaison* combinaison6 = new Combinaison(Couleur(6), Couleur(6), Couleur(6), Couleur(6));
	Combinaison* combinaison7 = new Combinaison(Couleur(7), Couleur(7), Couleur(7), Couleur(7));
	Combinaison* combinaison8 = new Combinaison(Couleur(8), Couleur(8), Couleur(8), Couleur(8));

	liste.ajouter(combinaison1);
	liste.ajouter(combinaison4);
	liste.ajouter(combinaison2);
	liste.ajouter(combinaison3);
	liste.ajouter(combinaison8);
	liste.ajouter(combinaison6);
	liste.ajouter(combinaison7);
	liste.ajouter(combinaison5);

	liste.affiche();

	delete combinaison1;
	delete combinaison2;
	delete combinaison3;
	delete combinaison4;
	delete combinaison5;
	delete combinaison6;
	delete combinaison7;
	delete combinaison8;

	system("pause");

    return 0;
}
