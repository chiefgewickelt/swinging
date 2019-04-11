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
  void update_tex();
  ~Character(){}

  bool is_hit_by(const Monster &  m);
  void gets_hit_by(/*const Monster & m*/);
  void drop_weapon();
  
  Character(sf::Texture& tex, float hbx, float hby, float xin, float yin,const float m);
  void swing(float dt);
  void update(float dt, const int X, const int Y);
  sf::Sprite sprite;
  Weapon* weapon;

  float life;
  float str;

  
};
