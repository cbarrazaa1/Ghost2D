#include "Engine.h"

Engine::Engine(unsigned int width, unsigned int height, const sf::String& title, bool framerateLock) {
	// create window
	window = new sf::RenderWindow(sf::VideoMode(width, height, 32U), title);
	spriteBatch = new SpriteBatch(*window);
	input = new Input(*window);

	// lock framerate to 60 if lock is on
	if(framerateLock) {
		window->setFramerateLimit(60);
		window->setVerticalSyncEnabled(true);
	}

	grass.loadFromFile("content/grass.png");

	// start the game
	start();
}

Engine::~Engine() {
	delete input;
	delete spriteBatch;
	delete window;
}

void Engine::start() {
	sf::Event ev;
	sf::Clock clock;

	// fps timing
	unsigned int fps = 0;
	sf::Time fpsTimer = sf::Time::Zero;

	// run game loop
	while(window->isOpen()) {
		sf::Time delta = clock.restart();

		// handle window events
		while(window->pollEvent(ev)) {
			if(ev.type == sf::Event::EventType::Closed) {
				window->close();
			}
		}

		// update game
		input->update();

		// render the game
		window->clear();
		spriteBatch->begin();

		for(int x = 0; x < 32; x++) {
			for(int y = 0; y < 23; y++) {
				spriteBatch->drawTexture(grass, sf::Vector2f(x * 32, y * 32));
			}
		}

		spriteBatch->end();
		window->display();

		// calculate fps
		fpsTimer += delta;
		if(fpsTimer >= sf::seconds(1)) {
			std::cout << "FPS: " << fps << std::endl;
			fps = 0;
			fpsTimer = sf::Time::Zero;
		}
		fps++;
	}
}