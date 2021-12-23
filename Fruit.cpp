#include "Fruit.hpp"

Fruit::Fruit()
{
    fruit.setRadius(5.f);
    fruit.setFillColor(sf::Color::Red);
}

Fruit::~Fruit()
{

}

void Fruit::setPosition(sf::Vector2f const& pos)
{
    fruit.setPosition(pos);
}

void Fruit::render(sf::RenderTarget &target)
{
    target.draw(fruit);
}

sf::Rect<float> Fruit::getGlobalBounds()
{
    return this->fruit.getGlobalBounds();
}