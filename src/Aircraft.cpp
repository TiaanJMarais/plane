#include "Aircraft.h"





//second edit

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
Aircraft::Aircraft(Type type):mType(type)
{

}

void Aircraft::drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const{

target.draw(mSprite, states);

}