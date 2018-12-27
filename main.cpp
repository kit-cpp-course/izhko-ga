#include "stdafx.h" 

int main()
{  
	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf"); 
	sf::RenderWindow window(sf::VideoMode(480, 480), "Pac_man"); 
	Menu GameMenu = Menu(); 
	while (window.isOpen())
	{  
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || GameMenu.ForExit() || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
		}  
		window.clear();
		switch (GameMenu.Stat())
		{
		case Start:
			GameMenu.StartMenu(&window);
			break;
		case Game:
			GameMenu.StartGame(&window);
			break;
		case Death:
			GameMenu.DeathGame(&window);
			break;
		case Win:
			GameMenu.WinGame(&window);
			break;
		default:
			break;
		}  
		window.display();
	}
	return 0;
}