#include "peashooter.hpp"

Peashooter::Peashooter() {
    textureInCart.loadFromFile("files/Images/icon_peashooter_100_dim.png");
    spriteInCart.setTexture(textureInCart);
    spriteInCart.setPosition(0, 0); // top left corner
    spriteInCart.setScale(0.5f, 0.5f);

    texturePlanted.loadFromFile("files/Images/Peashooter.png");
    spritePlanted.setTexture(texturePlanted);
    spritePlanted.setScale(0.05f, 0.05f);
}

void Peashooter::drawInCart(sf::RenderWindow &window) {
    window.draw(spriteInCart);
}

void Peashooter::drawPlanted(sf::RenderWindow &window, sf::Vector2f position) {
    spritePlanted.setPosition(position);
    window.draw(spritePlanted);
}
