#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cassert>
#include <..\SFML\Graphics.hpp>
#include "MenuElement.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MenuElementTest
{
    TEST_CLASS(MenuElementTestClass)
    {
    public:
        TEST_METHOD(getWidth)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            MenuElement menu_element(window.getSize().x, window.getSize().y, window_pointer);
            
            Assert::AreEqual(menu_element.getWidth(), 1000);
        }

        TEST_METHOD(getHeight)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            MenuElement menu_element(window.getSize().x, window.getSize().y, window_pointer);
            
            Assert::AreEqual(menu_element.getHeight(), 600);
        }

        TEST_METHOD(getButtonsNumber)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            MenuElement menu_element(window.getSize().x, window.getSize().y, window_pointer);
            
            Assert::AreEqual(menu_element.getButtonsNumber(), 3);
        }

        TEST_METHOD(upKeyAction)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            StartMenu start_menu(window.getSize().x, window.getSize().y, window_pointer);
            start_menu.upKeyAction();

            Assert::AreEqual(start_menu.getSelectedButtonIndex(), 1);
        }

        TEST_METHOD(downKeyAction)
        {
            sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
            sf::RenderWindow* window_pointer;
            window_pointer = &window;
            StartMenu start_menu(window.getSize().x, window.getSize().y, window_pointer);
            start_menu.downKeyAction();

            Assert::AreEqual(start_menu.getSelectedButtonIndex(), 0);
        }
    };
}
