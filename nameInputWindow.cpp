#include "nameInputWindow.h"

nameInputWindow::nameInputWindow(int w, int h, sf::RenderWindow* win)
    : MenuElement(w, h, win)
{
    buttons_number = 2;
    font_size = height / 12;
    x_pos = width / 10;
    y_pos_unit = height / (2 * buttons_number);

    setButtons();
    selectedButtonIndex = 0;
    buttons[0].setString("Input name:");
    buttons[1].setString(" ");

    start_menu = new StartMenu(width, height, window);
}

void nameInputWindow::run()
{
    sf::Event event;

    sf::Time elapsed = cursorClock.getElapsedTime();
    if (elapsed.asSeconds() >= 0.5f) {
        showCursor = !showCursor;
        cursorClock.restart();
    }
    if (showCursor) {
        std::string stdString = buttons[1].getString().toAnsiString();
        if (!stdString.empty()) {
            stdString.back() = '|';
            buttons[1].setString(stdString);
        }
    }
    else
    {
        std::string stdString = buttons[1].getString().toAnsiString();
        if (!stdString.empty()) {
            stdString.back() = ' ';
            buttons[1].setString(stdString);
        }
    }
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode < 128)
            {
                if (event.text.unicode == '\b' && !playerName.empty())
                {
                    playerName.pop_back();
                }
                else if (event.text.unicode != '\b')
                {
                    playerName += static_cast<char>(event.text.unicode);
                }
                buttons[1].setString(playerName + " ");
            }
        }
        if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                StartMenu* start_menu;
                start_menu = new StartMenu(width, height, window);
                start_menu->setPlayerName(playerName);
                while (window->isOpen())
                {
                    start_menu->run();
                }
            }
        }
        if (event.type == sf::Event::Closed)
        {
            window->close();
        }
    }
    draw();
}
