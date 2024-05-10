#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace sf;
class Projectile
{
public:
    Projectile(const Vector2f &startPos);

    virtual void update();
    virtual void render(RenderWindow &window);
    virtual Vector2f get_pos() = 0;
    virtual FloatRect get_rect() const;
    virtual int get_damage() const = 0;

protected:
    Vector2f position;
    float speed=5;
    Sprite sprite;
    Texture texture;
    int damage=30;
};

class NormalPea : public Projectile
{
public:
    NormalPea(const sf::Vector2f &startPos);
    virtual Vector2f get_pos();
    int get_damage() const override;
};

class SnowPea : public Projectile
{
public:
    virtual Vector2f get_pos();
    SnowPea(const sf::Vector2f &startPos);
    int get_damage() const override;
};
