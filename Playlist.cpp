//
// Created by Morgan Ziegler on 12/1/19.
//

#include "Playlist.h"
#include "ArrayLib.h"
#include "ArrayList.h"

Playlist::Playlist() {
    name = "unnamed";
    songs = new ArrayList(10);
}

Playlist::Playlist(std::string nameIn) {
    name = nameIn;
    songs = new ArrayList(10);
}



Playlist& Playlist::operator=(const Playlist &PlaylistToCopy){
    if (this != &PlaylistToCopy){
        delete this->songs;
        this->name = PlaylistToCopy.name;
        this->songs = new ArrayList(*PlaylistToCopy.songs);

    }
    return *this;
}



Playlist::Playlist(const Playlist& PlaylistToCopy) {

    this->name = PlaylistToCopy.name;
    this->songs = new ArrayList(*PlaylistToCopy.songs);
}


Playlist::~Playlist() {
    if (!songs->isEmpty()){
        songs->clearList();
    }
}
int Playlist::calcIntDuration() {
    int total = 0;
    if (songs->isEmpty()) {
        return 0;
    }
    else{
        for (int i = 0; i < songs->itemCount(); i++) {
            total += songs->getValueAt(i).getDuration();
        }
    }
    return total;
}

std::string Playlist::calcDuration() {
    int total = 0;
    int seconds = 0;
    int minutes = 0;
    int hours = 0;
    if (songs->isEmpty()) {
        return "0";
    }
    else{
        for (int i = 0; i < songs->itemCount(); i++) {
            total += songs->getValueAt(i).getDuration();
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
    return std::to_string(hours) + ":" + std::to_string(minutes) +":"+ std::to_string(seconds);
}

std::string Playlist::toString() {
    std::string info = "";
    for (int i = 0; i < songs->itemCount(); i++) {
        info += "\t";
        info += songs->getValueAt(i).toString();
        info += "\n";
    }
    return info;
}

std::string Playlist::playNext() {
    if (!songs->isEmpty()){
        std::string temp = songs->getValueAt(0).toStringtoFile();
        songs->removeValueAtFront();
        return temp;
    }
    return "Playlist is empty";
}

void Playlist::addSong(std::string SongIn) {
    std::string artist = Song(SongIn).getArtist();
    std::string title = Song(SongIn).getTitle();
    int index = songs->findArtistandTitle(songs->itemCount(),artist,title);
    if (index == -1){
        songs->insertAtEnd(SongIn);
    }
    else{
        std::cout << "This song is already in the given playlist" << std::endl;
    }
}

void Playlist::removeSong(std::string artist, std::string title) {
    int index = songs->findArtistandTitle(songs->itemCount(),artist,title);
    if (index != -1){
        songs->removeValueAt(index);

    }
    else{
        std::cout << title << " " << artist << "  : couldn't be removed" << std::endl;
    }
}

int Playlist::find(std::string artistIn, std::string titleIn){
    return songs->findArtistandTitle(songs->itemCount(),artistIn,titleIn);
}
int Playlist::playListLength(){
   return songs->itemCount();

}

std::string Playlist::getSong(int location){
    return songs->getValueAt(location).toStringtoFile();
}
std::string Playlist::getName(){
    return name;
}
bool Playlist::isEmpty(){
    return songs->isEmpty();
}
