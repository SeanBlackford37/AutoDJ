//
// Created by Morgan Ziegler on 11/19/19.
//

#include "Library.h"
#include "ArrayLib.h"
#include "Playlist.h"
#include "Song.h"
#include <iostream>
#include <fstream>
#include <sstream>

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

void Library::AddSongsFromFile(std::string file_name){
    std::cout << "reading..." << std::endl;
    std::string filename = file_name;
    std::ifstream infile(filename);
    if (infile){
        while (infile){
            std::string line;
            getline(infile, line);
            std::cout << line << std::endl;
            if(line != ""){
                addSongToLibrary(line);
            }

        }
    }else {
        std::cout << "file can not be read file!"  << std::endl;

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
    std::cout << "reading..." << std::endl;
    std::string filename = file_name;
    std::ifstream infile(filename);
    if (infile){
        while (infile){
            std::string line;
            getline(infile, line);
            if(line != line) {
                Song songin(line);
                removeFromPlaylists(songin.getArtist(), songin.getTitle());
                removeSongFromLibrary(line);
            }
        }
    }else {
        std::cout << "file can not be read file!"  << std::endl;

    }
    std::cout << "closing" << std::endl;
    infile.close();
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
    //TODO
    playlists->getValueAt(indexOfPlaylist).removeSong(artist,titleIn);
}
void Library::removeFromPlaylists(std::string artist, std::string titleIn) {

    for (int i = 0; i < playlists->itemCount(); i++){
        playlists->getValueAt(i).removeSong(artist,titleIn);
    }

}




void Library::addToPlaylist(std::string nameIn, std::string artist, std::string titleIn) {
    int indexOfPlaylist = playlists->find(nameIn);
    int indexOfSong = songs->findArtistandTitle(songs->itemCount(),artist,titleIn);
    Playlist tempPlay = playlists->getValueAt(indexOfPlaylist);
    if (indexOfSong == -1) {
        std::cout << "\tSong is not in Library" <<std::endl;
    }
    else if (indexOfPlaylist == -1){
        std::cout << "\tPlaylist with that name does not exist" << std::endl;
    }
    else{
        Song temp = songs->getValueAt(indexOfSong);
        tempPlay.addSong(temp.toStringtoFile());
        playlists->removeValueAt(indexOfPlaylist);
        playlists->insertAt(tempPlay,indexOfPlaylist);

//        Song temp = songs->getValueAt(indexOfSong);
//        Playlist tempPlay = playlists->getValueAt(indexOfPlaylist);
//        tempPlay.addSong(temp.toStringtoFile());
//        playlists->getValueAt(indexOfPlaylist) = tempPlay;
    }
}


void Library::displayArtist(std::string artistIn) {
    int count = 0;
    std::cout << "Songs by " + artistIn + ": " << std::endl;
    for (int i =0; i < songs->itemCount(); i++){
        if (artistIn == songs->getValueAt(i).getArtist()){
            count += 1;
            std::cout << "\t"+songs->getValueAt(i).toString() << std::endl;
        }
    }
    if (count ==0){
        std::cout << "\tNo songs by that artist were found" << std::endl;
    }

}

void Library::displaySong(std::string artistIn, std::string titleIn) {
    int index = songs->findArtistandTitle(songs->itemCount(),artistIn,titleIn);
    if (index != -1){
        std::cout << songs->getValueAt(index).toString() << std::endl;
    }
    else{
        std::cout << "\tSong was not in the Library" << std::endl;
    }
}


void Library::displayPlaylist(std::string nameIn) {
    int index = playlists->find(nameIn);
    if (index != -1){
        std::cout << nameIn + " Duration: " + playlists->getValueAt(index).calcDuration() << std::endl;
        std::cout << playlists->getValueAt(index).toString()<<std::endl;
    }
    else{
        std::cout << "Playlist does not exist" << std::endl;
    }

}

void Library::playNext(std::string nameIn) {
    int index = playlists->find(nameIn);
    Playlist tempPlay =playlists->getValueAt(index);
    std::string msg = tempPlay.playNext();
    playlists->removeValueAt(index);
    playlists->insertAt(tempPlay,index);
    if (msg == "Playlist is empty"){
        playlists->removeValueAt(index);
        std::cout << "Playlist is already empty, it will now be removed" << std::endl;
    }
    else{
        Song temp = Song(msg);
        int index = songs->findArtistandTitle(songs->itemCount(),temp.getArtist(),temp.getTitle());
        std::cout << "Song being played: " + songs->getValueAt(index).toString() << std::endl;
        Song real = songs->getValueAt(index);
        real.incrementPlayCount();
        songs->removeValueAt(index);
        songs->insertAt(real ,index);
        if (playlists->getValueAt(index).isEmpty()){
            playlists->removeValueAt(index);
        }
    }

}

void Library::newRandomPlaylist(std::string nameIn, std::string duration) {
    Playlist randPlaylist = Playlist(nameIn);
    std::stringstream splitter (duration);
    std::string words;
    int count = 0;
    int maxDuration = 0;
    if (splitter){
        getline(splitter, words, ':');
        while (splitter){
            int temp = stoi(words);
            // it to the integer x
            if(count == 0) {
                count++;
                maxDuration += temp * 60 * 60;
            }
            else if(count == 1) {
                count++;
                maxDuration += temp * 60;
            }
            else{
                maxDuration += temp;
            }
            getline(splitter, words, ':');
        }
    }
    int failCount = 0;
    int runningDuration = 0;
    while (failCount != 10){
        int randIndex = genRandInt(0, songs->itemCount()-1);
        Song randSong = songs->getValueAt(randIndex);
        if (randPlaylist.find(randSong.getArtist(),randSong.getTitle()) != -1){
            failCount++;
        }
        else{
            if (runningDuration + randSong.getDuration() > maxDuration){
                failCount ++;
            }
            else{
                failCount = 0;
                runningDuration += randSong.getDuration();
                randPlaylist.addSong(randSong.toStringtoFile());
            }
        }
    }
    playlists->insertAtEnd(randPlaylist);


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
            std::cout << Song(songIn).toString() << " is already in the library" << std::endl;
        }
    }

}


void Library::removeSongFromLibrary(std::string songIn) {

        Song temp = Song(songIn);
        int indexSong = songs->findArtistandTitle(songs->itemCount(), temp.getArtist(), temp.getTitle());
        if(indexSong != -1) {
            songs->removeValueAt(indexSong);
        }else{
            std::cout << Song(songIn).toString() << " is not in the library" << std::endl;
        }




}






