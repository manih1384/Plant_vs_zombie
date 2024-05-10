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
#include "zombie.hpp"
#include "plants.hpp"
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
    Texture bbackground;
    Sprite bsprite;
    Clock add_zombie_clock;
    Clock attack_zombie_clock;
    void handle_events();
    void handle_mouse_press(Event ev);
    void handle_mouse_release(Event ev);
    void makeplayground(vector<vector<Vector2f>> &playground);
    void add_zombie();
    void add_plants();
    vector<Zombie*> zombies;
    vector<Plant*> plants;
public:
    System(int width, int height);
    ~System();
    void collision_detector();
    void fix_position(Plant *plant);
    vector<vector<Vector2f>> playground;
    RenderWindow window;
    int rng;
    void run();
};










#endif