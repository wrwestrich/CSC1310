all				:	Zoo

Zoo				:	Zoo.o Creature.o
					g++ -o Zoo.exe Zoo.o Creature.o

Zoo.o			:	Zoo.cpp
					g++ -I ./ -c Zoo.cpp
				
Creature.o		:	Creature.cpp
					g++ -I ./ -c Creature.cpp
				
clean			:	Zoo.exe
					del *.o 
					del Zoo.exe
