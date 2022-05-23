#include "Game.h"
#include <iostream>

Game::Game() {
    this->windowWidth = 800.f;
    this->windowHeight = 600.f;
    this->title = "Game";
    this->frameLimit = 60.f;
    this->gameOver = false;

    this->window.create(VideoMode(windowWidth, windowHeight), title);
    this->window.setFramerateLimit(frameLimit);

    this->leftPaddle = new Paddle("left", 0);
    this->rightPaddle = new Paddle("right", 800 - 35);

    this->leftScore = new Score("left");
    this->rightScore = new Score("right");
}

bool Game::isGameOver() {
    return gameOver;
}

void Game::update() {
    leftPaddle->update();
    rightPaddle->update();
    ball.update(*leftPaddle, *rightPaddle, *leftScore, *rightScore);
}

void Game::draw() {
    window.clear(Color(255, 255, 204));

    window.draw(rightPaddle->paddle);
    window.draw(leftPaddle->paddle);
    window.draw(ball.ball);
    window.draw(leftScore->text);
    window.draw(rightScore->text);

    window.display();
}
