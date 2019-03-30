#pragma once
#include <SFML/Graphics.hpp>
#include "hitbox.hpp"
#include "moveable.hpp"
#include <string>
#include "weapon.hpp"


const float expected_Tex_size = 50.f;

class Character: public moveable{
public:
  void pick_up(Weapon* on_ground);
  //  void setPM(moveable&& pm_in){pm = pm_in;}
  void update_tex();
  ~Character(){}
  Character():weapon{}{}
  Character(sf::Texture& tex, float hbx, float hby, float xin, float yin,const float m);
  void swing(float angle);
  sf::Sprite sprite;
  Weapon* weapon; 
};
