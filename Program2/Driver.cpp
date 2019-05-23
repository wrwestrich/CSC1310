#include <iostream>
#include "DogHealth.h"
#include "ArrayHelper.h"

using namespace std;

int main()
{
    std::cout << "\n\nHello!  Welcome to the Dog Health Program!\n\n";
	
	//this will call the constructor and ask the user to enter in all the dog's information
	DogHealth myDog;
	
	myDog.printDogHealth();
	
	myDog.printWeightStatistics();
	
	myDog.printHeartRateStatistics();
	
	return 0;	
}
