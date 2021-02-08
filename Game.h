#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Game
{
private:
    // Variables
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    // Game objects
    sf::RectangleShape enemy;

    // Private functions
    void initVariables();
    void initWindow();
    void initEnemies();

public:
    // Constructors Destructors
    Game();
    ~Game();

    // Accessors
    bool running() const;

    // Functions
    void pollEvents();
    void update();
    void render();
};