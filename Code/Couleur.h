#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// R�pr�sente une couleur en sp�cifiant un identifiant allant de 1 � 8 inclusivement
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
    /// L'identifiant sp�cifiant la couleur
    /// </summary>
    short couleur;
};
