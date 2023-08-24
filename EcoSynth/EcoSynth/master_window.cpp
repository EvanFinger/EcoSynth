#include "stdafx.h"
#include "master_window.h"





void master_window::init_variables()
{
    this->window = nullptr;
    this->dt = 0.f;

    if (!this->font.loadFromFile("Fonts/TT Chocolates Trial Light.otf"))
    {
        std::cout << "FAILED TO LOAD FONT : simGUI.h" << "\n";
    }

    
}

void master_window::init_window()
{
    this->window = new sf::RenderWindow
    (
        sf::VideoMode(800, 600),
        "My window",
        sf::Style::Titlebar | sf::Style::Close
    );

    //TESTING REMOVE LATER
    this->test1 = new Button
    (
        this->window,
        100.f, 100.f,
        100.f, 80.f,
        this->font, 20, "BOO",
        23
    );
    this->test1->ColorBoundingRectangle
    (
        sf::Color(139, 72, 199, 200), sf::Color(95, 49, 135, 255), sf::Color(41, 21, 59, 150),
        sf::Color(139, 72, 199, 200), sf::Color(95, 49, 135, 255), sf::Color(41, 21, 59, 150)
    );
    this->test1->ColorText
    (
        sf::Color::White, sf::Color::White, sf::Color::White
    );

    //END TESTING REMOVE LATER
}

master_window::master_window()
{
    this->init_variables();
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

void master_window::updateSFMLevents()
{
    this->check_sfml_events();
}

void master_window::update()
{
    this->updateSFMLevents();
    //TESTING REMOVE LATER
    this->test1->update();
    if (this->test1->getReturnValue() == ACTIVE)
    {
        std::cout << ".";
    }
    //END TESTING
}

void master_window::render()
{
    this->window->clear();
    this->test1->render(); //TESTING REMOVE LATER
    this->window->display();
}

void master_window::run()
{


    // run the program as long as the window is open
    while (this->window->isOpen())
    {
        this->update(); 

        this->render();
    }
}
