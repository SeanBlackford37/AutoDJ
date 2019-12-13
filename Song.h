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
    /**
     * used to write to a file in a specfic format
     * @return the tostring of a song with its artist and or playcount
     */
    std::string toStringtoFile();
    /**
     * increments the current song play count
     */
    void incrementPlayCount();
    /**
     *
     * @return the current song's arist
     */
    std::string getArtist();
    /**
     *
     * @return the current song's title
     */
    std::string getTitle();
    /**
     *
     * @return the duration of the current song in int format
     */
    int getDuration();

    /**
     *
     * @return the duration of the current song in string format
     */
    std::string getDurationString();
};

#endif //CS220FINALPROEJECT_SONG_H
