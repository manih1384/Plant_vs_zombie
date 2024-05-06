#include "sunflower.hpp"

Sunflower::Sunflower() {

    texturePlanted.loadFromFile("files/Images/Sunflower.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.05f, 0.05f);
}

void Sunflower::drawPlanted(sf::RenderWindow &window, sf::Vector2f position) {
    spritePlanted.setPosition(position);
    window.draw(spritePlanted);
}
