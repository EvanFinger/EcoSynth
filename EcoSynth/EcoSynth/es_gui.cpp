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
	this->mouseDown = false;

	// Initialize the Bounding Rectangle
	this->boundingRectangle.setSize
	(
		sf::Vector2f(x_size, y_size)
	);
	this->boundingRectangle.setPosition
	(
		sf::Vector2f(x_position, y_position)
	);
	this->boundingRectangle.setFillColor(sf::Color::Transparent);
	this->boundingRectangle.setOutlineThickness(0);
	this->boundingRectangle.setOutlineColor(sf::Color::Transparent);

	// Initialize the Text for the button
}

Button::~Button()
{
}

void Button::ColorBoundingRectangle
(
	sf::Color idle, sf::Color hover, sf::Color active, 
	sf::Color oIdle, sf::Color oHover, sf::Color oActive
)
{
	this->colors.idle = idle, this->colors.hover = hover, this->colors.active = active;
	this->colors.outline_idle = oIdle, this->colors.outline_hover = oHover, this->colors.outline_active = oActive;
}

void Button::ColorText
(
	sf::Color idle, sf::Color hover, sf::Color active
)
{
	this->colors.text_idle = idle, this->colors.text_hover = hover, this->colors.text_active = active;
}

void Button::setText(std::string str)
{
	this->buttonText.setString(str);
}

void Button::setPosition(float x, float y)
{
}
