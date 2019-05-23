all			:	Program4

Program4	:	Program4.o
				g++ -o Program4.exe Program4.o
				
Program4.o	:	Program4.cpp
				g++ -I ./ -c Program4.cpp
				
clean		:	Program4.exe
				del *.o
				del Program4.exe