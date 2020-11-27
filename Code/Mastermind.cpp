#include "Mastermind.h"


Mastermind::Mastermind(ListeDouble<Combinaison>* _liste)
{
	// Créer les 4096 combinaisons
}

Mastermind::~Mastermind()
{

}


int Mastermind::getNbElements() const
{
	return this->liste->getNbElements();
}

/// <summary>
/// Retourne un élément de la liste en position index
/// </summary>
/// <param name="index">La position de l'élément à retourner</param>
/// <returns>L'élément qui est à la position index</returns>
Combinaison* Mastermind::getElement(int index) const
{
	return this->liste->getElement(index);
}

bool Mastermind::validerCombinaison(Combinaison* _toValidate, Combinaison* _ref, short* _tabVerdicts)
{
	//A COMPLETER
	//Vérifiez si la combinaison toValidate doit être retirée ou non de la liste, en fonction d'une combinaison de référence et d'un tableau de 4 verdicts.
	//Pour chacune des couleurs présentes dans toValidate, 3 verdicts possibles doivent être pris en considération pour éléminer ou non la combinaison, 
	//il s'agit de "Bonne couleur, bonne place" (valeur 1), "Bonne couleur, mauvaise place" (valeur 2) et "Mauvaise couleur" (valeur 3).

	//Voici un ébauche d'algorithme qui devrait vous aider à compléter cette méthode:
	//Pour chacune des couleurs de la combinaison toValidate, vérifiez:
	
	//Si le verdict est 1 (Bonne couleur, bonne place) et que la combinaison de couleurs à valider n'a pas la couleur à la même place que 
	//la combinaison de référence, il faut la retirer de la liste.

	//Si le verdict est 2 (Bonne couleur, mauvaise place) et que la combinaison de couleurs à valider n'a pas la couleur à un autre emplacement que
	//celui de la combinaison de référence, il faut la retirer de la liste.

	//Si le verdict est 3 (Mauvaise couleur) et que la combinaison de couleurs à valider a la couleur, il faut la retirer de la liste.

	//Retournez true si la combinaison est valide (respecte les verdicts) et false dans le cas contraire.
	return 0;
}

short Mastermind::nettoyerListe(Combinaison* _ref, short* _tabVerdicts)
{
	//A COMPLETER
	//Épure la liste de combinaisons de couleurs en fonction de la combinaison reçue et des 4 verdicts (valeurs 1 à 3).
	//Pour chacune des combinaisons de la liste, vérifier si elle doit être retirée ou non de liste.
	//Le nombre de combinaisons supprimées doit être retourné.

	return 0;
}
