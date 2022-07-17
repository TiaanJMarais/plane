#ifndef SCENENODE_H
#define SCENENODE_H
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <memory>
#include <vector>

#include "Game.h"

class SceneNode
{
public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode(Game *game);
    ~SceneNode();
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode &node);

private:
    //void draw();
    void draw(sf::RenderWindow target, sf::RenderStates states) const;

private:
    std::vector<Ptr> mChildren;
    SceneNode *mParent;
    Game *mGame;
};

#endif