#include "nameInputWindow.h"

nameInputWindow::nameInputWindow(int w, int h, sf::RenderWindow* win)
	: MenuElement(w, h, win)
{
    buttons_number = 1;
	font_size = height / 12;
	x_pos = width / 10;
	y_pos_unit = height / (2 * buttons_number);

	setButtons();
	selectedButtonIndex = 0;

}

void nameInputWindow::run()
{
	sf::Event event;
    StartMenu* start_menu;
	start_menu = new start_menu(width, height, window);

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b' && !playerName.empty()) {
                playerName.pop_back();
            }
            else if (event.text.unicode == '\r' || event.text.unicode == '\n') {
                window->close();
                start_menu->run();
            }
            else {
                playerName += static_cast<char>(event.text.unicode);
            }
            buttons[0].setString(playerName);
        }
	}
	draw();
}