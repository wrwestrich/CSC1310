/*
	Title:  Movies.cpp
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"
#include "Timer.h"

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

void Movies::RunAnalysis(){
    time_t start;
    time_t end;
    Text* temp = new Text("Llama");

    start = getTime();
    LinearSearch(movies, GetNumMovies()-1, temp->getText());
    end = getTime();
    cout << endl << endl << "\tLinear Search:\t" << totalTime(start, end) << "s" << endl;

    start = getTime();
    BinarySearch(movies, 0, GetNumMovies()-1, temp->getText());
    end = getTime();
    cout << "\tBinary Search:\t" << totalTime(start, end) << "s" << endl;

    InsertionSortInv(movies, GetNumMovies()-1);
    start = getTime();
    BubbleSort(movies, GetNumMovies()-1);
    end = getTime();
    cout << "\tBubble Sort:\t" << totalTime(start, end) << "s" << endl;

    InsertionSortInv(movies, GetNumMovies()-1);
    start = getTime();
    SelectionSort(movies, GetNumMovies()-1);
    end = getTime();
    cout << "\tSelection Sort:\t" << totalTime(start, end) << "s" << endl;

    InsertionSortInv(movies, GetNumMovies()-1);
    start = getTime();
    InsertionSort(movies, GetNumMovies()-1);
    end = getTime();
    cout << "\tInsertion Sort:\t" << totalTime(start, end) << "s" << endl;

    start = getTime();
    InsertionSortInv(movies, GetNumMovies()-1);
    end = getTime();
    cout << "\tInsertion Sort Decending:\t" << totalTime(start, end) << "s" << endl;

    start = getTime();
    MergeSort(movies, GetNumMovies()-1);
    end = getTime();
    cout << "\tMerge Sort:\t" << totalTime(start, end) << "s" << endl;

    InsertionSortInv(movies, GetNumMovies()-1);
    start = getTime();
    QuickSort(movies, 0, GetNumMovies()-1);
    end = getTime();
    cout << "\tQuick Sort:\t" << totalTime(start, end) << "s" << endl;

    delete temp;
}

void Movies::BubbleSort(LinkedList<Movie*>* movies, size_t n){

    for(size_t i = 0; i < n; ++i)
        for(size_t j = 1; j < n-i; ++j)
            if(strcmp(movies->getNodeValue(j-1)->getMovieTitle()->getText(), movies->getNodeValue(j)->getMovieTitle()->getText()) > 0)
                movies->Swap(j-1, j);
}

void Movies::InsertionSort(LinkedList<Movie*>* movies, size_t n){

    for(size_t i = 1; i < n; ++i){
        for(size_t j = i; j > 0 && strcmp(movies->getNodeValue(j-1)->getMovieTitle()->getText(), movies->getNodeValue(j)->getMovieTitle()->getText()) > 0; --j){
            movies->Swap(j-1, j);
        }
    }
}

void Movies::InsertionSortInv(LinkedList<Movie*>* movies, size_t n){
    
    for(size_t i = 1; i < n; ++i){
        for(size_t j = i; j > 0 && strcmp(movies->getNodeValue(j-1)->getMovieTitle()->getText(), movies->getNodeValue(j)->getMovieTitle()->getText()) < 0; --j){
            movies->Swap(j-1, j);
        }
    }
}

void Movies::Merge(LinkedList<Movie*>* movies, size_t left, size_t mid, size_t right){

    size_t sizeSorted = right - left;
    LinkedList<Movie*>* sortedList = new LinkedList<Movie*>;

    size_t currentLow = left;
    size_t currentHigh = mid;
    size_t currentSorted = 0;

    while((currentLow < mid) && (currentHigh < right)){
        if(strcmp(movies->getNodeValue(currentLow)->getMovieTitle()->getText(), movies->getNodeValue(currentHigh)->getMovieTitle()->getText()) < 0)
            sortedList->insertNode(movies->getNodeValue(currentLow++), currentSorted++);
        else
            sortedList->insertNode(movies->getNodeValue(currentHigh++), currentSorted++);
    }

    while(currentLow < mid){
        sortedList->insertNode(movies->getNodeValue(currentLow++), currentSorted++);
    }

    while(currentHigh < right){
        sortedList->insertNode(movies->getNodeValue(currentHigh++), currentSorted++);
    }

    for(currentSorted = 0; currentSorted < sizeSorted; ++currentSorted)
        movies->replaceNode(sortedList->getNodeValue(currentSorted), currentSorted);

    delete sortedList;
}

void Movies::MergeSort(LinkedList<Movie*>* movies, size_t n){

    for(size_t length = 1; length < n; length *= 2){
        for(size_t left = 0; left < (n-length); left += (length*2)){
            size_t mid = left + length;
            size_t right = min(left + length + length, n);

            Merge(movies, left, mid, right);
        }
    }
}

size_t Movies::Partition(LinkedList<Movie*>* movies, size_t low, size_t high){

    const char* pivot = movies->getNodeValue(low + ((high - low) / 2))->getMovieTitle()->getText();

    while(low < high){
        
        while(strcmp(movies->getNodeValue(low)->getMovieTitle()->getText(), pivot) < 0){
            ++low;
        }

        while(strcmp(movies->getNodeValue(high)->getMovieTitle()->getText(), pivot) > 0){
            --high;
        }

        if(low >= high)
            break;
        else
            movies->Swap(low++, high--);
    }
    return high;
}

void Movies::QuickSort(LinkedList<Movie*>* movies, size_t low, size_t high){

    if(low >= high)
        return;

    size_t p = Partition(movies, low, high);

    QuickSort(movies, low, p);
    QuickSort(movies, p+1, high);
}

void Movies::SelectionSort(LinkedList<Movie*>* movies, size_t n){
    size_t low = 0;

    for(size_t i = 0; i < n; ++i){
        low = i;
        for(size_t j = i+1; j < n; ++j)
            if(strcmp(movies->getNodeValue(j)->getMovieTitle()->getText(), movies->getNodeValue(low)->getMovieTitle()->getText()) < 0)
                low = j;

        movies->Swap(i, low);
    }
}

int Movies::BinarySearch(LinkedList<Movie*>* movies, int low, int high, const char* str){

    while(low <= high){
        
        int mid = low + (high - low) / 2;
        
        if(strcmp(movies->getNodeValue(mid)->getMovieTitle()->getText(), str) == 0)
            return mid;
        else if(strcmp(movies->getNodeValue(mid)->getMovieTitle()->getText(), str) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int Movies::LinearSearch(LinkedList<Movie*>* movies, int size, const char* str){

    for(int i = 0; i < size; ++i){
        if(strcmp(movies->getNodeValue(i)->getMovieTitle()->getText(), str) == 0)
            return i;
    }
    return -1;
}

int Movies::GetNumMovies(){

	return movies->getLength();
}
