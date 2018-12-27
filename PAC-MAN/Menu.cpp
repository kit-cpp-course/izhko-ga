#include "stdafx.h"
#include <sstream> 

Menu::Menu() : 
	Menu::PacMan::PacMan(1.f,9.f, 201, 201),
	Menu::MapPacMan::MapPacMan()
{
	font.loadFromFile("CyrilicOld.ttf");
	TextScore.setPosition(10, 10);
}

Menu::~Menu()
{
	delete Red1;
	delete Red2;
	delete Red3;
	delete Red4;
}

void Menu::restartGame()
{
	PacMan::Restart();
	LivePacMan = true;
	Red1->Restart();
	Red2->Restart();
	Red3->Restart();
	Red4->Restart();
	MapPacMan::Restart();
}

void Menu::StartMenu(sf::RenderWindow *window)
{
	sf::Text text1("Добро пожаловать в клон Pac-Man", font, 30);
	text1.setPosition(sf::Vector2f(10, 150));
	window->draw(text1);
	Button StartGameButton(200, 20, sf::Vector2f(120, 205), "Начало игры");
	sf::Text text2(StartGameButton.returnText(), font, 20);
	text2.setPosition(sf::Vector2f(160, 200));
	text2.setFillColor(sf::Color::Black);
	window->draw(StartGameButton.ShapeButton());
	
	Button EndGameButton(200, 20, sf::Vector2f(120, 255), "Выход");
	sf::Text text3(EndGameButton.returnText(), font, 20);
	text3.setPosition(sf::Vector2f(190, 250));
	text3.setFillColor(sf::Color::Black);
	window->draw(EndGameButton.ShapeButton());
	window->draw(text3);


	window->draw(text2);
	
	if (StartGameButton.CheckMouse(window))
	{
		restartGame();
		StatGame = Game;
	}

	if (EndGameButton.CheckMouse(window))
	{
		Exit = true;
	}
}

void Menu::StartGame(sf::RenderWindow *window)
{
	
	PacMan::Update(MapPacMan::returnValue());
	MapPacMan::Update(window);
	Red1->Update(window, PacMan::ReturnShape().getPosition().x, PacMan::ReturnShape().getPosition().y, &LivePacMan);
	Red2->Update(window, PacMan::ReturnShape().getPosition().x, PacMan::ReturnShape().getPosition().y, &LivePacMan);
	Red3->Update(window, PacMan::ReturnShape().getPosition().x, PacMan::ReturnShape().getPosition().y, &LivePacMan);
	Red4->Update(window, PacMan::ReturnShape().getPosition().x, PacMan::ReturnShape().getPosition().y, &LivePacMan);
	std::ostringstream Score;
	Score << PacMan::Score();
	TextScore.setString("Score: " + Score.str() + "/186");
	window->draw(TextScore);
	window->draw(PacMan::ReturnShape()); 
	if (PacMan::Score() == 186) StatGame = Win;
	if (!LivePacMan) StatGame = Death;
}

void Menu::DeathGame(sf::RenderWindow *window)
{
	sf::Text text1("Печально, но вы УМЕРЛИ", font, 30);
	text1.setPosition(sf::Vector2f(100, 150));
	window->draw(text1);
	Button StartMenuButton(200, 20, sf::Vector2f(120, 235), "В главное меню");
	sf::Text text2(StartMenuButton.returnText(), font, 20);
	text2.setPosition(sf::Vector2f(160, 230));
	text2.setFillColor(sf::Color::Black);
	window->draw(StartMenuButton.ShapeButton());

	window->draw(text2);

	if (StartMenuButton.CheckMouse(window))
	{
		StatGame = Start;
	}

}

void Menu::WinGame(sf::RenderWindow *window)
{
	sf::Text text1("Поздравляю, ВЫ ПОБЕДИЛИ!!!", font, 30);
	text1.setPosition(sf::Vector2f(10, 150));
	window->draw(text1);
	Button StartMenuButton(200, 20, sf::Vector2f(120, 235), "В главное меню");
	sf::Text text2(StartMenuButton.returnText(), font, 20);
	text2.setPosition(sf::Vector2f(160, 230));
	text2.setFillColor(sf::Color::Black);
	window->draw(StartMenuButton.ShapeButton());
	   
	window->draw(text2);

	if (StartMenuButton.CheckMouse(window))
	{
		StatGame = Start;
	}
	 
}