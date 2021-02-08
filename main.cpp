#include <SFML/Graphics.hpp>
#define RATIO (4.0/3.0)

int main()
{
    const int WIDTH = 800;
    sf::RenderWindow window(sf::VideoMode(WIDTH, WIDTH / RATIO), "Clicker", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event{};

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;
            }
        }

        window.clear(sf::Color::Magenta);
        window.display();
    }

    return 0;
}