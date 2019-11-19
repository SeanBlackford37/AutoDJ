//
// Created by Aidan DeBolt on 11/18/19.
//

#ifndef HELLOWORLD_SONG_H
#define HELLOWORLD_SONG_H
#include <string>

class Song {
private:
    //Artist for the song
    std::string artist;
    //The name of the song
    std::string songTitle;
    //Duration of the song converted into seconds from 3:20 format
    int duration;
    //the number of times the song has been played
    int playCount;

public:


    /**
     * Turns the given song to a string format and is returned
     */
    std::string toString();
};

#endif //HELLOWORLD_SONG_H
