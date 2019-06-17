#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"
#include "World.h"
#include "Matrix.hpp"
#include "NeuralNet.hpp"


int main()
{
    srand(time(nullptr));

    // create the window
    sf::RenderWindow win(sf::VideoMode(1920, 1080), "Flappy Bird");
    win.setFramerateLimit(30);

    World world;
    // run the program as long as the window is open
    while (win.isOpen()) {
        world.step();

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (win.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type==sf::Event::Closed)
                win.close();
        }

        // clear the window with black color
        win.clear(sf::Color::Black);

        // draw everything here...
        world.draw(win);

        // end the current frame
        win.display();
    }

    return 0;
}