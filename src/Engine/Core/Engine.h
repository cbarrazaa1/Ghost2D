#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteBatch.h"
#include "Input.h"

class Engine {
public:
	Engine(unsigned int width, unsigned int height, const sf::String& title, bool framerateLock);
	virtual ~Engine();

private:
	sf::RenderWindow* window;
	SpriteBatch* spriteBatch;
	Input* input;

	sf::Texture grass;

	void start();
};