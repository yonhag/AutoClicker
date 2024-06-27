#pragma once
#include "Button.h"
#include <SFML/Graphics.hpp>

class GraphicalHandler
{
public:
	GraphicalHandler();
	void CreateWindow();

private:
	// Consts
	const unsigned int WINDOW_WIDTH = 900;
	const unsigned int WINDOW_HEIGHT = 600;
	const std::string WINDOW_TITLE = "Yona AutoClicker";
	
	sf::RenderWindow _window;
	Button _leftButton;
	Button _rightButton;
	sf::Font _font;
};