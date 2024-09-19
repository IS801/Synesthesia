//
//  game.cpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/16/24.
//

#include <iostream>
#include <set>
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
    for (auto shape : keyboard.getKeys())
        window.draw(*shape);
}

void Game::setDisplay(){
    window.clear();
    visualizer.setEmitter(sf::Vector2f(500, 500));
    visualizer.update(clock.restart());
    window.draw(visualizer);
    drawKeys();
    window.display();
}

void Game::run(){
    std::srand(int(std::time(0)));
    
    window.clear();
    visualizer.setColorVector({sf::Color(0,0,0)});
    setDisplay();
    window.display();
    
    while(window.isOpen()){
        sf::Event event;
        
        while(window.pollEvent(event)){
                    
            for (auto& key : KEYS){
                
                Key* pianoKey = keyboard.getKey(key);
                
                if (sf::Keyboard::isKeyPressed(key)){
                    if (!pianoKey->isPressed){
                        pianoKey->shape.setFillColor(pianoKey->visColor);
                        pianoKey->playSound();
                        visualizer.addColor(pianoKey->visColor);
                        pianoKey->isPressed = true;
                    }
                } else {
                    if (pianoKey->isPressed){
                        pianoKey->shape.setFillColor(sf::Color(245,242,220));
                        pianoKey->killSound();
                        visualizer.removeColor(pianoKey->visColor);
                        pianoKey->isPressed = false;
                    }
                }
                
                setDisplay();
                
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
        window.clear();
        if (keyboard.anyKeyPressed()){
            setDisplay();
        } else {
            visualizer.setColorVector({sf::Color(0,0,0)});
            setDisplay();
        }
    }
}
