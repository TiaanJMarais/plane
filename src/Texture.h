#ifndef TEXTURE_H
#define TEXTURE_H

#include <map>
#include <memory>


#include <SFML/Graphics.hpp>

namespace Textures {
    enum ID { Landscape, Airplane, Missile };
};

class TextureHolder {
public:

    void load(Textures::ID id, const std::string& filename);
    sf::Texture& get(Textures::ID id);

private:
    std::map<Textures::ID, std::unique_ptr<sf::Texture>> mTextureMap ;


};






#endif 
