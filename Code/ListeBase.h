#pragma once

template <class T>
class ListeBase
{
public:
	virtual bool ajouter(T* _element) = 0;
	virtual int getNbElements() const = 0;
	// Indique si la liste est vide
	virtual bool isEmpty() const = 0;
	// Vide la liste et la remet dans l'état initial
	virtual void vider() = 0;
};
