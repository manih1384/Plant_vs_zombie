#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
using namespace sf;
using namespace std;
class TotalSun
{
private:
    int suns = 0;
    Texture numOfSunsTexture;
    Texture sun;
    Sprite sunSprite;
    Sprite numOfSunsSprite;
    Font font;
    Text text;
    RectangleShape rectangle;

public:
    TotalSun();
    void setSun(int value);
    int getSun();
    void render(RenderWindow &window);
};