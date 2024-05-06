// #ifndef PLANT_HPP
// #define PLANT_HPP

#include <SFML/Graphics.hpp>

class Wallnut {
public:
    Wallnut();
    void drawPlanted(sf::RenderWindow &window, sf::Vector2f position);

private:
    
    sf::Texture texturePlanted;
    sf::Texture textureCracked1;
    sf::Texture textureCracked2;
    sf::Sprite spritePlanted;
};

// #endif // PLANT_HPP
