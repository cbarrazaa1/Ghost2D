#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

typedef sf::Keyboard::Key KeyCode;
typedef sf::Mouse::Button MouseButton;

class Input {
public:
	Input(sf::RenderWindow& parentWindow);
	virtual ~Input() { }

	void update();

	bool isKeyDown(KeyCode key) const;
	bool isKeyPressed(KeyCode key) const;
	bool isKeyReleased(KeyCode key) const;

	bool isMouseDown(MouseButton button) const;
	bool isMousePressed(MouseButton button) const;
	bool isMouseReleased(MouseButton button) const;

	sf::Vector2i getGlobalMousePos() const;
	sf::Vector2i getLocalMousePos() const;
	bool intersects(const sf::IntRect& rect) const;

private:
	sf::RenderWindow& parentWindow;
	bool pressedKeys[KeyCode::KeyCount];
	bool pressedButtons[MouseButton::ButtonCount];
};