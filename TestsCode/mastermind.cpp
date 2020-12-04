#include "stdafx.h"
#include "CppUnitTest.h"
#include "Mastermind.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_Mastermind
{
	TEST_CLASS(Mastermind_Tests)
	{
		TEST_METHOD(getNbElements_whenMastermindWasJustCreated_shouldReturnTheRightNumberOfElements)
		{
			ListeDouble<Combinaison> liste;
			Mastermind mastermind(&liste);

			Assert::AreEqual((int)NB_COMBINAISONS_POSSIBLES, mastermind.getNbElements());
		}

		TEST_METHOD(getElement_whenMastermindWasJustCreated_shouldReturnTheRightElement)
		{
			ListeDouble<Combinaison> liste;
			Mastermind mastermind(&liste);
			
			Assert::AreEqual(1111, mastermind.getElement(0)->convertToNumeric());
		}

		#pragma region Tests de nettoyerListe()

		TEST_METHOD(nettoyerListe_shouldRemoveInvalidCombinaisons)
		{
			ListeDouble<Combinaison> liste;
			Mastermind mastermind(&liste);
			Combinaison combinaison(Couleur(1), Couleur(2), Couleur(3), Couleur(4));
			short verdicts[] = { 1, 3, 3, 3 };

			mastermind.nettoyerListe(&combinaison, verdicts);

			Iterateur<Combinaison> iterateur = liste.begin();
			while (iterateur != liste.end())
			{
				Assert::IsTrue(iterateur.getCourant()->getElement()->getCouleur(0) == 1);
				for (int i = 1; i <= 3; i++)
				{
					for (int j = 2; j <= 4; j++)
						Assert::IsFalse(iterateur.getCourant()->getElement()->getCouleur(i) == j);
				}
				++iterateur;
			}
		}

		TEST_METHOD(nettoyerListe_whenTriedCombinaisonIsTheValidOne_shouldRemoveAllOtherCombinaisons)
		{
			ListeDouble<Combinaison> liste;
			Mastermind mastermind(&liste);
			Combinaison combinaison(Couleur(1), Couleur(2), Couleur(3), Couleur(4));
			short verdicts[] = { 1, 1, 1, 1 };

			mastermind.nettoyerListe(&combinaison, verdicts);

			Assert::AreEqual(1, liste.getNbElements());
			Assert::IsTrue(combinaison == *liste.getElement(0));
		}

		TEST_METHOD(nettoyerListe_whenTriedCombinaisonIsTheValidOneButShuffled_shouldRemoveAllOtherCombinaisons)
		{
			ListeDouble<Combinaison> liste;
			Mastermind mastermind(&liste);
			const Couleur C1 = Couleur(1);
			const Couleur C2 = Couleur(2);
			const Couleur C3 = Couleur(3);
			const Couleur C4 = Couleur(4);
			Combinaison combinaison(C1, C2, C3, C4);
			short verdicts[] = { 2, 2, 2, 2 };

			mastermind.nettoyerListe(&combinaison, verdicts);

			Iterateur<Combinaison> iterateur = liste.begin();
			while (iterateur != liste.end())
			{
				Combinaison* current = iterateur.getCourant()->getElement();

				Assert::IsTrue(current->getCouleur(0) != C1.getCouleur());
				Assert::IsTrue(current->getCouleur(1) != C2.getCouleur());
				Assert::IsTrue(current->getCouleur(2) != C3.getCouleur());
				Assert::IsTrue(current->getCouleur(3) != C4.getCouleur());
				++iterateur;
			}
		}

		TEST_METHOD(nettoyerListe_whenTriedCombinaisonIsNotValid_shouldRemoveAllOtherCombinaisons)
		{
			ListeDouble<Combinaison> liste;
			Mastermind mastermind(&liste);
			const Couleur C1 = Couleur(1);
			const Couleur C2 = Couleur(2);
			const Couleur C3 = Couleur(3);
			const Couleur C4 = Couleur(4);
			Combinaison combinaison(C1, C2, C3, C4);
			short verdicts[] = { 3, 3, 3, 3 };

			mastermind.nettoyerListe(&combinaison, verdicts);

			Iterateur<Combinaison> iterateur = liste.begin();
			while (iterateur != liste.end())
			{
				Combinaison* current = iterateur.getCourant()->getElement();

				for (int i = 0; i < NB_COULEURS_PAR_COMBINAISON; i++)
				{
					Assert::IsTrue(current->getCouleur(i) != C1.getCouleur());
					Assert::IsTrue(current->getCouleur(i) != C2.getCouleur());
					Assert::IsTrue(current->getCouleur(i) != C3.getCouleur());
					Assert::IsTrue(current->getCouleur(i) != C4.getCouleur());
				}
				++iterateur;
			}
		}

		#pragma endregion
	};
}
