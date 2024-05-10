#include "icons.hpp"
Icons::Icons()
{
    peashooterIcon.loadFromFile("files/Images/icon_peashooter_100.png");
    SpritePeashootericon.setTexture(peashooterIcon);
    SpritePeashootericon.setScale(0.4f, 0.4f);
    SpritePeashootericon.setPosition({10,10});

    sunflowerIcon.loadFromFile("files/Images/icon_sunflower.png");
    SpriteSunflowerIcon.setTexture(sunflowerIcon);
    SpriteSunflowerIcon.setScale(0.05f, 0.05f);

    wallnutIcon.loadFromFile("files/Images/icon_walnut.png");
    SpritewallnutIcon.setTexture(wallnutIcon);
    SpritewallnutIcon.setScale(0.05f, 0.05f);
}

sf::FloatRect Icons::get_peashooter_rect()
{
    return SpritePeashootericon.getGlobalBounds();
}

sf::FloatRect Icons::get_sunflower_rect()
{
    return SpriteSunflowerIcon.getGlobalBounds();
}

sf::FloatRect Icons::get_wallnut_rect()
{
    return SpritewallnutIcon.getGlobalBounds();
}
sf::Sprite Icons::get_peashooter_sprite()
{
    return SpritePeashootericon;
}