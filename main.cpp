#include <..\SFML\Graphics.hpp>
#include "nameInputWindow.h"
#include <string>

int main()
{
    sf::RenderWindow window{ sf::VideoMode{1000, 600}, "Minesweeper" };
    sf::RenderWindow* window_pointer;
    window_pointer = &window;
    MenuElement* name_input = new nameInputWindow(window.getSize().x, window.getSize().y, window_pointer);

    while (window.isOpen())
    {
        name_input->run();
    }

    return 0;
}