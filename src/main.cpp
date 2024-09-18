#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace sf;

//color1 = (0, 63, 92)
//color2 = (44, 72, 117)
//color3 = (138, 80, 143)
//color4 = (188, 80, 144)
//color5 = (255, 99, 97)
//color6 = (255, 133, 49)
//color7 = (255, 166, 0)


class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

    ParticleSystem(unsigned int count) :
        m_particles(count),
        m_vertices(VertexArray(TriangleFan, count)),
        m_lifetime(sf::seconds(30)),
        m_emitter(500, 500)
    {
//        colors =
//    }
//    
//    void setColors(std::vector<sf::Color, colors){
//        this->colors = colors;
    }
    

    void setEmitter(sf::Vector2f position)
    {
        m_emitter = position;
    }

    void update(sf::Time elapsed)
    {
        std::vector<Color> colors = {Color(0, 63, 92), Color(44, 72, 117), Color(138, 80, 143), Color(188, 80, 144), Color(255, 99, 97), Color(255, 133, 49), Color(255, 166, 0)};
        for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            int randomColorIndex = std::rand() % colors.size();
            // update the particle lifetime
            Particle& p = m_particles[i];
            p.lifetime -= elapsed;
            
            // if the particle is dead, respawn it
            if (p.lifetime <= sf::Time::Zero){
                resetParticle(i);
//                m_vertices[0].color = colors[0];
                m_vertices[i].color = colors[randomColorIndex];
            }

            // update the position of the corresponding vertex
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            // update the alpha (transparency) of the particle according to its lifetime
            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio + 111 * 255);
        }
    }

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        // apply the transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

private:

    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };

    void resetParticle(std::size_t index)
    {
        // give a random velocity and lifetime to the particle
        float angle = (std::rand() % 360) * 3.14f / 180.f;
        float speed = (std::rand() % 50) + 50.f;
        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
        m_particles[index].lifetime = sf::milliseconds((std::rand() % 6500) + 1000);

        // reset the position of the corresponding vertex
        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};



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

        window.display();
    }

    return 0;
}
