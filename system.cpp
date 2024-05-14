#include "system.hpp"
#include "global.hpp"
#include "zombie.hpp"
#include <cstdlib>
#include "projectile.hpp"
#include "zombiesglobal.hpp"
#include "sunglobal.hpp"
using namespace std;
void System::plants_setting()
{
    ifstream file_name;
    string new_line;
    file_name.open("files/setting/plants_setting.csv");
    getline(file_name, new_line);
    while (getline(file_name, new_line))
    {
        stringstream ssnew_line(new_line);
        string name, damage, health, cooldown, hit_rate, speed, price;
        getline(ssnew_line, name, ',');
        getline(ssnew_line, damage, ',');
        getline(ssnew_line, health, ',');
        getline(ssnew_line, cooldown, ',');
        getline(ssnew_line, hit_rate, ',');
        getline(ssnew_line, speed, ',');
        getline(ssnew_line, price, ',');
        cout << name;
        if (name == "peashooter")
        {
            icons.PeashooterExistance = EXISTS;
            peashooterHealth = stoi(health);
            peashooterCooldown = stoi(cooldown);
            peashooterPrice = stoi(price);
            peashooter_hit_rate = stoi(hit_rate);
            NormalPeadamage = stoi(damage);
            NormalPeaSpeed = stof(speed);
        }
        else if (name == "snowshooter")
        {
            icons.snowShooterExistance = EXISTS;
            snowshooterHealth = stoi(health);
            snowshooterCooldown = stoi(cooldown);
            snowshooterPrice = stoi(price);
            snowshooter_hit_rate = stoi(hit_rate);
            snowPeadamage = stoi(damage);
            snowPeaspeed = stof(speed);
        }
        else if (name == "sunflower")
        {
            icons.sunflowerExistance = EXISTS;
            sunflowerHealth = stoi(health);
            sunflowerCooldown = stoi(cooldown);
            sunflowerPrice = stoi(price);
        }
        else if (name == "wallnut")
        {
            icons.wallnutExistance = EXISTS;
            wallnutHealth = stoi(health);
            wallnutCooldown = stoi(cooldown);
            wallnutPrice = stoi(price);
        }
    }
    file_name.close();
}
System::System(int width, int height)
{
    plants_setting();
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

    victory_background.loadFromFile("files/Images/victoryscreen.jpeg");
    victory_sprite.setTexture(victory_background);
    victory_sprite.scale(1.5f, 1.0f);

    sprite.setTexture(background);
    srand(time(NULL));
    rng = rand();
    zombie_setting();
    wave_setting();
    sun_setting();
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
                Time time_passed = zombies[i]->attackClock.getElapsedTime();

                if (time_passed.asSeconds() > smallZombieHitrate && !zombies[i]->is_big())
                {
                    plants[j]->get_damaged(zombies[i]->attack());
                    zombies[i]->attackClock.restart();
                }
                else if (time_passed.asSeconds() > bigZombieHitrate && zombies[i]->is_big())
                {
                    plants[j]->get_damaged(zombies[i]->attack());
                    zombies[i]->attackClock.restart();
                }

                if (plants[j]->get_health() < 0)
                {
                    for (int x = 0; x < occupied_positions.size(); x++)
                    {
                        if (plants[j]->getPos() == occupied_positions[x])
                        {
                            occupied_positions.erase(occupied_positions.begin() + x);
                        }
                    }
                    delete plants[j];

                    plants.erase(plants.begin() + j);
                    if (zombies[i]->isFrozen)
                    {
                        zombies[i]->applyEffect();
                    }
                    else
                    {
                        zombies[i]->startZombie();
                    }

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
                if (zombies[i]->isFrozen)
                {
                    zombies[i]->applyEffect();
                }
                else
                {
                    zombies[i]->startZombie();
                }

                j++;
            }
        }
    }
}

void System::zombie_setting()
{
    vector<string> lines = read_csv("files/setting/zombie_setting.csv");

    for (int i = 0; i < lines.size(); i++)
    {
        vector<string> data = cut_string(lines[i], ",");
        if (data[0] == "regular")
        {
            zombie_type = SMALL_ONLY;
            smallZombieDamage = stoi(data[1]);
            smallZombieHealth = stoi(data[2]);
            smallZombieHitrate = stoi(data[3]);
            smallZombieSpeed = stof(data[4]);
            smallZombieFreezeTime = stoi(data[5]);
        }
        if (data[0] == "gargantuar")
        {
            zombie_type = BIG_ONLY;
            bigZombieDamage = stoi(data[1]);
            bigZombieHealth = stoi(data[2]);
            bigZombieHitrate = stoi(data[3]);
            bigZombieSpeed = stof(data[4]);
            bigZombieFreezeTime = stoi(data[5]);
        }
    }
    if (lines.size() == 3)
    {
        zombie_type = BOTH;
    }
}

