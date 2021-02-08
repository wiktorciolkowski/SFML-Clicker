#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
    // Variables
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;

    // Private functions
    void initVariables();
    void initWindow();

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