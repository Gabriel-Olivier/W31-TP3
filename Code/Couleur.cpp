#include "Couleur.h"


Couleur::Couleur(void)
{
    couleur = 0;
}
Couleur::Couleur(short _c)
{
    couleur = _c;
}
Couleur::~Couleur(void){}

ostream& operator<<(ostream& sortie, const Couleur& c)
{
    
    switch(c.couleur){
        case 1:
            sortie<<"Rouge";
            break;
        case 2:
            sortie<<"Vert";
            break;
        case 3:
            sortie<<"Bleu";
            break;
        case 4:
            sortie<<"Jaune";
            break;
        case 5:
            sortie<<"Noir";
            break;
        case 6:
            sortie<<"Orange";
            break;
        case 7:
            sortie<<"Mauve";
            break;
        case 8:
            sortie<<"Blanc";
            break;
    };
    return sortie;
}

bool Couleur::operator==(const Couleur& c)
{ 
    return couleur == c.couleur;
}

bool Couleur::operator>(const Couleur& c){ 
    return couleur > c.couleur;
}

bool Couleur::operator<(const Couleur& c){ 
    return couleur < c.couleur;
}

bool Couleur::operator!=(const Couleur& c){ 
    return couleur != c.couleur;
}

void Couleur::operator=(const Couleur& c){ 
    couleur = c.couleur;
}

short Couleur::convertToNumeric(){
    return couleur;
}

void Couleur::setCouleur(short _c){
    couleur = _c;
}

short Couleur::getCouleur()
{
    return this->couleur;
}
