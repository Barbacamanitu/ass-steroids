#ifndef GAME_H
#define GAME_H

#include <Timing/Timestep.h>
#include <SFML/Graphics.hpp>
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

		sf::CircleShape myCircle;
		float speed;

};

#endif // GAME_H
