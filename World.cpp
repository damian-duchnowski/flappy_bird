//
// Created by Damian Duchnowski on 2019-06-15.
//

#include "World.h"

World::World(Bird& b, std::vector<Pipe>& p, sf::Clock& cl)
        :bird(b), pipes(p), clock(cl) { }

void World::checkCollisions()
{
    for (auto& pipeCouple : pipes) {
        if (bird.birdShape.getGlobalBounds().intersects(pipeCouple.topPipe.getGlobalBounds())
                || bird.birdShape.getGlobalBounds().intersects(pipeCouple.bottomPipe.getGlobalBounds()))
            pipeCouple.hitPipe();
    }
}

void World::step()
{
    bird.update();
    if (clock.getElapsedTime().asSeconds()>2.5) {
        Pipe tempPipe;
        pipes.push_back(tempPipe);
        clock.restart();
    }
    for (auto& pipeCouple : pipes) {
        pipeCouple.update();
        if (pipeCouple.getXPos()+pipeCouple.getPipeWidth()<0) {
            if (!pipes.empty()) pipes.erase(pipes.begin());
        }
    }
    checkCollisions();
}

void World::render(sf::RenderWindow& win)
{
    bird.render(win);
    for (auto& pipeCouple : pipes) pipeCouple.render(win);
}