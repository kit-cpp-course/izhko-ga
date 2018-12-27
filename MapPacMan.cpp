#include "stdafx.h"
#include "MapPacMan.h"

MapPacMan::MapPacMan() : Food(sf::CircleShape(2.f))
{
	Food.setFillColor(sf::Color::White);
	sf::Image map_Image;
	map_Image.loadFromFile("1234.png");
	sf::Texture map_texture;
	map_texture.loadFromImage(map_Image);
	s_map.setTexture(map_texture);
	Map = new char *[Height];
	for (int i = 0; i < Height; i++)
	{
		Map[i] = new char[Width];
	}
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			Map[i][j] = constMap[i][j];
		}
	}
}

char MapPacMan::returnValue(int i, int j)
{
	return Map[i][j];
}

char ** MapPacMan::returnValue() { return Map; }

void MapPacMan::Update(sf::RenderWindow *window)
{
	//Food.setFillColor(sf::Color::Red);
	sf::Image map_Image;
	map_Image.loadFromFile("1234.png");
	sf::Texture map_texture;
	map_texture.loadFromImage(map_Image);
	s_map.setTexture(map_texture);
	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			if (Map[i][j] == ' ')
			{
				s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
				s_map.setPosition(j * 20, i * 20);
				window->draw(s_map);
				Food.setPosition(j * 20 + 10, i * 20 + 10);
				window->draw(Food);
			}
			if (Map[i][j] == '1')
			{
				s_map.setTextureRect(sf::IntRect(0, 0, 32, 32));
				s_map.setPosition(j * 20, i * 20);
				window->draw(s_map);
			}
			if (Map[i][j] == '0')
			{
				s_map.setTextureRect(sf::IntRect(32, 0, 32, 32));
				s_map.setPosition(j * 20, i * 20);
				window->draw(s_map);
			}
		}
	}
}
void MapPacMan::Restart()
{
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			Map[i][j] = constMap[i][j];
		}
	}
}

MapPacMan::~MapPacMan()
{
	for (int i = 0; i < Height; i++)
	{
		delete Map[i];
	}
	delete[] Map;
}