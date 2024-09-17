//
//  game.hpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>

class Game{
    sf::Window window;
    
public:
    Game::Game(int wHeight = 800, wWidth = 600);
    void run();
}

#endif /* game_hpp */
