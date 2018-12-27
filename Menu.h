#pragma once

enum Stat {Start,Game,Death,Win};
class Menu : public PacMan, public MapPacMan
{
	bool LivePacMan = true;
	int StatGame = Start;
	sf::Font font;
	bool Exit = false;
	sf::Text TextScore = sf::Text("Score: ", font, 20);  
	Ghost *Red1 = new Ghost(0.7f, sf::Color::Red, 9, sf::Vector2f(440, 440));
	Ghost *Red2 = new Ghost(0.7f, sf::Color::Red, 9, sf::Vector2f(40, 40));
	Ghost *Red3 = new Ghost(0.7f, sf::Color::Red, 9, sf::Vector2f(440, 40));
	Ghost *Red4 = new Ghost(0.7f, sf::Color::Red, 9, sf::Vector2f(40, 440));
public:
	Menu();
	~Menu();
	void restartGame();
	void StartMenu(sf::RenderWindow *window);
	void StartGame(sf::RenderWindow *window);
	void DeathGame(sf::RenderWindow *window);
	void WinGame(sf::RenderWindow *window);
	void StatDeathGame() { StatGame = Death; };
	bool ForExit() { return Exit; };
	int Stat() { return StatGame; };

};

