#include "Snake.hpp"

Snake::Snake(sf::Vector2f const&pos)
{
    for(size_t i=0; i<4; i++)
    {
        sf::RectangleShape shape;
        sf::Vector2f snakepos;
        snakepos.x = pos.x - i*this->size.x;
        snakepos.y = pos.y;
        shape.setPosition(snakepos);
        shape.setSize(this->size);
        shape.setFillColor(sf::Color::White);
        this->snakeBody.push_back(shape);
    }
}

void Snake::Update()
{

}

void Snake::Render(sf::RenderTarget &target)
{
    for(auto const& e: this->snakeBody)
    {
        target.draw(e);
    }
}