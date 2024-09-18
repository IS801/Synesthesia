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
    keyboard(Keyboard(window)),
    visualizer(ParticleSystem())
{}

void Game::drawKeys(){
    for (auto [_, keyObj]: keyboard.getKeys())
        window.draw(keyObj.shape);
}

void Game::run(){
    sf::Clock clock;
    std::srand(std::time(0));
    
    window.clear();
    drawKeys();
    window.display();
    
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
            
            std::vector<sf::Keyboard::Key> pressedKeys = {};
            std::vector<sf::Keyboard::Key> unpresssedKeys = {};
            
            // keys to kill -> pressedKeys.intersection(unpressedKeys)
            // Keys to contunue -> pressedKeys.intersection(previously pressed keys)
            // new Keys to play -> pressedKeys - previously unpressed keys;
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                pressedKeys.push_back(sf::Keyboard::Z);
            else
                unpresssedKeys.push_back(sf::Keyboard::Z);
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                pressedKeys.push_back(sf::Keyboard::X);
            else
                unpresssedKeys.push_back(sf::Keyboard::X);
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                pressedKeys.push_back(sf::Keyboard::C);
            else
                unpresssedKeys.push_back(sf::Keyboard::C);
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
                pressedKeys.push_back(sf::Keyboard::V);
            else
                unpresssedKeys.push_back(sf::Keyboard::V);
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                pressedKeys.push_back(sf::Keyboard::B);
            else
                unpresssedKeys.push_back(sf::Keyboard::B);
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
                pressedKeys.push_back(sf::Keyboard::N);
            else
                unpresssedKeys.push_back(sf::Keyboard::N);
            
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                pressedKeys.push_back(sf::Keyboard::M);
            else
                unpresssedKeys.push_back(sf::Keyboard::M);
            
            keyboard.updateColors(sf::Color(120, 150, 200), pressedKeys);
            keyboard.updateColors(sf::Color(245,242,220), unpresssedKeys);
            window.clear();
            
            drawKeys();
            auto newColors = keyboard.getVisColors(pressedKeys);
            if (pressedKeys.empty())
                visualizer.setColorVector({sf::Color(0,0,0)});
            else
                visualizer.setColorVector(newColors);
            
            visualizer.setEmitter(sf::Vector2f(500, 500));
            sf::Time elapsed = clock.restart();
            visualizer.update(elapsed);
            window.draw(visualizer);
            
            window.display();
//            keyboard.playKeys(pressedKeys);
            
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}
