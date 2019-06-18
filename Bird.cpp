//
// Created by Damian Duchnowski on 2019-06-14.
//

#include "Bird.h"

void Bird::think(std::vector<Pipe>& pipes)
{
    Pipe closest = pipes[0];
    double closestD = x-closest.getXPos();
    for (auto& pipeCouple : pipes) {
        double d = pipeCouple.getXPos()-x;
        if (d<closestD && d>0) {
            closest = pipeCouple;
            closestD = d;
        }
    }

    Matrix inputs(1, 4);
    // TODO: find the closest
    inputs(0, 0) = y/1080.0;
    inputs(0, 1) = closest.getTopPipeLength()/1080.0;
    inputs(0, 2) = (1080-closest.getBottomPipeLength())/1080.0;
    inputs(0, 3) = closest.getXPos()/1080.0;

//    Matrix targetOutput(1, 2);
//    targetOutput(0, 0) = 1.0;
//    targetOutput(0, 1) = 0.0;
//
//    brain.trainingCycle(inputs, targetOutput);
//    Matrix query(1, 4);

    Matrix output = brain.queryNet(inputs);
    if (output(0, 0)>0.5) up();
}

void Bird::up()
{
    velocity += lift;
}

void Bird::reset()
{
    y = 1080/3.0;
    velocity = 5;
}

void Bird::update()
{
    velocity += gravity;
    velocity *= 0.9;
    y += velocity;

}

void Bird::draw(sf::RenderWindow& win)
{
    birdShape.setRadius(50);
    birdShape.setPosition(x, y);
    birdShape.setTexture(&birdTexture);
    win.draw(birdShape);
}