/**************************************************************
 * File:    GenreCompare.h
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * compares Genre titles alphabetically to order the 2-3 tree
 *
 *
 *************************************************************/
#ifndef GENRE_COMPARE_H
#define GENRE_COMPARE_H

/* Declaration of the comparison functor for use with the Genre index */

#include <string>
#include "Song.h"

struct GenreCompare
{
	/*
	 * Return whether or not song a's genre is
	 * lexicographically less than song b's genre
	 */
	bool operator()(const Song *a, const Song *b);

	/*
	 * Return whether or not the song's genre is
	 * lexicographically less than the given genre
	 */
	bool operator()(const Song *song, const std::string &genre);

	/*
	 * Return whether or not the given genre is
	 * lexicographically less than the song's genre
	 */
	bool operator()(const std::string &genre, const Song *song);
};

#endif

