#include "Paddle.h"

Paddle::Paddle(const String& orientation, float xPosition) {
    this->xSize = 35;
    this->ySize = 100;
    this->orientation = orientation;
    this->green = Color(100, 250, 50);

    paddle.setSize(Vector2<float>(xSize, ySize));
    paddle.setFillColor(green);
    paddle.setPosition(xPosition, 250);

    initPhysics();
}
void Paddle::initPhysics() {
    velocityMax = 15.f;
    velocityMin = 1.f;
    acceleration = 2.f;
    drag = 0.9f;
}
void Paddle::move(const float dir_x, const float dir_y) {
    // Acceleration
    velocity.x += dir_x * acceleration;
    velocity.y += dir_y * acceleration;

    // Limit velocity
    if (std::abs(velocity.x) > velocityMax) {
        velocity.x = velocityMax * ((velocity.x < 0.f) ? -1.0f : 1.0f);
    }
    if (std::abs(velocity.y) > velocityMax) {
        velocity.y = velocityMax * ((velocity.y < 0.f) ? -1.0f : 1.0f);
    }
}
void Paddle::updatePhysics() {
    // Deceleration
    velocity *= drag;

    // Limit deceleration
    if (std::abs(velocity.x) < velocityMin) {
        velocity.x = 0.f;
    }
    if (std::abs(velocity.y) < velocityMin) {
        velocity.y = 0.f;
    }

    // Set the boundaries for paddles
    if (paddle.getPosition().y < 0) {
        paddle.setPosition(paddle.getPosition().x, 0);
        velocity.y = 0;
    }
    if (paddle.getPosition().y > 600 - ySize) {
        paddle.setPosition(paddle.getPosition().x, 600 - ySize);
        velocity.y = 0;
    }

    paddle.move(velocity);
}
void Paddle::update() {
    updateMovement();
    updatePhysics();
}
void Paddle::updateMovement() {
    if (orientation == "left") {
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            move(0, -1);
        } else if (Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            move(0, 1);
        }
    } else {
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            move(0, -1);
        } else if (Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            move(0, 1);
        }
    }
}
