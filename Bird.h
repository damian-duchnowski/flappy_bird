//
// Created by Damian Duchnowski on 2019-06-14.
//

#ifndef FLAPPYBIRDWITHAI_BIRD_H
#define FLAPPYBIRDWITHAI_BIRD_H

#include <SFML/Graphics.hpp>

class Bird {
    const int x = 1920/4;
    double y = 1080/3.0;
    double velocity = 0;
    double gravity = 0.7;
    double lift = -14;

    sf::Texture birdTexture;
public:
    sf::CircleShape birdShape;

    Bird() { assert(birdTexture.loadFromFile("bird.png")); }

    double getVelocity() { return velocity; }

    void up();
    void reset();

    void draw(sf::RenderWindow& win);
    void update();
};

#endif //FLAPPYBIRDWITHAI_BIRD_H
