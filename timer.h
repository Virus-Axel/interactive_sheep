#ifndef TIMER_H
#define TIMER_H
#include <SFML/Graphics.hpp>
#include <iostream>

class timer{
public:
   static sf::Time time;
   static sf::Clock clock;
   sf::Time limit, counter;
   timer(sf::Time limit=sf::milliseconds(1000));
   void create(int limit);
   bool step();
   static void getdelta();
   ~timer();
};

#endif
