#include "system.hpp"
#include "global.hpp"
#include "zombie.hpp"
#include <cstdlib>
using namespace std;
System::System(int width, int height)
{
    window.create(sf::VideoMode(width, height), "PLANTS_VS_ZOMBIES", sf::Style::Close);
    window.setFramerateLimit(60);
    state = IN_GAME;

    // Initialize playground before creating the zombie
    makeplayground(playground); // Ensure the playground is created

    // Load the background and set the sprite
    if (!background.loadFromFile("files/Images/Frontyard.png"))
    {
        std::cerr << "Error loading background texture" << std::endl;
        // Handle error appropriately
    }

    bbackground.loadFromFile("files/Images/Losing_Message.png");
    bsprite.setTexture(bbackground);
    bsprite.scale(3.0f, 2.0f);
    sprite.setTexture(background);
    srand(time(NULL));
    rng = rand();
    add_plants();
}

System::~System()
{
}
void System::run()
{
    while (window.isOpen() && state != EXIT)
    {
        srand(time(NULL));
        rng = rand();
        render();
        update();
        handle_events();
    }
}

// void System::collision_detector()
// {
//     for (int i = 0; i < zombies.size(); i++)
//     {
//         FloatRect z_rect = zombies[i]->get_rect();
//         FloatRect p_rect = peashooter.get_rect();
//         if (z_rect.intersects(p_rect))
//         {
//             delete zombies[i];
//             zombies.erase(zombies.begin() + i);
//             i--; // adjust the index after erasing
//         }
//     }
// }

void System::update()
{
    if (state == IN_GAME)
    {
        Time time_passed = clock.getElapsedTime();
        if (time_passed.asMilliseconds() > 1000)
        {
            add_zombie();
            clock.restart();
        }
        collision_detector();
        for (int i = 0; i < zombies.size(); i++)
        {
            if (!zombies[i]->checkcollision(playground))
            {
                zombies[i]->move();
            }
            else
            {
                state = GAMEOVER;
                break; // exit the loop once the game is over
            }
        }
    }
}
void System::handle_events()
{
    Event event;
    bool isDragging=false;
    Vector2i intInitialClickPos;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window.close();
            state = EXIT;
            break;

        case Event::MouseButtonReleased:
            // handle_mouse_release(event);
            isDragging = false;
            break;
        case Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                Vector2i intInitialClickPos = sf::Mouse::getPosition(window);
                bool isDragging = true;
            }
            // handle_mouse_press(event);
            break;
        case Event::MouseMoved:
            if (isDragging)
            {
                sf::Vector2i intCurrentMousePos = sf::Mouse::getPosition(window);
                Vector2f currentMousePos = static_cast<sf::Vector2f>(intCurrentMousePos);
                Vector2f initialClickPos = static_cast<sf::Vector2f>(intInitialClickPos);
                sf::Vector2f delta = currentMousePos - initialClickPos;
                //peashooter.drawPlanted(window, {495, 280});
            }
        }
    }
}
void System::render()
{
    window.clear();

    switch (state)
    {
    case IN_GAME:
        window.draw(sprite);
        // sunflower.drawPlanted(window, {495, 380});
        // wallnut.drawPlanted(window, {495, 480});

        plants[0]->drawPlanted(window, {495, 280});
        if (zombies.size() != 0)
        {
            for (int i = 0; i < zombies.size(); i++)
            {
                zombies[i]->render(window);
            }
        }

        // cout << zombies[0].get_pos().x << "aa"<<zombies[0].get_pos().y<<endl;
        break;
    case GAMEOVER:
        window.draw(bsprite);
    default:
        break;
    }
    window.display();
}
/*void System::handle_mouse_release(Event ev)
{
    if (ev.mouseButton.button == Mouse::Right)
        return;
    Vector2f pos = {ev.mouseButton.x, ev.mouseButton.y};

    switch (state)
    {
    case IN_GAME:

        break;

    default:
        break;
    }
}
void System::handle_mouse_press(Event ev)
{
    if (ev.mouseButton.button == Mouse::Right)
        return;
    Vector2i initialClickPos = Mouse::getPosition(window);
    switch (state)
    {
    case IN_GAME:

        break;

    default:
        break;
    }
}
*/
void System::makeplayground(vector<vector<Vector2f>> &playground)
{
    playground.resize(5, vector<Vector2f>(9));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            playground[i][j].x = X0 + j * DX;
            playground[i][j].y = Y0 + i * DY;
        }
    }
}

void System::add_zombie()
{
    // Ensure playground has at least one row and one column
    if (!playground.empty() && playground[0].size() > 0)
    {
        Zombie *new_zombie = new Zombie(playground[2][8]);
        zombies.push_back(new_zombie);
    }
}
void System::add_plants()
{
    // Ensure playground has at least one row and one column
    if (!playground.empty() && playground[0].size() > 0)
    {
        Peashooter *new_plant = new Peashooter();
        plants.push_back(new_plant);
    }
}