#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteBatch.h"

class Engine {
public:
	Engine(unsigned int width, unsigned int height, const sf::String& title, bool framerateLock);
	virtual ~Engine();

private:
	sf::RenderWindow* window;
	SpriteBatch* spriteBatch;
	sf::Texture grass;
	sf::Texture dirt;
	sf::Texture dark;
	sf::Sprite sprite;

	void start();
};