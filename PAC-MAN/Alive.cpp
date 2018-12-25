#include "stdafx.h"

Alive::Alive(float _Speed, float _Radius, sf::Color Col, sf::Vector2f _StartPosition): 
	Speed(_Speed), 
	Radius(_Radius), 
	Shape(sf::CircleShape(_Radius))
{
	StartPosition = _StartPosition;
	Shape.setPosition(_StartPosition);
	Shape.setFillColor(Col);
}

bool Alive::CheckWall(const std::string  strMap[], int x, int y)
{
	return !(strMap[(int)(Shape.getPosition().y + y) / 20][(int)(Shape.getPosition().x + x) / 20] == '0' || strMap[(int)(Shape.getPosition().y + y + Radius * 2) / 20][(int)(Shape.getPosition().x + x + Radius * 2) / 20] == '0' || strMap[(int)(Shape.getPosition().y + y) / 20][(int)(Shape.getPosition().x + x + Radius * 2) / 20] == '0' || strMap[(int)(Shape.getPosition().y + y + Radius * 2) / 20][(int)(Shape.getPosition().x + x) / 20] == '0');

}

bool Alive::CheckWall(const std::string  strMap[], float PosX, float PosY, int x, int y)
{
	return !(strMap[(int)(PosY + y) / 20][(int)(PosX + x) / 20] == '0' || strMap[(int)(PosY + y + Radius * 2) / 20][(int)(PosX + x + Radius * 2) / 20] == '0' || strMap[(int)(PosY + y) / 20][(int)(PosX + x + Radius * 2) / 20] == '0' || strMap[(int)(PosY + y + Radius * 2) / 20][(int)(PosX + x) / 20] == '0');

}

bool Alive::CheckNoWall(const std::string  strMap[], float PosX, float PosY, int radius, int x, int y)
{
	return strMap[(int)(PosY + y) / 20][(int)(PosX + x) / 20] != '0' && strMap[(int)(PosY + y + radius * 2) / 20][(int)(PosX + x + radius * 2) / 20] != '0' && strMap[(int)(PosY + y) / 20][(int)(PosX + x + radius * 2) / 20] != '0' && strMap[(int)(PosY + y + radius * 2) / 20][(int)(PosX + x) / 20] != '0';

}

bool Alive::CheckAbsoluteWall(const std::string  strMap[], float PosX, float PosY, int radius, int x, int y)
{
	return !(strMap[(int)(PosY + y) / 20][(int)(PosX + x) / 20] == '0' && strMap[(int)(PosY + y + radius * 2) / 20][(int)(PosX + x + radius * 2) / 20] == '0' && strMap[(int)(PosY + y) / 20][(int)(PosX + x + radius * 2) / 20] == '0' && strMap[(int)(PosY + y + radius * 2) / 20][(int)(PosX + x) / 20] == '0');
}

Alive::~Alive()
{
}
