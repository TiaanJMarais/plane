#include "Game.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>


using namespace std;

//#include <SFML/Graphics/Rect.hpp>

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
Game::Game(sf::VideoMode mode)
    : mWindow(mode, "SFML Application"), mPlayerTexture(), mPlayer(), mMode(mode), mWorld(), mWorldTexture()
{

    sf::IntRect worldRect(0, 0, 640, 4800);

    // World
    if (!mWorldTexture.loadFromFile("/home/tiaan/Projects/plane/Media/Textures/Jungle.png"))
    {
        std::cout << "ERROR: canot load world texture\n";
    }


    mWorld.setTexture(mWorldTexture);
    mWorld.setTextureRect(worldRect);

    mWorld.setPosition(0.f, -4800.f);

    mCurrentSpeed = NORMAL_SPEED;

    //std::cout << "world: width=" << mWorldTexture.getSize().x << ", height=" << mWorldTexture.getSize().y << "\n";
    //std::cout << "sprite: width=" << mWorld.getTextureRect().width << ", height=" << mWorld.getTextureRect().height
    //          << "\n";


    // Player

    if (!mPlayerTexture.loadFromFile("../Media/Textures/plane.png"))
    {
        std::cout << "ERROR: cannot load Texture\n";
    }

    mPlayer.setPosition(250.f, 250.f);
    mPlayer.setTexture(mPlayerTexture);

    // Movement
    mIsMovingDown = false;
    mIsMovingUp = false;
    mIsMovingLeft = false;
    mIsMovingRight = false;

    mPlayerSpeed = 1920.f / 2.f;
    mPlayerSpeed = 1080.f / 1.f;

    mPlayerWidth = (float)mPlayerTexture.getSize().x;
    mPlayerHeight = (float)mPlayerTexture.getSize().y;


    // what is most enemies at a time
    this->mMaxEnemies = 4;
}

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::run()
{
    sf::Clock clock;

    while (mWindow.isOpen())
    {

        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::processEvents()
{

    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            mWindow.close();
            break;
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        default:
            break;
        }
    }
}


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

    //std::cout << "is pressed = " << isPressed << "\n";


    mCurrentSpeed = NORMAL_SPEED;

    if (key == sf::Keyboard::W || key == sf::Keyboard::Up)
    {
        mIsMovingUp = isPressed;
        if (isPressed)
            mCurrentSpeed = FAST_SPEED;
    }
    if (key == sf::Keyboard::S || key == sf::Keyboard::Down)
    {
        mIsMovingDown = isPressed;
        if (isPressed)
            mCurrentSpeed = BRAKE_SPEED;
    }
    else if (key == sf::Keyboard::A || key == sf::Keyboard::Left)
    {
        mIsMovingLeft = isPressed;
    }
    else if (key == sf::Keyboard::D || key == sf::Keyboard::Right)
    {
        mIsMovingRight = isPressed;
    }
}

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::update(sf::Time deltaTime)
{
    spawnEnemies();
    updatePlayer(deltaTime);
    updateEnemies(deltaTime);
    updateWorld(deltaTime);
}


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::updatePlayer(sf::Time deltaTime)
{

    // player
    float maxWidth = (float)mMode.width;
    float maxHeight = (float)mMode.height;
    sf::Vector2f movement(0.f, 0.f);

    if (mIsMovingUp)
        movement.y -= mPlayerSpeed;
    if (mIsMovingDown)
        movement.y += mPlayerSpeed;
    if (mIsMovingLeft)
        movement.x -= mPlayerSpeed;
    if (mIsMovingRight)
        movement.x += mPlayerSpeed;

    sf::Vector2f currentPos = mPlayer.getPosition();
    sf::Vector2f desiredMovement = movement * deltaTime.asSeconds();
    sf::Vector2f newPos = currentPos + desiredMovement;

    //std::cout << newPos.x << "," << newPos.y << "\n";


    // x remains
    if (newPos.x < 0)
    {
        return;
    }

    if (newPos.x >= maxWidth - mPlayerWidth)
    {
        return;
    }

    if (newPos.y < 0)
        if (newPos.y >= maxWidth - mPlayerHeight)
        {
            return;
        }

    // based on speed brake, normal, fast


    // if fast max is fast pos

    // if normal max is normal pos

    // if brake max is brake pos


    float maxy = 480 - mPlayerHeight;
    float miny = 960 - mPlayerHeight;

    if (mCurrentSpeed == FAST_SPEED)
    {
        maxy = FAST_POS;
    }
    else if (mCurrentSpeed == NORMAL_SPEED)
    {
        maxy = NORMAL_POS;
    }
    else if (mCurrentSpeed == BRAKE_SPEED)
    {
        miny = BRAKE_POS;
    }


    if (newPos.y < 1)
    {
        //std::cout << "newPos.y < 0\n";
        return;
    }


    if (newPos.y >= maxy)
    {
        //std::cout << "newPos.y >= " << maxy << "\n";
        return;
    }
    else if (newPos.y <= maxy)
    {
    }


    mPlayer.move(desiredMovement);
}

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::updateEnemies(sf::Time deltaTime)
{
    for (int i = 0; i < this->mEnemies.size(); i++)
    {
        Enemy *e = this->mEnemies[i];

        e->update(deltaTime);
    }
}

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::updateWorld(sf::Time deltaTime)
{

    sf::Vector2f movement(0.f, mCurrentSpeed);

    mWorld.move(movement);
}

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::render()
{
    mWindow.clear();
    mWindow.draw(mWorld);
    mWindow.draw(mPlayer);


    for (int i = 0; i < this->mEnemies.size(); i++)
    {
        Enemy *e = this->mEnemies[i];
        e->render(this->mWindow);


        //mWindow.draw(*e->sprite());
    }


    // mWindow.draw(mEnemies);
    mWindow.display();
}


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::spawnEnemies()
{
    while (this->mEnemies.size() < this->mMaxEnemies)
    {
        this->addEnemy();
    }
}

/// if the count of the enemy list is less than max the add enemies up to max


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::deleteEnemy(Enemy *e)
{
    int index = -1;
    for (int i = 0; i < this->mEnemies.size(); i++)
    {
        if (this->mEnemies[i] == e)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        this->mEnemies.erase(this->mEnemies.begin() + index);
    }

    delete e;
}
// delete the memory allocated and remove enemy for enimies list using delete keyword

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::addEnemy()
{
    int index = this->mEnemies.size();
    Enemy *e = new Enemy(index);

    this->mEnemies.push_back(e);
    // movement will be done in update enemies
}


// allocate a enemy using keyword new and add to list.
