//
//  game.hpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>

struct Rectangle{
    int xPos;
    int yPos;
    int width;
    int height;
    sf::Color color;
};

class Game{
    int window_height;
    int window_width;
    Rectangle partition;
    std::vector<Rectangle> keys;
    
    template <typename T>
    void drawToWindow(sf::RenderWindow& window, T& elemToDraw);
    void drawRectangle(sf::RenderWindow& window, Rectangle rectangle);
    void createKeys();
    
public:
    Game(int wHeight = 800, int wWidth = 600);
    void run();
};

#endif /* game_hpp */
