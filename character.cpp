#include "character.hpp"
#include <stdexcept>

Character::Character(sf::Texture& tex, float hbx, float hby, float xin, float yin,float mass){
    sprite.setTexture(tex);
    moveable(xin,yin,mass,hbx,hby);
};

void Character::pick_up(Weapon * on_ground){
  weapon = on_ground;
}

void Character::update_tex(){
  sprite.setPosition(xpos(), ypos());
  if(weapon)
    weapon->setPosition(x,y);
};

void Character::update(float dt, const int X, const int Y){
  update_bound(dt, X,Y);
  weapon->update(dt);
}
void Character::swing(float dt){
  weapon->omega+=10000*dt/weapon->mass;//modifiy by character atributes...
};
