#pragma once
#include "Noeud.h"

template <class T>
class IterateurBase
{
public:
	virtual void operator++() = 0;
	virtual void operator--() = 0;
	virtual T* operator->() = 0;
	virtual T& operator*() = 0;
	virtual Noeud<T>* getCourant() = 0;
};
