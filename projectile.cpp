#include "projectile.hpp"
#include <iostream>

Projectile::Projectile(const sf::Vector2f& startPos)
    : position(startPos){
    // Base initialization
}

void Projectile::update() {
    position.x += speed;
    sprite.setPosition(position);
}

void Projectile::render(sf::RenderWindow& window) {
    sprite.setPosition(position);
    //sprite.scale(0.3f,0.3f);
    window.draw(sprite); 
}

sf::FloatRect Projectile::get_rect() const {
    return sprite.getGlobalBounds();
}

NormalPea::NormalPea(const sf::Vector2f& startPos)
    : Projectile(startPos) {
    texture.loadFromFile("files/Images/pea.png");
    sprite.setTexture(texture);
}

int NormalPea::get_damage() const {
    return damage;
}

SnowPea::SnowPea(const sf::Vector2f& startPos)
    : Projectile(startPos) {
    if (!texture.loadFromFile("files/Images/SnowPea.png")) {
        std::cerr << "Error loading SnowPea texture" << std::endl;
    }
    sprite.setTexture(texture);
}

int SnowPea::get_damage() const {
    return damage;
}
