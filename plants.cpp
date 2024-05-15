#include "plants.hpp"
#include "global.hpp"
#include <iostream>
#include "system.hpp"
using namespace sf;
Plant::Plant(int health, int price) : health(health), price(price) {}

Peashooter::Peashooter(int health, int price) : Plant(health, price)
{
    for (int i = 0; i < 60; i++)
    {
        sf::Texture tex;
        tex.loadFromFile("files/Images/peashooters/tile0" + to_string(i) + ".png");
        texturePlanted.push_back(tex);
    }
    spritePlanted.setTexture(texturePlanted[0]);
    spritePlanted.setScale(1.2f, 1.2f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}
sf::Sprite Peashooter::getSprite() { return spritePlanted; }
int Peashooter::get_health() { return health; }
void Plant::update()
{
    spritePlanted.setTexture(texturePlanted[framenum]);
    if (framenum == texturePlanted.size() - 1)
        framenum = 0;
    else
        framenum++;
}
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
    if (time_passed.asMilliseconds() > peashooter_hit_rate)
    {

        NormalPea *newProjectile = new NormalPea({getPos().x + 15, getPos().y - 10}, NormalPeaSpeed, NormalPeadamage);
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
Snowshooter::Snowshooter(int health, int price) : Plant(health, price)
{
    for (int i = 0; i < 60; i++)
    {
        sf::Texture tex;
        tex.loadFromFile("files/Images/snowshooter/tile0" + to_string(i) + ".png");
        texturePlanted.push_back(tex);
    }
    spritePlanted.setTexture(texturePlanted[0]);
    spritePlanted.setScale(1.2f, 1.2f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}
sf::Sprite Snowshooter::getSprite() { return spritePlanted; }
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
    if (time_passed.asMilliseconds() > snowshooter_hit_rate)
    {

        SnowPea *newProjectile = new SnowPea({getPos().x + 15, getPos().y - 25}, snowPeaspeed, snowPeadamage);
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
Sunflower::Sunflower(int health, int price) : Plant(health, price)
{
    for (int i = 0; i < 25; i++)
    {
        sf::Texture tex;
        tex.loadFromFile("files/Images/sunflower/tile0" + to_string(i) + ".png");
        texturePlanted.push_back(tex);
    }
    spritePlanted.setTexture(texturePlanted[0]);
    spritePlanted.setScale(1.2f, 1.2f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}

void Sunflower::set_position(const sf::Vector2f &new_position)
{
    spritePlanted.setPosition(new_position);
}
sf::Sprite Sunflower::getSprite() { return spritePlanted; }
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
//void Sunflower::render(sf::RenderWindow &window) {}
Wallnut::Wallnut(int health, int price) : Plant(health, price)
{
    texturePlanted.loadFromFile("files/Images/Wallnut_body.png");
    textureCracked1.loadFromFile("files/Images/Wallnut_cracked1.png");
    textureCracked2.loadFromFile("files/Images/Wallnut_cracked2.png");
    spritePlanted.setTexture(texturePlanted);
    spriteCracked1.setTexture(textureCracked1);
    spriteCracked2.setTexture(textureCracked2);
    spritePlanted.setScale(0.7f, 0.7f);
    sf::FloatRect bounds = spritePlanted.getLocalBounds();
    spritePlanted.setOrigin(bounds.width / 2, bounds.height / 2);
}
sf::Sprite Wallnut::getSprite() { return spritePlanted; }
int Wallnut::get_health() { return health; }
void Wallnut::drawPlanted(sf::RenderWindow &window)
{
    if (health > 75)
    {
        window.draw(spritePlanted);
    }
    else if (health > 25 && health < 75)
    {
        spritePlanted.setTexture(textureCracked1);
        window.draw(spritePlanted);
    }
    else
    {
        spritePlanted.setTexture(textureCracked2);
        window.draw(spritePlanted);
    }
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
void Wallnut::update(){}
