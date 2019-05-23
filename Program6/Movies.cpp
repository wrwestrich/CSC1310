/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"

Movies::Movies() : movies(new LinkedList<Movie*>){
}


Movies::~Movies(){

    delete movies;
}

void Movies::AddToList(){

	char tempString[100];
	int length, year, numOscars;
	double numStars;
	Text* title;
	Text* genre;
	Text* rating;
	
	//add a movie
	cout << "\n\nMOVIE TITLE: ";
    cin.ignore();
	cin.getline(tempString, 100);
    if(BinarySearch(movies, 0, movies->getLength()-1, tempString) == -1){
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
        cin.ignore();
	
	    //create the movie
	    Movie* oneMovie = new Movie(title, length, year, genre, rating, numOscars, numStars);
	
	    movies->appendNode(oneMovie);
	
        InsertionSort(movies, movies->getLength());
    }
    else
        cout << endl << tempString << " already exists." << endl;
}

void Movies::RemoveFromList(){

	int movieChoice;
	
	if(movies->getLength() <= 1)
	{
	   cout << endl << "There must always be at least one movie in your library.  You can\'t";
	   cout << " remove any movies right now or you will have no movies in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following movies to remove:\n";
		DisplayTitles();
		cout << "\nChoose a movie to remove between 1 & " << movies->getLength() << ":  ";
		cin >> movieChoice;
		
		while(movieChoice < 1 || movieChoice > movies->getLength())
		{
			cout << "\nOops!  You must enter a number between 1 & " << movies->getLength() << ":  ";
			cin >> movieChoice;
		}
        cin.ignore();

		int movieIndexToBeRemoved = movieChoice-1;
		Text* movieTitle;
		movieTitle = movies->getNodeValue(movieIndexToBeRemoved)->getMovieTitle();
		
		cout << "\n\nThe movie \"";
		movieTitle->displayText();
		cout << "\" has been successfully deleted.\n";	
		
		//destroy this movie
		movies->deleteNode(movieIndexToBeRemoved);	
	}
}



void Movies::EditMovieInList(){

	int movieChoice;
	
	cout << "\n\nChoose from the following movies to edit:\n";
	DisplayTitles();
	
	cout << "\nChoose a movie to edit between 1 & " << movies->getLength() << ":  ";
	cin >> movieChoice;
	
	while(movieChoice < 1 || movieChoice > movies->getLength())
	{
		cout << "\nOops!  You must enter a number between 1 & " << movies->getLength() << ":  ";
		cin >> movieChoice;
	}
    cin.ignore();
	
	Movie* oneMovie = movies->getNodeValue(movieChoice-1);
	
	oneMovie->editMovie();
}



void Movies::DisplayMovies(){

	if(movies->getLength() > 0)
	{
		for(int x=0; x < movies->getLength(); x++)
		{
			cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
			movies->getNodeValue(x)->printMovieDetails(); //function is in Movie.cpp
		}
	}
	else	
		cout << "\nThere are no movies in your library yet.";
}

void Movies::DisplayTitles(){

	Text* movieTitle;
	
	for(size_t i = 0; i < movies->getLength(); ++i)
	{
		cout << "\nMOVIE " << i+1 <<": ";
		movieTitle = movies->getNodeValue(i)->getMovieTitle();
		movieTitle->displayText();
	}
}

void Movies::ReadFromFile(char *filename){

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
            if(BinarySearch(movies, 0, movies->getLength()-1, temp) == -1){
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
			
			    movies->appendNode(oneMovie);
			
			    //confirm addition to user
			    cout << endl;
			    title->displayText();
			    cout << " was added to the movie library!\n";

			    ++numMoviesReadFromFile;

                InsertionSort(movies, movies->getLength());
            }
            else{
                cout << endl << temp << " already exists." << endl;

                inFile >> movieLength;
                inFile >> movieYear;
                inFile.ignore();
                inFile.getline(temp, 100);
                inFile.getline(temp, 100);
                inFile >> movieOscars;
                inFile >> movieNumStars;
                inFile.ignore();
            }

            inFile.getline(temp, 100); //read in the next movie title if there is one
        }

		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void Movies::SaveToFile(char *filename){

	ofstream outFile;
	
	outFile.open(filename);
	
	for(size_t i = 0; i < movies->getLength(); ++i)
	{
		movies->getNodeValue(i)->printMovieDetailsToFile(outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}

void Movies::InsertionSort(LinkedList<Movie*>* movies, size_t n){

    for(size_t i = 1; i < n; ++i){
        for(size_t j = i; j > 0 && strcmp(movies->getNodeValue(j-1)->getMovieTitle()->getText(), movies->getNodeValue(j)->getMovieTitle()->getText()) > 0; --j){
            movies->Swap(j-1, j);
        }
    }
}

int Movies::BinarySearch(LinkedList<Movie*>* movies, int low, int high, const char* str){

    while(low <= high){
        
        int mid = (high + low) / 2;
        
        if(strcmp(movies->getNodeValue(mid)->getMovieTitle()->getText(), str) == 0)
            return mid;
        else if(strcmp(movies->getNodeValue(mid)->getMovieTitle()->getText(), str) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int Movies::GetNumMovies(){

	return movies->getLength();
}
