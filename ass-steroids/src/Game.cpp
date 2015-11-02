#include "Game.h"
#include <math.h>
#include <random>
#include "GameObjects/Spaceship.h"
Game::Game()
{
    //ctors
}

Game::~Game()
{
    //dtor
}

void Game::createWindow()
{
    gameWindow.create(sf::VideoMode(1280, 720), "SFML window");
    gameWindow.setVerticalSyncEnabled(true);
	ship.setPosition(sf::Vector2f(400, 400));


}

void Game::mainLoop()
{
	
    while (gameWindow.isOpen())
    {
        //Game Loop
        mTimestep.startLoop();

        processEvents();

        while(mTimestep.canUpdate())
            update(mTimestep.TIMESTEP);

        render(mTimestep.getAlpha());

        //End Game Loop
    }
}

void Game::render(const float alpha)
{
    gameWindow.clear();
    sf::RenderStates states;
	ship.Draw(gameWindow, states);
    gameWindow.display();
}





void Game::update(const float dt)
{
	ship.Update(dt);
}



void Game::processEvents()
{
     sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
            {
                gameWindow.close();
            }
            if (event.type == sf::Event::EventType::MouseButtonPressed)
            {
				if (event.mouseButton.button == sf::Mouse::Left)
				{
				}
            }

        }
}
