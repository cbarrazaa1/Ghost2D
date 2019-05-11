#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>

struct QueueItem {
	unsigned int count;
	sf::Texture* texture;

	QueueItem() { }
	QueueItem(unsigned int count, sf::Texture* texture) {
		this->count = count;
		this->texture = texture;
	}
};

class SpriteBatch {
public:
	SpriteBatch(sf::RenderWindow& window);
	~SpriteBatch();

	void begin();
	void end();
	void drawTexture(sf::Texture& texture, const sf::Vector2f& position);

private:
	sf::RenderWindow& window;
	std::vector<QueueItem> textures;
	std::vector<sf::Vertex> vertices;
	sf::Texture* activeTexture;
	bool active;
	unsigned int vertexCount;
	unsigned int queueCount;
	unsigned int capacity;

	void enqueue();
	unsigned int createTexture(sf::Texture& texture);
	void render();
};