void System::wave_setting()
{
    vector<string> lines = read_csv("files/setting/wave_setting.csv");

    vector<string> data = cut_string(lines[1], ",");

    total_time = stof(data[0]);
    wave_time = stof(data[1]);
    wave_attack = stof(data[2]);
    attack_rate = stof(data[3]);
}

void System::sun_setting()
{
    vector<string> lines = read_csv("files/setting/sun_setting.csv");

    vector<string> data = cut_string(lines[1], ",");

    sunSpeed = stoi(data[0]);
    sunInterval = stoi(data[1]);
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
        if (zombie->isFrozen && zombie->freezeClock.getElapsedTime().asSeconds() > smallZombieFreezeTime && !zombie->is_big())
        {
            zombie->removeEffect();
        }
        if (zombie->isFrozen && zombie->freezeClock.getElapsedTime().asSeconds() > bigZombieFreezeTime && zombie->is_big())
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

vector<string> System::read_csv(const char path[256])
{
    vector<string> lines;
    ifstream file_name;
    string new_line;
    file_name.open(path);
    while (getline(file_name, new_line))
    {
        lines.push_back(new_line);
    }
    file_name.close();
    return lines;
}

void System::update()
{
    if (state == IN_GAME)
    {
        if (zombies.size() == 0 && total_clock.getElapsedTime().asSeconds() > total_time)
        {
            state = VICTORY;
            return;
        }
        if (total_clock.getElapsedTime().asSeconds() < total_time)
        {
            if (wave_clock.getElapsedTime().asSeconds() > wave_time)
            {
                wave_clock.restart();
                wave_attack += attack_rate;
            }
            else

            {
                if (spawn_clock.getElapsedTime().asSeconds() > wave_time / wave_attack)
                {
                    add_zombie();
                    spawn_clock.restart();
                }
            }
        }
    }

    add_sun();
    add_stationary_sun();
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

void System::fix_position(Plant *plant)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (plant->getPos().x > playground[i][j].x && plant->getPos().y > playground[i][j].y && plant->getPos().x < playground[i][j].x + DX && plant->getPos().y < playground[i][j].y + DY)
            {
                plant->set_position({playground[i][j].x + DX / 2, playground[i][j].y + DY / 2});
                occupied_positions.push_back(plant->getPos());
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
    if (icons.get_peashooter_rect().contains(floatMousePos) && icons.PeashooterState == AVAILABLE && icons.PeashooterExistance == EXISTS)
    {

        icons.PeashooterState = COOLDOWN;
        totalsuns.setSun(-peashooterPrice);
        icons.peashooterclock.restart();
        add_plants("peashooter");
    }
    if (icons.get_sunflower_rect().contains(floatMousePos) && icons.sunflowerState == AVAILABLE && icons.sunflowerExistance == EXISTS)
    {

        icons.sunflowerState = COOLDOWN;
        totalsuns.setSun(-sunflowerPrice);
        icons.sunflowerclock.restart();
        add_plants("sunflower");
    }
    if (icons.get_wallnut_rect().contains(floatMousePos) && icons.wallnutState == AVAILABLE && icons.wallnutExistance == EXISTS)
    {

        icons.wallnutState = COOLDOWN;
        totalsuns.setSun(-wallnutPrice);
        icons.wallnutclock.restart();
        add_plants("wallnut");
    }
    if (icons.get_snowshooter_rect().contains(floatMousePos) && icons.snowShooterState == AVAILABLE && icons.snowShooterExistance == EXISTS)
    {
        icons.snowShooterState = COOLDOWN;
        totalsuns.setSun(-snowshooterPrice);
        icons.snowshooterclock.restart();
        add_plants("snowshooter");
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
void System::handle_mouse_press(Event event, bool &isDragging, int &draggingPlantIndex)
{
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
    }
}

bool System::is_occupied(Vector2f position)
{
    for (int i = 0; i < occupied_positions.size(); i++)
    {
        if (position.x > occupied_positions[i].x-DX/2 &&
            position.x < occupied_positions[i].x+DX/2  &&
            position.y > occupied_positions[i].y-DY/2 &&
            position.y < occupied_positions[i].y+DY/2

        )
        {
            return true;
        }
    }
    return false;
}

void System::handle_mouse_release(Event event, bool &isDragging, int &draggingPlantIndex)
{
    if (isDragging &&
        !is_out_of_bound(plants[draggingPlantIndex]) &&
        !is_occupied(plants[draggingPlantIndex]->getPos()))
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
}
void System::handle_mouse_moved(Event event, bool &isDragging, int &draggingPlantIndex)
{
    if (isDragging && draggingPlantIndex != -1)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f newPlantPos = static_cast<sf::Vector2f>(mousePos);

        plants[draggingPlantIndex]->set_position(newPlantPos);
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
            handle_mouse_press(event, isDragging, draggingPlantIndex);
            break;

        case sf::Event::MouseButtonReleased:
            handle_mouse_release(event, isDragging, draggingPlantIndex);

            break;

        case sf::Event::MouseMoved:
            handle_mouse_moved(event, isDragging, draggingPlantIndex);
            break;
        }
    }
}
void System::renderZombies()
{
    if (!zombies.empty())
    {
        for (int i = 0; i < zombies.size(); i++)
        {
            zombies[i]->render(window);
        }
    }
}
void System::renderSuns()
{
    if (!suns.empty())
    {
        for (int i = 0; i < suns.size(); i++)
        {
            suns[i]->render(window);
        }
    }
}
void System::drawPlants()
{
    if (!plants.empty())
    {
        for (const auto &plant : plants)
        {
            plant->drawPlanted(window);
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
        drawPlants();
        renderZombies();
        renderSuns();
        sunCartHandler();
        icons.render(window);
        break;
    case GAMEOVER:
        window.draw(bsprite);
    case VICTORY:
        window.draw(victory_sprite);
        break;
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

    if (!playground.empty() && playground[0].size() > 0)
    {
        int location_rng = rng;
        if (zombie_type == SMALL_ONLY)
        {
            rng = 0;
        }
        if (zombie_type == BIG_ONLY)
        {
            rng = 1;
        }
        if (rng % 2)
        {
            BigZombie *new_zombie = new BigZombie(playground[location_rng % 5][8], bigZombieHealth, bigZombieDamage, bigZombieSpeed, bigZombieSpeed, bigZombieSpeed / 2);
            zombies.push_back(new_zombie);
        }
        else
        {
            SmallZombie *new_zombie = new SmallZombie(playground[location_rng % 5][8], smallZombieHealth, smallZombieDamage, smallZombieSpeed, smallZombieSpeed, smallZombieSpeed / 2);
            zombies.push_back(new_zombie);
        }
    }
}

void System::add_sun()
{
    Time time_passed = add_sun_clock.getElapsedTime();
    if (time_passed.asSeconds() > sunInterval)
    {
        if (!playground.empty() && playground[0].size() > 0)
        {
            Sun *new_sun = new Sun(playground[0][rng % 9], sunSpeed);
            suns.push_back(new_sun);
        }
        add_sun_clock.restart();
    }
}
bool isSunflower(Plant *plant)
{
    return dynamic_cast<Sunflower *>(plant) != nullptr;
}

void System::add_stationary_sun()
{
    Time time_passed = stationarySunClock.getElapsedTime();
    for (int i = 0; i < plants.size(); i++)
    {
        if (isSunflower(plants[i]) && time_passed.asSeconds() > sunflower_hit_rate)
        {

            Sun *new_sun = new Sun(plants[i]->getSprite().getPosition(), 0);
            suns.push_back(new_sun);
            stationarySunClock.restart();
        }
    }
}

void System::add_plants(string type)
{
    if (type == "peashooter")
    {
        Peashooter *new_plant = new Peashooter(peashooterHealth, peashooterPrice);
        new_plant->set_position({60, 50});
        plants.push_back(new_plant);
    }
    if (type == "sunflower")
    {
        Sunflower *new_plant = new Sunflower(sunflowerHealth, sunflowerPrice);
        new_plant->set_position({60, 140});
        plants.push_back(new_plant);
    }
    if (type == "wallnut")
    {
        Wallnut *new_plant = new Wallnut(wallnutHealth, wallnutPrice);
        new_plant->set_position({60, 230});
        plants.push_back(new_plant);
    }
    if (type == "snowshooter")
    {
        Snowshooter *new_plant = new Snowshooter(snowshooterHealth, snowshooterPrice);
        new_plant->set_position({60, 320});
        plants.push_back(new_plant);
    }
}