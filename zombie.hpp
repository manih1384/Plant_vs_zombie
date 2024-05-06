#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <SFML/Graphics.hpp>

class Zombie {
public:
    Zombie(int health, float speed, const sf::Vector2f& startPos, const sf::Texture& texture);

    void move();
    void takeDamage(int damage);
    void attack();
    bool isAlive();
    void draw(sf::RenderWindow& window);

private:
    int health;
    float speed;
    sf::Vector2f position; 
    sf::Sprite sprite; 
};

#endif // ZOMBIE_HPP
