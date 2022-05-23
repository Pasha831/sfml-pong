#include "../header/Ball.h"
#include <iostream>

Ball::Ball() {
    this->radius = 25.f;
    this->red = Color(255, 153, 0);
    this->velocity = Vector2<float>(2.5f, 2.5f);
    this->acceleration = 0.0025f;
    this->isOutOfZone = false;

    ball.setRadius(radius);
    ball.setPosition(400 - radius, 300 - radius);
    ball.setFillColor(red);
}
void Ball::updatePhysics() {
    velocity += Vector2<float>(acceleration * ((velocity.x < 0) ? -1.f : 1.f),
                               acceleration * ((velocity.y < 0) ? -1.f : 1.f));
    ball.move(velocity);
}
void Ball::updateMovement(Paddle &left, Paddle &right, Score &leftScore, Score &rightScore) {
    // Change the direction by touching upper and lower boundaries (maybe change color?...)
    if (ball.getPosition().y <= 0 || ball.getPosition().y >= (600 - 2 * radius)) {
        velocity.y *= -1;
    }

    // Change the direction after the contact between ball and left/right paddle
    if (ball.getPosition().x <= left.xSize) {
        if (ball.getPosition().y + radius >= left.paddle.getPosition().y
            && ball.getPosition().y + radius <= left.paddle.getPosition().y + left.ySize && !isOutOfZone) {
            velocity.x *= -1;
        } else {
            rightScore.plusOne();
            ball.setPosition(400 - radius, 300 - radius);
            velocity = Vector2<float>(2.5f, 2.5f);
        }
    }
    if (ball.getPosition().x >= 800 - right.xSize - 2 * radius) {
        if (ball.getPosition().y + radius >= right.paddle.getPosition().y
            && ball.getPosition().y + radius <= right.paddle.getPosition().y + left.ySize && !isOutOfZone) {
            velocity.x *= -1;
        } else {
            leftScore.plusOne();
            ball.setPosition(400 - radius, 300 - radius);
            velocity = Vector2<float>(2.5f, 2.5f);
        }
    }
}
void Ball::update(Paddle &left, Paddle &right, Score &leftScore, Score &rightScore) {
    updateMovement(left, right, leftScore, rightScore);
    updatePhysics();
}