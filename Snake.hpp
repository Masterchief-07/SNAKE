#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

enum class Direction
{
    Left,
    Right,
    Up,
    Down,
};

class Snake
{
    private:
    //direction
    Direction snakeDirection;
    sf::Vector2f snakeDirectionVect;
    std::vector<sf::RectangleShape> snakeBody;

    const float directstep = 10.f;
    const sf::Vector2f size{10.f, 10.f};

    public:
    Snake(sf::Vector2f const&pos);
    ~Snake();
    void Update();
    void Render(sf::RenderTarget &target);
    void move(Direction direct);
    void grow();
    bool collide(sf::Vector2f const&pos);
    bool collide(sf::RectangleShape const&rect);
    bool collide(sf::CircleShape const&fruit);
    bool collide(sf::Rect<float> fruit);
    bool selfKill();
    const sf::Vector2f getHeadPos() const;
    void setHeadPos(sf::Vector2f const& newpos);

};