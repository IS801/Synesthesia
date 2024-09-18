#include <iostream>
#include "game.hpp"

int main(int argc, const char * argv[]) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    Game().run();
}
