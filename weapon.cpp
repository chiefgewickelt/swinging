#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include <string>
#include "weapon.hpp"
#include <cmath>

Weapon::~Weapon(){};
Axe::~Axe(){};


template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

//the rotation seem s to work in a mathematical positive way
std::vector<float> Axe::active_point(){

  //  std::vector<std::vector<float>> result(1);

  //calculate the tip of axe
  float alpha = sprite.getRotation()*3.14f/180.f;
  //std::cout << alpha << "\n";
  
  float x1 =  sprite.getPosition().x+std::sin(alpha)*range;
  float y1 =  sprite.getPosition().y-std::cos(alpha)*range;
  //select active side depending on rotation direction (sign of omega)
  //x1 += sgn(omega)*std::cos(alpha)*range/4.f;
  //y1 += sgn(omega)*std::sin(alpha)*range/4.f;
  return {x1,y1};
  
};
float Axe::dmg(float dirx,float diry){
  return 1.f;
};
void Axe::setPosition(float& from_x, float& from_y){
  float offx = 23.f;
  float offy = 23.f;
  sprite.setPosition(int(from_x+offx), int(from_y + offy) );
};



/*hardcode weapons here for the beginning...*/
