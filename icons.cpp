#include "icons.hpp"
Icons::Icons()
{
    peashooterIcon.loadFromFile("files/Images/icon_peashooter_100.png");
    SpritePeashootericon.setTexture(peashooterIcon);
    SpritePeashootericon.setScale(0.4f, 0.4f);
    SpritePeashootericon.setPosition({10, 10});
    peashooterDimIcon.loadFromFile("files/Images/icon_peashooter_100_dim.png");
    SpritePeashooterDimicon.setTexture(peashooterDimIcon);
    SpritePeashooterDimicon.setScale(0.4f, 0.4f);
    SpritePeashooterDimicon.setPosition({10, 10});

    sunflowerIcon.loadFromFile("files/Images/icon_sunflower.png");
    SpriteSunflowerIcon.setTexture(sunflowerIcon);
    SpriteSunflowerIcon.setScale(0.4f, 0.4f);
    SpriteSunflowerIcon.setPosition({10, 100});
    sunflowerDimIcon.loadFromFile("files/Images/icon_sunflower_dim.png");
    SpriteSunflowerDimIcon.setTexture(sunflowerDimIcon);
    SpriteSunflowerDimIcon.setScale(0.4f, 0.4f);
    SpriteSunflowerDimIcon.setPosition({10, 100});

    wallnutIcon.loadFromFile("files/Images/icon_walnut.png");
    SpritewallnutIcon.setTexture(wallnutIcon);
    SpritewallnutIcon.setScale(0.4f, 0.4f);
    SpritewallnutIcon.setPosition({10, 190});
    wallnutDimIcon.loadFromFile("files/Images/icon_walnut_dim.png");
    SpritewallnutDimIcon.setTexture(wallnutDimIcon);
    SpritewallnutDimIcon.setScale(0.4f, 0.4f);
    SpritewallnutDimIcon.setPosition({10, 190});

    snowshooterIcon.loadFromFile("files/Images/snowshootericon.png");
    SpriteSnowshooterIcon.setTexture(snowshooterIcon);
    SpriteSnowshooterIcon.setScale(1.1f, 1.1f);
    SpriteSnowshooterIcon.setPosition({10, 280});
    snowshooterDimIcon.loadFromFile("files/Images/snowshooterdimicon.png");
    SpriteSnowshooterDimIcon.setTexture(snowshooterDimIcon);
    SpriteSnowshooterDimIcon.setScale(1.1f, 1.1f);
    SpriteSnowshooterDimIcon.setPosition({10, 280});
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
void Icons::render(sf::RenderWindow &window)
{
    if (PeashooterExistance == EXISTS && (PeashooterState == AVAILABLE || PeashooterState == COOLDOWN || PeashooterState == UNAVAILABLE))
        window.draw(PeashooterState == AVAILABLE ? SpritePeashootericon : SpritePeashooterDimicon);

    if (snowShooterExistance == EXISTS && (snowShooterState == AVAILABLE || snowShooterState == COOLDOWN || snowShooterState == UNAVAILABLE))
        window.draw(snowShooterState == AVAILABLE ? SpriteSnowshooterIcon : SpriteSnowshooterDimIcon);

    if (wallnutExistance == EXISTS && (wallnutState == AVAILABLE || wallnutState == COOLDOWN || wallnutState == UNAVAILABLE))
        window.draw(wallnutState == AVAILABLE ? SpritewallnutIcon : SpritewallnutDimIcon);

    if (sunflowerExistance == EXISTS && (sunflowerState == AVAILABLE || sunflowerState == COOLDOWN || sunflowerState == UNAVAILABLE))
        window.draw(sunflowerState == AVAILABLE ? SpriteSunflowerIcon : SpriteSunflowerDimIcon);
}