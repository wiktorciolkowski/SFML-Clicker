#include "Game.h"

// Private functions
void Game::initVariables()
{
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.width = 800;
    this->videoMode.height = 800 * 3 / 4;

    this->window = new sf::RenderWindow(sf::VideoMode(this->videoMode), "Clicker", sf::Style::Titlebar | sf::Style::Close);
}

// Constructors Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}

// Accessors
bool Game::running() const
{
    return this->window->isOpen();
}

// Functions
void Game::pollEvents()
{
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape)
                {
                    this->window->close();
                }
                break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    this->window->clear(sf::Color(255, 0, 0, 255));

    // Draw game

    this->window->display();
}