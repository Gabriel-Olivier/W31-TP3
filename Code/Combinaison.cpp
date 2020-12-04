#include "Combinaison.h"

/// <summary>
/// Construit une combinaison à paritr de 4 couleurs
/// </summary>
/// <param name="c1">La première couleur de la combinaison</param>
/// <param name="c2">La deuxième couleur de la combinaison</param>
/// <param name="c3">La troisième couleur de la combinaison</param>
/// <param name="c4">La quatrième couleur de la combinaison</param>
Combinaison::Combinaison(Couleur c1, Couleur c2, Couleur c3, Couleur c4)
{
	tabCouleurs[0] = c1;
	tabCouleurs[1] = c2;
	tabCouleurs[2] = c3;
	tabCouleurs[3] = c4;
}

/// <summary>
/// Retourne la couleur de la combinaison à l'index spécifié
/// </summary>
/// <param name="index">L'index de la couleur</param>
/// <returns>La couleur de la combinaison à l'index spécifié</returns>
Couleur Combinaison::getCouleur(int index) const
{
	if (index < 0 || index > 3) throw invalid_argument("Votre index n'est pas entre 0 et 3");
	return tabCouleurs[index];
}

/// <summary>
/// Destructeur d'une combinaison
/// </summary>
Combinaison::~Combinaison()
{
}

/// <summary>
/// Vérifie si la valeur numérique de la combinaison est inférieur à la valeur numérique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison à comparer</param>
/// <returns>Retourne vrai si la valeur numérique de la combinaison est inférieur à celle passée en paramètre, faux sinon</returns>
bool Combinaison::operator<(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() < _combinaison.convertToNumeric();
}

/// <summary>
/// Vérifie si la valeur numérique de la combinaison est supérieur à la valeur numérique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison à comparer</param>
/// <returns>Retourne vrai si la valeur numérique de la combinaison est supérieur à celle passée en paramètre, faux sinon</returns>
bool Combinaison::operator>(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() > _combinaison.convertToNumeric();
}

/// <summary>
/// Vérifie si la valeur numérique de la combinaison est égale à la valeur numérique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison à comparer</param>
/// <returns>Retourne vrai si la valeur numérique de la combinaison est égale à celle passée en paramètre, faux sinon</returns>
bool Combinaison::operator==(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() == _combinaison.convertToNumeric();
}

/// <summary>
/// Vérifie si la valeur numérique de la combinaison n'est pas égale à la valeur numérique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison à comparer</param>
/// <returns>Retourne vrai si la valeur numérique de la combinaison n'est pas égale à celle passée en paramètre, faux sinon</returns>
bool Combinaison::operator!=(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() != _combinaison.convertToNumeric(); // !this->operator==(_combinaison)
}

/// <summary>
/// Retourne la valeur numérique d'une combinaison
/// </summary>
/// <returns>La valeur numérique d'une combinaison</returns>
int Combinaison::convertToNumeric() const
{
	return this->getCouleur(0).getCouleur() * 1000 +
		   this->getCouleur(1).getCouleur() * 100 +
		   this->getCouleur(2).getCouleur() * 10 +
		   this->getCouleur(3).getCouleur() * 1;
}
