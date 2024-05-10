#include "zombie.hpp"
#include "global.hpp"
#include "system.hpp"
#include <vector>
using namespace sf;
using namespace std;
Zombie::Zombie(const Vector2f &startPos)
    : position(startPos)
{
    if (!Zombie_Texture.loadFromFile("files/Images/Zombie_healthy.png"))
    {
        std::cerr << "Failed to load zombie texture" << std::endl;
        return; // If the texture doesn't load, the sprite might not be displayed
    }

    Zombie_sprite.setTexture(Zombie_Texture);
    Zombie_sprite.setScale(0.2f, 0.2f);
    Zombie_sprite.setPosition(position);

    // IntRect rect;
    // rect.width = 100;
    // rect.height = 100;
    // Zombie_sprite.setTextureRect(rect);
}

void Zombie::move()
{
    position.x -= speed;
    Zombie_sprite.setPosition(position);
    Zombie_sprite.setTexture(Zombie_Texture);
}

void Zombie::takeDamage(int damage)
{
    health -= damage;
}

void Zombie::start_zombie()
{
    speed = 1;
}
void Zombie::stop_zombie()
{
    speed = 0;
}

bool Zombie::isAlive()
{
    return health > 0;
}

int Zombie::attack()
{
    return damage;
}

void Zombie::render(RenderWindow &window)
{
    window.draw(Zombie_sprite);
}

bool Zombie::checkcollision(vector<vector<Vector2f>> playground)
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

Vector2f Zombie::get_pos() { return position; }

FloatRect Zombie::get_rect() { return Zombie_sprite.getGlobalBounds(); }