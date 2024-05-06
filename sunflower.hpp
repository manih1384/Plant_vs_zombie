
#define PLANT_HPP

#include <SFML/Graphics.hpp>

class Sunflower {
public:
    Sunflower();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position);

private:

    sf::Texture texturePlanted;
    sf::Sprite spritePlanted;
};
