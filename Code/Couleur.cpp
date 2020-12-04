#include "Couleur.h"

/// <summary>
/// Construit une couleur avec l'identifiant 0
/// </summary>
Couleur::Couleur(void)
{
    this->couleur = 0;
}

/// <summary>
/// Construit une couleur avec l'identifiant spécifié en paramètre
/// </summary>
Couleur::Couleur(short _c)
{
    this->couleur = _c;
}

/// <summary>
/// Destructeur d'une couleur
/// </summary>
Couleur::~Couleur(void)
{
}

/// <summary>
/// Surchage l'affichage d'une couleur dans la console avec le nom des couleurs
/// </summary>
/// <param name="sortie">Le stream à écrire</param>
/// <param name="c">La couleur à afficher</param>
/// <returns>Le stream transformé</returns>
ostream& operator<<(ostream& sortie, const Couleur& c)
{
    switch(c.couleur)
    {
        case 1:
            sortie << "Rouge";
            break; 
        case 2:
            sortie << "Vert";
            break; 
        case 3:
            sortie << "Bleu";
            break; 
        case 4:
            sortie << "Jaune";
            break; 
        case 5:
            sortie << "Noir";
            break; 
        case 6:
            sortie << "Orange";
            break; 
        case 7:
            sortie << "Mauve";
            break; 
        case 8:
            sortie << "Blanc";
            break;
    };
    return sortie;
}

/// <summary>
/// Vérifie si deux couleurs sont égales
/// </summary>
/// <param name="c">La couleur à comparer</param>
/// <returns>Retourne vrai si les deux couleurs ont le même identifiant, faux sinon</returns>
bool Couleur::operator==(const Couleur& c)
{ 
    return this->couleur == c.couleur;
}

/// <summary>
/// Vérifie si la couleur a un identifiant supérieur à celle passé en paramètre
/// </summary>
/// <param name="c">La couleur à comparer</param>
/// <returns>Retourne vrai si la couleur à un identifiant supérieur à celle passé en paramètre, faux sinon</returns>
bool Couleur::operator>(const Couleur& c)
{ 
    return this->couleur > c.couleur;
}

/// <summary>
/// Vérifie si la couleur a un identifiant inférieur à celle passé en paramètre
/// </summary>
/// <param name="c">La couleur à comparer</param>
/// <returns>Retourne vrai si la couleur à un identifiant inférieur à celle passé en paramètre, faux sinon</returns>
bool Couleur::operator<(const Couleur& c)
{ 
    return this->couleur < c.couleur;
}

/// <summary>
/// Vérifie si deux couleurs sont différentes
/// </summary>
/// <param name="c">La couleur à comparer</param>
/// <returns>Retourne vrai si les deux couleurs n'ont pas le même identifiant, faux sinon</returns>
bool Couleur::operator!=(const Couleur& c)
{ 
    return this->couleur != c.couleur;
}

/// <summary>
/// Permet de mettre la couleur égale à une autre
/// </summary>
/// <param name="c">La couleur de référence</param>
void Couleur::operator=(const Couleur& c)
{ 
    this->couleur = c.couleur;
}

/// <summary>
/// Modifie l'identifiant de la couleur
/// </summary>
/// <param name="_c">Le nouveau identifiant</param>
void Couleur::setCouleur(short _c)
{
    this->couleur = _c;
}

/// <summary>
/// Retourne l'identifiant de la couleur
/// </summary>
/// <returns>L'identifiant de la couleur</returns>
short Couleur::getCouleur() const
{
    return this->couleur;
}
