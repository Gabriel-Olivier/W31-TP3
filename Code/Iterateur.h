#pragma once
#include "IterateurBase.h"

/// <summary>
/// Structure servant � parcourir une s�rie de noeuds
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
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
	/// Le noeud contenu dans l'it�rateur
	/// </summary>
	Noeud<T>* courant;
};

/// <summary>
/// Constructeur par d�faut
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
template<class T>
Iterateur<T>::Iterateur()
{
}

/// <summary>
/// Initialise un it�rateur avec un noeud
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
/// <param name="courant">Le noeud courant de l'it�rateur</param>
template<class T>
Iterateur<T>::Iterateur(Noeud<T>* courant)
{
	this->courant = courant;
}

/// <summary>
/// Destructeur de l'it�rateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
template<class T>
Iterateur<T>::~Iterateur() {}

/// <summary>
/// Fait avancer l'it�rateur vers le noeud suivant
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
template<class T>
void Iterateur<T>::operator++()
{
	this->courant = this->courant->getSuivant();
}

/// <summary>
/// Fait reculer l'it�rateur vers le noeud pr�c�dent
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
template<class T>
void Iterateur<T>::operator--()
{
	this->courant = this->courant->getPrecedent();
}

/// <summary>
/// Retourne un pointeur vers l'�l�ment stock� dans le noeud de l'it�rateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
/// <returns>Un pointeur vers l'�l�ment stock� dans le noeud de l'it�rateur</returns>
template<class T>
T* Iterateur<T>::operator->()
{
	return this->courant->getElement();
}

/// <summary>
/// Retourne une r�f�renre vers l'�l�ment stock� dans le noeud de l'it�rateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
/// <returns>Une r�f�renre vers l'�l�ment stock� dans le noeud de l'it�rateur</returns>
template<class T>
T& Iterateur<T>::operator*()
{
	return *this->courant->getElement();
}

/// <summary>
/// Compare la r�f�rence des noeuds contenu dans les it�rateurs
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
/// <param name="iter">L'it�rateur � comparer</param>
/// <returns>Retourne vrai si les deux it�rateurs contiennent le m�me noeud, faux sinon</returns>
template<class T>
bool Iterateur<T>::operator==(Iterateur<T> iter)
{
	return this->courant == iter.courant;
}

/// <summary>
/// Compare la r�f�rence des noeuds contenu dans les it�rateurs
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
/// <param name="iter">L'it�rateur � comparer</param>
/// <returns>Retourne faux si les deux it�rateurs ne contiennent pas le m�me noeud, vrai sinon</returns>
template<class T>
bool Iterateur<T>::operator!=(Iterateur<T> iter)
{
	return this->courant != iter.courant;
}

/// <summary>
/// Retourne le noeud stock� dans l'it�rateur
/// </summary>
/// <typeparam name="T">Le type du noeud contenu dans l'it�rateur</typeparam>
/// <returns>Le noeud stock� dans l'it�rateur</returns>
template<class T>
Noeud<T>* Iterateur<T>::getCourant()
{
	return this->courant;
}
