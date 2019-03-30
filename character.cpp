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
void Character::swing(float angle){
  weapon->rotate(angle);
};
