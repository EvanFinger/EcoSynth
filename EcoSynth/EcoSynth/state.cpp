#include "stdafx.h"
#include "state.h"

//construct / destruct

State::State(stateData* state_data)
	: font(state_data->font)
{
	this->data = state_data;
	this->states = this->data->states;
	this->window = this->data->window;
	this->quit_state = false;
}

State::~State()
{

}

//getters

const bool& State::checkQuit() const
{
	return this->quit_state;
}

//modifiers

void State::endState()
{
	this->quit_state = true;
}

void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
