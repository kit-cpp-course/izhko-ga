#pragma once
#include <iostream>

class Button
{
	int HeigthButton=0;
	int WigthButton=0;
	sf::RectangleShape RecShButton; 
	std::string Text;
public:
	sf::Vector2f LeftUp() { return sf::Vector2f(RecShButton.getPosition().x, RecShButton.getPosition().y); };
	sf::Vector2f LeftDown() { return sf::Vector2f(RecShButton.getPosition().x, RecShButton.getPosition().y+HeigthButton); };
	sf::Vector2f RigthUp() { return sf::Vector2f(RecShButton.getPosition().x+WigthButton, RecShButton.getPosition().y); };
	sf::Vector2f RigthDown() { return sf::Vector2f(RecShButton.getPosition().x + WigthButton, RecShButton.getPosition().y+HeigthButton); };
	Button(int _Heigth, int _Wigth, sf::Vector2f StartPosition, std::string text);
	sf::RectangleShape ShapeButton() { return RecShButton; }; 
	std::string returnText() { return Text; };
	bool CheckMouse(sf::RenderWindow *window);
	~Button(); 
};
