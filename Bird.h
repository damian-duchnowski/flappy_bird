//
// Created by Damian Duchnowski on 2019-06-14.
//

#ifndef FLAPPYBIRDWITHAI_BIRD_H
#define FLAPPYBIRDWITHAI_BIRD_H

#include <SFML/Graphics.hpp>

class Bird {
    const int x = 1920/4;
    double y = 1080/2.0;
    double velocity = 0;
    double gravity = 0.7;
    double lift = -14;
public:
    sf::CircleShape birdShape;

    void up();

    void render(sf::RenderWindow& win);
    void update();
};

#endif //FLAPPYBIRDWITHAI_BIRD_H
