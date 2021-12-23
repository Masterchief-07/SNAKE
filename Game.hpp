#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include "Snake.hpp"

class Game
{
    private:
    //attributes
    sf::RenderWindow *window;
    sf::VideoMode videomode;
    sf::Event event;

    //snake
    Snake *snake;

    //counter
    unsigned counter;
    
    //init
    void initVariables();
    void initWindows();
    
    void pollEvent();

    public:
    Game();
    ~Game();
    void render();
    void update();
    const bool running() const;
};