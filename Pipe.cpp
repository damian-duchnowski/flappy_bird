//
// Created by Damian Duchnowski on 2019-06-14.
//

#include "Pipe.h"

void Pipe::render(sf::RenderWindow& win)
{
    topPipe.setFillColor(sf::Color::White);
    if (pipeHit) topPipe.setFillColor(sf::Color::Red);
    topPipe.setPosition(xPos, 0);
    topPipe.setSize(sf::Vector2f(pipeWidth, topPipeLength));

    bottomPipe.setFillColor(sf::Color::White);
    if (pipeHit) bottomPipe.setFillColor(sf::Color::Red);
    bottomPipe.setPosition(xPos, 1080-bottomPipeLength);
    bottomPipe.setSize(sf::Vector2f(pipeWidth, bottomPipeLength));

    win.draw(topPipe);
    win.draw(bottomPipe);
}

void Pipe::update()
{
    xPos -= speed;
}