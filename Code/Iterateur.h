#pragma once
#include "IterateurBase.h"
#include "ListeDouble.h"

template <class T>
class Iterateur : public IterateurBase<T>
{
public:
	Iterateur();
	Iterateur(Noeud<T>* courant);
	~Iterateur();

	void operator++() override;
	void operator--() override;
	T* operator->() override;
	T& operator*() override;
	bool operator==(Iterateur<T> iter) override;
	bool operator!=(Iterateur<T> iter) override;
	T* getCourant() override;

private:
	Noeud<T>* courant;
};

template<class T>
Iterateur<T>::Iterateur()
{
}

template<class T>
Iterateur<T>::Iterateur(Noeud<T>* courant)
{
	this->courant = courant;
}

template<class T>
Iterateur<T>::~Iterateur()
{
}

template<class T>
void Iterateur<T>::operator++()
{
	this->courant = this->courant->getSuivant();
}

template<class T>
void Iterateur<T>::operator--()
{
	this->courant = this->courant->getPrecedent();
}

template<class T>
T* Iterateur<T>::operator->()
{
	return this->courant->getElement();
}

template<class T>
T& Iterateur<T>::operator*()
{
	return *this->courant->getElement();
}

template<class T>
bool Iterateur<T>::operator==(Iterateur<T> iter)
{
	return this->courant == iter.courant;
}

template<class T>
bool Iterateur<T>::operator!=(Iterateur<T> iter)
{
	return this->courant != iter.courant;
}

template<class T>
T* Iterateur<T>::getCourant()
{
	return this->courant;
}
