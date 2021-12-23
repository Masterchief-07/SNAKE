#include<iostream>
#include <ctime>
#include "Game.hpp"
#include "Snake.hpp"

int main()
{

    std::srand(static_cast<unsigned>(time(NULL)));
    //init the game
    Game game;

    while(game.running())
    {
        game.update();
        game.render();
    }
    
}