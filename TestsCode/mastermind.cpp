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

		TEST_METHOD(Test)
		{

		}

		#pragma endregion
	};
}
