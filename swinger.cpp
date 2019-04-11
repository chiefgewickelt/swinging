//#include <SFML/Graphics.hpp>
//#include <algorithm>
#include <vector>
#include <iostream>
//#include <utility>
#include <cmath>
#include "moveable.hpp"
#include "character.hpp"
#include "weapon.hpp"
#include "monster.hpp"
#include "settings.hpp"

 
int main(){
  sf::RenderWindow window(sf::VideoMode(_X, _Y), "Swinger");

  //circles to indicate stuff ********************
  sf::CircleShape active_spot(4.f);
  active_spot.setFillColor(sf::Color(150,50,250));
  bool indication_needed = false;

  // sf::CircleShape hit_area(25.f);
  // hit_area.setFillColor(sf::Color(50,250,150));
  
  //**********************************************
  sf::Texture wikpic;
  if(!wikpic.loadFromFile("wiking.png")){
    std::cout << "wiking pic not found\n" ;
  }
  sf::Sprite noob_axe;
  sf::Texture axe;
  if(!axe.loadFromFile("axe.png")){
    std::cout << "axe pic not found\n" ;
  }

  sf::Sprite fist;
  sf::Texture fist_pic;
  if(!fist_pic.loadFromFile("fist.png")){
    std::cout << "fist pic not found\n";
  }
  fist.setOrigin(10,40);
  fist.setTexture(fist_pic);
  //quick and dirty pls fix:
  Axe karate("bare hands");
  karate.setSprite(fist);
  
  
  sf::Texture luitex;
  if(!luitex.loadFromFile("bittschy.png")){
    std::cout << "bittschy pic not found\n" ;
  }
  Monster lui(luitex,50.f,50.f);
    
  lui.setPosition(400.f,300.f);
  std::vector<Monster> monsters{lui};
  
  noob_axe.setOrigin(10,30);
  noob_axe.setTexture(axe);

  
  Character wiking(wikpic,23.f,23.f,100.0f,100.0f,playermass,&karate);
  Axe first_axe("noob axe");
  first_axe.setSprite(noob_axe);
  wiking.pick_up(&first_axe);


  std::vector<Weapon*> active_items;
  active_items.push_back(&first_axe);
  
  sf::Clock clock;

  float t = 0.0f;
  float dt = 1/60.0f;
  sf::Time currentTime = clock.getElapsedTime();
  sf::Time monster_reset = clock.getElapsedTime();
  
  bool space_hit = false;
  
  while (window.isOpen())
    {
      sf::Event event;
      sf::Time newTime = clock.getElapsedTime();
      
      sf::Time frameTimeP = newTime-currentTime;
      float frameTime = frameTimeP.asSeconds();
      currentTime = newTime;

      while(frameTime > 0.0f){
	float deltaTime = std::min(frameTime, dt);
	wiking.update(deltaTime,_X,_Y);
	frameTime -= deltaTime;
	t +=deltaTime;
      }

      while (window.pollEvent(event)){
	switch(event.type){
	case sf::Event::Closed:
	  window.close();
	case sf::Event::KeyPressed:
	  if(sf:: Keyboard::isKeyPressed(sf::Keyboard::A)){
	    //	    std::cout << "A\n" ;
	    wiking.swing(dt);
	  }
	  if(sf:: Keyboard::isKeyPressed(sf::Keyboard::D)){
	    //	    std::cout << "D\n" ;
	    wiking.swing(-dt);
	  }
	case sf::Event::KeyReleased:
	  if(event.key.code == sf::Keyboard::Space)
	    space_hit = true;
	}
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
	wiking.accX(dt,-stepsize);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
	wiking.accX(dt,stepsize);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
	wiking.accY(dt,-stepsize);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
	wiking.accY(dt,stepsize);
      }
            
      if(space_hit){
	wiking.accFac(0.5f);
	space_hit = false;
	}
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
	window.close();
      }

      ///HIT DETECTION *******************************

      std::vector<float> weapon_tip(2);
      weapon_tip = wiking.weapon->active_point();
      active_spot.setPosition(weapon_tip[0],weapon_tip[1]);

      //hit_area.setPosition(lui.center()[0],lui.center()[1]);
      
      
      for(auto& m: monsters){
	if(wiking.is_hit_by(m)and m.alife){
	  wiking.gets_hit_by(/*m*/);
	  std::cout << "player got hit.\n";
	}
	if(m.is_hit_by(weapon_tip) and m.alife){
	  m.get_hit(wiking.weapon->dmg(1.f,1.f));//TOBE REFINED firection to monster shlud be fiven...to avoid touch dmg... momentum can oly be computed with correcr relative information...
	  monster_reset = clock.getElapsedTime();
	}
      }
      ///*********************************************

      wiking.update_tex();
      
      window.clear();
      window.draw(wiking.sprite);
      for(auto& x: active_items){
	window.draw(x->sprite);
      }
      window.draw(wiking.weapon->sprite);

      //      if(indication_needed){
      //window.draw(active_spot);
	//      window.draw(hit_area);
      //      }
      for(auto& m:monsters){
	m.update_tex();
	if(m.alife)
	  window.draw(m.sprite);
	else{
	  if ((clock.getElapsedTime() - monster_reset).asSeconds()> 5.f){
	    m.alife = true;
	    
	  }
      }
      
      }
      window.display();
    }
  return 0;
}
    

