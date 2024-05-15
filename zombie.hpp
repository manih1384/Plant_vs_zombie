#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
using namespace sf;
using namespace std;

class Zombie {
public:
    Zombie(const Vector2f &startPos,int health,int damage,float speed,float Normalspeed,float FrozenSpeed);
    virtual ~Zombie() {}
    virtual void move();
    virtual void takeDamage(int damage);
    virtual int attack();
    virtual bool isAlive();
    virtual bool checkCollision(vector<vector<Vector2f>> playground);
    virtual void render(RenderWindow& window);
    virtual void stopZombie();
    virtual void startZombie();
    virtual Vector2f getPos();
    virtual void applyEffect();
    virtual bool is_big()=0;
    virtual void removeEffect();
    virtual FloatRect getRect();
    Clock freezeClock;
    Clock attackClock;
    bool isFrozen = false;
    virtual void update();
    int framenum=0;

protected:
    int health = 100;
    int damage = 10;
    float speed = 1;
    float frozenSpeed = 0.5;
    float normalSpeed = 1;
    int freeze_time;
    Vector2f position;
    Sprite sprite;
    vector<Texture> textures;
};

class BigZombie : public Zombie {
public:
    BigZombie(const Vector2f &startPos,int health,int damage,float speed,float Normalspeed,float FrozenSpeed);
    bool is_big();
};

class SmallZombie : public Zombie {
public:
    SmallZombie(const Vector2f &startPos,int health,int damage,float speed,float Normalspeed,float FrozenSpeed);
    bool is_big();
};

#endif // ZOMBIE_HPP
