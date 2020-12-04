#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// Réprésente une couleur en spécifiant un identifiant allant de 1 à 8 inclusivement
/// </summary>
class Couleur
{
public:
    Couleur(void);
    Couleur(short _c);
    ~Couleur(void);

    friend ostream& operator<<(ostream& sortie, const Couleur& c);

    bool operator==(const Couleur& _c);

    bool operator>(const Couleur& _c); 

    bool operator<(const Couleur& _c);

    bool operator!=(const Couleur& _c);

    void operator=(const Couleur& _c);

    void setCouleur(short _c);
    short getCouleur();

private:
    /// <summary>
    /// L'identifiant spécifiant la couleur
    /// </summary>
    short couleur;
};
