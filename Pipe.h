//
// Created by Damian Duchnowski on 2019-06-14.
//

#ifndef FLAPPYBIRDWITHAI_PIPE_H
#define FLAPPYBIRDWITHAI_PIPE_H

#include <cstdlib>
#include <SFML/Graphics.hpp>

class Pipe {
    const int pipeWidth = 100;
    int topPipeLength = rand()%1080/2;
    int bottomPipeLength = rand()%1080/2;
    int xPos = 1920;
    int speed = 5;

    sf::RectangleShape topPipe;
    sf::RectangleShape bottomPipe;

public:
    void render(sf::RenderWindow& win);
    void update();
};

#endif //FLAPPYBIRDWITHAI_PIPE_H
