#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>



#define MINleft 0
#define MAXright 1920

#define MINup 0
#define MAXdown 1080


#include "Game.h"


int main() {

 sf::VideoMode mode =  sf::VideoMode(640, 480);
 //sf::VideoMode mode =  sf::VideoMode(1920, 1080);

  Game game = Game(mode);
  game.run();
  return 0;
}





















///// OLD CODE
/*
 *


    // create the window

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "DOT works!");

    // Red shape
    sf::CircleShape red(10.f);

    red.setFillColor(sf::Color::Cyan);

    //red.setFillColor(sf::Color(100, 250, 50));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }


        ////////////////////////////////////////////// KEEP ABOVE
        sf::Vector2f pos;


 // movement


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {              //Left
          red.move(-1.f, 0.f);
          pos=red.getPosition();
          if(pos.x < MINleft){
             red.setPosition(MAXright,pos.y);
          }
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){        // Right
          red.move(1.f,0.f);
          pos=red.getPosition();
          if (pos.x>MAXright){
            red.setPosition(0.f,pos.y);
          }
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){        // Down
          //            red.move(0.f,1.f);
            red.move(0.f,1.f);
            pos=red.getPosition();
            if (pos.y>MAXdown){
              red.setPosition(pos.x, 0.f); // 1.f,pos.x);
            }
        } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {                                                     // Up
          red.move(0.f,-1.f);
          pos=red.getPosition();
          if (pos.y < MINup){
            red.setPosition(pos.x, MAXdown); // 1.f,pos.x);
          }
        }



        ////////////////////////////////////////////// KEEP BELOW

        // clear the window with black color
        window.clear(sf::Color::Black);
        window.draw(red);

        // draw everything here...
         //window.draw(...);

        // end the current frame
        window.display();
    }
*/




///////////////////////

/*
int main()
{






    red.move(100,100);
    //Green Shape
   //f:://


    while (window.isOpen())
    {
       sf::Event event;
       sf:: Vector2f pos;

        // Check for quit
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }




    // Red shape
    sf::CircleShape red(20.f);
    red.setFillColor(sf::Color::Blue);


    red.move(100,100);
    //Green Shape
   //f:://
    }
/*
    while (window.isOpen())
    {
       sf::Event event;
       sf:: Vector2f pos;

        // Check for quit
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();











        // Draw
        window.clear();
        window.draw(red);
        window.display();
    }


    return 0;
}
*/
