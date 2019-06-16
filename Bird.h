//
// Created by Damian Duchnowski on 2019-06-14.
//

#ifndef FLAPPYBIRDWITHAI_BIRD_H
#define FLAPPYBIRDWITHAI_BIRD_H

#include <SFML/Graphics.hpp>
#include "NeuralNet.hpp"
#include "Pipe.h"

class Bird {
    int x = 1920/4;
    double y = 1080/3.0;
    double velocity = 0;
    double gravity = 0.7;
    double lift = -14;

    NeuralNet brain;

    sf::Texture birdTexture;
public:
    sf::CircleShape birdShape;

    Bird()
            :brain(4, 4, 2, 1, 0.1) { assert(birdTexture.loadFromFile("bird.png")); }

    double getVelocity() { return velocity; }

    void think(std::vector<Pipe>& pipes);

    void up();
    void reset();

    void update();
    void draw(sf::RenderWindow& win);
};

#endif //FLAPPYBIRDWITHAI_BIRD_H
