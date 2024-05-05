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

void makeplayground(vector<vector<Vector2i>> &playground){
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            playground[i][j].x= X0 + i*DX;
            playground[i][j].y= Y0 + j*DY;
        }
        
    }
    
}


int main()
{
    vector<vector<Vector2i>> playground(5,vector<Vector2i>(9));

    // Create a system object with the desired window size
    System game(1400,600);

    // Run the game
    game.run();

    return 0;
}

