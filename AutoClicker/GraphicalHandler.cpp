#include "GraphicalHandler.h"
#include <iostream>

GraphicalHandler::GraphicalHandler() :
    _window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
    _leftButton("Left", 10, sf::Vector2f(100, 100), this->_font),
    _rightButton("Right", 10, sf::Vector2f(250, 100), this->_font)

{
    _window.setFramerateLimit(60);
    if (!_font.loadFromFile("Carlito/Carlito-Regular.ttf"))
        std::cerr << "Error loading font\n";
}

void GraphicalHandler::CreateWindow()
{
    // Main loop
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();

            // Check for mouse click
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
                if (_rightButton.GetGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    _rightButton.Click();
                    _leftButton.Unclick();
                }
                else if (_leftButton.GetGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    _leftButton.Click();
                    _rightButton.Unclick();
                }
            }
        }

        _window.clear(sf::Color::White);

        _leftButton.draw(_window);
        _rightButton.draw(_window);

        _window.display();
    }
}
