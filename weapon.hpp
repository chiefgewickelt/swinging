#pragma once
#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include <string>
#include <memory>


class Weapon {
 public:
  //  virtual bool hit(HitBox aimed_at, float at_x, float at_y)=0;
  // virtual float dmg(float vx, float vy ,float dirx ,float diry)=0;//dir should point to monster origin
  virtual void setPosition(float& from_x, float& from_y)=0;
  virtual  void setSprite(sf::Sprite sp)=0;
  virtual ~Weapon();
  sf::Sprite sprite;
  float mass = 1.f;
  float omega = 0.f;

  virtual void update(float dt)=0;
  
};

class Axe: public Weapon{
public:
  Axe(const std::string n):name{n}{}

  ~Axe();
  void setSprite(sf::Sprite sp){sprite = sp;}
  void setPosition(float& from_x, float& from_y);
  bool hit(HitBox aimed_at, float at_x, float at_y);
  float dmg(float vx,float vy,float dirx, float diry);
  void update(float dt){sprite.rotate(omega*dt);}
  std::string name;
};


