#include "zombie.hpp"
#include "global.hpp"
#include <iostream>

Zombie::Zombie(const Vector2f &startPos, int health, int damage, float speed, float Normalspeed, float FrozenSpeed)
    : position(startPos), frozenSpeed(FrozenSpeed), health(health), speed(speed), normalSpeed(Normalspeed), damage(damage)
{
}

SmallZombie::SmallZombie(const Vector2f &startPos, int health, int damage, float speed, float Normalspeed, float FrozenSpeed) : Zombie(startPos, health, damage, speed, Normalspeed, FrozenSpeed)
{
    for (int i = 0; i < 30; i++)
    {
        Texture tex;
        tex.loadFromFile("files/Images/zombie/tile0"+to_string(i)+".png");
        textures.push_back(tex);
    }

    sprite.setTexture(textures[0]);
    sprite.setScale(0.7f, 0.7f);
    sprite.setPosition(position);
}
BigZombie::BigZombie(const Vector2f &startPos, int health, int damage, float speed, float Normalspeed, float FrozenSpeed) : Zombie(startPos, health, damage, speed, Normalspeed, FrozenSpeed)
{
    for (int i = 0; i < 36; i++)
    {
        Texture tex;
        tex.loadFromFile("files/Images/bigzombie/hairmetal_walking_eating-ezgif.com-crop("+to_string(i)+").png");
        textures.push_back(tex);
    }

    sprite.setTexture(textures[0]);
    //sprite.setScale(0.7f, 0.7f);
    sprite.setPosition(position);
}

bool BigZombie::is_big()
{
    return true;
}

bool SmallZombie::is_big()
{
    return false;
}

void Zombie::move()
{
    position.x -= speed;
    sprite.setPosition(position);
    // sprite.setTexture(texture);
}

void Zombie::takeDamage(int damage)
{
    health -= damage;
}

int Zombie::attack()
{
    return damage;
}
void Zombie::update()
{
    sprite.setTexture(textures[framenum]);
    if (framenum == textures.size() - 1)
        framenum = 0;
    else
        framenum++;
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