#include "plants.hpp"

Plant::Plant(int health, int price) : health(health), price(price) {}

Peashooter::Peashooter() : Plant(100, 50)
{
    texturePlanted.loadFromFile("files/Images/Peashooter.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.05f, 0.05f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}

int Peashooter::get_health() { return health; }

void Peashooter::set_position(const sf::Vector2f &new_position)
{
    spritePlanted.setPosition(new_position);
}

void Peashooter::drawPlanted(sf::RenderWindow &window)
{
    window.draw(spritePlanted);
}

void Peashooter::get_damaged(int damage)
{
    health -= damage;
}

sf::FloatRect Peashooter::get_rect()
{
    return spritePlanted.getGlobalBounds();
}

sf ::Vector2f Peashooter::getPos() { return spritePlanted.getPosition(); }

void Sunflower::set_position(const sf::Vector2f &new_position)
{
    spritePlanted.setPosition(new_position);
}

Sunflower::Sunflower() : Plant(50, 25)
{
    texturePlanted.loadFromFile("files/Images/Sunflower.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.05f, 0.05f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}
int Sunflower::get_health() { return health; }
void Sunflower::drawPlanted(sf::RenderWindow &window)
{
    window.draw(spritePlanted);
}
void Sunflower::get_damaged(int damage)
{
    health -= damage;
}
sf::FloatRect Sunflower::get_rect()
{
    return spritePlanted.getGlobalBounds();
}
sf ::Vector2f Sunflower::getPos() { return spritePlanted.getPosition(); }

Wallnut::Wallnut() : Plant(200, 75)
{
    texturePlanted.loadFromFile("files/Images/Wallnut_body.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.7f, 0.7f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}

int Wallnut::get_health() { return health; }
void Wallnut::drawPlanted(sf::RenderWindow &window)
{

    window.draw(spritePlanted);
}
void Wallnut::get_damaged(int damage)
{
    health -= damage;
}
sf::FloatRect Wallnut::get_rect()
{
    return spritePlanted.getGlobalBounds();
}
sf ::Vector2f Wallnut::getPos() { return spritePlanted.getPosition(); }
void Wallnut::set_position(const sf::Vector2f &new_position)
{
    spritePlanted.setPosition(new_position);
}