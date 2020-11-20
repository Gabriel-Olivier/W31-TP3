#pragma once
#include "Couleur.h"

class Combinaison
{
public:
	Combinaison(Couleur _c1, Couleur _c2, Couleur _c3, Couleur _c4);
	~Combinaison();

	Couleur getCouleur(int index) const;

	bool operator < (const Combinaison& _combinaison) const;
	bool operator > (const Combinaison& _combinaison) const;
	bool operator == (const Combinaison& _combinaison) const;
	bool operator != (const Combinaison& _combinaison) const;
    
private:
	int convertToNumeric() const;
	static const unsigned int NB_COULEURS = 4;
	Couleur tabCouleurs[NB_COULEURS];
};
