#ifndef MASTER_WINDOW_H
#define MASTER_WINDOW_H

#include "state_mainmenu.h"

class master_window
{
public:

	sf::RenderWindow* window;

	//delta time tracking
	sf::Clock dtClock;
	float dt;

	sf::Font font;
	Button* test1;

	// initiators
	void init_variables();
	void init_window();

	master_window();
	~master_window();

	void check_sfml_events();
	void handle_sfml_events(sf::Event event);

	void updateSFMLevents();
	void update();
	void render();

	void run();
private:

};

#endif MASTER_WINDOW_H