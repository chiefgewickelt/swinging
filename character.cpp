
#include "character.hpp"
#include <stdexcept>
#include <cmath>
#include "settings.hpp"

Character::Character(sf::Texture& tex, float hbx, float hby, float xin, float yin,float mass, Weapon * hands){
    sprite.setTexture(tex);
    moveable(xin,yin,mass,hbx,hby);
    life = 100.f;
    str = 10.f;
    bare_hands = hands;
};

void Character::pick_up(Weapon * on_ground){
  weapon = on_ground;
  carrys_sth = true;
}

void Character::update_tex(){
  sprite.setPosition(xpos(), ypos());
  if(weapon)
    weapon->setPosition(x,y);
};

void Character::update(float dt, const int X, const int Y){
  update_bound(dt, X,Y);
  weapon->update(dt);
  //std::cout << weapon->omega << "\n";
  //if rotation speed is higher than str determins the maximal centripedal force
  if(std::abs(weapon->omega) > str * max_rot_factor){
    drop_weapon();
  }
  
}

void Character::drop_weapon(){
  //std::cout << "max rotation speen exeeded\n";
  weapon = bare_hands;
  carrys_sth = false;
}

void Character::swing(float dt){
  weapon->omega+=10*str*dt/weapon->mass;//modifiy by character atributes...
};

bool Character::is_hit_by(const Monster &  m){
  return std::pow(x-m.x,2)+std::pow(y-m.y,2)<std::pow(m.hit_radius,2);
}

void Character::gets_hit_by(/*const Monster & m*/){
  std::transform(v.begin(),v.end(),v.begin(),[](float d)->float {return d*0.5f;});
};
