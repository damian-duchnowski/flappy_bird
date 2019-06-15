//
// Created by Damian Duchnowski on 2019-06-14.
//

#include <iostream>
#include "Pipe.h"

Pipe::Pipe()
{
    assert(topPipeTexture.loadFromFile("topPipe.png"));
    assert(bottomPipeTexture.loadFromFile("bottomPipe.png"));
}

void Pipe::draw(sf::RenderWindow& win)
{
    topPipe.setTexture(&topPipeTexture);
    topPipe.setPosition(xPos, 0);
    topPipe.setSize(sf::Vector2f(pipeWidth, topPipeLength));

    bottomPipe.setTexture(&bottomPipeTexture);
    bottomPipe.setPosition(xPos, 1080-bottomPipeLength);
    bottomPipe.setSize(sf::Vector2f(pipeWidth, bottomPipeLength));

    win.draw(topPipe);
    win.draw(bottomPipe);
}

void Pipe::update()
{
    xPos -= speed;
}