#include "zombie.hpp"

Zombie::Zombie(int health, float speed, const sf::Vector2f& startPos, const sf::Texture& texture)
    : health(health), speed(speed), position(startPos) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Zombie::move() {
    position.x -= speed; 
    sprite.setPosition(position);
}

void Zombie::takeDamage(int damage) {
    health -= damage;
}

bool Zombie::isAlive() {
    return health > 0;
}

void Zombie::attack() {
}

void Zombie::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
