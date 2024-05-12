#include "totalsun.hpp"
TotalSun::TotalSun()
{
    if (!font.loadFromFile("files/Fonts/digit_font.ttf")) // replace with your font file path
    {
        cerr << "eror";
    }
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(240.f, 27.f);
    RectangleShape rect(Vector2f(130.f, 50.f));
    rectangle=rect;
    rectangle.setPosition(200.f,10.f);
    rectangle.setFillColor(sf::Color(20,0,255, 200));
    sun.loadFromFile("files/Images/sun.png");
    sunSprite.setTexture(sun);
    sunSprite.setPosition(170.f,0.f);
    sunSprite.setScale(0.6f,0.6f);
}

void TotalSun::setSun(int value)
{
    suns += value;
}
int TotalSun::getSun()
{
    return suns;
}
void TotalSun::render(sf::RenderWindow &window)
{
    text.setString(std::to_string(suns));
    window.draw(rectangle);
    window.draw(sunSprite);
    window.draw(text);
}
