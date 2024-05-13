#include "zombie.hpp"
#include "global.hpp"
#include <iostream>

Zombie::Zombie(const Vector2f &startPos,int health,int damage,int speed,int Normalspeed,int FrozenSpeed)
         : position(startPos),frozenSpeed(FrozenSpeed),health(health),speed(speed),normalSpeed(Normalspeed),damage(damage){
}

SmallZombie::SmallZombie(const Vector2f &startPos,int health,int damage,int speed,int Normalspeed,int FrozenSpeed) : Zombie(startPos,health,damage,speed,Normalspeed,FrozenSpeed)
{
    if (!texture.loadFromFile("files/Images/Zombie_healthy.png"))
    {
        std::cerr << "Failed to load zombie texture" << std::endl;
        return;
    }
    sprite.setTexture(texture);
    sprite.setScale(0.2f, 0.2f);
    sprite.setPosition(position);
}

BigZombie::BigZombie(const Vector2f &startPos,int health,int damage,int speed,int Normalspeed,int FrozenSpeed) : Zombie(startPos,health,damage,speed,Normalspeed,FrozenSpeed)
{
    if (!texture.loadFromFile("files/Images/bigzombie.png"))
    {
        std::cerr << "Failed to load zombie texture" << std::endl;
        return;
    }
    sprite.setTexture(texture);
    sprite.setScale(0.16f, 0.16f);
    sprite.setPosition(position);
}

void Zombie::move()
{
    position.x -= speed;
    sprite.setPosition(position);
    sprite.setTexture(texture);
}

void Zombie::takeDamage(int damage)
{
    health -= damage;
}

int Zombie::attack()
{
    return damage;
}

bool Zombie::isAlive()
{
    return health > 0;
}

bool Zombie::checkCollision(vector<vector<Vector2f>> playground)
{
    bool detected = false;
    for (int i = 0; i < 4; i++)
    {
        if (position.x < playground[i][0].x - DX)
        {
            detected = true;
        }
    }
    return detected;
}

void Zombie::render(RenderWindow &window)
{
    window.draw(sprite);
}

void Zombie::stopZombie()
{
    speed = 0;
}

void Zombie::startZombie()
{
    speed = normalSpeed;
}

Vector2f Zombie::getPos()
{
    return position;
}

void Zombie::applyEffect()
{
    speed = frozenSpeed;
    isFrozen = true;
}

void Zombie::removeEffect()
{
    speed = normalSpeed;
    isFrozen = false;
}

FloatRect Zombie::getRect()
{
    return sprite.getGlobalBounds();
}