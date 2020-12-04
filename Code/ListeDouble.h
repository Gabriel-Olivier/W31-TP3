#pragma once
#include "ListeBase.h"
#include "EmptyListException.h"
#include "Noeud.h"
#include "Iterateur.h"

/// <summary>
/// Liste chainée bidirectionelle
/// </summary>
/// <typeparam name="T">Le type d'élément qye stocke la liste</typeparam>
template<class T>
class ListeDouble : public ListeBase<T>
{
public:
	ListeDouble();
	~ListeDouble();

	bool ajouter(T* _element) override;
	T* getElement(int index) const;
	int getNbElements() const override;
	bool isEmpty() const override;
	void vider() override;

	bool retirer(Noeud<T>* _noeudCourant);
	Noeud<T>* getPremierNoeud();

	Iterateur<T> begin() const;
	Iterateur<T> end() const;

	void affiche();

private:
	void pushFront(T* _element);
	bool deleteFront();
	bool deleteAt(Iterateur<T>& _node);
	bool pushAt(Iterateur<T>& it, T* _element);

	/// <summary>
	/// Repr/sente le premier noeud de la liste
	/// </summary>
	Noeud<T>* premierNoeud;

	/// <summary>
	/// Stocke le nombre d'éléments dans la liste
	/// </summary>
	int nbElements;
};

/// <summary>
/// Constructeur de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément qye stocke la liste</typeparam>
template<class T>
ListeDouble<T>::ListeDouble()
{
	// Indicateur de liste vide
	this->premierNoeud = nullptr;
	this->nbElements = 0;
}

/// <summary>
/// Détruit la liste et supprime ses éléments
/// </summary>
/// <typeparam name="T">Le type d'élément qye stocke la liste</typeparam>
template<class T>
ListeDouble<T>::~ListeDouble()
{
	this->vider();
}

/// <summary>
/// Ajoute un nouvel élément à la liste
/// </summary>
/// <typeparam name="T">Le type d'élément qye stocke la liste</typeparam>
/// <param name="_element">L'élément à ajouter</param>
/// <returns>Retourne vrai si l'élément passé en paramètre s'est ajouté à la liste, faux sinon</returns>
template<class T>
bool ListeDouble<T>::ajouter(T* _element)
{
	bool isPushed = false;
	T* firstElement = this->premierNoeud ? this->premierNoeud->getElement() : nullptr;
	if (!firstElement || *_element < *firstElement)
	{
		this->pushFront(_element);
		isPushed = true;
	}
	else if (*_element != *firstElement)
	{
		Iterateur<T> current = this->begin();
		while (current.getCourant()->getSuivant() && *current.getCourant()->getSuivant()->getElement() < *_element)
			++current;
		isPushed = this->pushAt(current, _element);
	}
	return isPushed;
}

/// <summary>
/// Retourne l'élément à l'index spécifié en paramètre
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <param name="index">L'index de l'élément à trouver</param>
/// <returns>Retourne l'élément à l'index spécifié, nullptr si l'élément est introuvable</returns>
template<class T>
T* ListeDouble<T>::getElement(int index) const
{
	T* element = nullptr;
	if (index >= 0 && index < this->nbElements)
	{
		Iterateur<T> current = this->begin();
		for (int i = 0; i < index; i++)
			++current;
		element = current.getCourant()->getElement();
	}
	return element;
}

/// <summary>
/// Retourne le nombre d'éléments dans la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <returns>Le nombre d'éléments dans la liste</returns>
template<class T>
int ListeDouble<T>::getNbElements() const
{
	return this->nbElements;
}

/// <summary>
/// Permet de savoir si la liste est vide
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <returns>Retourne vrai si la liste est vide, faux sinon</returns>
template<class T>
bool ListeDouble<T>::isEmpty() const
{
	return this->premierNoeud == nullptr;
}

/// <summary>
/// Vide complètement la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
template<class T>
void ListeDouble<T>::vider()
{
	while (this->deleteFront());
}

/// <summary>
/// Retire le noeud spécifié en paramètre de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <param name="_noeudCourant">Le noeud à retirer</param>
/// <returns>Retourne vrai si le noeud spécifié en paramètre a été enlevé de la liste, faux sinon</returns>
template<class T>
bool ListeDouble<T>::retirer(Noeud<T>* _noeudCourant)
{
	bool isRemoved = false;
	if (!this->isEmpty() && _noeudCourant != nullptr)
	{
		if (this->premierNoeud == _noeudCourant)
			isRemoved = this->deleteFront();
		else
		{
			Iterateur<T> current = this->begin();
			while (current != this->end() && _noeudCourant != current.getCourant())
				++current;
			isRemoved = this->deleteAt(current);
		}
	}
	return isRemoved;
}

