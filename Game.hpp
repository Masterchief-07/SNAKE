#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

class Game
{
    private:
    //attributes
    sf::RenderWindow *window;
    sf::VideoMode videomode;
    sf::Event event;

    //functions
    void initVariables();
    void initWindows();

    public:
    Game();
    ~Game();
    void pollEvent();
    void render();
    void update();
    const bool running() const;
};