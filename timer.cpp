#include "timer.h"
sf::Clock timer::clock;
sf::Time timer::time;

timer::timer(sf::Time limit){
   counter = sf::milliseconds(0);
   this->limit = limit;
   timer::time = sf::milliseconds(0);
}
bool timer::step(){
   counter += timer::time;
   if(counter > limit){
      counter = sf::milliseconds(0);
      return 1;
   }
   else
      return 0;
}
void timer::create(int limit){
   this->limit = sf::milliseconds(limit);
   this->counter = sf::milliseconds(0);
}
void timer::getdelta(){
   time = clock.restart();
}
timer::~timer(){
}
