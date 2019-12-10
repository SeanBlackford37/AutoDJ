//
// Created by Morgan Ziegler on 12/10/19.
//

#include <iostream>
#include "Library.h"
#include <sstream>

//First we'd load in a file
int meen(){
    std::string command = "";
    Library djBoard = Library();
    std::cout << "Enter help for a list of commands" << std::endl;
    std::cout << "Enter your command: " <<std::endl;
    std::cin >> command;
    while (command != "quit" ){
        std::stringstream splitter (command);
        std::string words;
        getline(splitter, words, '<');
        if (command == "help"){
            std::cout << "help \n\t Provides a summary of all available commands." << std::endl;
            std::cout << "library \n\t Display all songs in alphabetical order by artist (within artist alphabetical by song)" << std::endl;
        }
        else if (command == "library"){
            djBoard.displaySongs();
        }
        else if (words == "artist"){
            //TODO
        }
        else if (words == "song"){
            //TODO
        }
        else if(words == "import"){
            //TODO
        }
        else if(words == "discontinue"){
            //TODO
        }
        else if(command == "playlists"){
            //TODO
        }
        else if(words == "playlist"){
            //TODO
        }
        else if(words == "add"){
            //TODO
        }
        else if(words == "remove"){
            //TODO
        }
        else if(words == "playnext"){
            //TODO
        }
        else if(words == "newrandom"){
            //TODO
        }
        else{
            std::cout << "That is not a valid command, enter help for a list of commands" << std::endl;
        }
        std::cout << "Enter your command: " <<std::endl;
        std::cin >> command;
    }
}

