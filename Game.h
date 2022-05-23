#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Paddle.h"
#include "Ball.h"
#include "Score.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Game {
private:
    RenderWindow window;
    int windowWidth;
    int windowHeight;
    String title;
    int frameLimit;
    bool gameOver;

    Paddle *leftPaddle;
    Paddle *rightPaddle;

    Ball ball;

    Score *leftScore;
    Score *rightScore;
public:
    Game();
    bool isGameOver();
    void update();
    void draw();
};

#endif //GAME_GAME_H
