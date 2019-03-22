//#include <SFML/Graphics.hpp>
//#include <algorithm>
#include <vector>
#include <iostream>
//#include <utility>
#include <cmath>
#include "moveable.hpp"
#include "character.hpp"
#include "weapon.hpp"
/* SETTINGS */
//screensize
const int _X = 800;
const int _Y = 600;

const float playermass = 10.0f;
const float stepsize = 20.f;
const float weap_angle = 10.f;

/*n
struct phy_sprite{
  moveable pm;
  sf::Sprite sprite;
  };*/

int main(){
  sf::RenderWindow window(sf::VideoMode(_X, _Y), "Swinger");

  sf::Texture wikpic;
  if(!wikpic.loadFromFile("wiking.png")){
    std::cout << "wiking pic not found\n" ;
  }
  sf::Sprite weapon;
  sf::Texture axe;
  if(!axe.loadFromFile("axe.png")){
    std::cout << "axe pic not found\n" ;
  }
  sf::Sprite monster;
  sf::Texture lui;
  if(!lui.loadFromFile("bittschy.png")){
    std::cout << "bittschy pic not found\n" ;
  }
  monster.setPosition(400,300);
  monster.setTexture(lui);
  
  weapon.setOrigin(10,30);
  weapon.setTexture(axe);
  
  Character wiking = Character(wikpic,23.f,23.f);
  wiking.setPM(moveable(100.0f,100.0f,playermass,50.f,50.f));

  sf::Clock clock;

  float t = 0.0f;
  float dt = 1/60.0f;
  sf::Time currentTime = clock.getElapsedTime();

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
	wiking.pm.update_bound(deltaTime,_X,_Y);
	frameTime -= deltaTime;
	t +=deltaTime;
      }

      
      while (window.pollEvent(event)){
	switch(event.type){
	case sf::Event::Closed:
	  window.close();
	case sf::Event::KeyPressed:
	  if(sf:: Keyboard::isKeyPressed(sf::Keyboard::A)){
	    weapon.rotate(weap_angle);
	  }
	  if(sf:: Keyboard::isKeyPressed(sf::Keyboard::D)){
	    weapon.rotate(-weap_angle);
	  }
	case sf::Event::KeyReleased:
	  if(event.key.code == sf::Keyboard::Space)
	    space_hit = true;
	}
      }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
	wiking.pm.accX(dt,-stepsize);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
	wiking.pm.accX(dt,stepsize);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
	wiking.pm.accY(dt,-stepsize);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
	wiking.pm.accY(dt,stepsize);
      }
            
      if(space_hit){
	wiking.pm.accFac(0.5f);
	space_hit = false;
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
	window.close();
      }
      

      wiking.update_tex();
      window.clear();
      window.draw(wiking.sprite);
      window.draw(weapon);
      window.draw(monster);
      window.display();
    }
  
  return 0;
}
