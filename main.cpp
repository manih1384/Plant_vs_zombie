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
using namespace std;
using namespace sf;
int main()
{
    // Create a system object with the desired window size
    system game(800, 600);

    // Run the game
    game.run();

    return 0;
}

