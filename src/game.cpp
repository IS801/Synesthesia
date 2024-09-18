//
//  game.cpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "game.hpp"

// Use member initialization to assign the non-copyable window to a member of Game
Game::Game(int wWidth, int wHeight):
    window_height(wHeight),
    window_width(wWidth),
    window(sf::RenderWindow(sf::VideoMode(wWidth, wHeight), "Synesthesia", sf::Style::Default)),
    keyboard(Keyboard(window))
{}

void Game::drawKeys(){
    for (auto [_, keyObj]: keyboard.getKeys())
        window.draw(keyObj.shape);
}

void Game::run(){
    window.clear();
    drawKeys();
    window.display();
    
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
            // TODO: Within this loop we must call window.clear then draw both the keys and the visualizer and then display
            // If the keys are released the the visualizer needs to return to black
            
            std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::Z) << std::endl;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
                std::cout << "Z" << std::endl;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
                std::cout << "X" << std::endl;
            }
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
