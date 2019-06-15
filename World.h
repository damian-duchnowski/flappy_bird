//
// Created by Damian Duchnowski on 2019-06-15.
//

#ifndef FLAPPYBIRDWITHAI_WORLD_H
#define FLAPPYBIRDWITHAI_WORLD_H

#include "Bird.h"
#include "Pipe.h"
class World {
    Bird& bird;
    std::vector<Pipe>& pipes;

    sf::Clock& clock;
public:
    World(Bird& b, std::vector<Pipe>& p, sf::Clock& cl);
    void checkCollisions();
    void pushBirdUp() { bird.up(); }
    void step();

    void render(sf::RenderWindow& win);
};

#endif //FLAPPYBIRDWITHAI_WORLD_H
