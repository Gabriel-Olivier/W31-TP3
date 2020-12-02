#pragma once

/// <summary>
/// Repr�sente une unit�e de chainage qui pourra �tre stock� dans un it�rateur et dans notre liste double.
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
template<class T>
class Noeud
{
public:
	Noeud();
	~Noeud();

	Noeud<T>* getSuivant();
	void setSuivant(Noeud<T>* _suivant);
	Noeud<T>* getPrecedent();
	void setPrecedent(Noeud<T>* _precedent);
	T* getElement();
	void setElement(T* _element);

private:
	/// <summary>
	/// Le prochain noeud de ce noeud
	/// </summary>
	Noeud<T>* suivant;

	/// <summary>
	/// Le noeud pr�c�dent de ce noeud
	/// </summary>
	Noeud<T>* precedent;

	/// <summary>
	/// L'�l�ment contenu dans ce noeud
	/// </summary>
	T* element;
};

/// <summary>
/// Constructeur d'un noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
template<class T>
Noeud<T>::Noeud()
{
}

/// <summary>
/// Destructeur d'un noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
template<class T>
Noeud<T>::~Noeud()
{
}

/// <summary>
/// M�thode d�finissant le prochain noeud de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
/// <param name="_suivant">Le prochain noeud de ce noeud</param>
template<class T>
void Noeud<T>::setSuivant(Noeud<T>* _suivant)
{
	this->suivant = _suivant;
}

/// <summary>
/// Permet d'obtenir le prochain noeud de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
/// <returns>Le prochain noeud de ce noeud</returns>
template<class T>
Noeud<T>* Noeud<T>::getSuivant()
{
	return this->suivant;
}

/// <summary>
/// M�thode d�finissant le noeud pr�c�dent de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
/// <param name="_precedent">Le nouveaux noeud</param>
template<class T>
void Noeud<T>::setPrecedent(Noeud<T>* _precedent)
{
	this->precedent = _precedent;
}

/// <summary>
/// Permet d'obtenir le noeud pr�c�dent de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
/// <returns>Le noeud pr�c�dent de ce noeud</returns>
template<class T>
Noeud<T>* Noeud<T>::getPrecedent()
{
	return this->precedent;
}

/// <summary>
/// Permet d'obtenir l'�l�ment contenu dans ce noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
/// <returns>L'�l�ment contenu dans ce noeud</returns>
template<class T>
T* Noeud<T>::getElement()
{
	return this->element;
}

/// <summary>
/// M�thode d�finissant l'�l�ment contenu dans ce noeud
/// </summary>
/// <typeparam name="T">Le type d'�l�ment dans ce noeud</typeparam>
/// <param name="_element">Le nouvel �l�ment</param>
template<class T>
void Noeud<T>::setElement(T* _element)
{
	this->element = _element;
}
