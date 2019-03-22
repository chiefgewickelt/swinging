#pragma once
#include <SFML/Graphics.hpp>
#include "moveable.h"
#include <string>

class Monster{
 public:
  moveable pm;
  sf::Sprite sprite;
  Monster(sf::Texture& tex, float hbx, float hby);
  void update_tex(){sprite.setPosition(pm.xpos(),pm.ypos());}
  void setPM(moveable pmin);
 private:
  int str = 1;
  int agil = 1;
  int life = 10;
};
