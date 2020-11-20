#include "stdafx.h"
#include "CppUnitTest.h"
#include "ListeDouble.h"
#include "Combinaison.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests_Liste_Double
{		
	TEST_CLASS(Liste_Double)
	{
		TEST_METHOD(getPremierNoeud_whenListIsEmpty_shouldReturnNull)
		{
			ListeDouble<Combinaison> liste;
			
			Assert::IsNull(liste.getPremierNoeud());
		}
	};
}