/// <summary>
/// Retourne le premier noeud de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <returns>Le premier noeud de la liste</returns>
template<class T>
Noeud<T>* ListeDouble<T>::getPremierNoeud()
{
	return this->premierNoeud;
}

/// <summary>
/// Retourne un itérateur pointant vers le premier noeud de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <returns>Un itérateur pointant vers le premier noeud de la liste</returns>
template<class T>
Iterateur<T> ListeDouble<T>::begin() const
{
	return Iterateur<T>(this->premierNoeud);
}

/// <summary>
/// Retourne un itérateur pointant vers le dernier noeud de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <returns>Un itérateur pointant vers le dernier noeud de la liste (nullptr)</returns>
template<class T>
Iterateur<T> ListeDouble<T>::end() const
{
	return Iterateur<T>(nullptr);
}

/// <summary>
/// Ajoute un élément au début de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <param name="_element">L'élément à ajouter au début de la liste</param>
template<class T>
void ListeDouble<T>::pushFront(T* _element)
{
	Noeud<T>* oldFirstNode = this->premierNoeud;
	Noeud<T>* newNode = new Noeud<T>;
	newNode->setElement(_element);
	this->premierNoeud = newNode;
	newNode->setSuivant(oldFirstNode);
	newNode->setPrecedent(nullptr);
	if (oldFirstNode)
	{
		oldFirstNode->setPrecedent(newNode);
	}
	this->nbElements++;
}

/// <summary>
/// Supprime l'élément au début de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <returns>Retourne vrai si le premier élément a été supprimé, faux sinon</returns>
template<class T>
bool ListeDouble<T>::deleteFront()
{
	bool isRemoved = false;
	if (this->premierNoeud)
	{
		Noeud<T>* oldFirstNode = this->premierNoeud;
		this->premierNoeud = this->premierNoeud->getSuivant();
		if (this->premierNoeud)
			this->premierNoeud->setPrecedent(nullptr);
		delete oldFirstNode;
		oldFirstNode = nullptr;
		isRemoved = true;
		this->nbElements--;
	}
	return isRemoved;
}

/// <summary>
/// Supprime de la liste le noeud contenu dans l'itérateur spécifié en paramètre
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <param name="it">L'itérateur contenant le noeud à supprimer</param>
/// <returns>Retourne vrai si le noeud contenu dans l'itérateur spécifié en paramètret a été supprimé, faux sinon</returns>
template<class T>
bool ListeDouble<T>::deleteAt(Iterateur<T>& it)
{
	bool isRemoved = false;
	Noeud<T>* currentNode = it.getCourant();
	if (currentNode)
	{
		Noeud<T>* nextNode = currentNode->getSuivant();
		Noeud<T>* previousNode = currentNode->getPrecedent();
		if (nextNode)
			nextNode->setPrecedent(previousNode);
		if (previousNode)
			previousNode->setSuivant(nextNode);
		delete currentNode;
		currentNode = nullptr;
		isRemoved = true;
		this->nbElements--;
	}
	return isRemoved;
}

/// <summary>
/// Ajoute à la liste l'élément spécifié en paramètre à la position de l'itérateur
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
/// <param name="it">L'itérateur spécifiant la position</param>
/// <param name="_element">L'élément à ajouter</param>
/// <returns>Retourne vrai si l'élément spécifié en paramètre a été supprimer, faux sinon</returns>
template<class T>
bool ListeDouble<T>::pushAt(Iterateur<T>& it, T* _element)
{
	bool isPushed = false;
	Noeud<T>* currentNode = it.getCourant();
	Noeud<T>* oldNextNode = currentNode->getSuivant();
	if (!oldNextNode || *_element < *oldNextNode->getElement())
	{
		Noeud<T>* newNode = new Noeud<T>;
		newNode->setElement(_element);
		currentNode->setSuivant(newNode);
		newNode->setSuivant(oldNextNode);
		newNode->setPrecedent(it.getCourant());
		isPushed = true;
		this->nbElements++;
	}
	return isPushed;
}

/// <summary>
/// Affiche tous les éléments de la liste
/// </summary>
/// <typeparam name="T">Le type d'élément que stocke la liste</typeparam>
template<class T>
void ListeDouble<T>::affiche()
{
	Iterateur<T> current = this->begin();
	while (current != this->end())
	{
		std::cout << (*current).convertToNumeric() << std::endl;
		++current;
	}
}
