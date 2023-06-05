#include "ChooseGamemodeMenu.h"


ChooseGamemodeMenu::ChooseGamemodeMenu(int w, int h, sf::RenderWindow* win)
	: MenuElement(w, h, win)
{
	font_size = height / 18;
	x_pos = width / 10;
	y_pos_unit = height / (2 * (buttons_number + 1));

	buttons_number = 4;
	buttons.resize(4);
	setButtons();

	selectedButtonIndex = 0;

	sf::Text return_button;
	buttons.push_back(return_button);

	buttons[0].setString("Easy Mode");
	buttons[1].setString("Normal Mode");
	buttons[2].setString("Hard Mode");
	buttons[3].setString("Return");
}

void ChooseGamemodeMenu::enterKeyAction()
{
	switch (selectedButtonIndex)
	{
	case 0:
		easyModeButtonAction();
		break;

	case 1:
		normalModeButtonAction();
		break;

	case 2:
		hardModeButtonAction();
		break;

	case 3:
		returnButtonAction();
		break;
	}
}

void ChooseGamemodeMenu::easyModeButtonAction()
{
	Player p(playerName);
	GameInterface* game_ptr = new EasyGame;
	game_ptr->playGame(p);
}

void ChooseGamemodeMenu::normalModeButtonAction()
{
	Player p(playerName);
	GameInterface* game_ptr = new MediumGame;
	game_ptr->playGame(p);

}

void ChooseGamemodeMenu::hardModeButtonAction()
{
	Player p(playerName);
	GameInterface* game_ptr = new HardGame;
	game_ptr->playGame(p);

}

void ChooseGamemodeMenu::returnButtonAction()
{
	return_pressed = true;
}

bool ChooseGamemodeMenu::returnButtonPressed()
{
	return return_pressed;
}

void ChooseGamemodeMenu::run()
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
