#include "stdafx.h"
#include "es_gui.h"

void gui_element::INIT()
{
	this->initVariables();
}

void gui_element::initVariables()
{
	this->parentWindow = nullptr;
	this->mousePositionView = sf::Vector2f(NULL, NULL);
	this->objectID = NULL;
	this->objectReturnValue = IDLE;
}

gui_element::gui_element(sf::RenderWindow* p_window, unsigned short id)
{
	this->INIT();

	this->parentWindow = p_window;
	this->objectID = id;
}

gui_element::~gui_element()
{
	delete this->parentWindow;
}

void gui_element::setObjectID(short unsigned id)
{
	this->objectID = id;
}

short unsigned gui_element::getObjectID()
{
	return this->objectID;
}

void gui_element::updateMousePosition()
{
	this->mousePositionView = this->parentWindow->mapPixelToCoords(sf::Mouse::getPosition(*this->parentWindow));
}

Button::Button
(
	sf::RenderWindow* parent_window,
	float x_position, float y_position,
	float x_size, float y_size,
	sf::Font& font, unsigned short font_size,
	std::string button_text,
	unsigned short id
)
	:gui_element(parent_window, id), font(font)
{

}
