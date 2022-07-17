#ifndef TEXTURE_H
#define TEXTURE_H
#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <memory>
#include <utility>
#include <string>
#include <stdexcept>
#include <cassert>




namespace Textures
{
    enum ID { Landscape, Airplane, Missile };
}



/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
class TextureHolder {
public:

    void load(Textures::ID id, const std::string& filename);
    sf::Texture& get(Textures::ID id);
    const sf::Texture& get(Textures::ID id) const;
private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture >> mTextureMap;
};




#endif
