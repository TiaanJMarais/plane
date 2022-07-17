#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <SFML/System/Time.hpp>
//#include <SFML/Window/VideoMode.hpp>


class Enemy
{
public:
    Enemy(int index);

    sf::Sprite *sprite()
    {
        return &this->mSprite;
    }
    sf::Texture *texture()
    {
        return &this->mTexture;
    }

    void update(sf::Time deltaTime);
    void render(sf::RenderWindow &window);

private:
    // sprite
    // texture

    sf::Sprite mSprite;
    sf::Texture mTexture;
    //sf::VideoMode mMode;
    sf::RectangleShape mHitbox;

    float mEnemySpeed;
};