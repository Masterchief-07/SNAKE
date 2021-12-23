#include<iostream>
#include "Game.hpp"
#include "Snake.hpp"

int main()
{
    //init the game
    Game game;

    while(game.running())
    {
        game.update();
        game.render();
    }
    
}