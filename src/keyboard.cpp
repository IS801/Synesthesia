//
//  keyboard.cpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/17/24.
//

#include <iostream>
#include <map>
#include "keyboard.hpp"

void Keyboard::createKeys(sf::RenderWindow& window){
    // The following magic numbers are static ratios to adjust key dimensions
    // and positions based on window size
    auto [windowW, windowH] = window.getSize();
    int width = windowW * 0.05;
    int height = windowH * 0.18;
    int yPos = windowH * 0.8;
    int startingX = (windowW / 2) - width * 3.5;
    for (int i = 0; i < KEYS.size(); i++){
        sf::RectangleShape shape;
        shape.setPosition(startingX + (width * i + 1), yPos);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color(245,242,220));
        shape.setOutlineThickness(1);
        shape.setOutlineColor(sf::Color(0, 0, 0)); // Always set boarder to black
        keys[KEYS[i]] = Key{shape};
    }
}

Keyboard::Keyboard(sf::RenderWindow& window){
    createKeys(window);
}

std::map<sf::Keyboard::Key, Key> Keyboard::getKeys(){
    return keys;
}

void Keyboard::updateColors(sf::Color newColor, std::vector<sf::Keyboard::Key> keysToUpdate){
    for (auto updateKey : keysToUpdate)
        keys[updateKey].updateColor(newColor);
}

void Key::updateColor(sf::Color newColor){
    shape.setFillColor(newColor);
};

//TODO: Fill in once sound files are present
void Key::playSound(){};
