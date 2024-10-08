#pragma once
#include "Button.h"
#include "Settings.h"
#include <SFML/Graphics.hpp>
#include <memory>

class GraphicalHandler
{
public:
	GraphicalHandler();
	[[noreturn]] void HandleWindow();
	void DisableClicker();

private:
	void HandleMouseEvent();

	// Consts
	const unsigned int WINDOW_WIDTH = 900;
	const unsigned int WINDOW_HEIGHT = 600;
	const std::string WINDOW_TITLE = "Yona AutoClicker";
	
	sf::RenderWindow _window;
	Button _leftButton;
	Button _rightButton;
	sf::Font _font;
	
	// Sharing results
	Settings _settings;
	bool _isOpen;
};