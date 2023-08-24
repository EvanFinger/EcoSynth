#ifndef STATE_H
#define STATE_H

#include "es_gui.h"

class State;

struct stateData
{
	//Vars
	sf::RenderWindow* window;
	std::stack<State*>* states;
	std::map< std::string, sf::Texture > textures;
};

class State
{
public:
	//construct / destruct
	State(stateData* state_data);
	~State();

	//getters
	const bool& checkQuit() const;
	
	//modifiers
	void endState();

	//updates
	virtual void updateMousePositions();
	virtual void updateInput() = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:

	//Vars
	stateData* data;
	std::stack<State*>* states;
	sf::RenderWindow* window;
	bool quit_state;

	//Mouse
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Resources
	std::map< std::string, sf::Texture > textures;

private:

};

#endif STATE_H
