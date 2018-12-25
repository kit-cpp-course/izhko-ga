#pragma once

class Alive
{
	float Speed;
	float Radius;
	sf::CircleShape Shape;
	sf::Vector2f StartPosition;
	sf::Vector2f Direction;
public: 
	Alive(float _Speed, float _Radius, sf::Color Col, sf::Vector2f StartPosition);
	~Alive();
	bool CheckWall(const std::string strMap[],  int x, int y); //ѕроверка на столкновение со стенкой
	bool CheckWall(const std::string strMap[], float PosX, float PosY,int x, int y);
	bool CheckAbsoluteWall(const std::string strMap[], float PosX, float PosY, int radius, int x, int y);
	bool CheckNoWall(const std::string  strMap[], float PosX, float PosY, int radius, int x, int y);
	sf::CircleShape ReturnShape() { return Shape; };
	sf::Vector2f ReturnDirection() { return Direction; };
	void ChangeStartPosition() { Shape.setPosition(StartPosition); };
	void ChangeDir(float x, float y) { Direction = sf::Vector2f(x, y); };
	void moveShape(sf::Vector2f _Direction) { Shape.move(_Direction*Speed); };
	void RestartAlive() { Shape.setPosition(StartPosition); };
	float ExactPositionX() { return Shape.getPosition().x; };
	float ExactPositionY() { return Shape.getPosition().y; };
	float ReturnRadius() { return Radius; };
	float ReturnSpeed() { return Speed; };
	
	sf::Vector2f ReturnStartPosition() { return StartPosition; };
};
