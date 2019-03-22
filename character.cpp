#include "character.hpp"

Character::Character(sf::Texture& tex, float hbx, float hby){
  sprite.setTexture(tex);
  pm.setHB(hbx, hby);
};

void Character::pick_up(Weapon& on_ground){
  weapon = on_gnround;
}

void Character::update_tex(){
  sprite.setPosition(pm.xpos(), pm.ypos());
  weapon.setPosition(pm.x,pm.y);
};
