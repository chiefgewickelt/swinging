#include "character.hpp"

Character::Character(sf::Texture& tex, float hbx, float hby){
  sprite.setTexture(tex);
  setHB(hbx, hby);
};

void Character::pick_up(Weapon& on_ground){
  weapon = &on_ground;
}

void Character::update_tex(){
  sprite.setPosition(xpos(), ypos());
  weapon->setPosition(x,y);
};
