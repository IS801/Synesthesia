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


const auto COLORS = std::map<sf::Keyboard::Key, sf::Color>{
    {sf::Keyboard::Z, sf::Color(0, 63, 92)},
    {sf::Keyboard::X, sf::Color(44, 72, 117)},
    {sf::Keyboard::C, sf::Color(138, 80, 143)},
    {sf::Keyboard::V, sf::Color(188, 80, 144)},
    {sf::Keyboard::B, sf::Color(255, 99, 97)},
    {sf::Keyboard::N, sf::Color(255, 133, 49)},
    {sf::Keyboard::M, sf::Color(255, 166, 0)}
};

struct Key{
    sf::RectangleShape shape;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;
    sf::Color visColor;
    bool isPressed = false;
    
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
    std::vector<sf::Shape*> getKeyColors();
    
    bool anyKeyPressed();
    Key* getKey(sf::Keyboard::Key key);
};

#endif /* keyboard_hpp */
