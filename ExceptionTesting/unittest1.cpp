#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"
#include "stdexcept"
#include <fstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExceptionTesting
{		
	TEST_CLASS(READINT_TEST)
	{
	public:
		TEST_METHOD(TestCase1)
		{
			std::ifstream ss("C:\\Users\\yfedas21\\Documents\\VS Projects YF\\Assignment3_Exceptions\\ExceptionTesting\\testcase1.txt");

			if (ss.fail())
				throw int(-1);

			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);
			ss.close();
		}

		TEST_METHOD(TestCase2)
		{
			auto func = []() {
				read_int("My prompt: ", 5, 1);
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestCase3)
		{
			std::ifstream ss("C:\\Users\\yfedas21\\Documents\\VS Projects YF\\Assignment3_Exceptions\\ExceptionTesting\\testcase3.txt");

			if (ss.fail())
				throw int(-1);

			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);
			ss.close();
		}

		TEST_METHOD(TestCase4)
		{
			auto func = []() {
				read_int("My prompt: ", 0, 0);
			};
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}