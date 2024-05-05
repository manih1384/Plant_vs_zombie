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

enum State
{
    IN_GAME,
    PAUSE_MENU,
    MAIN_MENU,
    VICTORY,
    GAMEOVER,
    EXIT

};
class system
{
private:
    State state;
    void render();
    void update();
    void handle_events();
    void handle_mouse_press(Event ev);
    void handle_mouse_release(Event ev);
public:
    system(int width, int height);
    ~system();
    RenderWindow window;
    void run();
};










#endif