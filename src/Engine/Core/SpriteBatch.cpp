#include "SpriteBatch.h"
#define MAX_CAPACITY 400000

SpriteBatch::SpriteBatch(sf::RenderWindow& parentWindow) : parentWindow(parentWindow) {
	capacity = MAX_CAPACITY;
	vertices.resize(MAX_CAPACITY / 1000);
}

SpriteBatch::~SpriteBatch() {

}

void SpriteBatch::begin() {
	vertexCount = 0;
	queueCount = 0;
	textures.clear();
	active = true;
}

void SpriteBatch::end() {
	unsigned int index = 0;

	enqueue();
	sf::RenderStates states;
	for(const auto& item : textures) {
		states.texture = item.texture;
		parentWindow.draw(&vertices[index], item.count, sf::Quads, states);
		index += item.count;
	}

	active = false;
}

void SpriteBatch::enqueue() {
	if(queueCount > 0) {
		textures.push_back(QueueItem(queueCount, activeTexture));
	}

	queueCount = 0;
}

unsigned int SpriteBatch::createTexture(sf::Texture& texture) {
	if(&texture != activeTexture) {
		enqueue();
		activeTexture = &texture;
	}

	if(vertexCount >= (vertices.size() / 4)) {
		if(vertices.size() < capacity) {
			vertices.resize(std::min(vertices.size() * 2, capacity));
		}
	}

	queueCount += 4;
	return (vertexCount++) * 4;
}

void SpriteBatch::drawTexture(sf::Texture& texture, const sf::Vector2f& position) {
	unsigned int index = createTexture(texture);
	sf::Vertex* v = &vertices[0] + index;
	sf::Vector2u size = texture.getSize();

	v[0].position.x = position.x;
	v[0].position.y = position.y;
	v[0].texCoords.x = 0;
	v[0].texCoords.y = 0;
	v[0].color = sf::Color::White;

	v[1].position.x = position.x + size.x;
	v[1].position.y = position.y;
	v[1].texCoords.x = size.x;
	v[1].texCoords.y = 0;
	v[1].color = sf::Color::White;

	v[2].position.x = position.x + size.x;
	v[2].position.y = position.y + size.y;
	v[2].texCoords.x = size.x;
	v[2].texCoords.y = size.y;
	v[2].color = sf::Color::White;

	v[3].position.x = position.x;
	v[3].position.y = position.y + size.y;
	v[3].texCoords.x = 0;
	v[3].texCoords.y = size.y;
	v[3].color = sf::Color::White;
}