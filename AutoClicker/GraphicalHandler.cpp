#include "GraphicalHandler.h"
#include <iostream>

GraphicalHandler::GraphicalHandler() :
    _window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE),
    _leftButton("Left", 10, sf::Vector2f(100, 100), this->_font),
    _rightButton("Right", 10, sf::Vector2f(250, 100), this->_font),
    _settings(MouseButton::Left, 0),
    _isOpen(true)
{
    _window.setFramerateLimit(60);
    if (!_font.loadFromFile("Carlito/Carlito-Regular.ttf"))
        std::cerr << "Error loading font\n";
}

void GraphicalHandler::HandleWindow()
{
    // Main loop
    while (_window.isOpen())
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
                HandleMouseEvent();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F7)
                _settings._activated = false;
        }

        _window.clear(sf::Color::White);

        _leftButton.draw(_window);
        _rightButton.draw(_window);

        _window.display();
    }

    _isOpen = false;
}

Settings GraphicalHandler::GetSettings() const
{
    return this->_settings;
}

void GraphicalHandler::HandleMouseEvent()
{
    sf::Vector2i mousePos = sf::Mouse::getPosition(_window);
    if (_rightButton.GetGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        _rightButton.Click();
        _leftButton.Unclick();
        _settings._button = MouseButton::Right;
    }
    else if (_leftButton.GetGlobalBounds().contains(mousePos.x, mousePos.y))
    {
        _leftButton.Click();
        _rightButton.Unclick();
        _settings._button = MouseButton::Left;
    }

    _settings._activated = true;
}
