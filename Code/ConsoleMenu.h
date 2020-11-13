#pragma once
#include "Couleur.h"
#include "Combinaison.h"

class ConsoleMenu
{
public:
	ConsoleMenu();
	~ConsoleMenu();
	void run();
private:
	bool saisirSequence(Couleur* tabCouleurs);
	void afficherResultat(short nbCoups);
	bool partieEstTerminee(short* tabVerdicts);
	void saisirVerdicts(Combinaison* tabCouleursRef, short* tabVerdicts);
};

