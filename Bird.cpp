//
// Created by Damian Duchnowski on 2019-06-14.
//

#include "Bird.h"

void Bird::up()
{
    velocity += lift;
}

void Bird::reset()
{
    y = 1080/3.0;
    velocity = 5;
}

void Bird::draw(sf::RenderWindow& win)
{
    birdShape.setRadius(50);
    birdShape.setPosition(x, y);
    birdShape.setTexture(&birdTexture);
    win.draw(birdShape);
}

void Bird::update()
{
    velocity += gravity;
    velocity *= 0.9;
    y += velocity;

}