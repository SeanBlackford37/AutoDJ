//
// Created by Morgan Ziegler on 11/19/19.
//

#include "Library.h"
void Library::AddSongsFromFile(std::string filename) {

}

void Library::displaySongs() {
    for (int i =0; i < songs->itemCount(); i++){
        std::cout << songs->toString();
    }

}