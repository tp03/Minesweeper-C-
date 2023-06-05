#include "StartMenu.h"


StartMenu::StartMenu(int w, int h, sf::RenderWindow* win)
	: MenuElement(w, h, win)
{
	font_size = height / 12;
	x_pos = width / 10;
	y_pos_unit = height / (2 * buttons_number);

	setButtons();

	selectedButtonIndex = 0;

	buttons[0].setString("Play");
	buttons[1].setString("Ranking");
	buttons[2].setString("Exit");
}

void StartMenu::enterKeyAction()
{
	switch (selectedButtonIndex)
	{
	case 0:
		playButtonAction();
		break;

	case 1:
		rankingButtonAction();
		break;

	case 2:
		exitButtonAction();
		break;
	}
}

void StartMenu::playButtonAction()
{
	ChooseGameMenu* choose_game_menu;
	choose_game_menu = new ChooseGameMenu(width, height, window);
	choose_game_menu->setPlayerName(playerName);

	while (!choose_game_menu->returnButtonPressed())
	{
		choose_game_menu->run();
	}

	delete choose_game_menu;
}

void StartMenu::rankingButtonAction()
{
	int index = 0;
	int modes_number = 3;

	std::vector <Ranking*> rankings{ 3 };
	std::vector <RankingHUD*> HUDs{ 3 };
	for (int i = 0; i < modes_number; ++i)
	{
		std::string file_name = "scores" + std::to_string(i) + ".txt";
		rankings[i] = new Ranking{ width, height, window, file_name };
		HUDs[i] = new RankingHUD(width, height, window, file_name);
	}

	while (!rankings[index]->escapeKeyClicked())
	{
		window->clear();

		HUDs[index]->run();
		rankings[index]->run();

		window->display();

		if (rankings[index]->rightKeyClicked())
		{
			index = (index + 1) % modes_number;
		}
		else if (rankings[index]->leftKeyClicked())
		{
			index = (index + modes_number - 1) % modes_number;
		}
	}

	for (int i = 0; i < rankings.size(); ++i)
	{
		delete rankings[i];
		delete HUDs[i];
	}
}

void StartMenu::exitButtonAction()
{
	window->close();
}

void StartMenu::run()
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
