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
	bool retirer(Noeud<T>* _element);
	void affiche();
	Noeud<T>* getPremierNoeud();
	Iterateur<T> begin();
	Iterateur<T> end();
	
private:
	void pushFront(T* _element);
	bool deleteFront();
	bool deleteAt(Noeud<T>* _node);
	bool pushAt(Noeud<T>* _node, T* _element);
	Noeud<T>* premierNoeud;
};

template<class T>
ListeDouble<T>::ListeDouble()
{
	// Indicateur de liste vide
	this->premierNoeud = nullptr;
}

template<class T>
ListeDouble<T>::~ListeDouble()
{
	while (this->premierNoeud)
	{
		Noeud<T>* oldFirstNode = this->premierNoeud;
		this->premierNoeud = this->premierNoeud->getSuivant();
		delete oldFirstNode;
	}
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
		Noeud<T>* current = this->premierNoeud;
		while (current->getSuivant() && *_element > * current->getSuivant()->getElement())
			current = current->getSuivant();
		isPushed = this->pushAt(current, _element);
	}
	return isPushed;
}

template<class T>
bool ListeDouble<T>::retirer(Noeud<T>* _element)
{
	if (!this->premierNoeud)
		return false;
	if (this->premierNoeud && *this->premierNoeud->getElement() == *_element->getElement())
		return this->deleteFront();
	Noeud<T>* current = this->premierNoeud;
	while (current->getSuivant() && *_element->getElement() != *current->getSuivant()->getElement())
		current = current->getSuivant();
	return this->deleteAt(current);
}

template<class T>
void ListeDouble<T>::affiche()
{
	Noeud<T>* current = this->premierNoeud;
	while (current)
	{
		current->getElement()->affiche();
		current = current->getSuivant();
	}
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
bool ListeDouble<T>::deleteAt(Noeud<T>* _node)
{
	bool isRemoved = false;
	Noeud<T>* oldNextNode = _node->getSuivant();
	if (oldNextNode)
	{
		_node->setSuivant(oldNextNode->getSuivant());
		delete oldNextNode;
		isRemoved = true;
	}
	return isRemoved;
}

template<class T>
bool ListeDouble<T>::pushAt(Noeud<T>* _node, T* _livre)
{
	bool isPushed = false;
	Noeud<T>* oldNextNode = _node->getSuivant();
	if (!oldNextNode || *_livre < *oldNextNode->getElement())
	{
		Noeud<T>* newNode = new Noeud<T>;
		newNode->setElement(_livre);
		_node->setSuivant(newNode);
		newNode->setSuivant(oldNextNode);
		isPushed = true;
	}
	return isPushed;
}
