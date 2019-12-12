//
// Created by Morgan Ziegler on 12/10/19.
//

#include <iostream>
#include "Library.h"
#include <sstream>




int maine(){
    std::string command = "";
    Library djBoard = Library();
    std::cout << "Enter help for a list of commands" << std::endl;
    std::cout << "Enter your command: " <<std::endl;
    std::getline(std::cin, command);
    while (command != "quit" ){
        std::stringstream splitter (command);
        std::string words;
        getline(splitter, words, '<');
        if (command == "help"){
            djBoard.help();
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
            getline(splitter, filename, '>');
            djBoard.AddSongsFromFile(filename);

        }
        else if(words == "discontinue"){
            std::string filename;
            getline(splitter, filename, '>');
            djBoard.discontinue(filename);

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
            std::string test;
            getline(splitter, name, ',');
            getline(splitter, duration, '>');
            getline(splitter, test, ':');
            if (duration == test){
                std::cout << "Not a valid use of the command, don't forget to put the duration" << std::endl;
            }
            else{
                djBoard.newRandomPlaylist(name, duration);
            }

        }
        else{
            std::cout << "That is not a valid command, enter help for a list of commands" << std::endl;
        }
        std::cout << "\nEnter your command: " <<std::endl;
        std::getline(std::cin, command);
    }

    djBoard.quit();

    return 0;
}

