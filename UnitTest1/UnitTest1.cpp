#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2-i/7.2-i.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62
{
	TEST_CLASS(UnitTest62)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int s[1] = { 1 };
			int** a = new int* [1];
			for (int i = 0; i < 1; i++)
				a[i] = new int[1];
			Create(a, 1, 1, 1);
			int mininEven = 1;
			int t = SearchMini(a, 1, mininEven);
			Assert::AreEqual(t, 0);

		}
	};
}
