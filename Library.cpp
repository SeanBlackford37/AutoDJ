//
// Created by Morgan Ziegler on 11/19/19.
//

#include "Library.h"
#include "ArrayLib.h"
#include <iostream>
#include <fstream>

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

void Library::AddSongsFromFile(std::string file_name) {
    std::cout << "testing..." << std::endl;
    std::string filename = "Songs.txt";
    std::ifstream infile(filename);
    if (infile){
        while (infile){
            std::string line;
            getline(infile, line);
            std::cout << line << std::endl;
        }
    }else {
        std::cout << "can't read file!"  << std::endl;

    }
    std::cout << "closing" << std::endl;
    infile.close();

}



void Library::displaySongs() {
    std::cout << "Library: " << std::endl;
    for (int i =0; i < songs->itemCount(); i++){
        std::cout << "\t" + songs->getValueAt(i).toString() + "\n";
    }
}

void Library::discontinue(std::string file_name) {

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
    int indexOfSong = songs->findArtistandTitle(songs->itemCount(),artist,titleIn);
    Song temp = songs->getValueAt(indexOfSong);
    playlists->getValueAt(indexOfPlaylist).addSong(temp.toStringtoFile());
}


void Library::displayArtist(std::string artistIn) {
    //TODO
}

void Library::displaySong(std::string artistIn, std::string titleIn) {
    int index = songs->findArtistandTitle(songs->itemCount(),artistIn,titleIn);
    if (index != -1){
        std::cout << songs->getValueAt(index).toString() << std::endl;
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

void Library::playNext(std::string nameIn) {
    int index = playlists->find(nameIn);
    std::string msg = playlists->getValueAt(index).playNext();
    if (msg == "Playlist is empty"){
        playlists->removeValueAtFront();
    }
    else{
        Song temp = Song(msg);
        int index = songs->findArtistandTitle(songs->itemCount(),temp.getArtist(),temp.getTitle());
        songs->getValueAt(index).incrementPlayCount();
    }

}

void Library::newRandomPlaylist(std::string nameIn, std::string duration) {
    playlists->insertAtEnd(Playlist(nameIn));
    //TODO get the random working
}

void Library::addSongToLibrary(std::string songIn) {
    if (songs->isEmpty()){
        songs->insertAtFront(Song(songIn));
    }
    else {
        Song temp = Song(songIn);
        if (songs->findArtistandTitle(songs->itemCount(), temp.getArtist(), temp.getTitle()) == -1) {
            songs->insertAtAlphabetized(Song(songIn));
        } else {
            std::cout << "Song already in" << std::endl;
        }
    }

}


