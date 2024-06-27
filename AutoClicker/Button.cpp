#include "Button.h"

Button::Button(const std::string& text, const float radius, const sf::Vector2f& position, const sf::Font& font) : _isPressed(false)
{
    // Main Circle
    _circleButton.setRadius(radius);
    _circleButton.setPosition(position);
    _circleButton.setFillColor(sf::Color::White);
    _circleButton.setOutlineColor(sf::Color::Black);
    _circleButton.setOutlineThickness(3.0);

    // Inner Circle
    float innerRadius = radius / 1.25f;
    _innerCircle.setRadius(innerRadius);
    _innerCircle.setOrigin(innerRadius, innerRadius);
    _innerCircle.setPosition(position.x + radius, position.y + radius);
    _innerCircle.setFillColor(sf::Color::Black);

    // Text
    _text = sf::Text(text, font, 30);
    _text.setPosition(position.x + 30, position.y - 10);
    _text.setFillColor(sf::Color::Black);
}

sf::FloatRect Button::GetGlobalBounds() const
{
    return this->_circleButton.getGlobalBounds();
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(_circleButton);
    window.draw(_text);
    if (_isPressed)
        window.draw(_innerCircle);
}

void Button::Click()
{
    _isPressed = true;
}

void Button::Unclick()
{
    _isPressed = false;
}
