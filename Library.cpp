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

void Library::addToPlaylist(std::string nameIn, std::string artist, std::string titleIn) {
    int indexOfPlaylist = playlists->find(nameIn);
    playlists->getValueAt(indexOfPlaylist).addSong(artist,titleIn);
}

void Library::displayArtist(std::string artistIn) {
    //TODO
}

void Library::displaySong(std::string artistIn, std::string titleIn) {
    int index = findArtistandTitle(const songs, songs->itemCount(), artistIn, titleIn);
    if (index != -1){
        songs->getValueAt(index).toString();
    }
    else{
        std::cout << "Song was not in the given Playlist" << std::endl;
    }
}

void Library::displayPlaylist(std::string nameIn) {
    int index = playlists->find(nameIn);
    std::cout << nameIn + " Duration: " + playlists->getValueAt(index).calcDuration() << std::endl;
    std::cout << playlists->getValueAt(index).toString()<<std::endl;
}

void Library::playNext() {
    if (!playlists->isEmpty())   {
        std::string msg = playlists->getValueAt(0).playNext();
        if (msg == )
    }

}


