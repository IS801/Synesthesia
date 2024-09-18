//
//  game.hpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#ifndef game_hpp
#define game_hpp

#include "keyboard.hpp"
#include "ParticleSystem.hpp"

class Game{
    int window_height;
    int window_width;
    sf::RenderWindow window;
    Keyboard keyboard;
    ParticleSystem visualizer;
    
public:
    Game(int wHeight = 1000, int wWidth = 1000);
    void run();
    void drawKeys();
};

#endif /* game_hpp */
