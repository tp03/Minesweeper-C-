#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cassert>
#include "../saper/Board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace testhistogram
{
	TEST_CLASS(testhistogram)
	{
	public:

		TEST_METHOD(flagged1)
		{
			Board b1(5, 5, 5);
			b1.flagCell(2, 2);
			Assert::AreEqual(b1.isCellFlag(2, 2), true);
		}

		TEST_METHOD(flagged2)
		{
			Board b1(10, 10, 5);
			b1.flagCell(5, 5);
			Assert::AreEqual(b1.isCellFlag(5, 5), true);
		}

		TEST_METHOD(unflagged1)
		{
			Board b1(5, 5, 5);
			b1.unflagCell(5, 5);
			Assert::AreEqual(b1.isCellFlag(5, 5), false);
		}

		TEST_METHOD(open1)
		{
			Board b1(5, 5, 5);
			b1.openCell(5, 5);
			Assert::AreEqual(b1.isCellOpen(5, 5), true);
		}

		TEST_METHOD(open2)
		{
			Board b1(5, 5, 5);
			b1.openCell(1, 1);
			Assert::AreEqual(b1.isCellOpen(5, 5), false);
		}

		TEST_METHOD(width1)
		{
			Board b1(5, 10, 5);
			Assert::AreEqual(b1.getWidth(), 10);
		}

		TEST_METHOD(width2)
		{
			Board b1(2, 10, 5);
			Assert::AreEqual(b1.getWidth(), 2);
		}

		TEST_METHOD(height1)
		{
			Board b1(5, 8, 5);
			Assert::AreEqual(b1.getHeight(), 5);
		}

		TEST_METHOD(height2)
		{
			Board b1(5, 2, 5);
			Assert::AreEqual(b1.getHeight(), 2);
		}

		TEST_METHOD(numMines1)
		{
			Board b1(5, 2, 5);
			Assert::AreEqual(b1.getNumMines(), 5);
		}

		TEST_METHOD(numMines2)
		{
			Board b1(5, 2, 1);
			Assert::AreEqual(b1.getNumMines(), 1);
		}

	};
}
