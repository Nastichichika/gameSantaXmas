#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Animation.h"
#include "Entity.h"
#include "Map.h"
#include "AnimationManager.h"
#include "Bullet.h"
#include "Enemy.h"


int main()
{

	sf::Text a;
	a.setString("You lose");
	a.setCharacterSize(30);
	a.setFillColor(sf::Color::Blue);

	sf::RenderWindow window(sf::VideoMode(480, 272), "Nastya works!");
	sf::View view(sf::FloatRect(0, 0, 480, 272));

	sf::Texture enemy, santa, bg;
	santa.loadFromFile("santa.png");
	enemy.loadFromFile("skeleton.png");
	bg.loadFromFile("background.png");

	sf::Sprite background(bg);
	background.setOrigin(bg.getSize().x / 2, bg.getSize().y / 2);
	background.setScale(1.3, 1.3);

	AnimationManager anim;
	anim.create("stay", santa, 3, 899, 26, 29, 0.003, 4, 96, 1);
	anim.create("walk", santa, 3, 415, 29, 32, 0.003, 6, 96, 1);
	anim.create("jump", santa, 3, 35, 26, 29, 0.005, 5, 96, 0);
	anim.create("gift", santa, 3, 684, 32, 51, 0.005, 11, 96, 1);
	anim.create("dead", santa, 3, 684, 32, 51, 0.005, 11, 96, 1);

	AnimationManager anim2;
	//anim2.create("move", gift, 586, 52, 10, 10, 1, 1, 1, 0);
	anim2.create("move", enemy, 23, 590, 24, 46, 0.005, 9, 60, 1);
	anim2.create("dead", enemy, 14, 143, 150, 50, 0.005, 1, 64, 1);

	AnimationManager anim3;
	anim3.create("move", santa, 586, 52, 10, 10, 1, 2, 0, 0);

	std::vector<Entity*>  entities;
	for (int i = 0; i < 5; i++)
		entities.push_back(new Enemy(anim2, 220+20 , 130+20 ));

	Player p(anim, 200, 100);

	Map map;
	sf::Clock clock;
	while (window.isOpen()) {

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 500; 
		if (time > 40) 
			time = 40;
		p.update(time, map);
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Space)
					entities.push_back(new Bullet(anim3, p.x + 15, p.y + 15, p.direction));
		}
		for (int i = 0; i < entities.size(); i++) {
			entities[i]->update(time, map);
			if (entities[i]->life == false) {
				entities.erase(entities.begin() + i);
			}
		}

		p.update(time, map);

		for (int i = 0; i < entities.size(); i++) {
			if (entities[i]->name == "Enemy") {
				Entity *enemy = entities[i];
				if (enemy->health <= 0) continue;
				if (p.getRect().intersects(enemy->getRect())) {
					enemy->dx = 0;
					p.dx = 0.2;
					p.health--;
				}
				//else if (!p.hit) {
				//		p.health -= 5; p.hit = true;
				//		if (p.direction) p.x += 10; else p.x -= 10;
				//	}
				for (int j = 0; j < entities.size(); j++){
					Entity *bullet = entities[j];
					if (bullet->name == "Bullet")
						if (bullet->health > 0)
							if (bullet->getRect().intersects(enemy->getRect())){
								bullet->health = 0; 
								enemy->health -= 5;
							}
					}
			}
		}

		background.setPosition(view.getCenter());
		window.draw(background);
		map.drawMar(window);
		if (p.health <= 0) {
			anim.set("dead");
			window.draw(a);
		}
		for (int i = 0; i < entities.size(); i++)
			entities[i]->draw(window);
		p.draw(window);
		window.display();
	}
	window.display();
	return 0;
}