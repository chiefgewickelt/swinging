#pragma once
#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include <string>



class Weapon {
 public:
  virtual bool hit(HitBox aimed_at)=0;
  virtual float dmg(float vx, float vy ,float dirx ,float diry)=0;//dir should point to monster origin
  virtual void setPosition(float from_x; float from_y)=0;
  void setSprite(sf::Sprite sp);

};

class Axe: public Weapon{
public:
  Axe(float m):mass{m}{}
  bool hit(HitBox aimed_at, float at_x, float at_y);
  float dmg(float vx,float vy,float dirx, float diry);
  std::string name;
  void setSprite(sf::Sprite sp){sprite = sp;}
  float mass;
  virtual void setPosition(float from_x; float from_y)=0;
private:
  sf::Sprite sprite;  
};
/*hardcode weapons here for the beginning...*/
