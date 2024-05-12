#include "sun.hpp"
#include "global.hpp"
#include "system.hpp"
#include <vector>
using namespace sf;
using namespace std;
Sun::Sun(const Vector2f &startPos)
    : position(startPos)
{
    if (!Sun_Texture.loadFromFile("files/Images/sun.png"))
    {
        std::cerr << "Failed to load Sun texture" << std::endl;
        return; // If the texture doesn't load, the sprite might not be displayed
    }

    Sun_sprite.setTexture(Sun_Texture);
    Sun_sprite.setScale(0.7f, 0.7f);
    Sun_sprite.setPosition(position);

    // IntRect rect;
    // rect.width = 100;
    // rect.height = 100;
    // Sun_sprite.setTextureRect(rect);
}

void Sun::move()
{
    position.y += speed;
    Sun_sprite.setPosition(position);
    Sun_sprite.setTexture(Sun_Texture);
}

void Sun::start_Sun()
{
    speed = 1;
}
void Sun::stop_Sun()
{
    speed = 0;
}



void Sun::render(RenderWindow &window)
{
    window.draw(Sun_sprite);
}

bool Sun::checkcollision(vector<vector<Vector2f>> playground)
{
    bool detected = false;
    for (int i = 0; i < 8; i++)
    {
        if (position.y > playground[4][i].y + DY)
        {
            detected = true;
        }
    }

    return detected;
}

Vector2f Sun::get_pos() { return position; }

FloatRect Sun::get_rect() { return Sun_sprite.getGlobalBounds(); }