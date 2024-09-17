//
//  game.cpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#include "game.hpp"


Game::Game(int wHeight, wWidth){
    this->window = sf::Window(
                              sf::VideoMode(wHeight, wWidth),
                              "Synesthesia",
                              sf::Style::Default;
                              );
}

void Game::run(){
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}
