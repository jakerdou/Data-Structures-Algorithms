/**************************************************************
 * File:    Song.h
 * Project: CSCE 221 - Project 3
 * Author : James Robinson
 * Date   : 4/8/19
 * Section: 510
 * E-mail:  jakerdou@tamu.edu
 *
 * songs to be placed in library
 *
 *
 *************************************************************/
#ifndef SONG_H
#define SONG_H

/* Song structure declaration */

#include <string>
#include <istream>
#include <ostream>

/* 
 * Song structure. Stores metadata relevant to songs.
 * Songs may be serialized and deserialized.
 */
struct Song
{
    std::string title;
    std::string artist;
    std::string album;
    std::string genre;
    unsigned long year;

    /* Insert the given song into the specified output stream */
    friend std::ostream &operator<<(std::ostream &stream, const Song &song);

    /* Insert the given song into the specified output stream */
    friend std::ostream &operator<<(std::ostream &stream, const Song *song);

    /* Deserialize a song from the given input stream */
    friend std::istream &operator>>(std::istream &stream, Song &song);
};


#endif
