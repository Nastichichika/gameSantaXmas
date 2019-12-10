#include "Map.h"

void Map::drawMar(sf::RenderWindow& window) {
	rectangle.setSize({ 16, 16 });
	for (int i = 0; i < 18; i++)
		for (int j = 0; j < 30; j++) {
			if (TileMap[i][j] == 'B') rectangle.setFillColor(sf::Color::White);
			if (TileMap[i][j] == ' ') continue;
			rectangle.setPosition(j * 16, i * 16);
			window.draw(rectangle);
		}
}
