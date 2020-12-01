#pragma once

#include "ListeDouble.h"
#include "Combinaison.h"
#include "Couleur.h"

class Mastermind
{
public:
    Mastermind(ListeDouble<Combinaison>* _liste);
    ~Mastermind();

    int getNbElements() const;
	Combinaison* getElement(int _index) const;

    short nettoyerListe(Combinaison* _ref, short* _tabVerdicts);

private:
	bool validerCombinaison(Combinaison* _toValidate, Combinaison* _ref, short* _tabVerdicts);
    void createCombinaisons();
    void deleteCombinaisons();

    void removeCombinaisonWith(short colorPos, short colorId);

    ListeDouble<Combinaison>* liste; //Contient toutes les combinaisons de couleurs possibles, selon le contexte.
    Combinaison* tabCombinaisons[NB_COMBINAISONS_POSSIBLES];
};
