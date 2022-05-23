#include <SFML/Graphics.hpp>
#include <iostream>
#include <valarray>

#include "Game.h"

using namespace sf;

/*class Paddle {
private:
    Vector2<float> velocity;
    float acceleration;
    float drag;
    float velocityMax;
    float velocityMin;
    String orientation;
    Color green;
public:
    RectangleShape paddle;
    float xSize;
    float ySize;

    Paddle(const String& orientation, float xPosition) {
        this->xSize = 35;
        this->ySize = 100;
        this->orientation = orientation;
        this->green = Color(100, 250, 50);

        paddle.setSize(Vector2<float>(xSize, ySize));
        paddle.setFillColor(green);
        paddle.setPosition(xPosition, 250);

        initPhysics();
    }
    void initPhysics() {
        velocityMax = 15.f;
        velocityMin = 1.f;
        acceleration = 2.f;
        drag = 0.9f;
    }
    void move(const float dir_x, const float dir_y) {
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
    void updatePhysics() {
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
    void update() {
        updateMovement();
        updatePhysics();
    }
    void updateMovement() {
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
};
class Ball {
private:
    float radius;
    Vector2<float> velocity;
    float acceleration;
    Color red;
    bool isOutOfZone;  // bool to check if it more left or more right than paddles
public:
    CircleShape ball;

    Ball() {
        this->radius = 25.f;
        this->red = Color(255, 153, 0);
        this->velocity = Vector2<float>(2.5f, 2.5f);
        this->acceleration = 0.0025f;
        this->isOutOfZone = false;

        ball.setRadius(radius);
        ball.setPosition(400 - radius, 300 - radius);
        ball.setFillColor(red);
    }
    void updatePhysics() {
        velocity += Vector2<float>(acceleration * ((velocity.x < 0) ? -1.f : 1.f),
                                   acceleration * ((velocity.y < 0) ? -1.f : 1.f));
        ball.move(velocity);
    }
    void updateMovement(Paddle left, Paddle right) {
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
                isOutOfZone = true;
            }
        }
        if (ball.getPosition().x >= 800 - right.xSize - 2 * radius) {
            if (ball.getPosition().y + radius >= right.paddle.getPosition().y
                && ball.getPosition().y + radius <= right.paddle.getPosition().y + left.ySize && !isOutOfZone) {
                velocity.x *= -1;
            } else {
                isOutOfZone = true;
            }
        }
    }
    void update(Paddle left, Paddle right) {
        updateMovement(left, right);
        updatePhysics();
    }
};*/

int main()
{
    Game game;
    while (!game.isGameOver()) {
        game.update();
        game.draw();
    }
    return 0;
}