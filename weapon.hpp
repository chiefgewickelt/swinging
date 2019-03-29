#pragma once
#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include <string>



class Weapon {
 public:
  Weapon(){}
  virtual bool hit(HitBox aimed_at, float at_x, float at_y)=0;
  virtual float dmg(float vx, float vy ,float dirx ,float diry)=0;//dir should point to monster origin
  virtual void setPosition(float& from_x, float& from_y)=0;
  void setSprite(sf::Sprite sp);
  virtual void rotate(float angle);
  virtual ~Weapon();

};
class Axe: public Weapon{
public:
  Axe(string n)name{n},m{1.0f}{}
  Axe():mass{1.0f}{}

  void setSprite(sf::Sprite sp){sprite = sp;}
  void setPosition(float& from_x, float& from_y){sprite.setPosition(from_x, from_y);}
  
  bool hit(HitBox aimed_at, float at_x, float at_y);
  float dmg(float vx,float vy,float dirx, float diry);
      
  void rotate(float angle) {sprite.rotate(angle);}
  
  float mass;
  sf::Sprite sprite;
  std::string name;
};
/*hardcode weapons here for the beginning...*/

