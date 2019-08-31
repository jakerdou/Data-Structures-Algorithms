/**************************************************************
 * File:    TitleCompare.h
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * compares song titles alphabetically to order the 2-3 tree
 *
 *
 *************************************************************/
#ifndef TITLE_COMPARE_H
#define TITLE_COMPARE_H

/* Declaration of the comparison functor for use with the Title index */

#include <string>
#include "Song.h"

struct TitleCompare
{
    /* 
     * Return whether or not song a's title is 
     * lexicographically less than song b's title
     */
	bool operator()(const Song *a, const Song *b);

    /*
     * Return whether or not the song's title is
     * lexicographically less than the given title
     */
	bool operator()(const Song *song, const std::string &title);

    /*
     * Return whether or not the given title is
     * lexicographically less than the song's title
     */
	bool operator()(const std::string &title, const Song *song);
};

#endif
