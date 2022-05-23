#include "Game.h"

int main()
{
    Game game;
    while (!game.isGameOver()) {
        game.update();
        game.draw();
    }
    return 0;
}
