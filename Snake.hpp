#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class Snake
{
    private:
    int direction = 0;
    std::vector<sf::RectangleShape> snakeBody;

    const sf::Vector2f size{30.f, 30.f};

    public:
    Snake(sf::Vector2f const&pos);
    ~Snake();
    void Update();
    void Render(sf::RenderTarget &target);

};