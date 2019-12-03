//
// Created by Aidan DeBolt on 11/18/19.
//

#ifndef CS220FINALPROEJECT_SONG_H
#define CS220FINALPROEJECT_SONG_H
#include <iostream>

class Song {
private:
    //Artist for the song
    std::string artist;
    //The name of the song
    std::string title;
    //Duration of the song converted into seconds from 3:20 format
    int duration;
    //Duration in the original format
    std::string durationString;
    //the number of times the song has been played
    int playCount;

public:
    /**
     * default constructor
     */
    Song();
    /**
     * Constructor
     * Takes in title,artist, and duration as strings
     */
    Song(std::string titleIn, std::string artistIn, std::string durationIn);

    //Constructor for reading a text file
    Song(std::string songInfo);

    /**
     * Coverts the given duration from a string to an integer ex) 3:20 -> 200
     */
    int durationToInt(std::string durationIn);


    /**
     * Turns the given song to a string format and is returned
     */
    std::string toString();

    std::string toStringtoFile();


    std::string getArtist();

    std::string getTitle();

    int getDuration();

    int getPlayCount();

    std::string getDurationString();
};

#endif //CS220FINALPROEJECT_SONG_H
