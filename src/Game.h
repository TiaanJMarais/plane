#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <cstdlib>
#include <string>
#include <vector>


#include "Enemy.h"

class Game
{
public:
    Game(sf::VideoMode mode);
    void run();
    int rand();

private:
    void processEvents();
    void update(sf::Time deltaTime);

    void updatePlayer(sf::Time deltaTime);
    void updateWorld(sf::Time deltaTime);
    void updateEnemies(sf::Time deltaTime);


    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    const void handlePlayerInput(sf::Keyboard, bool isReleased);

    sf::RenderWindow *window()
    {
        return &mWindow;
    }

    void spawnEnemies();
    void deleteEnemy(Enemy *e);
    void addEnemy();


private:
    //void debugPos(sf::Vector2f pos, std::string msg);
    const float FAST_SPEED = 0.1f;
    const float NORMAL_SPEED = 0.045f;
    const float BRAKE_SPEED = 0.005f;


    const float FAST_POS = 480.f;
    const float NORMAL_POS = 450.f;
    const float BRAKE_POS = 445.f;

    float mCurrentSpeed;

    sf::RenderWindow mWindow;
    sf::Sprite mPlayer;
    sf::Texture mPlayerTexture;

    sf::Sprite mWorld;
    sf::Texture mWorldTexture;

    sf::VideoMode mMode;
    float mPlayerWidth;
    float mPlayerHeight;


    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;

    float mPlayerSpeed;


    int mMaxEnemies;
    std::vector<Enemy *> mEnemies;
};


#endif
