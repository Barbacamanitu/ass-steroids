#include "Game.h"
#include <math.h>
#include <random>
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
	rand_s(time());
    gameWindow.create(sf::VideoMode(1280, 720), "SFML window");
    gameWindow.setVerticalSyncEnabled(true);
	myCircle.setRadius(50);
	myCircle.setOutlineColor(sf::Color::Green);
	myCircle.setOutlineThickness(4.0f);
	myCircle.setFillColor(sf::Color::Blue);
	myCircle.setPosition(sf::Vector2f(400, 400));
	speed = 100;
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
	gameWindow.draw(myCircle);
    gameWindow.display();
}





void Game::update(const float dt)
{
	
	float randX= rand() % 10;
	float randY = rand() % 10;
	randX -= 5;
	randY -= 5;
	sf::Vector2f randomVector(randX,randY);
	randomVector *= dt * 50;
	myCircle.move(randomVector);
	/*
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		myCircle.move(sf::Vector2f(0, -speed * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		myCircle.move(sf::Vector2f(-speed * dt, 0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		myCircle.move(sf::Vector2f(0, speed * dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		myCircle.move(sf::Vector2f(speed * dt, 0));
	}*/
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
