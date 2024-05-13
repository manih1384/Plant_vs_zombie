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
#include "system.hpp"
#include "global.hpp"

using namespace std;
using namespace sf;

int main()
{
    System game(1400, 600);
    game.run();
    return 0;
}
