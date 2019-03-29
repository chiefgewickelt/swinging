#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include <string>
#include "weapon.hpp"

Weapon::~Weapon(){};
Axe::~Axe(){};

bool Axe::hit(HitBox aimed_at , float at_x , float at_y){
  return false; 
};
float Axe::dmg(float vx, float vy,float dirx,float diry){
  return 1.0;
};
void Axe::setPosition(float& from_x, float& from_y){
  float offx = 23.f;
  float offy = 23.f;
  sprite.setPosition(from_x+offx, from_y + offy );
};


/*hardcode weapons here for the beginning...*/
