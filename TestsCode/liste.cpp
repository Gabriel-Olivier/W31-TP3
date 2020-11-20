#include "stdafx.h"
#include "CppUnitTest.h"
#include "ListeDouble.h"
#include "Combinaison.h"
#include "Constants.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_Liste_Double
{		
	TEST_CLASS(Liste_Double)
	{
		// Tests de getPremierNoeud()

		TEST_METHOD(getPremierNoeud_whenListIsEmpty_shouldReturnNull)
		{
			ListeDouble<Combinaison> liste;
			
			Assert::IsNull(liste.getPremierNoeud());
		}

		TEST_METHOD(getPremierNoeud_whenListIsNotEmpty_shouldNotBeNull)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));

			liste.ajouter(combinaison1);

			Assert::IsNotNull(liste.getPremierNoeud());

			delete combinaison1;
		}

		// Tests de getNbElements()

		TEST_METHOD(getNbElements_whenListIsEmpty_shouldReturnZero)
		{
			ListeDouble<Combinaison> liste;

			Assert::AreEqual(0, liste.getNbElements());
		}

		TEST_METHOD(getNbElements_whenAnElementWasAdded_shouldIncrementNbElementsByOne)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			const int INITIAL_NB_ELEMENTS = liste.getNbElements();

			liste.ajouter(combinaison1);

			const int FINAL_NB_ELEMENTS = liste.getNbElements();
			Assert::AreEqual(1, FINAL_NB_ELEMENTS - INITIAL_NB_ELEMENTS);

			delete combinaison1;
		}

		// Tests de isEmpty()

		TEST_METHOD(isEmpty_whenListIsEmpty_shouldReturnTrue)
		{
			ListeDouble<Combinaison> liste;

			Assert::IsTrue(liste.isEmpty());
		}

		TEST_METHOD(isEmpty_whenListIsNotEmpty_shouldReturnFalse)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));

			liste.ajouter(combinaison1);

			Assert::IsFalse(liste.isEmpty());

			delete combinaison1;
		}

		// Tests de vider()

		TEST_METHOD(vider_whenListIsNotEmpty_shouldEmptyTheList)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaisons[NB_COULEURS];
			for (int i = 1; i <= NB_COULEURS; i++)
			{
				combinaisons[i - 1] = new Combinaison(Couleur(i), Couleur(i), Couleur(i), Couleur(i));
				liste.ajouter(combinaisons[i - 1]);
			}
			
			liste.vider();

			Assert::IsNull(liste.getPremierNoeud());
			Assert::AreEqual(0, liste.getNbElements());
			Assert::IsTrue(liste.isEmpty());

			for (int i = 0; i < NB_COULEURS; i++)
				delete combinaisons[i];
		}
	};
}
