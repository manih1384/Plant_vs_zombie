#include "system.hpp"
#include "global.hpp"
#include "zombie.hpp"
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
    sprite.setTexture(background);
    // Ensure playground has at least one row and one column
    if (!playground.empty() && playground[0].size() > 0)
    {
        Zombie z(playground[0][8]); 
        cout<<playground[0][8].x;
        cout<<playground[0][8].y;
        zombies.push_back(z);
    }
}

System::~System()
{
}
void System::run()
{
    while (window.isOpen() && state != EXIT)
    {
        update();
        render();
        handle_events();
    }
}
void System::update()
{
    for (int i = 0; i < zombies.size(); i++)
    {
        if (!zombies[i].checkcollision(playground))
        {
            zombies[i].move();
        }
    }
}
void System::handle_events()
{
    Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case Event::Closed:
            window.close();
            state = EXIT;
            break;

        case Event::MouseButtonReleased:
            handle_mouse_release(event);
            break;
        case Event::MouseButtonPressed:
            handle_mouse_press(event);
            break;
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
        sunflower.drawPlanted(window, {495, 380});
        wallnut.drawPlanted(window, {495, 480});

        peashooter.drawPlanted(window, {495, 280});
        zombies[0].render(window);
        // cout << zombies[0].get_pos().x << "aa"<<zombies[0].get_pos().y<<endl;
        break;

    default:
        break;
    }
    window.display();
}
void System::handle_mouse_release(Event ev)
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
    Vector2f pos = {ev.mouseButton.x, ev.mouseButton.y};
    switch (state)
    {
    case IN_GAME:

        break;

    default:
        break;
    }
}

void System::makeplayground(vector<vector<Vector2f>> &playground)
{
    playground.resize(5, vector<Vector2f>(9));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            playground[i][j].x = X0 + j * DX;
            playground[i][j].y = Y0 + i * DY;
        }
    }
}
