#include "Game.hpp"

Game::Game()
{
    initVariables();
    initWindows();
}

Game::~Game()
{
    delete this->window;
}

void Game::initVariables()
{
    this->videomode.height = 800;
    this->videomode.width = 800;
    sf::Vector2f snakePos(videomode.height/2.f , videomode.width/2.f);
    snake = new Snake(snakePos);
}

void Game::initWindows()
{
    this->window = new sf::RenderWindow(this->videomode, "SNAKE", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvent()
{
    while(this->window->pollEvent(this->event))
    {
        switch(this->event.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if(this->event.key.code == sf::Keyboard::Escape)
                    this->window->close();
            default:
                break;
        }
    }
}

void Game::update()
{
    pollEvent();
    snake->Update();
}


void Game::render()
{
    this->window->clear();
    snake->Render(*this->window);
    this->window->display();
}