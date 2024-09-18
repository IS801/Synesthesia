//
//  keyboard.hpp
//  synesthesia
//
//  Created by Christopher Lawton on 9/17/24.
//

#ifndef keyboard_hpp
#define keyboard_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

const auto KEYS = std::vector<sf::Keyboard::Key>{
    sf::Keyboard::Z,
    sf::Keyboard::X,
    sf::Keyboard::C,
    sf::Keyboard::V,
    sf::Keyboard::B,
    sf::Keyboard::N,
    sf::Keyboard::M,
};

const auto SOUNDS = std::map<sf::Keyboard::Key, std::string>{
    {sf::Keyboard::Z, "N1.wav"},
    {sf::Keyboard::X, "N2.wav"},
    {sf::Keyboard::C, "N3.wav"},
    {sf::Keyboard::V, "N4.wav"},
    {sf::Keyboard::B, "N5.wav"},
    {sf::Keyboard::N, "N6.wav"},
    {sf::Keyboard::M, "N7.wav"}
};

struct Key{
    sf::RectangleShape shape;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    
    void updateColor(sf::Color newColor);
    void setSound();
    void playSound();
    void killSound();
    void loadSound();
};

class Keyboard{
    std::map<sf::Keyboard::Key, Key> keys = {};
    
public:
    Keyboard(sf::RenderWindow& window);
    void createKeys(sf::RenderWindow& window);
    std::map<sf::Keyboard::Key, Key> getKeys();
    void updateColors(sf::Color newColor, std::vector<sf::Keyboard::Key>);
    void playKeys(std::vector<sf::Keyboard::Key>);
    void killKeys(std::vector<sf::Keyboard::Key> unPressedKeys);
};

#endif /* keyboard_hpp */
