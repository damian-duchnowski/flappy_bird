//
// Created by Damian Duchnowski on 2019-06-14.
//

#include <iostream>
#include "Bird.h"

void Bird::up()
{
    velocity += lift;
}

void Bird::render(sf::RenderWindow& win)
{
    birdShape.setRadius(50);
    birdShape.setPosition(x, y);
    birdShape.setFillColor(sf::Color::White);
    win.draw(birdShape);
}

void Bird::update()
{
    if (y>1080-birdShape.getLocalBounds().height || y<0) velocity = 0;
    else {
        velocity += gravity;
        velocity *= 0.9;
        y += velocity;
    }
}