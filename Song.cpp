//
// Created by Aidan DeBolt on 11/18/19.
//

#include "Song.h"
#include <sstream>
#include <iostream>


//Adds songs from user
Song::Song(std::string titleIn, std::string artistIn, std::string durationIn){
    title = titleIn;
    artist = artistIn;
    durationToInt(durationIn);
}


int Song::durationToInt(std::string durationIn) {
    std::stringstream splitter (durationIn);
    std::string words;
    int count = 0;
    int currDuration = 0;
    if (splitter){
        getline(splitter, words, ':');
        while (splitter){
            std::stringstream stringToInt(words);
            // it to the integer x
            int x = 0;
            stringToInt >> x;
            if(count == 0) {
                count++;
                currDuration = x * 60;
            }
            currDuration += x;
            getline(splitter, words, ':');
        }
    }
    return currDuration;
}

std::string Song::toString(){
    return "Title: " + title + " Artist: " + artist + " Duration: " + std::to_string(duration);
}