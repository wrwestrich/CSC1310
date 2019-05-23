/*
	This program was created to randomly generate movies in the crockett_movie_data.txt
	text file so that we could have over 100,000 movies in the file without me taking
	80 years of my life to type in all the movie data.  I have already compiled
	and ran this program and so the crockett_movie_data.txt file already has over
	100,000 movies in it.  
	
	You do not need to modify or use this file.  I am only including it if you 
	were curious how & why I did this.
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

string generate_random_string(int);

int main()
{
	ofstream outFile;
	srand(time(0));
	
	outFile.open("crockett_movie_data.txt", ios::app); //open file in append mode
	int counter = 0;
	while(counter < 2088)
	{
		//write movie title to file
		outFile << generate_random_string(50) << endl; //100 is the maximum length of the movie title string
		
		//write length of movie between 30 minutes to 240 minutes
		outFile << (30 + rand() % 210) << endl;
		
		//write movie year from 1920 to 2018
		outFile << (1920 + rand() % 98) << endl;
		
		//write genre string
		int options = 1 + rand() % 3;
		if(options == 1)
			outFile << "Comedy" << endl;
		else if(options == 2)
			outFile << "Drama" << endl;
		else
			outFile << "Suspense" << endl;
		
		//write rating
		outFile << "PG" << endl;
		
		//write number of oscars won
		options = 1 + rand() % 3;
		if(options == 1)
			outFile << 3 << endl;
		else if(options == 2)
			outFile << 0 << endl;
		else
			outFile << 8 << endl;
		
		//write IMDB rating from 1.0 to 10.0
		outFile << (1.0 + rand() % 9) << endl;
		counter++;
	}
	outFile.close();
	outFile.clear();
	
	return 0;
}

string generate_random_string(int max_length)
{
	const string alphabet = "ABCEDEFHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz ";
	
	int stringLength = 1 + rand() % max_length;
	//cout << "\nString Length: " << stringLength << endl;
	int index;
	
	string generatedString = "";
	index = rand() % 25; 
	generatedString += alphabet[index];
	for(int x=1; x<stringLength; x++)
	{
		index = rand() % 54;  //55 is length of alphabet string
		generatedString += alphabet[index];
	}
	//cout << "\nGenerated String: " << generatedString << endl;
	return generatedString;
}