//
// Created by Damian Duchnowski on 2019-06-14.
//

#include <iostream>
#include "Pipe.h"

void Pipe::render(sf::RenderWindow& win)
{
    topPipe.setFillColor(sf::Color::White);
    topPipe.setPosition(xPos, 0);
    topPipe.setSize(sf::Vector2f(pipeWidth, topPipeLength));

    bottomPipe.setFillColor(sf::Color::White);
    bottomPipe.setPosition(xPos, 1080-bottomPipeLength);
    bottomPipe.setSize(sf::Vector2f(pipeWidth, bottomPipeLength));

    win.draw(topPipe);
    win.draw(bottomPipe);
}

void Pipe::update()
{
    xPos -= speed;
}