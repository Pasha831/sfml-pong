#include <SFML/Graphics.hpp>
#include <iostream>
#include <valarray>

using namespace sf;

class Paddle {
private:
    Vector2<float> velocity;
    float acceleration;
    float drag;
    float velocityMax;
    float velocityMin;
    float xSize;
    float ySize;
    String orientation;
    Color green;
public:
    RectangleShape paddle;

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

int main()
{
    RenderWindow window(sf::VideoMode(800, 600), "App");
    window.setFramerateLimit(60);

    CircleShape ball(25.f);
    ball.setFillColor(Color(100, 250, 50));
    ball.setPosition(20, 40);

    Paddle leftPaddle("left", 0);
    Paddle rightPaddle("right", 800 - 35);

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        leftPaddle.update();
        rightPaddle.update();

        window.clear(Color(255, 255, 204));

        window.draw(ball);
        window.draw(rightPaddle.paddle);
        window.draw(leftPaddle.paddle);

        window.display();
    }

    return 0;
}