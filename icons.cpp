#include "icons.hpp"
Icons::Icons()
{
    peashooterIcon.loadFromFile("files/Images/icon_peashooter_100.png");
    SpritePeashootericon.setTexture(peashooterIcon);
    SpritePeashootericon.setScale(0.4f, 0.4f);
    SpritePeashootericon.setPosition({10, 10});

    sunflowerIcon.loadFromFile("files/Images/icon_sunflower.png");
    SpriteSunflowerIcon.setTexture(sunflowerIcon);
    SpriteSunflowerIcon.setScale(0.4f, 0.4f);
    SpriteSunflowerIcon.setPosition({10, 100});

    wallnutIcon.loadFromFile("files/Images/icon_walnut.png");
    SpritewallnutIcon.setTexture(wallnutIcon);
    SpritewallnutIcon.setScale(0.4f, 0.4f);
    SpritewallnutIcon.setPosition({10, 190});

    snowshooterIcon.loadFromFile("files/Images/snowshootericon.png");
    SpriteSnowshooterIcon.setTexture(snowshooterIcon);
    SpriteSnowshooterIcon.setScale(1.6f,1.6f );
    SpriteSnowshooterIcon.setPosition({10, 280});
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
sf::FloatRect Icons::get_snowshooter_rect()
{
    return SpriteSnowshooterIcon.getGlobalBounds();
}
sf::Sprite Icons::get_peashooter_sprite()
{
    return SpritePeashootericon;
}
sf::Sprite Icons::get_sunflower_sprite()
{
    return SpriteSunflowerIcon;
}
sf::Sprite Icons::get_wallnut_sprite()
{
    return SpritewallnutIcon;
}
sf::Sprite Icons::get_snowshooter_sprite()
{
    return SpriteSnowshooterIcon;
}