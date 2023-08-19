#include "stdafx.h"
#include "master_window.h"





void master_window::init_window()
{
    this->window = new sf::RenderWindow
    (
        sf::VideoMode(800, 600),
        "My window",
        sf::Style::Titlebar | sf::Style::Close
    );
}

master_window::master_window()
{
    this->init_window();
}

master_window::~master_window()
{
    delete this->window;
}

void master_window::check_sfml_events()
{
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        this->handle_sfml_events(event);
    }
}

void master_window::handle_sfml_events(sf::Event event)
{
    // "close requested" event: we close the window
    if (event.type == sf::Event::Closed)
        this->window->close();
}

void master_window::update()
{
}

void master_window::render()
{
}

void master_window::run()
{


    // run the program as long as the window is open
    while (this->window->isOpen())
    {
        this->check_sfml_events();

        this->update();

        this->render();
    }
}