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
    int window_height;
    int window_width;
    sf::RenderWindow window;
    
    template <typename T>
    void drawToWindow(sf::RenderWindow& window, T& elemToDraw);
    void drawWindowPartition(sf::RenderWindow& window);
    
public:
    Game(int wHeight = 800, int wWidth = 600);
    void run();
};

#endif /* game_hpp */
