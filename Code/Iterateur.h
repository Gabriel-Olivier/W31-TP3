#pragma once
#include "IterateurBase.h"

/// <summary>
/// Structure servant à parcourir une série de noeuds
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
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
	Noeud<T>* getCourant() override;

	bool operator==(Iterateur<T> iter);
	bool operator!=(Iterateur<T> iter);

private:
	/// <summary>
	/// Le noeud contenu dans l'itérateur
	/// </summary>
	Noeud<T>* courant;
};

/// <summary>
/// Constructeur par défaut
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
template<class T>
Iterateur<T>::Iterateur()
{
}

/// <summary>
/// Initialise un itérateur avec un noeud
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
/// <param name="courant">Le noeud courant de l'itérateur</param>
template<class T>
Iterateur<T>::Iterateur(Noeud<T>* courant)
{
	this->courant = courant;
}

/// <summary>
/// Destructeur de l'itérateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
template<class T>
Iterateur<T>::~Iterateur() {}

/// <summary>
/// Fait avancer l'itérateur vers le noeud suivant
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
template<class T>
void Iterateur<T>::operator++()
{
	this->courant = this->courant->getSuivant();
}

/// <summary>
/// Fait reculer l'itérateur vers le noeud précédent
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
template<class T>
void Iterateur<T>::operator--()
{
	this->courant = this->courant->getPrecedent();
}

/// <summary>
/// Retourne un pointeur vers l'élément stocké dans le noeud de l'itérateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
/// <returns>Un pointeur vers l'élément stocké dans le noeud de l'itérateur</returns>
template<class T>
T* Iterateur<T>::operator->()
{
	return this->courant->getElement();
}

/// <summary>
/// Retourne une référenre vers l'élément stocké dans le noeud de l'itérateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
/// <returns>Une référenre vers l'élément stocké dans le noeud de l'itérateur</returns>
template<class T>
T& Iterateur<T>::operator*()
{
	return *this->courant->getElement();
}

/// <summary>
/// Compare la référence des noeuds contenu dans les itérateurs
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
/// <param name="iter">L'itérateur à comparer</param>
/// <returns>Retourne vrai si les deux itérateurs contiennent le même noeud, faux sinon</returns>
template<class T>
bool Iterateur<T>::operator==(Iterateur<T> iter)
{
	return this->courant == iter.courant;
}

/// <summary>
/// Compare la référence des noeuds contenu dans les itérateurs
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
/// <param name="iter">L'itérateur à comparer</param>
/// <returns>Retourne faux si les deux itérateurs ne contiennent pas le même noeud, vrai sinon</returns>
template<class T>
bool Iterateur<T>::operator!=(Iterateur<T> iter)
{
	return this->courant != iter.courant;
}

/// <summary>
/// Retourne le noeud stocké dans l'itérateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'itérateur</typeparam>
/// <returns>Le noeud stocké dans l'itérateur</returns>
template<class T>
Noeud<T>* Iterateur<T>::getCourant()
{
	return this->courant;
}
