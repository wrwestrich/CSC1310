/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"

Movies::Movies(int max)
{
	maxMovies = max;
	numMovies = 0;
	
	//dynamically create the array that will hold the movies
	moviesArray = new Movie[max];
	
}

void Movies::resizeMovieArray()
{
	int max = maxMovies * 2; //increase size by 2
	
	//make an array that is twice as big as the one I've currently got
	Movie* newMoviesArray = new Movie[max];
	for(int x = 0; x < numMovies; ++x)
	{
		newMoviesArray[x] = moviesArray[x];
	}
	
	//delete the original array from memory
	delete [] moviesArray;
	
	moviesArray = newMoviesArray;
	maxMovies = max;
}

void Movies::addMovieToArray() 
{
	char tempString[100];
	int length, year, numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//get movie data from the user
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nMOVIE TITLE: ";
	cin.getline(tempString, 100);
	title = new Text(tempString);
	cout << "\nMOVIE LENGTH (in minutes): ";
	cin >> length;
	cout << "\nMOVIE YEAR: ";
	cin >> year;
	cin.ignore();
	cout << "\nMOVIE GENRE: ";
	cin.getline(tempString, 100);
	genre = new Text(tempString);
	cout << "\nMOVIE RATING: ";
	cin.getline(tempString, 100);
	rating = new Text(tempString);
	cout << "\nNUMBER OF OSCARS WON: ";
	cin >> numOscars;
	cout << "\nSTAR RATING (out of 10): ";
	cin >> numStars;
	
	//create the movie
	Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);
					
	//add the movie to the library	
	if(numMovies == maxMovies)
		resizeMovieArray();	//increase size by 2

	moviesArray[numMovies] = *oneMovie;

	++(numMovies);
}

void Movies::removeMovieFromArray()
{
	int movieChoice;
	cout << numMovies << endl << endl;
	//delete a movie if there is more than one movie in the library.
	if((numMovies) <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:" << endl;;
		displayMovieTitles();
		cout << "\nChoose a movie to remove between 1 & " << numMovies << ":  ";
		cin >> movieChoice;
		while(movieChoice < 1 || movieChoice > numMovies)
		{
			cout << "\nOops!  You must enter a number between 1 & " << numMovies << ":  ";
			cin >> movieChoice;
		}
		int movieIndexToBeRemoved = movieChoice-1;
		Text* movieTitle;
		movieTitle = moviesArray[movieIndexToBeRemoved].getMovieTitle();
			
		int numElementsToMoveBack = (numMovies) - 1;
		
		for(int x = movieIndexToBeRemoved; x < numElementsToMoveBack; ++x)
		{
			moviesArray[x] = moviesArray[x+1]; //move array elements!
		}
		
		//set the last movie to a null pointer
        Movie* temp = &moviesArray[numElementsToMoveBack];
		temp = nullptr;
		
		//decrement the current number of movies
		--(numMovies);
		
		cout << "\n\nThe movie \"";
		movieTitle->displayText();
		cout << "\" has been successfully deleted.\n";	
	}
}

void Movies::editMovieInArray()
{
	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	displayMovieTitles();
	cout << "\nChoose a movie to remove between 1 & " << numMovies << ":  ";
	cin >> movieChoice;
	while(movieChoice < 1 || movieChoice > numMovies)
	{
		cout << "\nOops!  You must enter a number between 1 & " << numMovies << ":  ";
		cin >> movieChoice;
	}
	moviesArray[movieChoice-1].editMovie(moviesArray[movieChoice-1]);
}

Movies::~Movies()
{
	//delete each movie
	/*for(int x=0; x< numMovies; ++x)
	{
		//delete myMovies->moviesArray[x];
        if(&moviesArray[x] != nullptr)
		    delete &moviesArray[x];
	}
	
	//delete movies array
	delete [] moviesArray;*/
}

void Movies::displayMovies()
{
	if(numMovies > 0)
	{
		for(int x=0; x < (numMovies); ++x)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			moviesArray[x].printMovieDetails(moviesArray[x]); //function is in Movie.cpp
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void Movies::displayMovieTitles()
{
	Text* title;
	
	for(int x=0; x < (numMovies); ++x)
	{
		cout << "\nMOVIE " << (x+1) <<": ";
		title = moviesArray[x].getMovieTitle();
		title->displayText();
	}
}

void Movies::readMoviesFromFile(char *filename)
{
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	int movieOscars; //number of oscars won
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			title = new Text(temp);//create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre = new Text(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = new Text(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			//one movie has been read from the file.  Now create a movie object
			oneMovie = new Movie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
			//now add this movie to the library
			if(numMovies == maxMovies)
				resizeMovieArray();	//increase size by 2
			moviesArray[numMovies] = *oneMovie;
			++(numMovies);
			
			//confirm addition to the user
			cout << endl;
			title->displayText();
			cout << " was added to the movie library!\n";
			
			
			inFile.getline(temp, 100); //read in the next movie title if there is one
			
			++numMoviesReadFromFile;
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void Movies::saveToFile(char *filename)
{
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x < (numMovies); x++)
	{
		moviesArray[x].printMovieDetailsToFile(moviesArray[x], outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}

Movie* Movies::getMovieArray(){

        return moviesArray;
}

int Movies::getMaxMovies(){

        return maxMovies;
}

int Movies::getNumMovies(){

        return numMovies;
}

Movie Movies::getSingleMovie(int i){

        return moviesArray[i];
}
