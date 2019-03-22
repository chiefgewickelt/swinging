#pragma once
#include <SFML/Graphics.hpp>
#include "hitbox.h"
#include <string>


bool Axe::hit(HitBox aimed_at , float at_x , float, at_y){
  return false; 
};
float Axe::dmg(float vx, vy, dirx, diry){
  return 1.0;
};
poid Axe::setPosition(float from_x; float from_y, float offx =23.f,float offy = 23.f){
  sprite.setPostion(from_x+offx, from_y + offy );
};


/*hardcode weapons here for the beginning...*/
