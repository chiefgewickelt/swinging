#include "monster.hpp"

Monster::Monster(sf::Texture& tex, float hbx, float hby):alife{true},hit_radius{25.f}{
  sprite.setTexture(tex);
  setHB(hbx, hby);
};

/*std::vector<float> Monster::center(){
  //get the center of the sprite, this gets useless if origin of monster sprite is set to the visual center instead of upper left corner
  return std::vector<float>{sprite.getOrigin().x + std::sqrt(2.f)*hit_radius, sprite.getOrigin().y + std::sqrt(2.f)*hit_radius};
  }*/


bool Monster::is_hit_by(std::vector<float> const incomming){
    if( std::abs(x+hitbox.x-incomming[0]) <  hit_radius and std::abs(y+hitbox.y-incomming[1]) < hit_radius){//if indicator points are in hit circle
      return true;
    }
    return false;
  
};

std::vector<float> Monster::center(){
  
  // result = std::vector{x+hitbox.x/2,y+hitbox.y/2};
  
  return {x+hitbox.x/2,y+hitbox.y/2};
};


  


  
