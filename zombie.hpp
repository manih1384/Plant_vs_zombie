#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
using namespace sf;
using namespace std;
class Zombie {
public:
    Zombie(const Vector2f& startPos);

    void move();
    void takeDamage(int damage);
    int attack();
    bool isAlive();
    bool checkcollision(vector<vector<Vector2f>> playground);
    void render(RenderWindow& window);
    void stop_zombie();
    void start_zombie();
    Vector2f get_pos();
    void apply_effect();
    FloatRect get_rect();
    void remove_effect();
    Clock freeze_clock;
    bool is_froze = false;

private:
    int health=100;
    int damage=10;
    float speed=1;
    float frozen_speed=0.5;
    float normal_speed=1;
    
    Vector2f position; 
    Sprite Zombie_sprite; 
    Texture Zombie_Texture;
};

#endif // ZOMBIE_HPP
