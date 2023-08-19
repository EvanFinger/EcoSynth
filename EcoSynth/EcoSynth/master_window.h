#ifndef MASTER_WINDOW_H
#define MASTER_WINDOW_H

class master_window
{
public:

	sf::RenderWindow* window;


	void init_window();

	master_window();
	~master_window();

	void check_sfml_events();
	void handle_sfml_events(sf::Event event);
	void update();
	void render();

	void run();
private:

};

#endif MASTER_WINDOW_H