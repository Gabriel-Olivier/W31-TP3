#include "pch.h"
#include "ConsoleMenu.h"
#include "ListeDouble.h"

int main()
{
    //ConsoleMenu menu;
    //menu.run();
	ListeDouble<Combinaison> liste;
	Combinaison* combinaisons[NB_COULEURS];
	for (int i = NB_COULEURS; i >= 1; i--)
	{
		combinaisons[i - 1] = new Combinaison(Couleur(i), Couleur(i), Couleur(i), Couleur(i));
		liste.ajouter(combinaisons[i - 1]);
	}

	liste.affiche();

	liste.retirer(liste.getPremierNoeud());
	std::cout << std::endl;
	
	liste.affiche();

	for (int i = 0; i < NB_COULEURS; i++)
		delete combinaisons[i];

	system("pause");

    return 0;
}
