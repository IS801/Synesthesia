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
#include <map>

const auto KEYS = std::vector{
    sf::Keyboard::Z,
    sf::Keyboard::X,
    sf::Keyboard::C,
    sf::Keyboard::V,
    sf::Keyboard::B,
    sf::Keyboard::N,
    sf::Keyboard::M,
};

struct Key{
    sf::RectangleShape shape;
    int sound;
    
    void updateColor(sf::Color newColor);
    void playSound();
};

class Keyboard{
    std::map<sf::Keyboard::Key, Key> keys = {};
    
public:
    Keyboard(sf::RenderWindow& window);
    void createKeys(sf::RenderWindow& window);
    std::map<sf::Keyboard::Key, Key> getKeys();
};

#endif /* keyboard_hpp */
