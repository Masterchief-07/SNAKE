#include "Snake.hpp"

Snake::Snake(sf::Vector2f const&pos)
{
    //head creation
    sf::RectangleShape shape;
    sf::Vector2f snakepos{pos};
    //snakepos.x -= (i*(this->size.x));
    //snakepos.x -= (i>0)? 5:0;
    shape.setPosition(snakepos);
    shape.setSize(this->size);
    shape.setFillColor(sf::Color::Blue);
    this->snakeBody.push_back(shape);
    //body creation
    for(int i=1; i<4; i++)
    {
        snakepos.x -= (i*(this->size.x));
        //snakepos.x -= (i>0)? 5:0;
        shape.setPosition(snakepos);
        shape.setSize(this->size);
        shape.setFillColor(sf::Color::White);
        this->snakeBody.push_back(shape);
        
    }
    snakeDirection = Direction::Right;
    snakeDirectionVect.x = this->size.x;
    snakeDirectionVect.y = 0;
}

Snake::~Snake()
{

}

void Snake::move(Direction dir)
{
    switch (dir)
    {
    case Direction::Left:
        if(snakeDirection!= Direction::Right)
        {
            snakeDirectionVect.x = -this->size.x;
            snakeDirectionVect.y = 0;
            snakeDirection = dir;
        }
        break;
    case Direction::Right:
        if(snakeDirection!= Direction::Left)
        {
            snakeDirectionVect.x = this->size.x;
            snakeDirectionVect.y = 0;
            snakeDirection = dir;
        }
        break;
    case Direction::Up:
        if(snakeDirection!= Direction::Down)
        {
            snakeDirectionVect.x = 0;
            snakeDirectionVect.y = -this->size.x;
            snakeDirection = dir;
        }
        break;
    case Direction::Down:
        if(snakeDirection!= Direction::Up)
        {
            snakeDirectionVect.x = 0;
            snakeDirectionVect.y = this->size.x;
            snakeDirection = dir;
        }
        break;

    default:
        break;
    }
}

void Snake::Update()
{
    for(int i=snakeBody.size()-1; i>=1; i--)
    {
        snakeBody[i].setPosition(snakeBody[i-1].getPosition());
    }
    snakeBody[0].move(snakeDirectionVect);
}

void Snake::Render(sf::RenderTarget &target)
{
    for(auto const& e: this->snakeBody)
    {
        target.draw(e);
    }
}

bool Snake::collide(sf::Vector2f const&pos)
{
    return this->snakeBody[0].getGlobalBounds().contains(pos);
}

bool Snake::collide(sf::RectangleShape const&rect)
{
    return this->snakeBody[0].getGlobalBounds().intersects(rect.getGlobalBounds());
}

bool Snake::collide(sf::CircleShape const&fruit)
{
    return this->snakeBody[0].getGlobalBounds().intersects(fruit.getGlobalBounds());
}

bool Snake::collide(sf::Rect<float> fruit)
{
    return this->snakeBody[0].getGlobalBounds().intersects(fruit);
}

void Snake::grow()
{
    sf::RectangleShape rec{this->snakeBody[snakeBody.size()-1]};
    snakeBody.push_back(rec);
    //snakeBody.push_back();
}

const sf::Vector2f Snake::getHeadPos() const
{
    return this->snakeBody[0].getPosition();
}
    

void Snake::setHeadPos(sf::Vector2f const& newpos)
{
    this->snakeBody[0].setPosition(newpos);
}