//
// Created by Morgan Ziegler on 11/19/19.
//

#include "Library.h"
#include "ArrayLib.h"

Library::Library(){
    songs = new ArrayList(30);
    playlists = new PlaylistArrayList(15);
    loadLibrary();
}

Library::~Library(){
    delete songs;
    delete playlists;
}

void Library::loadLibrary(){
    //TODO
}

void Library::AddSongsFromFile(std::string filename) {
    //TODO
}

void Library::displaySongs() {
    std::cout << "Library: \n" << std::endl;
    for (int i =0; i < songs->itemCount(); i++){
        std::cout << songs->toString();
    }
}

void Library::discontinue(std::string filename) {
    //TODO
}

void Library::saveLibrary() {
    //TODO
}

void Library::displayPlaylists() {
    std::cout << "Playlists: " << std::endl;
    for (int i =0; i< playlists->itemCount(); i++){
        std::cout << "Name: " + playlists->getValueAt(i).getName() + "Duration: " + playlists->getValueAt(i).calcDuration() << std::endl;
    }
}

void Library::newPlaylist(std::string nameIn) {
    playlists->insertAtEnd(Playlist(nameIn));
}

void Library::removeFromPlaylist(std::string nameIn, std::string artist, std::string titleIn) {
    int indexOfPlaylist = playlists->find(nameIn);
    playlists->getValueAt(indexOfPlaylist).removeSong(artist,titleIn);
}


