#include "peashooter.hpp"

Peashooter::Peashooter() {

    texturePlanted.loadFromFile("files/Images/Peashooter.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.05f, 0.05f);
}

void Peashooter::drawPlanted(sf::RenderWindow &window, sf::Vector2f position) {
    spritePlanted.setPosition(position);
    window.draw(spritePlanted);
}
