#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "zombie.hpp"
#include "projectile.hpp"
class Plant
{
public:
    int health;
    int price;
    Clock clock;
    virtual sf::FloatRect get_rect() = 0;
    Plant(int health, int price);
    virtual void drawPlanted(sf::RenderWindow &window) = 0;
    virtual sf::Vector2f getPos() = 0;
    virtual void get_damaged(int damage) = 0;
    virtual int get_health() = 0;
    virtual bool can_shoot() = 0;
    virtual void set_position(const sf::Vector2f &new_position) = 0;
    virtual void shoot()=0;
    virtual void update_shots()=0;

public:
    std::vector<Projectile *> projectiles;
};

class Peashooter : public Plant
{
public:
    Peashooter();
    void drawPlanted(sf::RenderWindow &window) override;
    void get_damaged(int damage) override;
    int get_health() override;
    void set_position(const sf::Vector2f &new_position) override;
    sf::Vector2f getPos() override;
    sf::FloatRect get_rect() override;
    bool can_shoot() override;
    void shoot() override;
    void update_shots() override;
    

private:
    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};

class Sunflower : public Plant
{
public:
    Sunflower();
    void drawPlanted(sf::RenderWindow &window) override;
    void get_damaged(int damage) override;
    void set_position(const sf::Vector2f &new_position) override;
    int get_health() override;
    sf::Vector2f getPos() override;
    sf::FloatRect get_rect() override;
    bool can_shoot() override;

private:
    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};

class Wallnut : public Plant
{
public:
    Wallnut();
    void drawPlanted(sf::RenderWindow &window) override;
    void get_damaged(int damage) override;
    int get_health() override;
    sf::Vector2f getPos() override;
    void set_position(const sf::Vector2f &new_position) override;
    sf::FloatRect get_rect() override;
    bool can_shoot() override;

private:
    sf::Texture texturePlanted;
    sf::Texture textureCracked1;
    sf::Texture textureCracked2;
    sf::Sprite spritePlanted;
};
