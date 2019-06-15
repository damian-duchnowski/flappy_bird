#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"
#include "World.h"

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

    World world(bird, pipes, clock);

    // run the program as long as the window is open
    while (win.isOpen()) {
        world.step();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (win.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type==sf::Event::Closed)
                win.close();
            if (event.type==sf::Event::KeyPressed)
                if (event.key.code==sf::Keyboard::Space) {
                    world.pushBirdUp();
                }
        }

        // clear the window with black color
        win.clear(sf::Color::Black);

        // draw everything here...
        world.render(win);

        // end the current frame
        win.display();
    }

    return 0;
}