#ifndef GUI_H
#define GUI_H

enum objectReturnValues
{
	IDLE, HOVER, ACTIVE, RELEASED
};

class gui_element
{
public:
	gui_element(sf::RenderWindow* p_window, unsigned short id);
	virtual ~gui_element();

	void setObjectID(short unsigned id);

	short unsigned getObjectID();

	virtual void update() = 0;
	void updateMousePosition();

	virtual void render() = 0;

protected:
	sf::RenderWindow* parentWindow;
	sf::Vector2f mousePositionView;
	short unsigned objectID;
	objectReturnValues objectReturnValue;

private:

	void INIT();
	void initVariables();

};

class Button
	:gui_element
{
public:
	Button
	(
		sf::RenderWindow* parent_window,
		float x_position, float y_position,
		float x_size, float y_size,
		sf::Font& font, unsigned short font_size,
		std::string button_text,
		unsigned short id
	);

	virtual ~Button();

	void ColorBoundingRectangle
	(
		sf::Color idle, sf::Color hover, sf::Color active,
		sf::Color oIdle, sf::Color oHover, sf::Color oActive
	);

	void ColorText
	(
		sf::Color  idle, sf::Color hover, sf::Color active
	);

	void setText
	(
		std::string str
	);

	void setPosition
	(
		float x, float y
	);

	void setSize
	(
		float width, float height
	);

	void setOutlineThickess
	(
		unsigned short thickness
	);

	objectReturnValues getReturnValue();

	sf::RectangleShape* getBoundingRectangle();

	std::string getButtonTextAsString();

	void update();

	void render();

protected:
	sf::Font& font;

	bool mouseDown;

	sf::RectangleShape boundingRectangle;
	sf::Text buttonText;

	struct ButtonColors
	{
		sf::Color idle, hover, active; // bounding ractangle fill color
		sf::Color outline_idle = sf::Color::Transparent, outline_hover = sf::Color::Transparent, outline_active = sf::Color::Transparent; // bounding rectangle outline color
		sf::Color text_idle, text_hover, text_active;
	};

	ButtonColors colors;
};


#endif GUI_H