#include <SFML/Graphics.hpp>
#include <iostream>
#include "Bird.h"
#include "Pipe.h"

int main()
{
    srand(time(nullptr));

    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow win(sf::VideoMode(1920, 1080), "Flappy Bird", sf::Style::Default, settings);
    win.setFramerateLimit(60);

    Bird bird;
    std::vector<Pipe> pipes;

    sf::Clock clock;

    // run the program as long as the window is open
    while (win.isOpen()) {
        bird.update();
        if (clock.getElapsedTime().asSeconds()>0.2) {
            Pipe tempPipe;
            pipes.push_back(tempPipe);
            clock.restart();
        }
        for (auto pipeCouple : pipes) {
            pipeCouple.update();
        }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (win.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type==sf::Event::Closed)
                win.close();
            if (event.type==sf::Event::KeyPressed)
                if (event.key.code==sf::Keyboard::Space) {
                    bird.up();
                }
        }

        // clear the window with black color
        win.clear(sf::Color::Black);

        // draw everything here...
        bird.render(win);
        for (auto pipeCouple : pipes) pipeCouple.render(win);

        // end the current frame
        win.display();
    }

    return 0;
}