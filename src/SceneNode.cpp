#include "SceneNode.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <Transformable.hpp>
#include <algorithm>
#include <cassert>


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
SceneNode::SceneNode(Game *game) : mGame(game)
{
}

/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
SceneNode::~SceneNode()
{
}


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
void SceneNode::attachChild(Ptr child)
{
    child->mParent = this;
    mChildren.push_back(std::move(child));
}


/* -------------------------------------------------------------
 *
 * ------------------------------------------------------------ */
SceneNode::Ptr SceneNode::detachChild(const SceneNode &node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr &p) -> bool { return p.get() == &node; });
    assert(found != mChildren.end());

    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;

    sf::RenderWindow window();
    SceneNode::Ptr node();


    //this->window window.draw(*node);
}


//void draw();

void SceneNode::draw(sf::RenderWindow target, sf::RenderStates states) const
{

    states.transform *= getTransform();

    drawCurrent(target, states);

    for (auto itr = mChildren.begin(), itr != mChildren.end()++ itr)
    {

        (*itr)->draw(target, states);
    }
}