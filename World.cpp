//
// Created by Damian Duchnowski on 2019-06-15.
//

#include <iostream>
#include "World.h"

World::World()
{
    assert(backgroundTexture.loadFromFile("background.jpg"));
    backgroundSprite.setTexture(backgroundTexture);

//    assert(groundTexture.loadFromFile("ground.png"));
//    ground.setPosition(0, 800);
//    ground.setSize(sf::Vector2f(1920, 1080-ground.getPosition().y));
//    ground.setTexture(&groundTexture);

    assert(font.loadFromFile("Roboto-Regular.ttf"));
    scoreLabel.setFont(font);
    scoreLabel.setStyle(sf::Text::Bold);
    scoreLabel.setCharacterSize(30);
    scoreLabel.setPosition(30, 30);
    scoreLabel.setString("Score: ");
    scoreValue.setFont(font);
    scoreValue.setStyle(sf::Text::Bold);
    scoreValue.setCharacterSize(30);
    scoreValue.setPosition(scoreLabel.getPosition().x+100, scoreLabel.getPosition().y);
}

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
        if (!pipeCouple.getCheckedIfPassed() && pipeCouple.getXPos()+pipeCouple.getPipeWidth()
                <0+bird.birdShape.getPosition().x+bird.birdShape.getRadius()) {
            score++;
            pipeCouple.passPipe();
            pipeCouple.checkIfPassed();
        }
        if (pipeCouple.getPipeHit() || bird.getVelocity()==0) reset();
    }
    checkCollisions();
    scoreValue.setString(std::to_string(score));
}

void World::reset()
{
    score = 0;
    pipes.clear();
    clock.restart();
    bird.reset();
}

void World::render(sf::RenderWindow& win)
{
    win.draw(backgroundSprite);
    bird.render(win);
    for (auto& pipeCouple : pipes) pipeCouple.render(win);
//    win.draw(ground);
    win.draw(scoreLabel);
    win.draw(scoreValue);
}