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
		#pragma region Tests de getPremierNoeud()

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

		#pragma endregion

		#pragma region Tests de getNbElements()

		TEST_METHOD(getNbElements_whenListIsEmpty_shouldReturnZero)
		{
			ListeDouble<Combinaison> liste;

			Assert::AreEqual(0, liste.getNbElements());
		}

		TEST_METHOD(getNbElements_whenListContainsOneElement_shouldIncrementNbElementsByOne)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			const int INITIAL_NB_ELEMENTS = liste.getNbElements();

			liste.ajouter(combinaison1);

			const int FINAL_NB_ELEMENTS = liste.getNbElements();
			Assert::AreEqual(1, FINAL_NB_ELEMENTS - INITIAL_NB_ELEMENTS);

			delete combinaison1;
		}

		TEST_METHOD(getNbElements_whenListContainsMultipleElements_shouldReturnNbElements)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaisons[NB_COULEURS];
			for (int i = 1; i <= NB_COULEURS; i++)
			{
				combinaisons[i - 1] = new Combinaison(Couleur(i), Couleur(i), Couleur(i), Couleur(i));
				liste.ajouter(combinaisons[i - 1]);
			}

			Assert::AreEqual((unsigned)NB_COULEURS, (unsigned)liste.getNbElements());

			for (int i = 0; i < NB_COULEURS; i++)
				delete combinaisons[i];
		}

		#pragma endregion
		
		#pragma region Tests de isEmpty()

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

		#pragma endregion

		#pragma region Tests de vider()

		TEST_METHOD(vider_whenListIsEmpty_shouldDoNothing)
		{
			ListeDouble<Combinaison> liste;

			liste.vider();
			
			Assert::AreEqual(0, liste.getNbElements());
			Assert::IsTrue(liste.isEmpty());
			Assert::IsNull(liste.getPremierNoeud());
		}

		TEST_METHOD(vider_whenListContainsOneElement_shouldEmptyTheList)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(2), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison);

			liste.vider();

			Assert::AreEqual(0, liste.getNbElements());
			Assert::IsTrue(liste.isEmpty());
			Assert::IsNull(liste.getPremierNoeud());

			delete combinaison;
		}

		TEST_METHOD(vider_whenListContainsMultipleElements_shouldEmptyTheList)
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

		#pragma endregion

		#pragma region Tests de ajouter()
		
		TEST_METHOD(ajouter_whenListIsEmpty_shouldAddTheElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));

			liste.ajouter(combinaison);

			Assert::IsTrue(combinaison == liste.getPremierNoeud()->getElement());
			Assert::AreEqual(1, liste.getNbElements());
			Assert::IsFalse(liste.isEmpty());

			delete combinaison;
		}

		TEST_METHOD(ajouter_whenListContainsOneElement_shouldAddTheElementAtTheRightPlace)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			Combinaison* combinaison2 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison1);

			liste.ajouter(combinaison2);

			Assert::IsTrue(combinaison2 == liste.getPremierNoeud()->getElement());
			Assert::AreEqual(2, liste.getNbElements());
			Assert::IsFalse(liste.isEmpty());

			delete combinaison1;
			delete combinaison2;
		}

		TEST_METHOD(ajouter_whenListContainsMultipleElements_shouldAddTheElementAtTheRightPlace)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			Combinaison* combinaison2 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			Combinaison* combinaison3 = new Combinaison(Couleur(3), Couleur(3), Couleur(3), Couleur(3));
			liste.ajouter(combinaison3);
			liste.ajouter(combinaison1);
			liste.ajouter(combinaison2);

			Assert::AreEqual(3, liste.getNbElements());
			Assert::IsFalse(liste.isEmpty());
			Assert::IsTrue(combinaison1 == liste.getPremierNoeud()->getElement());
			liste.retirer(liste.getPremierNoeud());
			Assert::IsTrue(combinaison2 == liste.getPremierNoeud()->getElement());
			liste.retirer(liste.getPremierNoeud());
			Assert::IsTrue(combinaison3 == liste.getPremierNoeud()->getElement());
			liste.retirer(liste.getPremierNoeud());

			delete combinaison1;
			delete combinaison2;
			delete combinaison3;
		}

		TEST_METHOD(ajouter_whenListContainsOneElement_shouldMaintainsReferenceNeighborhood)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison);

			Iterateur<Combinaison> current = liste.begin();
			Assert::IsTrue(current.getCourant()->getElement() == combinaison);
			Assert::IsTrue(current.getCourant()->getPrecedent() == nullptr);
			Assert::IsTrue(current.getCourant()->getSuivant() == nullptr);

			Assert::AreEqual(1, liste.getNbElements());
			Assert::IsFalse(liste.isEmpty());

			delete combinaison;
		}

		TEST_METHOD(ajouter_whenListContainsTwoElement_shouldMaintainsReferenceNeighborhood)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			Combinaison* combinaison2 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			liste.ajouter(combinaison1);
			liste.ajouter(combinaison2);

			Iterateur<Combinaison> current = liste.begin();
			Assert::IsTrue(current.getCourant()->getElement() == combinaison1);
			Assert::IsTrue(current.getCourant()->getPrecedent() == nullptr);
			Assert::IsTrue(current.getCourant()->getSuivant()->getElement() == combinaison2);
			++current;
			Assert::IsTrue(current.getCourant()->getElement() == combinaison2);
			Assert::IsTrue(current.getCourant()->getPrecedent()->getElement() == combinaison1);
			Assert::IsTrue(current.getCourant()->getSuivant() == nullptr);

			Assert::AreEqual(2, liste.getNbElements());
			Assert::IsFalse(liste.isEmpty());

			delete combinaison1;
			delete combinaison2;
		}

		TEST_METHOD(ajouter_whenListContainsMultipleElements_shouldMaintainsReferenceNeighborhood)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaisons[NB_COULEURS];
			for (int i = 1; i <= NB_COULEURS; i++)
			{
				combinaisons[i - 1] = new Combinaison(Couleur(i), Couleur(i), Couleur(i), Couleur(i));
				liste.ajouter(combinaisons[i - 1]);
			}

			Iterateur<Combinaison> current = liste.begin();
			Assert::IsTrue(combinaisons[0] == current.getCourant()->getElement());
			Assert::IsTrue(current.getCourant()->getSuivant()->getElement() == combinaisons[1]);
			++current;
			for (int i = 1; i < NB_COULEURS - 1; i++)
			{
				Assert::IsTrue(combinaisons[i - 1] == current.getCourant()->getPrecedent()->getElement());
				Assert::IsTrue(combinaisons[i] == current.getCourant()->getElement());
				Assert::IsTrue(combinaisons[i + 1] == current.getCourant()->getSuivant()->getElement());
				++current;
			}
			Assert::IsTrue(combinaisons[NB_COULEURS - 1] == current.getCourant()->getElement());
			Assert::IsTrue(current.getCourant()->getPrecedent()->getElement() == combinaisons[NB_COULEURS - 2]);
			Assert::AreEqual(NB_COULEURS, (unsigned)liste.getNbElements());
			for (int i = 0; i < NB_COULEURS; i++)
				delete combinaisons[i];
		}

		#pragma endregion

		#pragma region Tests de retirer()

		TEST_METHOD(retirer_whenListDoesNotContainTheNode_shouldReturnFalse)
		{
			ListeDouble<Combinaison> liste;
			Noeud<Combinaison>* noeud = new Noeud<Combinaison>();
			
			Assert::IsFalse(liste.retirer(noeud));
		}

		TEST_METHOD(retirer_whenListContainsOneElement_shouldRemoveTheElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison);
			
			liste.retirer(liste.getPremierNoeud());

			Assert::AreEqual(0, liste.getNbElements());
			Assert::IsTrue(liste.isEmpty());
			Assert::IsNull(liste.getPremierNoeud());
		}

		TEST_METHOD(retirer_whenListContainsMultipleElements_shouldRemoveTheRightElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			Combinaison* combinaison2 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison1);
			liste.ajouter(combinaison2);

			liste.retirer(liste.getPremierNoeud());

			Assert::AreEqual(1, liste.getNbElements());
			Assert::IsFalse(liste.isEmpty());
			Assert::IsTrue(combinaison1 == liste.getPremierNoeud()->getElement());
		}

		#pragma endregion

		#pragma region Tests de begin()
		TEST_METHOD(begin_whenListIsEmpty_shouldReturnEnd)
		{
			ListeDouble<Combinaison> liste;

			Assert::IsTrue(liste.begin() == liste.end());
			Assert::IsNull(liste.begin().getCourant());
		}

		TEST_METHOD(begin_whenListContainsOneElement_shouldNotReturnEnd)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));

			liste.ajouter(combinaison);

			Assert::IsTrue(liste.begin() != liste.end());
			Assert::IsNotNull(liste.begin().getCourant());
			Assert::IsTrue(liste.begin().getCourant() == liste.getPremierNoeud());

			delete combinaison;
		}

		#pragma endregion

		#pragma region Test de end()

		TEST_METHOD(end_shouldReturnNull)
		{
			ListeDouble<Combinaison> liste;

			Assert::IsNull(liste.end().getCourant());
		}

		#pragma endregion

		#pragma region Tests de getElement()
		
		TEST_METHOD(getElement_whenListIsEmpty_shouldReturnNull)
		{
			ListeDouble<Combinaison> liste;

			Assert::IsNull(liste.getElement(0));
		}
		
		TEST_METHOD(getElement_whenListContainsOneElement_shouldReturnTheElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison);

			Assert::IsTrue(combinaison == liste.getElement(0));

			delete combinaison;
		}

		TEST_METHOD(getElement_whenListContainsMultipleElements_shouldReturnTheGoodElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			Combinaison* combinaison2 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			liste.ajouter(combinaison1);
			liste.ajouter(combinaison2);

			Assert::IsTrue(combinaison1 == liste.getElement(0));
			Assert::IsTrue(combinaison2 == liste.getElement(1));

			delete combinaison1;
			delete combinaison2;
		}

		TEST_METHOD(getElement_whenAnElementIsRemovedFromTheList_shouldReturnNull)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			liste.ajouter(combinaison);
			liste.retirer(liste.getPremierNoeud());

			Assert::IsNull(liste.getElement(0));

			delete combinaison;
		}

		TEST_METHOD(getElement_whenAnElementIsRemovedFromTheList_shouldReturnTheGoodElement)
		{
			ListeDouble<Combinaison> liste;
			Combinaison* combinaison1 = new Combinaison(Couleur(1), Couleur(1), Couleur(1), Couleur(1));
			Combinaison* combinaison2 = new Combinaison(Couleur(2), Couleur(2), Couleur(2), Couleur(2));
			liste.ajouter(combinaison1);
			liste.ajouter(combinaison2);
			liste.retirer(liste.getPremierNoeud());

			Assert::IsTrue(combinaison2 == liste.getElement(0));

			delete combinaison1;
			delete combinaison2;
		}
		
		#pragma endregion
	};
}
