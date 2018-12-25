#include "stdafx.h"

Ghost::Ghost(float _Speed,sf::Color Col, float _radius, sf::Vector2f _startPosition) :
	Ghost::Alive::Alive(_Speed,_radius,Col,_startPosition) 
{ 
	turn = true;
	Povorot = true;
	lenght = 9999;
}


void Ghost::Update(sf::RenderWindow *window, float PacX, float PacY, bool *live)
{
	
	int i = 0;
	if (((float)((int)ReturnShape().getPosition().x / 20)) && ((float)((int)ReturnShape().getPosition().y / 20)))
	{
		if (!CheckWall(constMap, ReturnShape().getPosition().x, ReturnShape().getPosition().y, 0, 20)) i++;
		if (!CheckWall(constMap, ReturnShape().getPosition().x, ReturnShape().getPosition().y, 0, -20))  i++;
		if (!CheckWall(constMap, ReturnShape().getPosition().x, ReturnShape().getPosition().y, 20, 0))  i++;
		if (!CheckWall(constMap, ReturnShape().getPosition().x, ReturnShape().getPosition().y, -20, 0))  i++;
		if (i >= 2) Povorot = true;

		if (i <= 1 && Povorot)
		{
			turn = true;
			Povorot = false;
		}
	}
	if (turn)
	{
		std::cout << "1";
		TempVec = ReturnDirection();
		if (ReturnDirection().x == 0)
		{
			Environment(PacX, PacY, 20 * ReturnDirection().x, 20 * ReturnDirection().y, ReturnDirection().x, ReturnDirection().y);
			Environment(PacX, PacY, 20, 0, 1, 0);
			Environment(PacX, PacY, -20, 0, -1, 0);
		}
		else if (ReturnDirection().y == 0)
		{
			Environment(PacX, PacY, 20 * ReturnDirection().x, 20 * ReturnDirection().y, ReturnDirection().x, ReturnDirection().y);
			Environment(PacX, PacY, 0, 20, 0, 1);
			Environment(PacX, PacY, 0, -20, 0, -1);
		}
		lenght = 9999;
		turn = false;
		moveShape(ReturnDirection());
		if (!(CheckWall(constMap, 0, 0)))
		{
			moveShape(-ReturnDirection());
			ChangeDir(TempVec.x,TempVec.y);
			moveShape(ReturnDirection());
		}
		
	}
	else
	{
		moveShape(ReturnDirection());
	}

	if (!(CheckWall(constMap, 0, 0)))
	{
		moveShape(-ReturnDirection());
		turn = true;
	}
	if ((int)ReturnShape().getPosition().x - (int)PacX < 3 && (int)ReturnShape().getPosition().x - (int)PacX > -3 && (int)ReturnShape().getPosition().y - (int)PacY < 3 && (int)ReturnShape().getPosition().y - (int)PacY> -3)
	{ 
		*live = false;
	} 
	if (ReturnDirection().x == 0 && ReturnDirection().y == 0) ChangeDir(TempVec.x, TempVec.y);
	window->draw(ReturnShape());
}

sf::CircleShape Ghost::returnSpriteGhost() { return ReturnShape(); }

float Ghost::_Length(float x1, float y1, float x2, float y2)
{
	return std::sqrtf((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

void Ghost::Environment(float PacX, float PacY, int PlusX, int PlusY, int VectX, int VectY)
{
	if (CheckWall(constMap, ReturnShape().getPosition().x, ReturnShape().getPosition().y, PlusX, PlusY) && CheckWall(constMap, ReturnShape().getPosition().x, ReturnShape().getPosition().y, VectX,VectY))
	{
		if (lenght > _Length(ReturnShape().getPosition().x + PlusX, ReturnShape().getPosition().y + PlusY, PacX , PacY))
		{
			lenght = _Length(ReturnShape().getPosition().x + PlusX, ReturnShape().getPosition().y + PlusY, PacX, PacY);
			ChangeDir(VectX, VectY);
		}
	}
}

void Ghost::Restart()
{
	RestartAlive();
}