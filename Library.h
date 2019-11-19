//
// Created by Morgan Ziegler on 11/19/19.
//

#ifndef HELLOWORLD_LIBRARY_H
#define HELLOWORLD_LIBRARY_H

#include <iostream>

class Library {
private:
    List* songs;


public:
    Library();
    void AddSongsFromFile();
    void displaySongs();
    void discontinue();


};


#endif //HELLOWORLD_LIBRARY_H
