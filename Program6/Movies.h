/*
	Title:  Movies.h
	Author:  April R Crockett
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#ifndef MOVIES_H
#define MOVIES_H

#include "Movie.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class Movies
{
	private:
		LinkedList<Movie*>* movies;

	public:
		/*
			Function name:  Movies constructor 
			Parameters:  	An integer containing the maximum size of the movie library 
			Purpose:  		This function is automatically called when a Movies object is created and it creates a library
							of movies.  The function will dynamically allocate a movies array based
							on the maximum size and will also set the current number of movies to zero.
		*/
		Movies();
		
		/*
			Function name:  ~Movies destructor 
			Purpose:  		This function is automatically called when the Movies object is destroyed.
							This releases the dynamically created individual movies and then deletes the array.
		*/
		~Movies();
		
		/*
			Function name:  addMovieToArray 
			Parameters:  	none
			Returns: 		A boolean indicating if the movie was able to be added or not
			Purpose:  		This function should be called when you need to add a single movie to the
							movie library.
		*/
		void AddToList();  

		/*
			Function name:  displayMovies 
			Parameters:  	none
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to have all the movies
							in the library printed to the screen.
		*/
		void DisplayMovies();
		
		/*
			Function name:  displayMovieTitles 
			Parameters:  	none 
			Returns: 		none (void)
			Purpose:  		This function should be called when you want to print only the movie titles
							out of the movie library
		*/
		void DisplayTitles();
		
		/*
			Function name:  readMoviesFromFile 
			Parameters:  	A pointer to a character (c-string or string literal argument) containing the filename
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to read movie data from a file
							and add the movies to the movie library.  The file must have data in the following order:
							title, length, year, genre, rating, number of Oscars won, star rating
		*/
		void ReadFromFile(char* filename);
		
		/*
			Function name:  removeMovieFromArray 
			Parameters:  	none
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to remove one single movie
							from the movie library.  The movie to be removed must is identified
							by the user and then removed.
		*/
		void RemoveFromList();

		/*
			Function name:  editMovieInArray 
			Parameters:  	none
			Returns: 		none
			Purpose:  		This function should be called when you need to edit a movie in the array
		*/
		void EditMovieInList();
				
		/*
			Function name:  saveToFile 
			Parameters:  	A pointer to a character (c-string or string literal argument) containing the filename
			Returns: 		none (void)
			Purpose:  		This function should be called when the user wants to print all the movie data
							from the movie library to a file.  The data is printed in the following order (one piece
							of data per line):
							title, length, year, genre, rating, num oscars won, star rating
		*/
		void SaveToFile(char *filename);

        void InsertionSort(LinkedList<Movie*>*, size_t);

        int BinarySearch(LinkedList<Movie*>*, int, int, const char*);

		//accessor functions to get the attribute values
		int GetNumMovies();	
};
#endif
