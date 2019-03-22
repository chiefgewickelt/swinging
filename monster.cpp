#include "monster.h"

Monster::Monster(sf::Texture& tex, float hbx, float hby){
  sprite.setTexture(tex);
  pm.setHB(hbx, hby);
};
void Monster::setPM(moveable pmin){
  pm = pmin;
};
