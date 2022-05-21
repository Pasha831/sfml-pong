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
    Font font;
public:
    RectangleShape paddle;
    Text speedInfo;

    Paddle() {
        if (!font.loadFromFile(R"(C:\Users\dimapcc\CLionProjects\game\arial.ttf)")) {
            std::cout << "Fuck it!";
        }

        speedInfo.setFont(font);
        speedInfo.setCharacterSize(24);
        speedInfo.setFillColor(Color::Black);
        speedInfo.setPosition(5, 5);

        paddle.setSize(Vector2<float>(35, 100));
        paddle.setFillColor(Color(100, 250, 50));
        paddle.setPosition(800 - 35, 0);

        initPhysics();
    }
    void initPhysics() {
        velocityMax = 15.f;
        velocityMin = 1.f;
        acceleration = 2.f;
        drag = 0.9f;
    }
    void display(RenderWindow window) {
        window.draw(paddle);
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
        speedInfo.setString(std::to_string(velocity.x * velocity.x + velocity.y * velocity.y));
        updateMovement();
        updatePhysics();
    }
    void updateMovement() {
        if (Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
            move(0, -1);
        } else if (Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
            move(0, 1);
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

    Paddle pRight;

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        pRight.update();

        window.clear(Color(255, 255, 204));

        window.draw(ball);
        window.draw(pRight.speedInfo);
        window.draw(pRight.paddle);
        window.display();
    }

    return 0;
}