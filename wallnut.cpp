#include "wallnut.hpp"

Wallnut::Wallnut() {

    texturePlanted.loadFromFile("files/Images/Wallnut_body.png");
    // textureCracked1.loadFromFile("files/Images/Wallnut_cracked1.png");
    // textureCracked2.loadFromFile("files/Images/Wallnut_cracked2.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.7f, 0.7f);
}

void Wallnut::drawPlanted(sf::RenderWindow &window, sf::Vector2f position) {
    spritePlanted.setPosition(position);
    window.draw(spritePlanted);
}
