#include "ChooseGameMenu.h"


ChooseGameMenu::ChooseGameMenu(int w, int h, sf::RenderWindow* win)
	: MenuElement(w, h, win)
{
	font_size = height / 18;
	x_pos = width / 10;
	y_pos_unit = height / (2 * buttons_number);

	setButtons();

	selectedButtonIndex = 0;

	buttons[0].setString("New Game");
	buttons[1].setString("Saved Game");
	buttons[2].setString("Return");
}

void ChooseGameMenu::enterKeyAction()
{
	switch (selectedButtonIndex)
	{
	case 0:
		newGameButtonAction();
		break;

	case 1:
		savedGameButtonAction();
		break;

	case 2:
		returnButtonAction();
		break;
	}
}

void ChooseGameMenu::newGameButtonAction()
{
	ChooseGamemodeMenu* choose_gamemode_menu;
	choose_gamemode_menu = new ChooseGamemodeMenu(width, height, window);
	choose_gamemode_menu->setPlayerName(playerName);

	while (!choose_gamemode_menu->returnButtonPressed())
	{
		choose_gamemode_menu->run();
	}

	delete choose_gamemode_menu;
}

void ChooseGameMenu::savedGameButtonAction()
{
	Player p(playerName);
	GameInterface* game_ptr = new LoadedGame;
	game_ptr->playGame(p);
}

void ChooseGameMenu::returnButtonAction()
{
	return_pressed = true;
}

bool ChooseGameMenu::returnButtonPressed()
{
	return return_pressed;
}

void ChooseGameMenu::run()
{
	sf::Event event;

	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				upKeyAction();
				break;

			case sf::Keyboard::Down:
				downKeyAction();
				break;

			case sf::Keyboard::Enter:
				enterKeyAction();
				break;
			}
		}
		else if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	draw();
}
