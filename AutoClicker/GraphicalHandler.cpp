#include "GraphicalHandler.h"
#include <iostream>
#include "Button.h"

void GraphicalHandler::OpenWindow()
{
    sf::RenderWindow window(sf::VideoMode(900, 600), "SFML GUI Example");

    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("Carlito/Carlito-Regular.ttf"))
        std::cerr << "Error loading font\n";

    Button leftButton("Left", 10, sf::Vector2f(100, 100), font);
    Button rightButton("Right", 10, sf::Vector2f(250, 100), font);
    
    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Check for mouse click
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (rightButton.GetGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    rightButton.Click();
                    leftButton.Unclick();
                }
                else if (leftButton.GetGlobalBounds().contains(mousePos.x, mousePos.y))
                {
                    leftButton.Click();
                    rightButton.Unclick();
                }
            }
        }

        window.clear(sf::Color::White);

        leftButton.draw(window);
        rightButton.draw(window);

        window.display();
    }
}
