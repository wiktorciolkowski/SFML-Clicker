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

    this->window->setFramerateLimit(60);
}

void Game::initEnemies()
{
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

// Constructors Destructors
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initEnemies();
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

    // Update mouse position

    // Relative to the screen
    // std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;

    // Relative to window
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " "
    << sf::Mouse::getPosition(*this->window).y << std::endl;

}

void Game::render()
{
    this->window->clear();

    // Draw game
    this->window->draw(this->enemy);

    this->window->display();
}