#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <utility>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;

class system
{
private:
    void render();
    void update();
public:
    system(int width, int height);
    ~system();
    RenderWindow Window;
    void run();
};

system::system(int width, int height)
{
}

system::~system()
{
}








#endif