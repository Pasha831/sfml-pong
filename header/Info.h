#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Info {
private:
    Font font;
    Text condition;
    std::string possibleConditions[1];
public:
    Info();
    Text getInfo();
};


#endif //GAME_INFO_H
