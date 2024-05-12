#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
using namespace sf;
using namespace std;
class TotalSun
{
private:
    int suns=0;
    Texture numOfSunsTexture;
    Sprite numOfSunsSprite;
    Font font;
    Text text;

public:
    TotalSun();
    void setSun(int value);
    void render(RenderWindow &window);
};