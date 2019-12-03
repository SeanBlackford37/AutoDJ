//
// Created by Sean Blackford on 11/19/19.
//
#include "Song.h"
#include <iostream>
#include "TestLib.h"

void songTests(){
    std::cout  << "-----Song Tests-----" << std::endl;
    Song* test = new Song("Darude Sandstorm", "Darude", "3:52" );
    printAssertEquals(test->getDurationString(),"3:52");
    printAssertEquals(test->getDuration(),232);
    Song* test2;
    test2 = test;
    delete test;
    printAssertEquals(test2->getDurationString(),"3:52");
    printAssertEquals(test2->getDuration(),232);
    delete test2;


}


int main(){
    songTests();

}