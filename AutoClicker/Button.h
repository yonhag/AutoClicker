#pragma once
#include <SFML/Graphics.hpp>

class Button 
{
public:
    Button(const std::string& text, const float radius, const sf::Vector2f& position, const sf::Font& font);

    sf::FloatRect GetGlobalBounds() const;
    void draw(sf::RenderWindow& window);
    void Click();
    void Unclick();

private:
    sf::CircleShape _circleButton;
    sf::CircleShape _innerCircle;
    sf::Text _text;
    bool _isPressed;
};