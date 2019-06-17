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
    int speed = 10;
    bool pipeHit = false;
    bool pipePassed = false;
    bool checkedIfPassed = false;

    sf::Texture topPipeTexture;
    sf::Texture bottomPipeTexture;
public:
    sf::RectangleShape topPipe;
    sf::RectangleShape bottomPipe;

    Pipe();

    int getTopPipeLength() { return topPipeLength; }
    int getGapSize() { return gapSize; }
    int getXPos() { return xPos; }
    int getPipeWidth() { return pipeWidth; }
    bool getPipeHit() { return pipeHit; }
    bool getPipePassed() { return pipePassed; }
    bool getCheckedIfPassed() { return checkedIfPassed; }

    void hitPipe() { pipeHit = true; }
    void passPipe() { pipePassed = true; }
    void checkIfPassed() { checkedIfPassed = true; }

    void draw(sf::RenderWindow& win);
    void update();
};

#endif //FLAPPYBIRDWITHAI_PIPE_H
