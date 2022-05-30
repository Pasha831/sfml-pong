#include "../header/Info.h"

Info::Info() {
    if (!this->font.loadFromFile("arial.ttf")) {
        // error...
    }

    this->condition.setFont(font);
    this->condition.setCharacterSize(24);
    this->condition.setFillColor(Color(Color::Black));

    this->possibleConditions[0] = "Pong!\nPress any key to start";
    this->possibleConditions[1] = "Paused";
}

Text Info::getInfo() {
    return condition;
}

void Info::setPauseText() {
    condition.setPosition(355, 250);
    condition.setString(possibleConditions[1]);
}

void Info::setStartText() {
    condition.setPosition(300, 250);
    condition.setString(possibleConditions[0]);
}
