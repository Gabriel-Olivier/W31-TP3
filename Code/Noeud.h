#pragma once

/// <summary>
/// Représente une unitée de chainage qui pourra être stocké dans un itérateur et dans notre liste double.
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
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
	/// Le noeud précédent de ce noeud
	/// </summary>
	Noeud<T>* precedent;

	/// <summary>
	/// L'élément contenu dans ce noeud
	/// </summary>
	T* element;
};

/// <summary>
/// Constructeur d'un noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
template<class T>
Noeud<T>::Noeud()
{
}

/// <summary>
/// Destructeur d'un noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
template<class T>
Noeud<T>::~Noeud()
{
}

/// <summary>
/// Méthode définissant le prochain noeud de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
/// <param name="_suivant">Le prochain noeud de ce noeud</param>
template<class T>
void Noeud<T>::setSuivant(Noeud<T>* _suivant)
{
	this->suivant = _suivant;
}

/// <summary>
/// Permet d'obtenir le prochain noeud de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
/// <returns>Le prochain noeud de ce noeud</returns>
template<class T>
Noeud<T>* Noeud<T>::getSuivant()
{
	return this->suivant;
}

/// <summary>
/// Méthode définissant le noeud précédent de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
/// <param name="_precedent">Le nouveaux noeud</param>
template<class T>
void Noeud<T>::setPrecedent(Noeud<T>* _precedent)
{
	this->precedent = _precedent;
}

/// <summary>
/// Permet d'obtenir le noeud précédent de ce noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
/// <returns>Le noeud précédent de ce noeud</returns>
template<class T>
Noeud<T>* Noeud<T>::getPrecedent()
{
	return this->precedent;
}

/// <summary>
/// Permet d'obtenir l'élément contenu dans ce noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
/// <returns>L'élément contenu dans ce noeud</returns>
template<class T>
T* Noeud<T>::getElement()
{
	return this->element;
}

/// <summary>
/// Méthode définissant l'élément contenu dans ce noeud
/// </summary>
/// <typeparam name="T">Le type d'élément dans ce noeud</typeparam>
/// <param name="_element">Le nouvel élément</param>
template<class T>
void Noeud<T>::setElement(T* _element)
{
	this->element = _element;
}
