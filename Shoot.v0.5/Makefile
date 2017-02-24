CXXFLAGS= -g -Wall -pedantic
LDFLAGS= -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

%: %.o
	$(CXX) $(CXXFLAGS) $(CPPFLAGS)  -o $@ $^ $(LDFLAGS) 

execs     = shoot

all: $(execs)

shoot: shoot.o GameModel.o GameView.o GraphicElement.o Element.o MovableElement.o Ship.o Laser.o utils.o

# -------------------------------------------------------------
clean:
	$(RM) *~ *.o *.bak 

mrproper: clean
	$(RM) $(execs)

#----------------------------------------------------------------
# pour mettre à jour les dépendances ci-dessous
depend:
	makedepend -Y *.cc

# DO NOT DELETE

GameModel.o: GameModel.h 
GameView.o: GameView.h 
shoot.o: GameView.h GameModel.h GraphicElement.h
GraphicElement.o: GraphicElement.h
Element.o: Element.h
MovableElement.o: MovableElement.h Element.h
Ship.o: Ship.h
Laser.o: Laser.h
utils.o : utils.h 
