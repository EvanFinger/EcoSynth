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
	//this->INIT();

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
	this->buttonText.setFont(this->font);
	this->buttonText.setCharacterSize(font_size);  
	this->buttonText.setFillColor(sf::Color::White);
	this->buttonText.setString(button_text);
	this->buttonText.setPosition
	(
		this->boundingRectangle.getPosition().x + 
		(this->boundingRectangle.getGlobalBounds().width / 2.f) - 
		this->buttonText.getGlobalBounds().width / 2.f,

		this->boundingRectangle.getPosition().y + 
		(this->boundingRectangle.getGlobalBounds().height / 2.f) - 
		this->buttonText.getGlobalBounds().height / 1.2f
	);
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

void Button::setSize(float width, float height)
{
	this->boundingRectangle.setSize
	(
		sf::Vector2f(width, height)
	);
}

void Button::setOutlineThickess(unsigned short thickness)
{
	this->boundingRectangle.setOutlineThickness(thickness);
}

objectReturnValues Button::getReturnValue()
{
	return this->objectReturnValue;
}

sf::RectangleShape* Button::getBoundingRectangle()
{
	return &this->boundingRectangle;
}

std::string Button::getButtonTextAsString()
{
	return this->buttonText.getString();
}

void Button::update()
{
	this->updateMousePosition();
	this->objectReturnValue = IDLE;
	if (this->boundingRectangle.getGlobalBounds().contains(this->mousePositionView))
	{
		this->objectReturnValue = HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->objectReturnValue = ACTIVE;
			this->mouseDown = true;
		}
		else if (this->mouseDown)
		{
			this->objectReturnValue = IDLE;
			this->mouseDown = false;
		}
	}

	switch (this->objectReturnValue)
	{
	case IDLE:
		this->boundingRectangle.setFillColor(this->colors.idle);
		this->boundingRectangle.setOutlineColor(this->colors.outline_idle);
		this->buttonText.setFillColor(this->colors.text_idle);
		break;
	case HOVER:
		this->boundingRectangle.setFillColor(this->colors.hover);
		this->boundingRectangle.setOutlineColor(this->colors.outline_hover);
		this->buttonText.setFillColor(this->colors.text_hover);
		break;
	case ACTIVE:
		this->boundingRectangle.setFillColor(this->colors.active);
		this->boundingRectangle.setOutlineColor(this->colors.outline_active);
		this->buttonText.setFillColor(this->colors.text_active);
		break;
	default:
		std::cout << "INVALID BUTTON STATE ON BUTTON: " << this->objectID << "\n";
	}
}

void Button::render()
{
	this->parentWindow->draw(this->boundingRectangle);
	this->parentWindow->draw(this->buttonText);
}


