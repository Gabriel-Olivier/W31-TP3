#pragma once
#include "Constants.h"
#include "Couleur.h"

/// <summary>
/// Représente une combinaison de 4 couleurs
/// </summary>
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

	int convertToNumeric() const;

private:
	/// <summary>
	/// Tableau contenant l'ensemble des couleurs de la combinaison
	/// </summary>
	Couleur tabCouleurs[NB_COULEURS_PAR_COMBINAISON];
};
