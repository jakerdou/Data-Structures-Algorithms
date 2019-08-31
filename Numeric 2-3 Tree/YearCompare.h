/**************************************************************
 * File:    YearCompare.h
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * compares song years numerically to order the 2-3 tree
 *
 *
 *************************************************************/
#ifndef YEAR_COMPARE_H
#define YEAR_COMPARE_H

/* Declaration of the comparison functor for use with the Year index */

#include "Song.h"

struct YearCompare
{
	/*
	 * Return whether or not song a's year is
	 * less than song b's year
	 */
	bool operator()(const Song *a, const Song *b);

	/*
	 * Return whether or not the song's year is
	 * less than the given year
	 */
	bool operator()(const Song *song, const unsigned long &year);

	/*
	 * Return whether or not the given year is
	 * less than the song's year
	 */
	bool operator()(const unsigned long &year, const Song *song);
};

#endif

