SFML=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS=-std=c++11
#OOS=swinger.o, moveable.o, character.o, weapon.o


swinger.o: swinger.cpp 
moveable.o: moveable.cpp
character.o: character.cpp
weapon.o: weapon.cpp

%.o : %.cpp
	g++ $(CXXFLAGS) -c $<

swinger: swinger.o moveable.o character.o weapon.o moveable.hpp character.hpp weapon.hpp 
	g++ $(CXXFLAGS) $? -o $@ $(SFML)

