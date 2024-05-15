#include "projectile.hpp"
#include <iostream>

Projectile::Projectile(const sf::Vector2f &startPos,float speed,int damage)
    : position(startPos)
{
}

void Projectile::update()
{
    position.x += speed;
    sprite.setPosition(position);
}

void Projectile::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}

sf::FloatRect Projectile::get_rect() const
{
    return sprite.getGlobalBounds();
}

NormalPea::NormalPea(const sf::Vector2f &startPos,float speed,int damage)
    : Projectile(startPos, speed, damage)
{
    texture.loadFromFile("files/Images/pea.png");
    sprite.scale(0.15f, 0.15f);
    sprite.setTexture(texture);
    FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
}

int NormalPea::get_damage() const
{
    return damage;
}


Vector2f NormalPea::get_pos(){return position;}

bool NormalPea::is_snow(){return false;}




SnowPea::SnowPea(const sf::Vector2f &startPos,float speed,int damage)
    : Projectile(startPos, speed, damage)
{
    if (!texture.loadFromFile("files/Images/ball_blue.png"))
    {
        std::cerr << "Error loading SnowPea texture" << std::endl;
    }
    sprite.scale(2.0f,2.0f);
    sprite.setTexture(texture);
}

int SnowPea::get_damage() const
{
    return damage;
}

Vector2f SnowPea::get_pos(){return position;}


bool SnowPea::is_snow(){return true;}