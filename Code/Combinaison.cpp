#include "Combinaison.h"

Combinaison::Combinaison(Couleur c1, Couleur c2, Couleur c3, Couleur c4)
{
	tabCouleurs[0] = c1;
	tabCouleurs[1] = c2;
	tabCouleurs[2] = c3;
	tabCouleurs[3] = c4;
}

Couleur Combinaison::getCouleur(int index) const
{
	if (index < 0 || index > 3) throw invalid_argument("Votre index n'est pas entre 0 et 3");
	return tabCouleurs[index];
}

Combinaison::~Combinaison()
{
}

bool Combinaison::operator<(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() < _combinaison.convertToNumeric();
}

bool Combinaison::operator>(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() > _combinaison.convertToNumeric();
}

bool Combinaison::operator==(const Combinaison& _combinaison) const
{
	bool sameCombinaisons = true;
	for (int i = 0; i < NB_COULEURS; i++)
	{
		if (this->getCouleur(i) != _combinaison.getCouleur(i))
		{
			sameCombinaisons = false;
			break;
		}
	}
	return sameCombinaisons;
}

bool Combinaison::operator!=(const Combinaison& _combinaison) const
{
	return !(*this == _combinaison); // !this->operator==(_combinaison)
}

int Combinaison::convertToNumeric() const
{
	return this->getCouleur(0).convertToNumeric() * 1000 +
		   this->getCouleur(1).convertToNumeric() * 100 +
		   this->getCouleur(2).convertToNumeric() * 10 +
		   this->getCouleur(3).convertToNumeric() * 1;
}
