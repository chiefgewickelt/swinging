#pragma once
#include <algorithm>
#include "hitbox.hpp"
#include <vector>

class moveable{
public:
  ~moveable(); 
  moveable(float xin, float yin, float mass, float hbx, float hby):x{xin},y{yin},v{0.f,0.f},m{mass},hitbox{hbx,hby}{}
  moveable():x{0}, y{0},v{0,0},m{1.0f},hitbox{50.f,50.f}{}
  void accX(float dt, float df);
  void accY(float dt, float df);
  void update_bound(float dt, const int _X, const int _Y );
  void set_v(float dvx, float dvy){v[0]=dvx;v[1]=dvy;}
  void accFac(float fac){transform(v.begin(),v.end(),v.begin(),[fac](float vi){	return vi*fac;});}
  void setHB(float hbx, float hby){hitbox = {hbx,hby};}
  int xpos(){return (int) x;}
  int ypos(){return (int) y;}
  float x;
  float y;
  HitBox hitbox;

private:
  static const float MAX_V;
    std::vector<float> v;
  float m;

};

