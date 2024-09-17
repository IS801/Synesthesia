//
//  game.cpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#include "game.hpp"


Game::Game(int wHeight, int wWidth){
    window_height = wHeight;
    window_width = wWidth;
}

// TODO:
// 1. Use sf::Keyboard::IsKeyPressed and sf::Keyboard::Scan to figure out what chord is being pressed (See the scan codes in sf::Keyboard::Scancode)
void Game::run(){
    sf::RenderWindow window (sf::VideoMode(window_height, window_width), "Synesthesia", sf::Style::Default);
    
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
//                // check the type of the event...
//                    switch (event.type)
//                    {
//                        // window closed
//                        case sf::Event::Closed:
//                            window.close();
//                            break;
//
//                        // key pressed
//                        case sf::Event::KeyPressed:
//                            ...
//                            break;
//
//                        // we don't process other types of events
//                        default:
//                            break;
//                    }
                window.close();
        }
        window.clear();
        window.display();
    }
}
