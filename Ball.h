#ifndef GAME_BALL_H
#define GAME_BALL_H

#include <SFML/Graphics.hpp>
#include "Paddle.h"
using namespace sf;

class Ball {
private:
    float radius;
    Vector2<float> velocity;
    float acceleration;
    Color red;
    bool isOutOfZone;  // bool to check if it more left or more right than paddles
public:
    CircleShape ball;

    Ball();
    void updatePhysics();
    void updateMovement(Paddle left, Paddle right);
    void update(Paddle left, Paddle right);
};

#endif //GAME_BALL_H
