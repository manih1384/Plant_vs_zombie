#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
class Icons
{
public:
    Icons();
    sf::FloatRect get_rect();

private:
    sf::Texture peashooterIcon;
    sf::Sprite SpritePeashootericon;

    sf::Texture sunflowerIcon;
    sf::Sprite SpriteSunflowerIcon;

    sf::Texture wallnutIcon;
    sf::Sprite SpritewallnutIcon;

    sf::Texture peashooterIcon;
    sf::Sprite Spriteer;
};