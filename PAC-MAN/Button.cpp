#include "stdafx.h"

Button::Button(int _Heigth, int _Wigth, sf::Vector2f StartPosition, std::string text) :
	HeigthButton(_Heigth), 
	WigthButton(_Wigth),
	Text(text)
{
	RecShButton = sf::RectangleShape(sf::Vector2f(HeigthButton, WigthButton));
	RecShButton.setPosition(StartPosition); 
}

bool Button::CheckMouse(sf::RenderWindow *window)
{
	return (sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition().x-window->getPosition().x >= RecShButton.getPosition().x && sf::Mouse::getPosition().x - window->getPosition().x <= RecShButton.getPosition().x + HeigthButton && sf::Mouse::getPosition().y - window->getPosition().y-30 >= RecShButton.getPosition().y && sf::Mouse::getPosition().y - window->getPosition().y-30 <= RecShButton.getPosition().y + WigthButton);
}

Button::~Button()
{
}