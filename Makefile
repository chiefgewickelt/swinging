LDFLAGS+=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS=-std=c++11 -fsanitize=address
LINK.o=$(LINK.cc)
all: swinger

swinger.o: swinger.cpp *.hpp
moveable.o: moveable.cpp
character.o: character.cpp
weapon.o: weapon.cpp
monster.o: monster.cpp

%.o : %.cpp
	g++ $(CXXFLAGS) -c $<	
%.o : *.hpp

.PHONY: clean
clean:
	$(RM) *.o


swinger: swinger.o moveable.o character.o weapon.o monster.o

