#include "moveable.hpp"
#include <cmath>


template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
};

template <typename T> int sgn_0to1(T val){
  int s = sgn(val);
  return s+(1-s)%2;
};


const float moveable::MAX_V = 200.0;


moveable::~moveable(){};

void moveable::accX(float dt, float df){
  float next = v[0] + dt * df/m;
  v[0]=std::min(std::abs(next), MAX_V)*sgn(next);
};

void moveable::accY(float dt, float df){
  float next = v[1] + dt * df/m;
  v[1]=std::min(std::abs(next), MAX_V)*sgn(next);
};

void moveable::update_bound(float dt,const int _X, const int _Y){
  x = std::max(x+v[0]*dt,0.0f-hitbox.x/2.f);
  y = std::max(y+v[1]*dt,0.0f-hitbox.y/2.f);
  //here we use a global variable ... mind while refactoring
  x = std::min( _X-hitbox.x/2.f, x);
  y = std::min( _Y-hitbox.x/2.f, y);
}
