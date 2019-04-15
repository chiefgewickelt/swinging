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
    if( std::abs(x+hitbox.x/2.f-incomming[0]) <  hit_radius and std::abs(y+hitbox.y/2.f-incomming[1]) < hit_radius){//if indicator points are in hit circle
      return true;
    }
    return false;
  
};

std::vector<float> Monster::center(){//?????
  
  // result = std::vector{x+hitbox.x/2,y+hitbox.y/2};
  
  return {x+hitbox.x/2.f,y+hitbox.y/2.f};
};

void Monster::update(float dt, const int X, const int Y, float x_to, float y_to, std::vector<float>& v_to){
  update_bound(dt, X, Y);
  accFac(0.5f);
  accX(dt,x_to - x + v_to[0]);
  accY(dt,y_to - y + v_to[1]);
  accFac(2.f);
  /*v[0] = x_to - x + v_to[0];
    v[1] = y_to - y + v_to[1];*/
};
  


  
