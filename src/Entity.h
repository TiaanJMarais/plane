#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/System/Vector2.hpp>


class Entity
{
public:

    void    setVelocity(sf::Vector2f velocity);
    void    setVelocity(float x,float y);
    sf::Vector2f getVelocity() const;

private:
        sf::Vector2f    mVelocity;




};


#endif
