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
#include "icons.hpp"
#include "sun.hpp"
#include "totalsun.hpp"
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
    Clock add_sun_clock;
    Clock attack_zombie_clock;
    Clock attack_plant_clock;
    void handle_events();
    void handle_mouse_press(Event ev);
    void handle_mouse_release(Event ev);
    void makeplayground(vector<vector<Vector2f>> &playground);
    void add_zombie();
    void add_sun();
    void sun_clicked(sf::Vector2f floatMousePos);
    void cartHandler(sf::Vector2f floatMousePos);
    void sunCartHandler();
    void add_plants(string type);
    vector<Zombie *> zombies;
    vector<Plant *> plants;
    vector<Sun *> suns;
    TotalSun totalsuns;
    Icons icons;
    vector<Vector2f> centers;

public:
    System(int width, int height);
    ~System();
    vector<string> cut_string(string str, string delim);
    void zombie_projectile_collision();
    void zombie_plant_collision();
    void handle_shooting();
    bool is_center(Plant *plant);
    void fix_position(Plant *plant);
    bool is_out_of_bound(Plant *plant);
    vector<string> read_csv(const char path[256]);
    vector<vector<Vector2f>> playground;

    RenderWindow window;
    int rng;
    void run();
};

#endif