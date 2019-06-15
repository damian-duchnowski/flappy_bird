//
// Created by Damian Duchnowski on 2019-06-14.
//

#ifndef FLAPPYBIRDWITHAI_PIPE_H
#define FLAPPYBIRDWITHAI_PIPE_H

#include <cstdlib>
#include <SFML/Graphics.hpp>

class Pipe {
    static const int pipeWidth = 200;
    int gapSize = 300;
    int topPipeLength = rand()%1080/2;
    int bottomPipeLength = 1080-topPipeLength-gapSize;
    int xPos = 1920;
    int speed = 5;
    bool pipeHit = false;

public:
    sf::RectangleShape topPipe;
    sf::RectangleShape bottomPipe;

    int getTopPipeLength() { return topPipeLength; }
    int getGapSize() { return gapSize; }
    int getXPos() { return xPos; }
    int getPipeWidth() { return pipeWidth; }

    void hitPipe() { pipeHit = true; }

    void render(sf::RenderWindow& win);
    void update();
};

#endif //FLAPPYBIRDWITHAI_PIPE_H
