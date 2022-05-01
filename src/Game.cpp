#include "Game.h"
#include <iostream>


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
Game::Game() :  mWindow(sf::VideoMode(1920, 1080),"SFML Application"), mTexture(),  mPlayer()
{
    if(!mTexture.loadFromFile("Media/Textures/plane.png")) {
      std::cout << "ERROR: cannot load Texture\n";
    }


    mPlayer.setPosition(100.f,100.f);
    mPlayer.setTexture(mTexture);



    mIsMovingDown = false;
    mIsMovingUp = false;
    mIsMovingLeft = false;
    mIsMovingRight = false;

    std::cout<< "check mPlayer.setPosition /n ";


    mPlayerSpeed =  1920.f / 1.f ;
    mPlayerSpeed =  1080.f / 1.f ;
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
void Game::processEvents(){

 sf::Event event;
 while (mWindow.pollEvent(event))
 {
     switch (event.type)
     {
       case sf::Event::Closed:
         mWindow.close();
         break;
      case sf::Event::KeyPressed:
        handlePlayerInput(event.key.code,true);
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
  if (key == sf::Keyboard::W)
    mIsMovingUp = isPressed;
  else if (key == sf::Keyboard::S)
    mIsMovingDown = isPressed;
  else if (key == sf::Keyboard::A)
    mIsMovingLeft = isPressed;
  else if (key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
}





/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game:: update(sf::Time deltaTime)
{

  sf::Vector2f movement(0.f,0.f);

  if (mIsMovingUp)
    movement.y -= mPlayerSpeed;
  if (mIsMovingDown)
    movement.y += mPlayerSpeed;
  if (mIsMovingLeft)
    movement.x -= mPlayerSpeed;
  if (mIsMovingRight)
    movement.x += mPlayerSpeed;

  mPlayer.move(movement * deltaTime.asSeconds());

}

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void Game::render()
{
  mWindow.clear();
  mWindow.draw(mPlayer);
  mWindow.display();

}
