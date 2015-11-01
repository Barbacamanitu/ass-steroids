#ifndef GAME_H
#define GAME_H

#include <Timing/Timestep.h>
#include <SFML/Graphics.hpp>
#include "GameObjects/Spaceship.h"
class Game
{
    public:
        Game();
        virtual ~Game();

        void createWindow();
        void mainLoop();
        void update(const float dt);
        void render(const float alpha);
    protected:
    private:
        sf::RenderWindow gameWindow;
        Timestep mTimestep;
        void processEvents();
		Spaceship ship;

};

#endif // GAME_H
