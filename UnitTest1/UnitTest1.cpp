#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1(char).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountFunction)
		{
			char str[] = "a+b-c=d++e--f==";
			int countPlus = 0, countMinus = 0, countEqual = 0;

			Count(str, countPlus, countMinus, countEqual);

			Assert::AreEqual(3, countPlus);   // Має бути 3 символи '+'
			Assert::AreEqual(3, countMinus);  // Має бути 3 символи '-'
			Assert::AreEqual(3, countEqual);  // Має бути 3 символи '='
		}

		TEST_METHOD(TestChangeFunction)
		{
			char str[] = "a+b-c==d++e--f==";
			char expected[] = "a+b-c***d***e***f***";

			char* result = Change(str);

			Assert::AreEqual(expected, result); // Перевіряємо, чи результат співпадає з очікуваним

			delete[] result; // Видаляємо динамічну пам'ять, виділену у функції Change
		}
	};
}
