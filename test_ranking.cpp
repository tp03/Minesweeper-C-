#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cassert>
#include <..\SFML\Graphics.hpp>
#include "Ranking.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RankingTest
{
    TEST_CLASS(RankingTestClass)
    {
    public:
        TEST_METHOD(rightKeyAction)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            Ranking ranking(window.getSize().x, window.getSize().y, window_pointer);
            ranking.rightKeyAction();

            Assert::AreEqual(ranking.rightKeyClicked(), true);
        }

        TEST_METHOD(leftKeyAction)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            Ranking ranking(window.getSize().x, window.getSize().y, window_pointer);
            ranking.leftKeyAction();

            Assert::AreEqual(ranking.leftKeyClicked(), true);
        }

        TEST_METHOD(escapeKeyAction)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            Ranking ranking(window.getSize().x, window.getSize().y, window_pointer);
            ranking.escapeKeyAction();

            Assert::AreEqual(ranking.escapeKeyClicked(), true);
        }
    };
}
