#pragma once
#include <SFML/Graphics.hpp>
#include "moveable.hpp"
#include <string>
#include "hitbox.hpp"//the rectangular hitbox might be overcome
#include <cmath>
#include <iostream>

class Monster: public moveable{
 public:
  sf::Sprite sprite;
  Monster(sf::Texture& tex, float hbx, float hby);
  void update_tex(){sprite.setPosition(xpos(),ypos());}
  void setPosition(float xin, float yin){x=xin;y=yin;}
  void get_hit(float dmg){alife = false;
    std::cout << "monster got hit\n ";}
  bool is_hit_by(std::vector<float> const incomming);
  std::vector<float> center();
  
  float hit_radius;
  bool alife;
 private:
  
  int str = 1;
  int agil = 1;
  int life = 10;
};
