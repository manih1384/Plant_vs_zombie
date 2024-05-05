#include "system.hpp"
System::System(int width, int height)
{
    window.create(VideoMode(width, height), "PLANTS_VS_ZOMBIES", Style::Close);
    window.setFramerateLimit(60);
    state = IN_GAME;
    background.loadFromFile("files/Images/Frontyard.png");
    sprite.setTexture(background);
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
         peashooter.drawPlanted(window,{495,280});
        break;
    
    default:
        break;
    }
    window.display();
}
void System::handle_mouse_release(Event ev)
{
    if(ev.mouseButton.button==Mouse::Right)
    return;
    Vector2f pos={ev.mouseButton.x,ev.mouseButton.y};
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
    if(ev.mouseButton.button==Mouse::Right)
    return;
    Vector2f pos={ev.mouseButton.x,ev.mouseButton.y};
    switch (state)
    {
    case IN_GAME:
        
        break;
    
    default:
        break;
    }
}