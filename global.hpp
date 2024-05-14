#ifndef GLOBAL_H
#define GLOBAL_H
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
using namespace sf;
using namespace std;

const string IMAGEFILE = "files/Images";
const int WIDTH = 1400;
const int HEIGHT = 600;
const int DX = 80;
const int DY = 98;
const int X0 = 255;
const int Y0 = 80;

extern int peashooterCooldown;
extern int snowshooterCooldown;
extern int sunflowerCooldown;
extern int wallnutCooldown;
extern int peashooterHealth;
extern int peashooterPrice;
extern int snowshooterHealth;
extern int snowshooterPrice;
extern int wallnutHealth;
extern int wallnutPrice;
extern int sunflowerHealth;
extern int sunflowerPrice;
extern float snowPeaspeed;
extern int snowPeadamage;
extern float NormalPeaSpeed;
extern int NormalPeadamage;
extern int peashooter_hit_rate;
extern int snowshooter_hit_rate;
extern int sunflower_hit_rate;

#endif
