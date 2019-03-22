SFML= -lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS= -std=c++11
TARGETS= swinger.o, moveable.o, character.o, weapon.o

swinger.o: swinger.cpp 
moveable.o: moveable.cpp
character.o: character.cpp
weapon.o: weapon.cpp

$(TARGETS):
	g++ -std=$(STD) -c $?

swinger: swinger.o moveable.o character.o 
	g++ $(CXXFLAGS) $? -o $@ $(SFML)

