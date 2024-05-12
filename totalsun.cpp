#include "totalsun.hpp"
TotalSun::TotalSun()
{
    if (!font.loadFromFile("files/Fonts/ArielFont.otf")) // replace with your font file path
    {
       cerr<<"eror";
    }
    text.setFont(font);
    text.setCharacterSize(956); // in pixels
    text.setFillColor(sf::Color::Black);
    text.setPosition(10.f, 10.f); // top-left corner
        text.setString("TOTAL SUNS : " + std::to_string(suns));
}

void TotalSun::setSun(int value)
{
    suns+=value;
}

void TotalSun::render(sf::RenderWindow &window)
{
    // text.setString("TOTAL SUNS : " + std::to_string(suns));
    window.draw(text);
}
