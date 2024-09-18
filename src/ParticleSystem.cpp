//
//  ParticleSystem.cpp
//  synesthesia
//
//  Created by Isaac Shaw on 9/18/24.
//

#include "ParticleSystem.hpp"

//color1 = (0, 63, 92)
//color2 = (44, 72, 117)
//color3 = (138, 80, 143)
//color4 = (188, 80, 144)
//color5 = (255, 99, 97)
//color6 = (255, 133, 49)
//color7 = (255, 166, 0)

//{sf::Color(0, 63, 92), sf::Color(44, 72, 117), sf::Color(138, 80, 143), sf::Color(188, 80, 144), sf::Color(255, 99, 97), sf::Color(255, 133, 49), sf::Color(255, 166, 0)}



void ParticleSystem::setLifetimeInt(int time){
    lifetimeInt = time;
}

void ParticleSystem::setVelocityInt(int speed){
    velocityInt = speed;
}

void ParticleSystem::setOpacity(int tint){
    opacity = tint;
}

void ParticleSystem::setColorVector(std::vector<sf::Color> colors){
    this->colors = colors;
}

int ParticleSystem::getRandomColor(std::vector<sf::Color> colors){
    int randomColorIndex = std::rand() % colors.size();
    return randomColorIndex;
}


void ParticleSystem::update(sf::Time elapsed)
{
    for (std::size_t i = 0; i < m_particles.size(); ++i)
    {

        // update the particle lifetime
        Particle& p = m_particles[i];
        m_vertices[0].color = colors[0];
        p.lifetime -= elapsed;
        
        // if the particle is dead, respawn it
        if (p.lifetime <= sf::Time::Zero){
            resetParticle(i);
            int randomColorIndex = getRandomColor(colors);
            m_vertices[i + 1].color = colors[randomColorIndex];
        }

        // update the position of the corresponding vertex
        m_vertices[i+1].position += p.velocity * elapsed.asSeconds();

        // update the alpha (transparency) of the particle according to its lifetime
        float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
        m_vertices[i].color.a = static_cast<sf::Uint8>(ratio + opacity * 255);
    }
}

void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // our particles don't use a texture
    states.texture = NULL;

    // draw the vertex array
    target.draw(m_vertices, states);
}

void ParticleSystem::resetParticle(std::size_t index)
{
    // give a random velocity and lifetime to the particle
    float angle = (std::rand() % 360) * 3.14f / 180.f;
    float speed = (std::rand() % 10) + 50.f;
    m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed * velocityInt, std::sin(angle) * speed * velocityInt);
    m_particles[index].lifetime = sf::milliseconds((std::rand() % lifetimeInt) + 5000);
    
    // reset the position of the corresponding vertex
    m_vertices[index].position = m_emitter;
}
