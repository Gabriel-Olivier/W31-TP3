#include "stdafx.h"
#include "CppUnitTest.h"
#include "ListeDouble.h"
#include "Combinaison.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_Iterateur
{
	TEST_CLASS(Iterateur_Tests)
	{
		TEST_METHOD(getCourant_whenListIsEmpty_shouldReturnNull)
		{
			ListeDouble<Combinaison> liste;
			Iterateur<Combinaison> iterateur = liste.begin();

			Assert::IsTrue(iterateur == nullptr);
		}

		TEST_METHOD(getCourant_whenListContainsOneElement_shouldReturnTheElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison);
			Iterateur<Combinaison> iterateur = liste.begin();

			Assert::IsTrue(iterateur.getCourant()->getElement() == combinaison);
			delete combinaison;
		}

		TEST_METHOD(getCourant_whenListContainsTwoElementsAndPlusOperatorUsed_shouldReturnTheRightElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			Combinaison* combinaison2 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			liste.ajouter(combinaison1);
			liste.ajouter(combinaison2);
			Iterateur<Combinaison> iterateur = liste.begin();
			
			++iterateur;

			Assert::IsTrue(iterateur.getCourant()->getElement() == combinaison2);

			delete combinaison1;
			delete combinaison2;
		}

		TEST_METHOD(getCourant_whenListContainsTwoElementsAndOneIsRemoved_shouldReturnTheRightElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			Combinaison* combinaison2 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			liste.ajouter(combinaison1);
			liste.ajouter(combinaison2);
			Iterateur<Combinaison> iterateur = liste.begin();
			liste.retirer(iterateur.getCourant());
			iterateur = liste.begin();

			Assert::IsTrue(iterateur.getCourant()->getElement() == combinaison2);

			delete combinaison1;
			delete combinaison2;
		}
	};
}
