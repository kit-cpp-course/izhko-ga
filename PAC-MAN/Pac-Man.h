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
	sf::CircleShape PacManSh(); //���������� ���� ( �������, ��� �������������� � ��� �����)
	void movePacMan(); // ������� ������� �� Direction
	void movePacMan(float X, float Y); // ������� �� ������ ���-�� ��������
	void movePacMan(sf::Vector2f _Direction); // ������� �� ������ ���-�� ��������
	void Update(char ** strMap); //����� ������� ��������� ������� 
	void Restart(); 
	bool CheckFood(char ** strMap); //�������� �� ������������ � ���� 
 
	int Score();

	~PacMan();
};