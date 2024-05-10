#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
class Icons
{
public:
    Icons();
    sf::FloatRect get_peashooter_rect();
    sf::FloatRect get_sunflower_rect();
    sf::FloatRect get_wallnut_rect();
    sf::Sprite get_peashooter_sprite();
    sf::Sprite get_sunflower_sprite();
    sf::Sprite get_wallnut_sprite();

private:
    sf::Texture peashooterIcon;
    sf::Sprite SpritePeashootericon;

    sf::Texture sunflowerIcon;
    sf::Sprite SpriteSunflowerIcon;

    sf::Texture wallnutIcon;
    sf::Sprite SpritewallnutIcon;
};