#include "Combinaison.h"


Combinaison::Combinaison(Couleur c1, Couleur c2, Couleur c3, Couleur c4)
{
	tabCouleurs[0] = c1;
	tabCouleurs[1] = c2;
	tabCouleurs[2] = c3;
	tabCouleurs[3] = c4;
}

Couleur Combinaison::getCouleur(int index)
{
	if (index < 0 || index > 3) throw invalid_argument("Votre index n'est pas entre 0 et 3");
	return tabCouleurs[index];
}

Combinaison::~Combinaison()
{
}

bool Combinaison::operator< (const Combinaison& _combinaison) const
{
	return true;
}

bool Combinaison::operator > (const Combinaison& _combinaison) const
{
	return true;
}

bool Combinaison::operator == (const Combinaison& _combinaison) const
{
	//A COMPLETER	
	return false;
}
