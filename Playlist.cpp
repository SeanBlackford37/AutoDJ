//
// Created by Morgan Ziegler on 12/1/19.
//

#include "Playlist.h"


Playlist::Playlist(std::string nameIn) {
    name = nameIn;
    songs = new ArrayList(10);
}


Playlist::~Playlist() {
    while (!songs->isEmpty()){
        //delete songs->removeValueAtEnd();
    }
}

std::string Playlist::calcDuration() {
    int total = 0;
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    if (songs->isEmpty()) {
        return 0;
    }
    else{
        for (int i = 0; i < songs->itemCount(); i++) {
            //total += songs->getValueAt(i)->getDuration();
            //get duration technically
        }
    }
    if (total > 60){
        seconds = total % 60;
        minutes = (total - seconds) / 60;
    }
    if (minutes > 60){
        int temp = minutes;
        minutes = minutes % 60;
        hours = (minutes - temp) /60;
    }
    return std::to_string(hours) + ":" + std::to_string(minutes) + std::to_string(seconds);
}

std::string Playlist::toString() {
    for (int i = 0; i < songs->itemCount(); i++) {
        //std::cout << songs->getValueAt(i)->toString() << std::endl;
    }
}

std::string Playlist::playNext() {

}

