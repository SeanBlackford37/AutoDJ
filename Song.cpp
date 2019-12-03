//
// Created by Aidan DeBolt on 11/18/19.
//

#include "Song.h"
#include <sstream>
#include <iostream>


Song::Song(){
    title = "Untitled";
    artist = "Unknown";
    duration = 0;
    durationString = "0";
    playCount = 0;
}

//Adds songs from user
Song::Song(std::string titleIn, std::string artistIn, std::string durationIn){
    title = titleIn;
    artist = artistIn;
    duration = durationToInt(durationIn);
    durationString = durationIn;
    playCount = 0;
}

Song::Song(std::string songInfo){
    std::stringstream splitter (songInfo);
    std::string words;
    //works if no commas in the any of the data except for separation
    //we can use ;s instead of commas though if we wanted to try and avoid that issue
    //we'd just need the user to input it in that specific way
    if (splitter) {
        getline(splitter, words, ',');
        title = words;
        getline(splitter, words, ',');
        artist = words;
        getline(splitter, words, ',');
        durationString = words;
        duration = durationToInt(words);
        playCount = 0;
    }

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
            else{
                currDuration += x;
            }
            getline(splitter, words, ':');
        }
    }
    return currDuration;
}


std::string Song::toString(){
    return "Title: " + title + " Artist: " + artist + " Duration: " + durationString;
}

std::string Song::toStringtoFile() {
    return title + "," + artist + "," + durationString;
}

 std::string Song::getArtist() {
    return artist;
}

 std::string Song::getTitle() {
    return title;
}

int Song::getDuration() {
    return duration;
}

int Song::getPlayCount() {
    return playCount;
}

std::string Song::getDurationString() {
    return durationString;
}