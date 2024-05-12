#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
enum iconState
{
    AVAILABLE,
    COOLDOWN,
    UNAVAILABLE
};
class Icons
{
public:
    Icons();
    iconState PeashooterState = AVAILABLE;
    iconState snowShooterState = AVAILABLE;
    iconState sunflowerState = AVAILABLE;
    iconState wallnutState = AVAILABLE;
    void render(sf::RenderWindow &window);
    sf::FloatRect get_peashooter_rect();
    sf::FloatRect get_sunflower_rect();
    sf::FloatRect get_wallnut_rect();
    sf::FloatRect get_snowshooter_rect();
    sf::Sprite get_peashooter_sprite();
    sf::Sprite get_snowshooter_sprite();
    sf::Sprite get_sunflower_sprite();
    sf::Sprite get_wallnut_sprite();
    sf::Clock peashooterclock;
    sf::Clock snowshooterclock;
    sf::Clock wallnutclock;
    sf::Clock sunflowerclock;

private:
    sf::Texture peashooterIcon;
    sf::Sprite SpritePeashootericon;
    sf::Texture peashooterDimIcon;
    sf::Sprite SpritePeashooterDimicon;

    sf::Texture snowshooterIcon;
    sf::Sprite SpriteSnowshooterIcon;
    sf::Texture snowshooterDimIcon;
    sf::Sprite SpriteSnowshooterDimIcon;

    sf::Texture sunflowerIcon;
    sf::Sprite SpriteSunflowerIcon;
    sf::Texture sunflowerDimIcon;
    sf::Sprite SpriteSunflowerDimIcon;

    sf::Texture wallnutIcon;
    sf::Sprite SpritewallnutIcon;
    sf::Texture wallnutDimIcon;
    sf::Sprite SpritewallnutDimIcon;
};