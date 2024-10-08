//
//  ParticleSystem.hpp
//  synesthesia
//
//  Created by Isaac Shaw on 9/18/24.
//

#ifndef ParticleSystem_hpp
#define ParticleSystem_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count = 250) :
        m_particles(count),
        m_vertices(sf::VertexArray(sf::TriangleFan, count)),
        m_lifetime(sf::seconds(30)),
        m_emitter(500, 500)
    {}
        
    void setEmitter(sf::Vector2f position){ m_emitter = position;}

    void update(sf::Time elapsed);
    
    void setLifetimeInt(int time);
    
    void setVelocityInt(int speed);
    
    void setOpacity(int value);
    
    void setColorVector(std::vector<sf::Color> activeKeys);
    
    void addColor(sf::Color color);
    
    void removeColor(sf::Color color);
    
    int getRandomColor(std::vector<sf::Color> colors);
    
    std::vector<sf::Color> getColors();
    
private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void drawWindow(sf::RenderWindow window);

private:
    
    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index);

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
    std::vector<sf::Color> colors;
    int lifetimeInt = 5000;
    int velocityInt = 2;
    int opacity = 500;
};

#endif /* ParticleSystem_hpp */
