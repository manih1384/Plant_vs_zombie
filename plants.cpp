#include "plants.hpp"
#include <iostream>
using namespace sf;
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

bool Peashooter::can_shoot()
{
    return true;
}

void Peashooter::update_shots()
{
    for (Projectile *&projectile : projectiles)
    {

        projectile->update();
        if (projectile->get_pos().x > 1000)
        {
            delete projectile;
            projectiles.erase(find(projectiles.begin(), projectiles.end(), projectile));
        }
    }
}

void Peashooter::set_position(const sf::Vector2f &new_position)
{
    spritePlanted.setPosition(new_position);
}

void Peashooter::drawPlanted(sf::RenderWindow &window)
{
    window.draw(spritePlanted);

    for (const auto &projectile : projectiles)
    {
        projectile->render(window);
    }
}

void Peashooter::shoot()
{
    Time time_passed = clock.getElapsedTime();
    if (time_passed.asMilliseconds() > 1000)
    {

        NormalPea *newProjectile = new NormalPea({getPos().x + 15, getPos().y - 10});
        projectiles.push_back(newProjectile);
        clock.restart();
    }
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






Snowshooter::Snowshooter() : Plant(150, 70)
{
    texturePlanted.loadFromFile("files/Images/snowshooter.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.09f, 0.09f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}

int Snowshooter::get_health() { return health; }

bool Snowshooter::can_shoot()
{
    return true;
}

void Snowshooter::update_shots()
{
    for (Projectile *&projectile : projectiles)
    {

        projectile->update();
        if (projectile->get_pos().x > 1000)
        {
            delete projectile;
            projectiles.erase(find(projectiles.begin(), projectiles.end(), projectile));
        }
    }
}

void Snowshooter::set_position(const sf::Vector2f &new_position)
{
    spritePlanted.setPosition(new_position);
}

void Snowshooter::drawPlanted(sf::RenderWindow &window)
{
    window.draw(spritePlanted);

    for (const auto &projectile : projectiles)
    {
        projectile->render(window);
    }
}

void Snowshooter::shoot()
{
    Time time_passed = clock.getElapsedTime();
    if (time_passed.asMilliseconds() > 1000)
    {

        SnowPea *newProjectile = new SnowPea({getPos().x + 15, getPos().y - 25});
        projectiles.push_back(newProjectile);
        clock.restart();
    }
}

void Snowshooter::get_damaged(int damage)
{
    health -= damage;
}

sf::FloatRect Snowshooter::get_rect()
{
    return spritePlanted.getGlobalBounds();
}

sf ::Vector2f Snowshooter::getPos() { return spritePlanted.getPosition(); }







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

bool Sunflower::can_shoot()
{
    return false;
}
void Sunflower::shoot() {}
void Sunflower::update_shots() {}
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

bool Wallnut::can_shoot()
{
    return false;
}
void Wallnut::shoot() {}
void Wallnut::update_shots() {}
