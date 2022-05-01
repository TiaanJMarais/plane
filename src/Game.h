#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>




class Game
{
public:
                     Game(sf::VideoMode mode);
    void              run();

private:

    void             processEvents();
    void             update(sf::Time deltaTime);
    void             render();
    void             handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:

    sf::RenderWindow mWindow;
    sf::Sprite  mPlayer;
    sf::Texture mTexture;



    /*
     *
     * sf::Texturesf::Sprite...
Game();
mTexture;
mPlayer;
*/






     bool mIsMovingUp;
     bool mIsMovingDown;
     bool mIsMovingLeft;
     bool mIsMovingRight;

     float mPlayerSpeed;

};


#endif
