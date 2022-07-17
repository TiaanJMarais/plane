

#include "Enemy.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>

Enemy::Enemy(int index)
{
    if (!this->mTexture.loadFromFile("../Media/Textures/Enemy.png"))
    {
        std::cout << "ERROR: cannot load enemy texture\n";
    }

    float xpos = 175 * (float)(index);


    this->mSprite.setPosition(xpos, 10.f);
    this->mSprite.setTexture(this->mTexture);


    sf::FloatRect rect = this->mSprite.getLocalBounds();
    sf::Vector2f size = sf::Vector2f(rect.width, rect.height);
    sf::Vector2f pos = sf::Vector2f(rect.left, rect.width);
    this->mHitbox.setPosition(pos);
    this->mHitbox.setSize(size);
    this->mHitbox.setOutlineColor(sf::Color::Red);
    this->mHitbox.setOutlineThickness(0.5f);
}


void Enemy::update(sf::Time deltaTime)
{
    sf::Vector2 m(0.f, 0.005f);
    this->mSprite.move(m);


    /// update this enemy


    //Collision
}


void Enemy::render(sf::RenderWindow &window)
{
    window.draw(this->mSprite);
    window.draw(this->mHitbox);
}