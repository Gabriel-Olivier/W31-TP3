#include "pch.h"
#include "ConsoleMenu.h"
#include "ListeDouble.h"
#include "Mastermind.h"

int main()
{
    //ConsoleMenu menu;
    //menu.run();

	ListeDouble<Combinaison> liste;
	Mastermind mastermind (&liste);
	cout << liste.getNbElements();

	system("pause");
    return 0;
}
