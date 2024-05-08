#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Plant {
public:
    int health;
    int price;
    virtual sf::FloatRect get_rect()=0;
    Plant(int health, int price);
    virtual void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) = 0;
    virtual sf::Vector2f getPos()=0;
    virtual void get_damaged(int damage)=0;
    virtual int get_health()=0;
};

class Peashooter : public Plant {
public:
    Peashooter();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) override;
    void get_damaged(int damage) override;
    int get_health() override;
    sf::Vector2f getPos() override;
    sf::FloatRect get_rect() override;

private:
    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};

class Sunflower : public Plant {
public:
    Sunflower();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) override;
    void get_damaged(int damage) override;
    int get_health() override;
    sf::Vector2f getPos() override;
    sf::FloatRect get_rect() override;

private:
    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};

class Wallnut : public Plant {
public:
    Wallnut();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) override;
    void get_damaged(int damage) override;
    int get_health() override;
    sf::Vector2f getPos() override;
    sf::FloatRect get_rect() override;

private:
    sf::Texture texturePlanted;
    sf::Texture textureCracked1;
    sf::Texture textureCracked2;
    sf::Sprite spritePlanted;
};
