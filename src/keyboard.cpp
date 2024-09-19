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
        
        // Load sound file for each key
//        sf::SoundBuffer buffer;
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

std::vector<sf::Shape*> Keyboard::getKeys(){
    std::vector<sf::Shape*> shapes;
    for (auto& [_, key] : keys){
        shapes.push_back(&key.shape);
    }
    return shapes;
}

std::vector<sf::Color> Keyboard::getVisColors(std::vector<sf::Keyboard::Key> pressedKeys){
    std::vector<sf::Color> returnColors;
    for (auto key : pressedKeys){
        auto keyPair = keys.find(key);
        returnColors.push_back(keyPair->second.visColor);
    }
    return returnColors;
}

sf::Color Keyboard::getVisColor(sf::Keyboard::Key pressedKey){
    return keys[pressedKey].visColor;
}

void Keyboard::updateColor(sf::Color newColor, sf::Keyboard::Key updateKey){
        keys[updateKey].updateColor(newColor);
}

void Keyboard::playKey(sf::Keyboard::Key pressedKey){
        keys[pressedKey].playSound();
}

void Keyboard::killSound(sf::Keyboard::Key unPressedKey){
        keys[unPressedKey].killSound();
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
