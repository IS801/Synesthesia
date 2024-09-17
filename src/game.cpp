//
//  game.cpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#include "game.hpp"


Game::Game(int wWidth, int wHeight){
    window_height = wHeight;
    window_width = wWidth;
}

template <typename T>
void Game::drawToWindow(sf::RenderWindow& window, T& elemToDraw){
    window.clear();
    window.draw(elemToDraw);
    window.display();
}

# TODO: Change this function to draw shape with sf::Drawable?
void Game::drawRectangle(sf::RenderWindow& window, Rectangle rectangle){
    sf::RectangleShape shape;
    shape.setPosition(rectangle.xPos, rectangle.yPos);
    shape.setSize(sf::Vector2f(rectangle.width, rectangle.height));
    shape.setFillColor(rectangle.color);
    drawToWindow(window, shape);
}

void Game::createKeys(){
    // TODO: START HERE
    int startingPos;
    int endPos;
    int keyHight;
    int keyWidth;
    
}

// TODO:
// 1. Use sf::Keyboard::IsKeyPressed and sf::Keyboard::Scan to figure out what chord is being pressed (See the scan codes in sf::Keyboard::Scancode)
void Game::run(){
    sf::RenderWindow window (sf::VideoMode(window_width, window_height), "Synesthesia", sf::Style::Default);
    
    int partition_boundary = window_height * 0.75;
    auto partition = Rectangle{0, partition_boundary, window_width, 5, sf::Color::White};
    drawRectangle(window, partition);
    
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
            // TODO: Catch and forward different event types here
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
