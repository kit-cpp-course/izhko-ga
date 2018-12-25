#pragma once 
#include "Alive.h"
class PacMan : public Alive
{
	 
	int _Score = 0;
	int MaxScore = 186; 
	sf::Vector2f PastDirection = sf::Vector2f(0, 0);
	sf::Text TextScore;
public:
	PacMan(float _speed, float _radius, int x, int y); 
	sf::Text  ScoreText();
	sf::CircleShape PacManSh(); //возвращает круг ( пакмена, его местоположение и так далее)
	void movePacMan(); // двигает пакмена на Direction
	void movePacMan(float X, float Y); // двигает на нужное кол-во кординат
	void movePacMan(sf::Vector2f _Direction); // двигает на нужное кол-во кординат
	void Update(char ** strMap); //Общая функция изменения Пакмена 
	void Restart(); 
	bool CheckFood(char ** strMap); //Проверка на столкновение с едой 
 
	int Score();

	~PacMan();
};