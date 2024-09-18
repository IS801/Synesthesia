//
//  game.hpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#ifndef game_hpp
#define game_hpp

#include "keyboard.hpp"

class Game{
    int window_height;
    int window_width;
    sf::RenderWindow window;
    Keyboard keyboard;
    
public:
    Game(int wHeight = 600, int wWidth = 800);
    void run();
    void drawKeys();
};

#endif /* game_hpp */
