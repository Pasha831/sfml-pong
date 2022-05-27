#include "../header/Info.h"

Info::Info(int positionX, int positionY) {
    if (!this->font.loadFromFile("arial.ttf")) {
        // error...
    }

    this->condition.setFont(font);
    this->condition.setCharacterSize(24);
    this->condition.setFillColor(Color(Color::Black));
    this->condition.setPosition(positionX, positionY);

    this->possibleConditions[0] = "Press any key to start";
    this->possibleConditions[1] = "Paused";

    this->condition.setString(possibleConditions[1]);
}

Text Info::getInfo() {
    return condition;
}
