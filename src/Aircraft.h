#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include "Entity.h"
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Aircraft : public Entity
{
public:
    enum Type
    {
        Eagle,
        Raptor,
    };
public:

  explicit Aircraft(Type type);
virtual void drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;

private:
  
    Type    mType;
    sf::Sprite  mSprite;

};
#endif
