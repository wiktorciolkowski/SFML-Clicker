#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

class Game
{
private:
    // Variables
    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode;
    sf::Vector2i mousePosWindow;

    // Game objects
    std::vector<sf::RectangleShape> enemies;
    sf::RectangleShape enemy;

    // Game logic
    int points;
    float enemySpawnTimer;
    float enemySpawnTimerMax;
    unsigned int maxEnemies;

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
    void spawnEnemy();

    void pollEvents();
    void updateMousePositions();
    void updateEnemies();
    void update();

    void renderEnemies();
    void render();
};