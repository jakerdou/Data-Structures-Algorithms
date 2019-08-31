/**************************************************************
 * File:    main.cpp
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * The main file for Project 3. This includes the main function
 * that will take in a library of songs and sort them many
 * different ways into 2-3 tree. Then, for each of those ways
 * of ordering, it will print the tree inorder and level order
 *************************************************************/
/*
 * Basic driver to get you started
 */

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "Library.h"
#include "Song.h"
#include "Tree.h"
#include "TitleCompare.h"
#include "YearCompare.h"
#include "ArtistCompare.h"
#include "GenreCompare.h"
#include "AlbumCompare.h"

#define EXPECTED_ARGC 2

using namespace std;

/* Print the given song to stdout */
void printSong(Song *song)
{
    std::cout << song << '\n';
}

int main(int argc, char **argv)
{
	// INCLUDED DRIVER CODE
	
    if (argc != EXPECTED_ARGC)
    {
        std::cerr << "Usage: " << argv[0] << " <library-path>" << std::endl;
        return 1;
    }

    Library library(argv[1]);
    
	Tree<Song *, AlbumCompare> albumIndex;
	Tree<Song *, ArtistCompare> artistIndex;
	Tree<Song *, GenreCompare> genreIndex;
	Tree<Song *, TitleCompare> titleIndex;
	Tree<Song *, YearCompare> yearIndex;
	
	for (Library::const_iterator iter = library.begin();
		iter != library.end();
		iter++)
	{
		albumIndex.insert(*iter);
	}

	for (Library::const_iterator iter = library.begin();
		iter != library.end();
		iter++)
	{
		artistIndex.insert(*iter);
	}

	for (Library::const_iterator iter = library.begin();
		iter != library.end();
		iter++)
	{
		genreIndex.insert(*iter);
	}

    for (Library::const_iterator iter = library.begin(); 
         iter != library.end(); 
         iter++)
    {
        titleIndex.insert(*iter);
    }

	for (Library::const_iterator iter = library.begin();
		iter != library.end();
		iter++)
	{
		yearIndex.insert(*iter);
	}

	// In order printing
	cout << "\nALBUM IN ORDER PRINTING\n\n";
	std::for_each(albumIndex.begin(), albumIndex.end(), printSong);
	std::cout << std::endl;

	cout << "\nALBUM LEVEL ORDER PRINTING\n\n";
	// Level order Printing
	cout << albumIndex << endl;


	// In order printing
	cout << "\nARTIST IN ORDER PRINTING\n\n";
	std::for_each(artistIndex.begin(), artistIndex.end(), printSong);
	std::cout << std::endl;

	cout << "\nARTIST LEVEL ORDER PRINTING\n\n";
	// Level order Printing
	cout << artistIndex << endl;


	// In order printing
	cout << "\nGENRE IN ORDER PRINTING\n\n";
	std::for_each(genreIndex.begin(), genreIndex.end(), printSong);
	std::cout << std::endl;

	cout << "\nGENRE LEVEL ORDER PRINTING\n\n";
	// Level order Printing
	cout << genreIndex << endl;


	// In order printing
	cout << "\nTITLE IN ORDER PRINTING\n\n";
	std::for_each(titleIndex.begin(), titleIndex.end(), printSong);
	std::cout << std::endl;

	cout << "\nTITLE LEVEL ORDER PRINTING\n\n";
	// Level order Printing
	cout << titleIndex << endl;
	

	// In order printing
	cout << "\nYEAR IN ORDER PRINTING\n\n";
	std::for_each(yearIndex.begin(), yearIndex.end(), printSong);
	std::cout << std::endl;

	cout << "\nYEAR LEVEL ORDER PRINTING\n\n";
	// Level order Printing
	cout << yearIndex << endl;
	
    return 0;
}
