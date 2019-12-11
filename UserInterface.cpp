//
// Created by Morgan Ziegler on 12/10/19.
//

#include <iostream>
#include "Library.h"
#include <sstream>
#include <fstream>



//First we'd load in a file but need that to work first
int maine(){
    std::string command = "";
    Library djBoard = Library();
    //WE'd get rid of this
    djBoard.addSongToLibrary("Darude Sandstorm,Darude,3:52");
    djBoard.addSongToLibrary("Wake Me Up,Avicii,4:32");
    djBoard.addSongToLibrary("Hey Brother,Avicii,4:21");
    //to here, this was for testing
    std::cout << "Enter help for a list of commands" << std::endl;
    std::cout << "Enter your command: " <<std::endl;
    std::getline(std::cin, command);
    while (command != "quit" ){
        std::stringstream splitter (command);
        std::string words;
        getline(splitter, words, '<');
        if (command == "help"){
            std::cout << "help \n\t Provides a summary of all available commands." << std::endl;
            std::cout << "library \n\t Display all songs in alphabetical order by artist (within artist alphabetical by song)" << std::endl;
            std::cout << "artist<artist> \n\tDisplay all songs for the given artist." << std::endl;
            std::cout << "song<artist,title> \n\tDisplay all information for the given song." <<std::endl;
            std::cout << "import<filename>\n\tAdd all songs from the given file to the library." <<std::endl;
            std::cout << "discontinue<filename>\n\tRemove all songs from the given file from the library. Also remove these songs from any playlist in which they occur." <<std::endl;
            std::cout << "playlists\n\tDisplay the names of all playlists and their durations." << std::endl;
            std::cout << "playlist<name>\n\tDisplay all songs left in the given playlist, and the duration (time it will take to play the remaining songs)" << std::endl;
            std::cout << "new<name>\n\tMake a new empty playlist with the given name." <<std::endl;
            std::cout << "add<name,artist,title>\n\tAdd the given song to the end of the given playlist" << std::endl;
            std::cout << "remove<name, artist, title>\n\tremove the given song from the playlist" << std::endl;
            std::cout << "playnext<name>\n\tPrint all information about the next song to be played from the given playlist to the screen." <<std::endl;
            std::cout << "newrandom<name,duration>\n\tMake a new playlist with the given name, and populate it with a random group of songs that do not repeat. \n\tInput duration like 0:12:2 if the desired length of the playlist was 0 hours, 12 minutes, and 2 seconds" << std::endl;
            std::cout << "quit\n\tSave the library and all playlists and terminate execution." << std::endl;
        }
        else if (command == "library"){
            djBoard.displaySongs();
        }
        else if (words == "artist"){
            std::string artist;
            getline(splitter, artist, '>');
            djBoard.displayArtist(artist);
        }
        else if (words == "song"){
            std::string title;
            std::string artist;
            getline(splitter, artist, ',');
            getline(splitter, title, '>');
            djBoard.displaySong(artist,title);
        }
        else if(words == "import"){
            std::string filename;

            std::cout << "reading..." << std::endl;
            filename = "Songs.txt";
            std::ifstream infile(filename);
            if (infile){
                while (infile){
                    std::string line;
                    getline(infile, line);
                    getline(splitter, filename, '>');
                    djBoard.addSongToLibrary(line);
                }
            }else {
                std::cout << "can't read file!"  << std::endl;
            }
            std::cout << "read....closing" << std::endl;
            infile.close();



            getline(splitter, filename, '>');
            //djBoard.AddSongsFromFile(filename);
            //TODO in prog

        }
        else if(words == "discontinue"){
            //TODO Remove all songs from the given file from the library?
            std::string filename;
            getline(splitter, filename, '>');
            std::cout << "reading..." << std::endl;
            filename = "Songs.txt";
            std::ifstream infile(filename);
            if (infile){
                while (infile){
                    std::string line;
                    getline(infile, line);
                    getline(splitter, filename, '>');
                    djBoard.discontinue(line);
                }
            }else {
                std::cout << "can't read file!"  << std::endl;
            }
            std::cout << "read....closing" << std::endl;
            infile.close();


            //djBoard.discontinue(filename);
            //TODO in prog

        }
        else if(command == "playlists"){
            djBoard.displayPlaylists();
        }
        else if(words == "playlist"){
            std::string name;
            getline(splitter, name, '>');
            djBoard.displayPlaylist(name);
        }
        else if(words == "new"){
            std::string name;
            getline(splitter, name, '>');
            djBoard.newPlaylist(name);
        }
        else if(words == "add"){
            std::string name;
            std::string title;
            std::string artist;
            getline(splitter, name, ',');
            getline(splitter, artist, ',');
            getline(splitter, title, '>');
            djBoard.addToPlaylist(name,artist,title);
        }
        else if(words == "remove"){
            std::string name;
            std::string title;
            std::string artist;
            getline(splitter, name, ',');
            getline(splitter, artist, ',');
            getline(splitter, title, '>');
            djBoard.removeFromPlaylist(name,artist,title);
        }
        else if(words == "playnext"){
            std::string name;
            getline(splitter, name, '>');
            djBoard.playNext(name);
        }
        else if(words == "newrandom"){
            std::string name;
            std::string duration;
            getline(splitter, name, ',');
            getline(splitter, duration, '>');
            djBoard.newRandomPlaylist(name, duration);
        }
        else{
            std::cout << "That is not a valid command, enter help for a list of commands" << std::endl;
        }
        std::cout << "Enter your command: " <<std::endl;
        std::getline(std::cin, command);
    }

    //djBoard.saveLibrary();

    return 0;
}

