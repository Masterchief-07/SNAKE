#pragma once

#include <iostream>

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "Snake.hpp"
#include "Fruit.hpp"

class Game
{
    private:
    //attributes
    sf::RenderWindow *window;
    sf::VideoMode videomode;
    sf::Event event;

    //snake
    Snake *snake;
    //fruits
    Fruit fruit;
    //score
    unsigned points;

    //counter
    unsigned counter;

    //init
    void initVariables();
    void initWindows();
    
    void pollEvent();
    //game logic
    void snakeEatFruit();
    sf::Vector2f randPos();
    bool GAMEOVER;

    public:
    Game();
    ~Game();
    void render();
    void update();
    const bool running() const;
};