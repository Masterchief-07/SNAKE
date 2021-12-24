#include "Game.hpp"

Game::Game()
{
    initVariables();
    initWindows();
}

Game::~Game()
{
    delete this->window;
    delete this->snake;
}

void Game::initVariables()
{
    this->videomode.height = 800;
    this->videomode.width = 800;
    sf::Vector2f snakePos(videomode.height/2.f , videomode.width/2.f);
    snake = new Snake(snakePos);
    this->counter = 0;
    this->points = 0;
    this->fruit.setPosition({videomode.height/2.f +10.f , videomode.width/2.f +10.f});
    this->GAMEOVER = false;
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
                else if(this->event.key.code == sf::Keyboard::Up)
                    snake->move(Direction::Up);
                else if(this->event.key.code == sf::Keyboard::Down)
                    snake->move(Direction::Down);
                else if(this->event.key.code == sf::Keyboard::Left)
                    snake->move(Direction::Left);
                else if(this->event.key.code == sf::Keyboard::Right)
                    snake->move(Direction::Right);
            default:
                break;
        }
    }
}

void Game::update()
{
    pollEvent();
    if(counter == 0 && !GAMEOVER)
    {
        if(snake->collide(this->fruit.getGlobalBounds()))
        {
            this->points+=1;
            fruit.setPosition(randPos());
            snake->grow();
            std::cout<<"Points: "<<this->points<<"\n";
        }
        if(snake->getHeadPos().x >= this->window->getSize().x)
        {
            snake->setHeadPos({0.f, this->snake->getHeadPos().y});
        }
        else if(snake->getHeadPos().x < 0.f)
        {
            sf::Vector2f newpos = {static_cast<float>(this->window->getSize().x), this->snake->getHeadPos().y};
            snake->setHeadPos(newpos);
        }
        else if(snake->getHeadPos().y >= this->window->getSize().y)
        {
            snake->setHeadPos({this->snake->getHeadPos().x, 0.f});
        }
        else if(snake->getHeadPos().y < 0.f)
        {
            sf::Vector2f newpos = {this->snake->getHeadPos().x, static_cast<float>(this->window->getSize().y)};
            snake->setHeadPos(newpos);
        }

        if(this->snake->selfKill())
        {
            GAMEOVER = true;
        }

        snake->Update();
        counter =5;
    }
    else
    {
        counter--;
    }
}


void Game::render()
{
    this->window->clear();
    snake->Render(*this->window);
    fruit.render(*this->window);
    this->window->display();
}

sf::Vector2f Game::randPos()
{
    sf::Vector2f pos;
    pos.x = rand() % this->window->getSize().x;
    pos.y = rand() % this->window->getSize().y;
    return pos;
}