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

using namespace sf;

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count = 150) :
        m_particles(count),
        m_vertices(VertexArray(TriangleFan, count)),
        m_lifetime(sf::seconds(30)),
        m_emitter(500, 500)
    {}
    
    void runVisualizer();
    
    void setEmitter(sf::Vector2f position){ m_emitter = position;}

    void update(sf::Time elapsed);
    
    void setLifetimeInt(int time);
    
    void setVelocityInt(int speed);
    
    void setOpacity(int value);
    
    auto setColorVector(std::vector<Color> activeKeys);
    
    int getRandomColor(std::vector<Color> colors);
    
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
    std::vector<Color> colors;
    int lifetimeInt = 10000;
    int velocityInt = 1;
    int opacity = 500;
};

#endif /* ParticleSystem_hpp */
