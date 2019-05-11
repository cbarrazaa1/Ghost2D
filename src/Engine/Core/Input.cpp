#include "Input.h"

Input::Input(sf::RenderWindow& parentWindow) : parentWindow(parentWindow) {
	for(unsigned int i = 0; i < KeyCode::KeyCount; i++) {
		pressedKeys[i] = false;
	}

	for(unsigned int i = 0; i < MouseButton::ButtonCount; i++) {
		pressedButtons[i] = false;
	}
}

void Input::update() {
	for(unsigned int i = 0; i < KeyCode::KeyCount; i++) {
		pressedKeys[i] = isKeyDown((KeyCode)i);
	}

	for(unsigned int i = 0; i < MouseButton::ButtonCount; i++) {
		pressedButtons[i] = isMouseDown((MouseButton)i);
	}
}

bool Input::isKeyDown(KeyCode key) const {
	return sf::Keyboard::isKeyPressed(key);
}

bool Input::isKeyPressed(KeyCode key) const {
	return isKeyDown(key) && !pressedKeys[key];
}

bool Input::isKeyReleased(KeyCode key) const {
	return !isKeyDown(key) && pressedKeys[key];
}

bool Input::isMouseDown(MouseButton button) const {
	return sf::Mouse::isButtonPressed(button);
}

bool Input::isMousePressed(MouseButton button) const {
	return isMouseDown(button) && !pressedButtons[button];
}

bool Input::isMouseReleased(MouseButton button) const {
	return !isMouseDown(button) && pressedButtons[button];
}

sf::Vector2i Input::getGlobalMousePos() const {
	return sf::Mouse::getPosition();
}

sf::Vector2i Input::getLocalMousePos() const {
	return sf::Mouse::getPosition(parentWindow);
}

bool Input::intersects(const sf::IntRect& rect) const {
	sf::Vector2i pos = getLocalMousePos();
	return rect.intersects(sf::IntRect(pos.x, pos.y, 1, 1));
}