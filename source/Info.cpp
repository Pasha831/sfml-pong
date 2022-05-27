#include "../header/Info.h"

Info::Info() {
    if (!this->font.loadFromFile("arial.ttf")) {
        // error...
    }

    this->condition.setFont(font);
    this->condition.setCharacterSize(24);
    this->condition.setFillColor(Color(Color::Black));
    this->condition.setPosition(355, 250);

    this->possibleConditions[0] = "Paused";

    this->condition.setString(possibleConditions[0]);
}

Text Info::getInfo() {
    return condition;
}
