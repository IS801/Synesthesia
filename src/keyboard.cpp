//
//  keyboard.cpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/17/24.
//

#include <iostream>
#include <filesystem>
#include <map>
#include <SFML/Audio.hpp>
#include "keyboard.hpp"

namespace fs = std::filesystem;

const fs::path WAV_FILES = fs::path(__FILE__).parent_path().parent_path() / "wav_files";

void Keyboard::createKeys(sf::RenderWindow& window){
    // The following magic numbers are static ratios to adjust key dimensions
    // and positions based on window size. These ratios were determined by manual experimentation.
    auto [windowW, windowH] = window.getSize();
    int width = windowW * 0.05;
    int height = windowH * 0.09;
    int yPos = windowH * 0.9;
    int startingX = (windowW / 2) - width * 3.5;
    for (int i = 0; i < KEYS.size(); i++){
        sf::RectangleShape shape;
        shape.setPosition(startingX + (width * i + 1), yPos);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(sf::Color(245,242,220));
        shape.setOutlineThickness(1);
        shape.setOutlineColor(sf::Color(0, 0, 0)); // Always set boarder to black
        
        // Load sound file for each key
        std::string fileName;
        auto pair = SOUNDS.find(KEYS[i]);
        fileName = pair->second;
        fs::path wavFile = WAV_FILES / fileName;
        
        
        keys[KEYS[i]] = Key{shape};
        auto colorPair = COLORS.find(KEYS[i]);
        keys[KEYS[i]].visColor = colorPair->second;
        if(!keys[KEYS[i]].soundBuffer.loadFromFile(wavFile)){
            std::cerr << "File " << KEYS[i] << " can't be loaded." << std::endl;
            exit(1);
        }
        keys[KEYS[i]].setSound();
    }
}

Keyboard::Keyboard(sf::RenderWindow& window){
    createKeys(window);
}

std::vector<sf::Shape*> Keyboard::getKeyColors(){
    std::vector<sf::Shape*> shapes;
    for (auto& [_, key] : keys){
        shapes.push_back(&key.shape);
    }
    return shapes;
}

Key* Keyboard::getKey(sf::Keyboard::Key key){
    return &(keys.at(key));
}

bool Keyboard::anyKeyPressed(){
    for (const auto& [_, key] : keys){
        if (key.isPressed)
            return true;
    }
    return false;
}

void Key::updateColor(sf::Color newColor){
    shape.setFillColor(newColor);
};

void Key::setSound(){
    sound.setBuffer(soundBuffer);
}

void Key::playSound(){
    sound.play();
};

void Key::killSound(){
    sound.stop();
};
