#include "Mastermind.h"

Mastermind::Mastermind(ListeDouble<Combinaison>* _liste)
{
	this->liste = _liste;
	this->createCombinaisons();
}

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

bool Mastermind::validerCombinaison(Combinaison* _toValidate, Combinaison* _ref, short* _tabVerdicts)
{
	//A COMPLETER
	//V�rifiez si la combinaison toValidate doit �tre retir�e ou non de la liste, en fonction d'une combinaison de r�f�rence et d'un tableau de 4 verdicts.
	//Pour chacune des couleurs pr�sentes dans toValidate, 3 verdicts possibles doivent �tre pris en consid�ration pour �l�miner ou non la combinaison, 
	//il s'agit de "Bonne couleur, bonne place" (valeur 1), "Bonne couleur, mauvaise place" (valeur 2) et "Mauvaise couleur" (valeur 3).


	//Voici un �bauche d'algorithme qui devrait vous aider � compl�ter cette m�thode:
	//Pour chacune des couleurs de la combinaison toValidate, v�rifiez:
	
	//Si le verdict est 1 (Bonne couleur, bonne place) et que la combinaison de couleurs � valider n'a pas la couleur � la m�me place que 
	//la combinaison de r�f�rence, il faut la retirer de la liste.

	//Si le verdict est 2 (Bonne couleur, mauvaise place) et que la combinaison de couleurs � valider n'a pas la couleur � un autre emplacement que
	//celui de la combinaison de r�f�rence, il faut la retirer de la liste.

	//Si le verdict est 3 (Mauvaise couleur) et que la combinaison de couleurs � valider a la couleur, il faut la retirer de la liste.

	//Retournez true si la combinaison est valide (respecte les verdicts) et false dans le cas contraire.
	return 0;
}

short Mastermind::nettoyerListe(Combinaison* _ref, short* _tabVerdicts)
{
	//A COMPLETER
	//�pure la liste de combinaisons de couleurs en fonction de la combinaison re�ue et des 4 verdicts (valeurs 1 � 3).
	//Pour chacune des combinaisons de la liste, v�rifier si elle doit �tre retir�e ou non de liste.
	//Le nombre de combinaisons supprim�es doit �tre retourn�.

	int numberOfCombinaisonsRemoved = 0;

	for (int currentColorPos = 0; currentColorPos < NB_COULEURS_PAR_COMBINAISON; currentColorPos++)
	{
		int currentVerdict = _tabVerdicts[currentColorPos];
		short currentColorId = _ref->getCouleur(currentColorPos).getCouleur();
		if (currentVerdict == 1)
		{
			numberOfCombinaisonsRemoved += this->removeCombinaisonsWithAllColorsExceptAtPosition(currentColorPos, currentColorId);
		}
		else if (currentVerdict == 2)
		{
			numberOfCombinaisonsRemoved += this->removeCombinaisonsWithColorAtPosition(currentColorPos, currentColorId);
		}
		else if (currentVerdict == 3)
		{
			for (int i = 0; i < NB_COULEURS_PAR_COMBINAISON; i++)
				numberOfCombinaisonsRemoved += this->removeCombinaisonsWithColorAtPosition(i, currentColorId);
		}
	}

	return numberOfCombinaisonsRemoved;
}

/// <summary>
/// Permet de g�n�rer toutes les combinaisons possibles du jeu mastermind
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
	Iterateur<Combinaison> currentCombinaison = this->liste->begin();
	short numberOfCombinaisonsRemoved = 0;
	for (int i = 0; i < this->liste->getNbElements(); i++)
	{
		Noeud<Combinaison>* currentNode = currentCombinaison.getCourant();
		if (currentNode->getElement()->getCouleur(colorPos).getCouleur() == colorId)
		{
			this->liste->retirer(currentNode);
			numberOfCombinaisonsRemoved++;
		}
		++currentCombinaison;
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
	for (int currentColorId = 1; currentColorId <= NB_COULEURS; currentColorId++)
	{
		if (currentColorId != validColorId)
			numberOfCombinaisonsRemoved += this->removeCombinaisonsWithColorAtPosition(colorPos, currentColorId);
	}
	return numberOfCombinaisonsRemoved;
}
