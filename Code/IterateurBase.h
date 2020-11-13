#pragma once
template <class T>
class IterateurBase{
public:

	//méthodes usuelles vues en classe pour un itérateur
	virtual void operator++() = 0;
	virtual void operator--() = 0;
	virtual T* operator->() = 0;
	T& operator*() = 0;
	bool operator==(IterateurBase<T> iter) = 0;
	bool operator!=(IterateurBase<T> iter) = 0;
};
