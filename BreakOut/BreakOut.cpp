#include <SFML/Graphics.hpp>
#include"Configs.h"
#include<iostream>
#include"Controller.h"
#include<Windows.h>
size_t toMilliseconds(SYSTEMTIME time) {
    return time.wHour * 3600000 + time.wMinute * 60000 + time.wSecond * 1000 + time.wMilliseconds;
}
int main()
{
    SYSTEMTIME time;
    GetLocalTime(&time);
    globalConfigs.setScreen(sf::Vector2i(800, 600));
    globalConfigs.setGameScreen(sf::Vector2f(15, 10));
    Controller controller;
    // Create a window
    sf::RenderWindow window(sf::VideoMode(globalConfigs.getScreen<int>().x, globalConfigs.getScreen<int>().y), "SFML Window");
    // Main loop
    sf::View view = window.getDefaultView();
    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                    controller.buttonChange(event.key.code,true);
            }
            if (event.type == sf::Event::KeyReleased) {
                controller.buttonChange(event.key.code,false);
            }
            if (event.type == sf::Event::Resized) {
                view.setSize({
                   static_cast<float>(event.size.width),
                   static_cast<float>(event.size.height)
                });
                window.setView(view);
                globalConfigs.setScreen(sf::Vector2i(event.size.width, event.size.height));
                
            }
        }
        SYSTEMTIME time1;
        GetLocalTime(&time1);
        float delta = toMilliseconds(time1) - toMilliseconds(time);
        time = time1;
        delta = delta / 1000.f;
        controller.tick(delta);
        window.clear();
        window.draw(controller);
        window.display();
    }

    return 0;
}
