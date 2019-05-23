all				:	DogHealth

DogHealth		:	Driver.o ArrayHelper.o DogHealth.o
					g++ -o DogHealth.exe Driver.o DogHealth.o ArrayHelper.o

Driver.o		:	Driver.cpp
					g++ -I ./ -c Driver.cpp
				
ArrayHelper.o	:	ArrayHelper.cpp
					g++ -I ./ -c ArrayHelper.cpp
			
DogHealth.o		:	DogHealth.cpp
					g++ -I ./ -c DogHealth.cpp
			
clean			:	DogHealth.exe
					del *.o 
					del DogHealth.exe
