#pragma once
#include <iostream>
using namespace std;

class Couleur{
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
 
    short convertToNumeric();

    void setCouleur(short _c);
    short getCouleur();

private:
    short couleur;
};

