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

    std::string filename = "library.txt";
    std::ifstream infile(filename);

    if (infile){
        while (infile){

            std::string line;
            getline(infile, line);

            std::stringstream splitter (line);
            std::string words;

            //std::cout << line << std::endl;

            getline(splitter, words, ':');
            if(line != "" && words == "Title"){
                while(infile) {
                    getline(splitter, words, '\n');
                    std::string name = words;
                    newPlaylist(name);
                    while (infile) {
                        getline(infile, line);
                        std::stringstream splitter(line);
                        getline(splitter, words, ':');
                        if (words == "Title") {
                            getline(splitter, words, '\n');
                            break;
                        }
                        if (line != "") {
                            Song temp = Song(line);
                            addToPlaylist(name, temp.getArtist(), temp.getTitle());
                        }

                    }
                }
            }
            else{
                if(line != ""){
                    addSongToLibrary(line);
                }
            }
        }
    }else {
        std::cout << "save file can not be read file!"  << std::endl;

    }
    infile.close();
}

void Library::quit(){
    std::ofstream myfile;
    std::cout << "saving..." << std::endl;
    std::ofstream file("library.txt", std::ios::trunc);
    myfile.open("library.txt");

    for(int i = 0; i <songs->itemCount();i++){
        myfile << songs->getValueAt(i).toStringtoFile();
        myfile << "\n";
    }
    for(int i = 0; i<playlists->itemCount();i++){
        myfile <<"Title:" + playlists->getValueAt(i).getName();
        myfile<<"\n";
        for(int j = 0; j < playlists->getValueAt(i).playListLength(); j++) {
            myfile << playlists->getValueAt(i).getSong(j);
            myfile<<"\n";
        }
    }
    std::cout << "library has been saved" << std::endl;
    myfile.close();

}

void Library::AddSongsFromFile(std::string file_name){
    std::string filename = file_name;
    std::ifstream infile(filename);
    if (infile){
        std::cout << "reading file..." << std::endl;
        while (infile){
            std::string line;
            getline(infile, line);
            //std::cout << line << std::endl;
            if(line != ""){
                addSongToLibrary(line);
            }
        }
        std::cout << "read" << std::endl;
    }else {
        std::cout << "file can not be read file!"  << std::endl;

    }

    infile.close();

}



void Library::displaySongs() {
    std::cout << "Library: " << std::endl;
    for (int i =0; i < songs->itemCount(); i++){
        std::cout << "\t" + songs->getValueAt(i).toString() + "\n";
    }
}
void Library::discontinue(std::string file_name) {
    std::string filename = file_name;
    std::ifstream infile(filename);
    if (infile){
        std::cout << "reading file..." << std::endl;
        while (infile){
            std::string line;
            getline(infile, line);
            if(line != "") {
                Song songIn = Song(line);
                removeFromPlaylists(songIn.getArtist(), songIn.getTitle());
                removeSongFromLibrary(line);
            }
        }
        std::cout << "read" << std::endl;
    }else {
        std::cout << "file can not be read file!"  << std::endl;

    }
    infile.close();
}



void Library::displayPlaylists() {
    std::cout << "Playlists: " << std::endl;
    int count = 0;
    for (int i =0; i< playlists->itemCount(); i++){
        std::cout << "Name: " + playlists->getValueAt(i).getName() + " Duration: " + playlists->getValueAt(i).calcDuration() << std::endl;
        count ++;
    }
    if (count ==0){
        std::cout << "\tNo Playlists available" << std::endl;
    }
}

void Library::newPlaylist(std::string nameIn) {
    int index = playlists->find(nameIn);
    if (index == -1){
        std::cout << "Playlist was created,  Name : " + nameIn << std::endl;
        playlists->insertAtEnd(Playlist(nameIn));
    }
    else{
        std::cout << "Playlist with that name already exists" << std::endl;
    }

}

void Library::removeFromPlaylist(std::string nameIn, std::string artist, std::string titleIn) {
    int indexOfPlaylist = playlists->find(nameIn);
    if (indexOfPlaylist != -1){
        Playlist temp = playlists->getValueAt(indexOfPlaylist);
        temp.removeSong(artist,titleIn,1);
        playlists->removeValueAt(indexOfPlaylist);
        playlists->insertAt(temp,indexOfPlaylist);
        std::cout << titleIn + " by " + artist + " was removed from the playlist: " + nameIn << std::endl;
    }

}
void Library::removeFromPlaylists(std::string artist, std::string titleIn) {

    for (int i = 0; i < playlists->itemCount(); i++){
        Playlist temp = playlists->getValueAt(i);
        temp.removeSong(artist,titleIn,0);
        playlists->removeValueAt(i);
        playlists->insertAt(temp,i);
    }

}




void Library::addToPlaylist(std::string nameIn, std::string artist, std::string titleIn) {
    int indexOfPlaylist = playlists->find(nameIn);
    int indexOfSong = songs->findArtistandTitle(songs->itemCount(),artist,titleIn);

    if (indexOfSong == -1) {
        std::cout << "\tSong is not in Library" <<std::endl;
    }
    else if (indexOfPlaylist == -1){
        std::cout << "\tPlaylist with that name does not exist" << std::endl;
    }
    else{
        Playlist tempPlay = playlists->getValueAt(indexOfPlaylist);
        Song temp = songs->getValueAt(indexOfSong);
        tempPlay.addSong(temp.toStringtoFile());
        playlists->removeValueAt(indexOfPlaylist);
        playlists->insertAt(tempPlay,indexOfPlaylist);
        std::cout << titleIn + "by " + artist + " was added to the playlist: " + nameIn << std::endl;

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
    if (index != -1) {
        Playlist tempPlay = playlists->getValueAt(index);
        std::string msg = tempPlay.playNext();
        playlists->removeValueAt(index);
        playlists->insertAt(tempPlay, index);
        if (msg == "Playlist is empty") {
            playlists->removeValueAt(index);
            std::cout << "Playlist is already empty, it will now be removed" << std::endl;
        } else {
            Song temp = Song(msg);
            int songindex = songs->findArtistandTitle(songs->itemCount(), temp.getArtist(), temp.getTitle());
            std::cout << "Song being played: " + songs->getValueAt(songindex).toString() << std::endl;
            Song real = songs->getValueAt(songindex);
            real.incrementPlayCount();
            songs->removeValueAt(songindex);
            songs->insertAt(real, songindex);
            if (playlists->getValueAt(index).isEmpty()) {
                playlists->removeValueAt(index);
            }
        }
    }
    else{
        std::cout<< "Playlist with this name does not exist" <<std::endl;
    }

}

void Library::newRandomPlaylist(std::string nameIn, std::string duration) {
    if (playlists->find(nameIn) == -1){
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
        while (failCount != songs->itemCount()*2){
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
        std::cout << "a random playlist was created. Playlist: " + nameIn << std::endl;
    }
    else{
        std::cout << "Playlist with this name already exists" << std::endl;
    }



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






