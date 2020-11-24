#pragma once
#include "ListeBase.h"
#include "EmptyListException.h"
#include "Noeud.h"
#include "Iterateur.h"

template<class T>
class ListeDouble : public ListeBase<T>
{
public:
	ListeDouble();
	~ListeDouble();

	bool ajouter(T* _element) override;
	int getNbElements() const override;
	bool isEmpty() const override;
	void vider() override;

	bool retirer(Noeud<T>* _noeudCourant);
	Noeud<T>* getPremierNoeud();

	Iterateur<T> begin();
	Iterateur<T> end();

private:
	void pushFront(T* _element);
	bool deleteFront();
	bool deleteAt(Iterateur<T>& _node);
	bool pushAt(Iterateur<T>& it, T* _element);
	void retirer();
	Noeud<T>* premierNoeud;
	int nbElements;
};

template<class T>
ListeDouble<T>::ListeDouble()
{
	// Indicateur de liste vide
	this->premierNoeud = nullptr;
	this->nbElements = 0;
}

template<class T>
ListeDouble<T>::~ListeDouble()
{
	this->retirer();
}

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
		while (current.getCourant()->getSuivant() != nullptr && *_element > *current)
			++current;
		isPushed = this->pushAt(current, _element);
	}
	std::cout << isPushed << std::endl;
	if (isPushed) this->nbElements++;
	return isPushed;
}

template<class T>
int ListeDouble<T>::getNbElements() const
{
	return this->nbElements;
}

template<class T>
bool ListeDouble<T>::isEmpty() const
{
	return this->premierNoeud == nullptr;
}

template<class T>
void ListeDouble<T>::vider()
{
	while (this->premierNoeud)
		this->retirer(this->premierNoeud);
}

template<class T>
bool ListeDouble<T>::retirer(Noeud<T>* _noeudCourant)
{
	bool isRemoved = false;
	if (this->premierNoeud)
	{
		if (*this->premierNoeud->getElement() == *_noeudCourant->getElement())
			isRemoved = this->deleteFront();
		else
		{
			Iterateur<T> current = this->begin();
			while (current != this->end() && *_noeudCourant->getElement() != *current.getCourant()->getSuivant()->getElement() )
				++current;
			isRemoved = this->deleteAt(current);
		}
	}
	if (isRemoved) this->nbElements--;
	return isRemoved;
}

template<class T>
Noeud<T>* ListeDouble<T>::getPremierNoeud()
{
	return this->premierNoeud;
}

template<class T>
Iterateur<T> ListeDouble<T>::begin()
{
	return Iterateur<T>(this->premierNoeud);
}

template<class T>
Iterateur<T> ListeDouble<T>::end()
{
	return Iterateur<T>(nullptr);
}

template<class T>
void ListeDouble<T>::pushFront(T* _element)
{
	Noeud<T>* oldFirstNode = this->premierNoeud;
	Noeud<T>* newNode = new Noeud<T>;
	newNode->setElement(_element);
	this->premierNoeud = newNode;
	newNode->setSuivant(oldFirstNode);
}

template<class T>
bool ListeDouble<T>::deleteFront()
{
	bool isRemoved = false;
	if (this->premierNoeud)
	{
		Noeud<T>* oldFirstNode = this->premierNoeud;
		this->premierNoeud = this->premierNoeud->getSuivant();
		delete oldFirstNode;
		isRemoved = true;
	}
	return isRemoved;
}

template<class T>
bool ListeDouble<T>::deleteAt(Iterateur<T>& it)
{
	bool isRemoved = false;
	Noeud<T>* oldNextNode = it.getCourant()->getSuivant();
	if (oldNextNode)
	{
		it.getCourant()->setSuivant(oldNextNode->getSuivant());
		delete oldNextNode;
		isRemoved = true;
	}
	return isRemoved;
}

template<class T>
bool ListeDouble<T>::pushAt(Iterateur<T>& it, T* _livre)
{
	bool isPushed = false;
	Noeud<T>* oldNextNode = it.getCourant()->getSuivant();
	if (!oldNextNode || *_livre < *oldNextNode->getElement())
	{
		Noeud<T>* newNode = new Noeud<T>;
		newNode->setElement(_livre);
		it.getCourant()->setSuivant(newNode);
		newNode->setSuivant(oldNextNode);
		isPushed = true;
	}
	return isPushed;
}

template<class T>
void ListeDouble<T>::retirer()
{
	while (this->premierNoeud)
	{
		Noeud<T>* oldFirstNode = this->premierNoeud;
		this->premierNoeud = this->premierNoeud->getSuivant();
		delete oldFirstNode;
	}
}
