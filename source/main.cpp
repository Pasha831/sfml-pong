#include "../header/Game.h"

int main()
{
    Game game;
    while (!game.isGameOver()) {
        game.update();
        game.draw();
    }
    game.closeWindow();
    return 0;
}
