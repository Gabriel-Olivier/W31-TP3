#include "Combinaison.h"

/// <summary>
/// Construit une combinaison � paritr de 4 couleurs
/// </summary>
/// <param name="c1">La premi�re couleur de la combinaison</param>
/// <param name="c2">La deuxi�me couleur de la combinaison</param>
/// <param name="c3">La troisi�me couleur de la combinaison</param>
/// <param name="c4">La quatri�me couleur de la combinaison</param>
Combinaison::Combinaison(Couleur c1, Couleur c2, Couleur c3, Couleur c4)
{
	tabCouleurs[0] = c1;
	tabCouleurs[1] = c2;
	tabCouleurs[2] = c3;
	tabCouleurs[3] = c4;
}

/// <summary>
/// Retourne la couleur de la combinaison � l'index sp�cifi�
/// </summary>
/// <param name="index">L'index de la couleur</param>
/// <returns>La couleur de la combinaison � l'index sp�cifi�</returns>
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
/// V�rifie si la valeur num�rique de la combinaison est inf�rieur � la valeur num�rique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison � comparer</param>
/// <returns>Retourne vrai si la valeur num�rique de la combinaison est inf�rieur � celle pass�e en param�tre, faux sinon</returns>
bool Combinaison::operator<(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() < _combinaison.convertToNumeric();
}

/// <summary>
/// V�rifie si la valeur num�rique de la combinaison est sup�rieur � la valeur num�rique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison � comparer</param>
/// <returns>Retourne vrai si la valeur num�rique de la combinaison est sup�rieur � celle pass�e en param�tre, faux sinon</returns>
bool Combinaison::operator>(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() > _combinaison.convertToNumeric();
}

/// <summary>
/// V�rifie si la valeur num�rique de la combinaison est �gale � la valeur num�rique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison � comparer</param>
/// <returns>Retourne vrai si la valeur num�rique de la combinaison est �gale � celle pass�e en param�tre, faux sinon</returns>
bool Combinaison::operator==(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() == _combinaison.convertToNumeric();
}

/// <summary>
/// V�rifie si la valeur num�rique de la combinaison n'est pas �gale � la valeur num�rique d'une autre combinaison
/// </summary>
/// <param name="_combinaison">La combinaison � comparer</param>
/// <returns>Retourne vrai si la valeur num�rique de la combinaison n'est pas �gale � celle pass�e en param�tre, faux sinon</returns>
bool Combinaison::operator!=(const Combinaison& _combinaison) const
{
	return this->convertToNumeric() != _combinaison.convertToNumeric(); // !this->operator==(_combinaison)
}

/// <summary>
/// Retourne la valeur num�rique d'une combinaison
/// </summary>
/// <returns>La valeur num�rique d'une combinaison</returns>
int Combinaison::convertToNumeric() const
{
	return this->getCouleur(0).getCouleur() * 1000 +
		   this->getCouleur(1).getCouleur() * 100 +
		   this->getCouleur(2).getCouleur() * 10 +
		   this->getCouleur(3).getCouleur() * 1;
}
