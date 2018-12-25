#include "stdafx.h" 
PacMan::PacMan(float _speed, float _radius, int x, int y) : PacMan::Alive::Alive(_speed, _radius, sf::Color::Yellow, sf::Vector2f(x,y) )
{  
	sf::Font font;
	font.loadFromFile("CyrilicOld.ttf");
	TextScore= sf::Text("Score: ", font, 20);
	TextScore.setPosition(10, 10);
}; 

sf::CircleShape PacMan::PacManSh() { return PacMan::Alive::ReturnShape(); };
sf::Text  PacMan::ScoreText() { return TextScore; };
void PacMan::movePacMan()
{
	PacMan::Alive::ReturnShape().move(PacMan::Alive::ReturnDirection());
}
void PacMan::movePacMan(float X, float Y)
{
	PacMan::Alive::ReturnShape().move(X, Y);
}
void PacMan::movePacMan(sf::Vector2f _Direction)
{
	PacMan::Alive::ReturnShape().move(_Direction);
}

void PacMan::Update(char ** strMap)
{ 
	CheckFood(strMap);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		PacMan::Alive::ChangeDir(-1, 0); 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		PacMan::Alive::ChangeDir(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		PacMan::Alive::ChangeDir(0,-1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		PacMan::Alive::ChangeDir(0, 1);
	}
	if (CheckWall(constMap, PacMan::Alive::ReturnDirection().x * 10 , PacMan::Alive::ReturnDirection().y * 10)) PastDirection = PacMan::Alive::ReturnDirection();
	if (CheckWall(constMap, PastDirection.x*2 , PastDirection.y*2))
	{
		PacMan::Alive::moveShape(PastDirection);
	}
}

bool PacMan::CheckFood(char ** strMap)
{
	if (strMap[((int)PacMan::Alive::ReturnShape().getPosition().y / 20)][((int)PacMan::Alive::ReturnShape().getPosition().x / 20)] == ' ')
	{
		_Score++;
		strMap[((int)PacMan::Alive::ReturnShape().getPosition().y / 20)][((int)PacMan::Alive::ReturnShape().getPosition().x / 20)] = '1';
		return true;
	}
	return false;
}

int PacMan::Score() { return _Score; }
 

void PacMan::Restart()
{
	ChangeStartPosition();
	_Score = 0;
}

PacMan::~PacMan() {}