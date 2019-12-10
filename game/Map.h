#pragma once
#include <SFML/Graphics.hpp>
class Map
{
	sf::RectangleShape rectangle;
public:
	sf::String TileMap[18]{
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
		"B                           BB",
		"B                        BB  B",
		"B  BB     B         BB       B",
		"B                            B",
		"B               BBB          B",
		"B                            B",
		"B                     B      B",
		"B                            B",
		"B                            B",
		"B                          BBB",
		"B                            B",
		"B                            B",
		"B                            B",
		"B           BB               B",
		"BBBBBBB BBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBB BBBBBBBBBBBBBBBBBBBBBB",
		"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	};
	void drawMar(sf::RenderWindow&);
};

