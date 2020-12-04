#include "Mastermind.h"

/// <summary>
/// Constructeur de Mastermind
/// </summary>
/// <param name="_liste">La liste des combinaisons possibles</param>
Mastermind::Mastermind(ListeDouble<Combinaison>* _liste)
{
	this->liste = _liste;
	this->createCombinaisons();
}

/// <summary>
/// Destructeur de Mastermind
/// </summary>
Mastermind::~Mastermind()
{
	this->deleteCombinaisons();
}

/// <summary>
/// Permet d'obtenir le nombre d'�l�ments actuellement pr�sents dans la liste
/// </summary>
/// <returns>Le nombre d'�l�ments actuellement pr�sents dans la liste</returns>
int Mastermind::getNbElements() const
{
	return this->liste->getNbElements();
}

/// <summary>
/// Retourne un �l�ment de la liste � une certaine position
/// </summary>
/// <param name="index">La position de l'�l�ment � retourner</param>
/// <returns>L'�l�ment qui est � la position sp�cifi�e</returns>
Combinaison* Mastermind::getElement(int index) const
{
	return this->liste->getElement(index);
}

/// <summary>
/// Permet de supprimer les combinaisons qui ne sont plus valides de la liste
/// </summary>
/// <param name="_ref">La combinaison essay�e</param>
/// <param name="_tabVerdicts">Les verdicts pour chaque couleur de la combinaison essay�e (entre 1 et 3 inclusivement)</param>
/// <returns>Le nombre de combinaisons supprim�es de la liste</returns>
short Mastermind::nettoyerListe(Combinaison* _ref, short* _tabVerdicts)
{
	int numberOfCombinaisonsRemoved = 0;

	// Pour chaque couleur de la combinaison essay�e
	for (int currentColorPos = 0; currentColorPos < NB_COULEURS_PAR_COMBINAISON; currentColorPos++)
	{
		// On obtient le verdict et la couleur essay�e
		int currentVerdict = _tabVerdicts[currentColorPos];
		short currentColorId = _ref->getCouleur(currentColorPos).getCouleur();

		// Si c'est une bonne couleur au bon endroit
		if (currentVerdict == 1)
			numberOfCombinaisonsRemoved += this->removeCombinaisonsWithAllColorsExceptAtPosition(currentColorPos, currentColorId);

		// Si c'est uniquement une bonne couleur
		else if (currentVerdict == 2)
			numberOfCombinaisonsRemoved += this->removeCombinaisonsWithColorAtPosition(currentColorPos, currentColorId);

		// Si ce n'est pas une bonne couleur
		else if (currentVerdict == 3)
		{
			for (int i = 0; i < NB_COULEURS_PAR_COMBINAISON; i++)
				numberOfCombinaisonsRemoved += this->removeCombinaisonsWithColorAtPosition(i, currentColorId);
		}
	}

	return numberOfCombinaisonsRemoved;
}

/// <summary>
/// Permet de g�n�rer toutes les combinaisons possibles
/// </summary>
void Mastermind::createCombinaisons()
{
	int index = 0;
	for (int i = 1; i <= NB_COULEURS; i++)
	{
		for (int j = 1; j <= NB_COULEURS; j++)
		{
			for (int k = 1; k <= NB_COULEURS; k++)
			{
				for (int w = 1; w <= NB_COULEURS; w++)
				{
					Combinaison* combinaison = new Combinaison(Couleur(i), Couleur(j), Couleur(k), Couleur(w));
					this->tabCombinaisons[index] = combinaison;
					this->liste->ajouter(combinaison);
					index++;
				}
			}
		}
	}
}

/// <summary>
/// Permet de supprimer toutes les combinaisons
/// </summary>
void Mastermind::deleteCombinaisons()
{
	for (int i = 0; i < NB_COMBINAISONS_POSSIBLES; i++)
		delete this->tabCombinaisons[i];
}

/// <summary>
/// Permet de supprimer toutes les combinaisons qui ont la couleur sp�cifi�e � la position sp�cifi�e
/// </summary>
/// <param name="colorPos">La position de la couleur dans la combinaison (entre 0 et 3 inclusivement)</param>
/// <param name="colorId">L'identifiant de la couleur (entre 1 et 8 inclusivement)</param>
/// <returns>Le nombre de combinaisons supprim�es</returns>
short Mastermind::removeCombinaisonsWithColorAtPosition(short colorPos, short colorId)
{
	short numberOfCombinaisonsRemoved = 0;

	// On place un it�rateur au d�but de la liste des combinaisons
	Iterateur<Combinaison> currentCombinaison = this->liste->begin();
	
	// Tant que l'it�rateur n'a pas atteint la fin de la liste
	while (currentCombinaison != this->liste->end())
	{
		// On obtient la combinaison point�e par l'it�rateur
		Noeud<Combinaison>* currentNode = currentCombinaison.getCourant();

		// On d�place l'it�rateur � la combinaison suivante
		++currentCombinaison;

		// Si la combinaison a la couleur sp�cifi�e � la position sp�cifi�e, on la supprime de la liste
		if (currentNode->getElement()->getCouleur(colorPos).getCouleur() == colorId)
		{
			this->liste->retirer(currentNode);
			numberOfCombinaisonsRemoved++;
		}
	}

	return numberOfCombinaisonsRemoved;
}

/// <summary>
/// Permet de supprimer toutes les combinaisons ayant toutes les couleurs sauf une � la position sp�cifi�e
/// </summary>
/// <param name="colorPos">La position de la couleur dans la combinaison (entre 0 et 3 inclusivement)</param>
/// <param name="colorId">L'identifiant de la couleur (entre 1 et 8 inclusivement)</param>
/// <returns>Le nombre de combinaisons supprim�es</returns>
short Mastermind::removeCombinaisonsWithAllColorsExceptAtPosition(short colorPos, short validColorId)
{
	short numberOfCombinaisonsRemoved = 0;

	// Pour chaque couleur possible
	for (int currentColorId = 1; currentColorId <= NB_COULEURS; currentColorId++)
	{
		// Si la couleur n'est pas celle valide � la position sp�cifi�e, on supprime la combinaison
		if (currentColorId != validColorId)
			numberOfCombinaisonsRemoved += this->removeCombinaisonsWithColorAtPosition(colorPos, currentColorId);
	}

	return numberOfCombinaisonsRemoved;
}
