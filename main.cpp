#include "Game.h"

int main()
{
    // Initialize srand
    std::srand(static_cast<unsigned>(time(nullptr)));

    Game game;

    while (game.running())
    {
        game.update();
        game.render();
    }

    return 0;
}