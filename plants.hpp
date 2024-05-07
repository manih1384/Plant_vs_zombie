#pragma once
#include <SFML/Graphics.hpp>

class Plant {
public:
    int health;
    int price;

    Plant(int health, int price);
    virtual void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) = 0;
};

class Peashooter : public Plant {
public:
    Peashooter();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) override;

private:
    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};

class Sunflower : public Plant {
public:
    Sunflower();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) override;

private:
    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};

class Wallnut : public Plant {
public:
    Wallnut();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position) override;

private:
    sf::Texture texturePlanted;
    sf::Texture textureCracked1;
    sf::Texture textureCracked2;
    sf::Sprite spritePlanted;
};
