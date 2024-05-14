#ifndef SUN_HPP
#define SUN_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
using namespace sf;
using namespace std;
class Sun {
public:
    Sun(const Vector2f& startPos,int speed);

    void move();
    bool checkcollision(vector<vector<Vector2f>> playground);
    void render(RenderWindow& window);
    void stop_Sun();
    void start_Sun();
    Vector2f get_pos();
    FloatRect get_rect();

private:

    int speed=1;
    Vector2f position; 
    Sprite Sun_sprite; 
    Texture Sun_Texture;
};

#endif // Sun_HPP
