//
// Created by Aidan DeBolt on 11/18/19.
//

#ifndef HELLOWORLD_SONG_H
#define HELLOWORLD_SONG_H
#include <iostream>

class Song {
private:
    //Artist for the song
    std::string artist;
    //The name of the song
    std::string title;
    //Duration of the song converted into seconds from 3:20 format
    int duration;
    //the number of times the song has been played
    int playCount;

public:
    /**
     * Constructor
     * Takes in title,artist, and duration as strings
     */
    Song(std::string titleIn, std::string artistIn, std::string durationIn);

    //Constructor for reading a text file

    /**
     * Coverts the given duration from a string to an integer ex) 3:20 -> 200
     */
    int durationToInt(std::string durationIn);


    /**
     * Turns the given song to a string format and is returned
     */
    std::string toString();
};

#endif //HELLOWORLD_SONG_H
