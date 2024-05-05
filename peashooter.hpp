#ifndef PLANT_HPP
#define PLANT_HPP

#include <SFML/Graphics.hpp>

class Peashooter {
public:
    Peashooter();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position);

private:
    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};

#endif // PLANT_HPP
