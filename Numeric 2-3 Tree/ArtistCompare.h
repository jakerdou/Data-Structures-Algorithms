/**************************************************************
 * File:    ArtistCompare.h
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * compares artist titles alphabetically to order the 2-3 tree
 *
 *
 *************************************************************/
#ifndef ARTIST_COMPARE_H
#define ARTIST_COMPARE_H

/* Declaration of the comparison functor for use with the Artist index */

#include <string>
#include "Song.h"

struct ArtistCompare
{
	/*
	 * Return whether or not song a's artist is
	 * lexicographically less than song b's artist
	 */
	bool operator()(const Song *a, const Song *b);

	/*
	 * Return whether or not the song's artist is
	 * lexicographically less than the given artist
	 */
	bool operator()(const Song *song, const std::string &artist);

	/*
	 * Return whether or not the given artist is
	 * lexicographically less than the song's artist
	 */
	bool operator()(const std::string &artist, const Song *song);
};

#endif
