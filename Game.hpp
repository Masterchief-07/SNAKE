#pragma once
#include "Window.hpp"
#include "Snake.hpp"
#include "World.hpp"
#include <iostream>

class Game
{
    public:
        Game();
        ~Game();

        void HandleInput();
        void Update();
        void Render();

        void RestartClock();
        sf::Time GetElapsed();

        Window* GetWindow();

    private:
        Window m_window;
        sf::Clock m_clock;
        sf::Time m_elapsed;
        World m_world;
        Snake m_snake;
};