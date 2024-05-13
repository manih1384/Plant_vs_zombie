#include "system.hpp"
#include "plantsglobal.hpp"
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

    makeplayground(playground);
    if (!background.loadFromFile("files/Images/Frontyard.png"))
    {
        std::cerr << "Error loading background texture" << std::endl;
    }

    bbackground.loadFromFile("files/Images/Losing_Message.png");
    bsprite.setTexture(bbackground);
    bsprite.scale(3.0f, 2.0f);
    sprite.setTexture(background);
    srand(time(NULL));
    rng = rand();
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
            FloatRect z_rect = zombies[i]->getRect();
            FloatRect p_rect = plants[j]->get_rect();
            if (z_rect.intersects(p_rect))
            {
                zombies[i]->stopZombie();
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
                    zombies[i]->startZombie();
                    zombies[i]->applyEffect();
                    for (int x = 0; x < zombies.size(); x++)
                    {
                        if (zombies[i]->getPos().y == zombies[x]->getPos().y)
                        {
                            zombies[x]->startZombie();
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
    for (auto &plant : plants)
    {
        if (!(plant->can_shoot() && is_center(plant)))
            continue;

        auto &projectiles = plant->projectiles;

        for (auto *projectile : projectiles)
        {
            for (auto &zombie : zombies)
            {
                if (!(projectile->get_rect().intersects(zombie->getRect())))
                    continue;

                if (projectile->is_snow())
                {
                    zombie->applyEffect();
                    zombie->freezeClock.restart();
                }

                zombie->takeDamage(projectile->get_damage());

                delete projectile;
                projectiles.erase(find(projectiles.begin(), projectiles.end(), projectile));
                if (!zombie->isAlive())
                {
                    delete zombie;
                    zombies.erase(find(zombies.begin(), zombies.end(), zombie));
                }

                break;
            }
        }
    }
    for (auto &zombie : zombies)
    {
        if (zombie->isFrozen && zombie->freezeClock.getElapsedTime().asSeconds() > 5)
        {
            zombie->removeEffect();
        }
    }
}

vector<string> System::cut_string(string str, string delim)
{

    int char_count = 0;
    int head = 0;
    vector<string> string_list;
    string new_string;
    int num_of_delim = count(str.begin(), str.end(), delim[0]);

    for (int i = 0; i < str.size(); i++)
    {
        string separator = str.substr(i, 1);
        char_count += 1;
        string a;
        if (separator == delim)
        {
            if (head == 0)
            {
                a = str.substr(head, char_count - 1);
                string_list.push_back(a);
                head = i;
                char_count = 0;
            }
            else
            {
                a = str.substr(head + 1, char_count - 1);
                string_list.push_back(a);
                head = i;
                char_count = 0;
            }
        }
        else if (num_of_delim == 0)
        {
            string_list.push_back(str);
            break;
        }

        else if (i == str.size() - 1)
        {
            a = str.substr(head + 1, char_count);
            string_list.push_back(a);
            head = i;
            char_count = 0;
        }
    }
    return string_list;
}

void System::handle_shooting()
{
    for (Plant *&plant : plants)
    {
        if (plant->can_shoot() && is_center(plant))
        {
            plant->shoot();
            plant->update_shots();
        }
    }
}

void System::update()
{
    if (state == IN_GAME)
    {
        add_zombie();
        add_sun();
        zombie_plant_collision();
        zombie_projectile_collision();
        handle_shooting();

        for (int i = 0; i < zombies.size(); i++)
        {
            if (!zombies[i]->checkCollision(playground))
            {
                zombies[i]->move();
            }
            else
            {
                state = GAMEOVER;
                break;
            }
        }

        for (int i = 0; i < suns.size(); i++)
        {
            if (!suns[i]->checkcollision(playground))
            {
                suns[i]->move();
            }
            else
            {
                delete suns[i];
                suns.erase(find(suns.begin(), suns.end(), suns[i]));
                break;
            }
        }

        if (icons.PeashooterState == COOLDOWN && icons.peashooterclock.getElapsedTime().asSeconds() > peashooterCooldown)
        {
            icons.PeashooterState = AVAILABLE;
        }
        if (icons.sunflowerState == COOLDOWN && icons.sunflowerclock.getElapsedTime().asSeconds() > sunflowerCooldown)
        {
            icons.sunflowerState = AVAILABLE;
        }
        if (icons.wallnutState == COOLDOWN && icons.wallnutclock.getElapsedTime().asSeconds() > wallnutCooldown)
        {
            icons.wallnutState = AVAILABLE;
        }
        if (icons.snowShooterState == COOLDOWN && icons.snowshooterclock.getElapsedTime().asSeconds() > snowshooterCooldown)
        {
            icons.snowShooterState = AVAILABLE;
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
bool System::is_out_of_bound(Plant *plant)
{
    sf::Vector2f pos = plant->getPos();
    if ((pos.x > playground[0][0].x && pos.x < playground[0][8].x + DX) && (pos.y > playground[0][0].y && pos.y < playground[4][0].y + DY))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void System::sun_clicked(sf::Vector2f floatMousePos)
{
    for (int i = 0; i < suns.size(); i++)
    {
        if (suns[i]->get_rect().contains(floatMousePos))
        {

            delete suns[i];
            suns.erase(find(suns.begin(), suns.end(), suns[i]));
            totalsuns.setSun(100);
            break;
        }
    }
}
void System::cartHandler(sf::Vector2f floatMousePos)
{
    if (icons.get_peashooter_rect().contains(floatMousePos))
    {
        if (icons.PeashooterState == AVAILABLE)
        {
            icons.PeashooterState = COOLDOWN;
            totalsuns.setSun(-peashooterPrice);
            icons.peashooterclock.restart();
            add_plants("peashooter");
        }
    }
    if (icons.get_sunflower_rect().contains(floatMousePos))
    {
        if (icons.sunflowerState == AVAILABLE)
        {
            icons.sunflowerState = COOLDOWN;
            totalsuns.setSun(-sunflowerPrice);
            icons.sunflowerclock.restart();
            add_plants("sunflower");
        }
    }
    if (icons.get_wallnut_rect().contains(floatMousePos))
    {
        if (icons.wallnutState == AVAILABLE)
        {
            icons.wallnutState = COOLDOWN;
            totalsuns.setSun(-wallnutPrice);
            icons.wallnutclock.restart();
            add_plants("wallnut");
        }
    }
    if (icons.get_snowshooter_rect().contains(floatMousePos))
    {
        if (icons.snowShooterState == AVAILABLE)
        {
            icons.snowShooterState = COOLDOWN;
            totalsuns.setSun(-snowshooterPrice);
            icons.snowshooterclock.restart();
            add_plants("snowshooter");
        }
    }
}
void System::sunCartHandler()
{
    if (totalsuns.getSun() < wallnutPrice)
    {
        icons.wallnutState = UNAVAILABLE;
    }
    else if (icons.wallnutState != COOLDOWN)
    {
        icons.wallnutState = AVAILABLE;
    }

    if (totalsuns.getSun() < peashooterPrice)
    {
        icons.PeashooterState = UNAVAILABLE;
    }
    else if (icons.PeashooterState != COOLDOWN)
    {
        icons.PeashooterState = AVAILABLE;
    }

    if (totalsuns.getSun() < sunflowerPrice)
    {
        icons.sunflowerState = UNAVAILABLE;
    }
    else if (icons.sunflowerState != COOLDOWN)
    {
        icons.sunflowerState = AVAILABLE;
    }

    if (totalsuns.getSun() < snowshooterPrice)
    {
        icons.snowShooterState = UNAVAILABLE;
    }
    else if (icons.sunflowerState != COOLDOWN)
    {
        icons.snowShooterState = AVAILABLE;
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

                sun_clicked(floatMousePos);
                cartHandler(floatMousePos);
                for (int i = 0; i < plants.size(); i++)
                {
                    if (plants[i]->get_rect().contains(floatMousePos) && is_out_of_bound(plants[i]))
                    {
                        isDragging = true;
                        draggingPlantIndex = i;
                        break;
                    }
                }

                break;
            }
        case sf::Event::MouseButtonReleased:
            if (isDragging && !is_out_of_bound(plants[draggingPlantIndex]))
            {
                fix_position(plants[draggingPlantIndex]);
                isDragging = false;
                draggingPlantIndex = -1;
            }
            else
            {

                // delete plants[draggingPlantIndex];
                // //plants.erase(find(plants.begin(),plants.end(),plants[draggingPlantIndex]));
                // plants.erase(plants.begin() + draggingPlantIndex);
                // draggingPlantIndex= -1;
                // isDragging = false;
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
        totalsuns.render(window);
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

        if (!suns.empty())
        {
            for (int i = 0; i < suns.size(); i++)
            {
                suns[i]->render(window);
            }
        }
        sunCartHandler();
        icons.render(window);
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
            Vector2f center = playground[i][j];
            center.x += DX / 2;
            center.y += DY / 2;
            centers.push_back(center);
        }
    }
}

bool System::is_center(Plant *plant)
{
    bool flag = false;
    for (Vector2f center : centers)
    {
        if (center == plant->getPos())
        {
            flag = true;
        }
    }
    return flag;
}

void System::add_zombie()
{
    Time time_passed = add_zombie_clock.getElapsedTime();
    if (time_passed.asMilliseconds() > 2000)
    {
        if (!playground.empty() && playground[0].size() > 0)
        {
            if(rng%2){
                BigZombie *new_zombie = new BigZombie(playground[rng % 5][8],100,1,1,1,1);
                zombies.push_back(new_zombie);
            }
            else{
                SmallZombie *new_zombie = new SmallZombie(playground[rng % 5][8],1,1,1,1,1);
                zombies.push_back(new_zombie);
            }
            
        }
        add_zombie_clock.restart();
    }
}

void System::add_sun()
{
    Time time_passed = add_sun_clock.getElapsedTime();
    if (time_passed.asMilliseconds() > 2000)
    {
        if (!playground.empty() && playground[0].size() > 0)
        {
            Sun *new_sun = new Sun(playground[0][rng % 9]);
            suns.push_back(new_sun);
        }
        add_sun_clock.restart();
    }
}

void System::add_plants(string type)
{
    // if (!playground.empty() && playground[0].size() > 0)
    if (type == "peashooter")
    {
        Peashooter *new_plant = new Peashooter();
        new_plant->set_position({60, 50});
        plants.push_back(new_plant);
    }
    if (type == "sunflower")
    {
        Sunflower *new_plant = new Sunflower();
        new_plant->set_position({60, 140});
        plants.push_back(new_plant);
    }
    if (type == "wallnut")
    {
        Wallnut *new_plant = new Wallnut();
        new_plant->set_position({60, 230});
        plants.push_back(new_plant);
    }
    if (type == "snowshooter")
    {
        Snowshooter *new_plant = new Snowshooter();
        new_plant->set_position({60, 320});
        plants.push_back(new_plant);
    }
}