//
// Created by Sean Blackford on 11/19/19.
//
#include "Song.h"
#include <iostream>

void songTests(){
    Song test = Song("Darude Sandstorm", "Darude", "3:52" );
    std::cout << test.getDuration() << std::endl;
    std::cout << test.getDurationString() << std::endl;
    Song test2 = Song("darude sandstrom,darude,3:52");
    std::cout << test2.getDuration() <<std::endl;
    std::cout << test2.getDurationString() << std::endl;
}


int main(){
    songTests();

}