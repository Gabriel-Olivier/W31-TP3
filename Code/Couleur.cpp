#include "Couleur.h"

/// <summary>
/// Construit une couleur avec l'identifiant 0
/// </summary>
Couleur::Couleur(void)
{
    this->couleur = 0;
}

/// <summary>
/// Construit une couleur avec l'identifiant sp�cifi� en param�tre
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
/// <param name="sortie">Le stream � �crire</param>
/// <param name="c">La couleur � afficher</param>
/// <returns>Le stream transform�</returns>
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
/// V�rifie si deux couleurs sont �gales
/// </summary>
/// <param name="c">La couleur � comparer</param>
/// <returns>Retourne vrai si les deux couleurs ont le m�me identifiant, faux sinon</returns>
bool Couleur::operator==(const Couleur& c)
{ 
    return this->couleur == c.couleur;
}

/// <summary>
/// V�rifie si la couleur a un identifiant sup�rieur � celle pass� en param�tre
/// </summary>
/// <param name="c">La couleur � comparer</param>
/// <returns>Retourne vrai si la couleur � un identifiant sup�rieur � celle pass� en param�tre, faux sinon</returns>
bool Couleur::operator>(const Couleur& c)
{ 
    return this->couleur > c.couleur;
}

/// <summary>
/// V�rifie si la couleur a un identifiant inf�rieur � celle pass� en param�tre
/// </summary>
/// <param name="c">La couleur � comparer</param>
/// <returns>Retourne vrai si la couleur � un identifiant inf�rieur � celle pass� en param�tre, faux sinon</returns>
bool Couleur::operator<(const Couleur& c)
{ 
    return this->couleur < c.couleur;
}

/// <summary>
/// V�rifie si deux couleurs sont diff�rentes
/// </summary>
/// <param name="c">La couleur � comparer</param>
/// <returns>Retourne vrai si les deux couleurs n'ont pas le m�me identifiant, faux sinon</returns>
bool Couleur::operator!=(const Couleur& c)
{ 
    return this->couleur != c.couleur;
}

/// <summary>
/// Permet de mettre la couleur �gale � une autre
/// </summary>
/// <param name="c">La couleur de r�f�rence</param>
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
