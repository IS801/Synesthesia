#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

#include "ParticleSystem.hpp"

using namespace sf;

int main()
{
    std::srand(std::time(0));
    
    ContextSettings settings;
    settings.antialiasingLevel = 8;

    RenderWindow window(VideoMode(1000, 1000), "Synesthesia", Style::Default, settings);
    
    ParticleSystem particles(150);
    Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        Event event;
        while (window.pollEvent(event))
        {

            // "close requested" event: we close the window
            if (event.type == Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(Color::Black);

        particles.setEmitter(sf::Vector2f(500, 500));
        
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);
        
        window.draw(particles);
        particlesystem.drawWindow()

        window.display();
    }

    return 0;
}
