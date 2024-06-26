#include "Button.h"

Button::Button(const std::string& text, const float radius, const sf::Vector2f& position, const sf::Font& font) : _isPressed(false)
{
    // Main Circle
    this->_circleButton.setRadius(radius);
    this->_circleButton.setPosition(position);
    this->_circleButton.setFillColor(sf::Color::White);
    this->_circleButton.setOutlineColor(sf::Color::Black);
    this->_circleButton.setOutlineThickness(3.0);

    // Inner Circle
    float innerRadius = radius / 1.25f;
    this->_innerCircle.setRadius(innerRadius);
    this->_innerCircle.setOrigin(innerRadius, innerRadius);
    this->_innerCircle.setPosition(position.x + radius, position.y + radius);
    this->_innerCircle.setFillColor(sf::Color::Black);

    // Text
    this->_text = sf::Text(text, font, 30);
    this->_text.setPosition(position.x + 30, position.y - 10);
    this->_text.setFillColor(sf::Color::Black);
}

sf::FloatRect Button::GetGlobalBounds() const
{
    return this->_circleButton.getGlobalBounds();
}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(this->_circleButton);
    window.draw(this->_text);
    if (this->_isPressed)
        window.draw(this->_innerCircle);
}

void Button::Click()
{
    this->_isPressed = true;
}

void Button::Unclick()
{
    this->_isPressed = false;
}
