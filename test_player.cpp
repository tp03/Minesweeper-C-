#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cassert>
#include "../saper/player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayerTest
{
    TEST_CLASS(PlayerTestClass)
    {
    public:
        TEST_METHOD(GetName)
        {
            Player player("John");
            Assert::AreEqual(player.getName(), std::string("John"));
        }

        TEST_METHOD(GetScore)
        {
            Player player("John");
            Assert::AreEqual(player.getScore(), 0);
        }

        TEST_METHOD(IncreaseScore)
        {
            Player player("John");
            player.increaseScore(10);
            Assert::AreEqual(player.getScore(), 10);

            player.increaseScore(5);
            Assert::AreEqual(player.getScore(), 15);
        }

        TEST_METHOD(ResetScore)
        {
            Player player("John");
            player.increaseScore(10);
            player.resetScore();
            Assert::AreEqual(player.getScore(), 0);
        }

        TEST_METHOD(SetScore)
        {
            Player player("John");
            player.setScore(100);
            Assert::AreEqual(player.getScore(), 100);

            player.setScore(50);
            Assert::AreEqual(player.getScore(), 50);
        }
    };
}
