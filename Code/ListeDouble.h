#pragma once
#include "ListeBase.h"
#include "EmptyListException.h"

using namespace std;

template <class T>
//On hérite de la liste de base
//TODO : Décommenter pour activer l'héritage
class ListeDouble //: public ListeBase<T>
{
//TODO : Définissez votre liste double, TOUTES les méthodes à surcharger sont dans ListeBase<T>
public :
	ListeDouble();
	~ListeDouble();
	void vider();

private:
	
};

//TODO : Implémentez votre liste double (toutes les méthodes de la classe mère)
template <class T>
ListeDouble<T>::ListeDouble()
{
}

template <class T>
ListeDouble<T>::~ListeDouble()
{
}

template <class T>
void ListeDouble<T>::vider()
{
}