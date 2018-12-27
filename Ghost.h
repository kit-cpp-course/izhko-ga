#pragma once
#include "Alive.h"
class Ghost : public Alive
{  
	sf::Vector2f TempVec;
	bool turn;
	bool Povorot; 
	float lenght; 
public:
	Ghost(float _Speed, sf::Color Col, float _radius, sf::Vector2f _startPosition);
	void Update(sf::RenderWindow *window, float PacX, float PacY, bool *live);
	void Restart();
	sf::CircleShape returnSpriteGhost();
	float _Length(float x1, float y1, float x2, float y2);
	void Environment(float PacX, float PacY, int PlusX, int PlusY, int VectX, int VectY);
};

