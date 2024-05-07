#include "plants.hpp"

Plant::Plant(int health, int price) : health(health), price(price) {}

Peashooter::Peashooter() : Plant(100, 50)
{
    texturePlanted.loadFromFile("files/Images/Peashooter.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.05f, 0.05f);
}

void Peashooter::drawPlanted(sf::RenderWindow &window, sf::Vector2f position)
{
    spritePlanted.setPosition(position);
    window.draw(spritePlanted);
}
sf::FloatRect Peashooter::get_rect()
{
    return spritePlanted.getGlobalBounds();
}
Sunflower::Sunflower() : Plant(50, 25)
{
    texturePlanted.loadFromFile("files/Images/Sunflower.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.05f, 0.05f);
}

void Sunflower::drawPlanted(sf::RenderWindow &window, sf::Vector2f position)
{
    spritePlanted.setPosition(position);
    window.draw(spritePlanted);
}

Wallnut::Wallnut() : Plant(200, 75)
{
    texturePlanted.loadFromFile("files/Images/Wallnut_body.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.7f, 0.7f);
}

void Wallnut::drawPlanted(sf::RenderWindow &window, sf::Vector2f position)
{
    spritePlanted.setPosition(position);
    window.draw(spritePlanted);
}
