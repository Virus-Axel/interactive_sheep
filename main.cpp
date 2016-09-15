#include <iostream>
#include <unistd.h>
#include <vector>
#include "timer.h"
#include "classes.h"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

int main(){
	srand(time(NULL));
	std::vector<force_field> f;
	f.push_back(force_field(-1.0f, -1.0f, 2.5f, 10.0f, 1));
	f.push_back(force_field(2.0f, 2.0f, 2.5f, 10.0f, 1));
	f.push_back(force_field(2.0f, -1.0f, 2.5f, 10.0f, 1));
	f.push_back(force_field(-1.0f, 2.0f, 2.5f, 10.0f, 1));
	//f.push_back(force_field(0.5f, 1.0f, 0.5f, 1.0f, 1));
	//f.push_back(force_field(0.5f, 0.0f, 0.5f, 1.0f, 1));
	std::vector<particle> p;
	for(unsigned int c1 = 1; c1 < 100; c1++)
		for(unsigned int c2 = 1; c2 < 75; c2++)
			p.push_back(particle(c1/100.0f, c2/75.0f, rand()%255, rand()%255, rand()%255, 250, 1));
	std::cout << "hello" << std::endl;
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Sjukaste jag hört!");
	timer t1(sf::milliseconds(10));
	sf::CircleShape shape(20);
	shape.setOrigin(10, 10);
	shape.setFillColor(sf::Color(250, 100, 200, 200.0f));
	while(window.isOpen()){
		timer::getdelta();
		sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }
		if(t1.step()){
			window.clear();
			for(unsigned int c = 0; c < p.size(); c++){
				if(p[c].handle(f)){
					std::cout << "erasing " << c << std::endl;
					p.erase(p.begin()+c);
				}
				//shape.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255, 100.0f));
				shape.setFillColor(sf::Color(p[c].r, p[c].g, p[c].b, p[c].a));
				shape.setPosition(p[c].x*800, p[c].y*600);
				window.draw(shape);
			}
			window.display();
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				sf::Vector2i pos = sf::Mouse::getPosition(window);
				p.push_back(particle(pos.x/800.0f, pos.y/600.0f, rand()%255, rand()%255, rand()%255, 255, 1));
			}
		}
	}
}
