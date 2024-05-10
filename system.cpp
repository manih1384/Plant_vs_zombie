#include "system.hpp"
#include "global.hpp"
#include "zombie.hpp"
#include <cstdlib>
#include "projectile.hpp"
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
    add_plants();
    plants[0]->set_position({440, 300});
    plants[1]->set_position({400, 200});
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

void System::zombie_plant_collision()
{

    for (int i = 0; i < zombies.size(); i++)
    {
        int j = 0;
        while (j < plants.size())
        {
            FloatRect z_rect = zombies[i]->get_rect();
            FloatRect p_rect = plants[j]->get_rect();
            if (z_rect.intersects(p_rect))
            {
                zombies[i]->stop_zombie();
                Time time_passed = attack_zombie_clock.getElapsedTime();

                if (time_passed.asMilliseconds() > 500)
                {
                    plants[j]->get_damaged(zombies[i]->attack());
                    attack_zombie_clock.restart();
                }
                if (plants[j]->get_health() < 0)
                {
                    delete plants[j];
                    plants.erase(plants.begin() + j);
                    zombies[i]->start_zombie();
                    for (int x = 0; x < zombies.size(); x++)
                    {
                        if (zombies[i]->get_pos().y == zombies[x]->get_pos().y)
                        {
                            zombies[x]->start_zombie();
                        }
                    }
                }
                else
                {
                    j++;
                }
            }
            else
            {
                j++;
            }
        }
    }
}

void System::zombie_projectile_collision()
{
}

void System::update()
{
    if (state == IN_GAME)
    {
        add_zombie();
        zombie_plant_collision();
        zombie_projectile_collision();
        for (Plant *&plant : plants)
        {
            if (plant->can_shoot())
            {
                plant->shoot();
                plant->update_shots();
            }
        }

        for (int i = 0; i < zombies.size(); i++)
        {
            if (!zombies[i]->checkcollision(playground))
            {
                zombies[i]->move();
            }
            else
            {
                state = GAMEOVER;
                break;
            }
        }
    }
}

void System::fix_position(Plant *plant)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (plant->getPos().x > playground[i][j].x && plant->getPos().y > playground[i][j].y && plant->getPos().x < playground[i][j].x + DX && plant->getPos().y < playground[i][j].y + DY)
            {
                plant->set_position({playground[i][j].x + DX / 2, playground[i][j].y + DY / 2});
                return;
            }
        }
    }
}

void System::handle_events()
{
    sf::Event event;
    static bool isDragging = false;
    static int draggingPlantIndex = -1;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            state = EXIT;
            break;

        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {

                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f floatMousePos = static_cast<sf::Vector2f>(mousePos);

                for (int i = 0; i < plants.size(); i++)
                {
                    if (plants[i]->get_rect().contains(floatMousePos))
                    {
                        isDragging = true;
                        draggingPlantIndex = i;
                        break;
                    }
                }
            }
            break;

        case sf::Event::MouseButtonReleased:
            if (isDragging)
            {
                fix_position(plants[draggingPlantIndex]);

                isDragging = false;
                draggingPlantIndex = -1;
            }
            break;

        case sf::Event::MouseMoved:
            if (isDragging && draggingPlantIndex != -1)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f newPlantPos = static_cast<sf::Vector2f>(mousePos);

                plants[draggingPlantIndex]->set_position(newPlantPos);
            }
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
        if (!plants.empty())
        {
            for (const auto &plant : plants)
            {
                plant->drawPlanted(window);
            }
        }

        if (!zombies.empty())
        {
            for (int i = 0; i < zombies.size(); i++)
            {
                zombies[i]->render(window);
            }
        }
        break;
    case GAMEOVER:
        window.draw(bsprite);
    default:
        break;
    }
    window.display();
}

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
    Time time_passed = add_zombie_clock.getElapsedTime();
    if (time_passed.asMilliseconds() > 2000)
    {
        if (!playground.empty() && playground[0].size() > 0)
        {
            Zombie *new_zombie = new Zombie(playground[2][8]);
            zombies.push_back(new_zombie);
        }
        add_zombie_clock.restart();
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