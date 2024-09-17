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

void Game::drawWindowPartition(sf::RenderWindow& window){
    sf::RectangleShape rectangle;
    rectangle.setPosition(0, partition_boundary);
    rectangle.setSize(sf::Vector2f(window_width, 5.f));
    rectangle.setFillColor(sf::Color::White);
    drawToWindow(window, rectangle);
}

// TODO:
// 1. Use sf::Keyboard::IsKeyPressed and sf::Keyboard::Scan to figure out what chord is being pressed (See the scan codes in sf::Keyboard::Scancode)
void Game::run(){
    sf::RenderWindow window (sf::VideoMode(window_width, window_height), "Synesthesia", sf::Style::Default);
    
    partition_boundary = window_height * 0.75;
    drawWindowPartition(window);
    
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
            // TODO: Catch and forward different event types here
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
