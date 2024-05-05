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
#include "peashooter.hpp"
using namespace std;
using namespace sf;

enum State
{
    IN_GAME,
    PAUSE_MENU,
    MAIN_MENU,
    VICTORY,
    GAMEOVER,
    EXIT

};
class System
{
private:
    State state;
    void render();
    void update();
    Texture background;
    Sprite sprite;
    void handle_events();
    void handle_mouse_press(Event ev);
    void handle_mouse_release(Event ev);
    vector<vector<Vector2i>> playground(5,vector<Vector2i>(9));
    void makeplayground(vector<vector<Vector2i>> &playground);
    Peashooter peashooter;
public:
    System(int width, int height);
    ~System();
    RenderWindow window;
    void run();
};










#endif