#pragma once
#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include <string>
#include <memory>
#include "monster.hpp"
#include <vector>


class Weapon {
 public:
  //return a vector of points(vector of length 2 of type float) that indicate hitzones... 
  virtual std::vector<float> active_point()=0;
  //virtual bool hit(const Monster& aimed_at)=0;
  virtual float dmg(float dirx, float diry)=0; //dir points towards monster
  virtual void setPosition(float& from_x, float& from_y)=0;
  virtual  void setSprite(sf::Sprite sp)=0;
  virtual ~Weapon();
  sf::Sprite sprite;
  float mass = 0.1f;
  float omega = 0.f;

  virtual void update(float dt)=0;
  
};

class Axe: public Weapon{
public:
  Axe(const std::string n):name{n},range{25.f}{}

  ~Axe();
  void setSprite(sf::Sprite sp){sprite = sp;}
  void setPosition(float& from_x, float& from_y);
  std::vector<float> active_point();
  bool hit(HitBox aimed_at, float at_x, float at_y);
  float dmg(float dirx, float diry);
  void update(float dt){sprite.rotate(omega*dt);}
  std::string name;
  float range;
};


