#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cassert>
#include <..\SFML\Graphics.hpp>
#include "StartMenu.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StartMenuTest
{
    TEST_CLASS(StartMenuTestClass)
    {
    public:
        TEST_METHOD(getFontSize)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            StartMenu start_menu(window.getSize().x, window.getSize().y, window_pointer);

            Assert::AreEqual(start_menu.getFontSize(), 50);
        }

        TEST_METHOD(getXPos)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            StartMenu start_menu(window.getSize().x, window.getSize().y, window_pointer);

            Assert::AreEqual(start_menu.getXPos(), 100);
        }

        TEST_METHOD(getYPosUnit)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            StartMenu start_menu(window.getSize().x, window.getSize().y, window_pointer);

            Assert::AreEqual(start_menu.getYPosUnit(), 100);
        }
    };
}
