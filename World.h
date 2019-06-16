//
// Created by Damian Duchnowski on 2019-06-15.
//

#ifndef FLAPPYBIRDWITHAI_WORLD_H
#define FLAPPYBIRDWITHAI_WORLD_H

#include "Bird.h"
#include "Pipe.h"
class World {
    const int TOTAL = 30;
    std::vector<Bird> birds;
    std::vector<Pipe> pipes;

    sf::Clock clock;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Texture groundTexture;
    sf::RectangleShape ground;

    sf::Font font;
    sf::Text scoreLabel;
    sf::Text scoreValue;

    int score = 0;
public:
    World();
    void checkCollisions(Bird& bird);
    void pushBirdUp(Bird& bird) { bird.up(); }
    void createNewPipes();
    void eraseOffScreenPipes(Pipe& pipeCouple);
    void incrementScore(Pipe& pipeCouple, Bird& bird);

    void step();
    void reset();

    void drawScore();
    void drawBackground();
    void drawGround();
    void draw(sf::RenderWindow& win);
};

#endif //FLAPPYBIRDWITHAI_WORLD_H
