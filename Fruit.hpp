#pragma once
#include<SFML/Graphics.hpp>

class Fruit
{
    public:
    Fruit();
    ~Fruit();
    //void update();
    void render(sf::RenderTarget &target);
    void setPosition(sf::Vector2f const& pos);
    sf::Rect<float> getGlobalBounds();

    private:
    //shape
    sf::CircleShape fruit;



};