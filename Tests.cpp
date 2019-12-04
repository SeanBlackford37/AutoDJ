//
// Created by Sean Blackford on 11/19/19.
//
#include "Song.h"
#include <iostream>
#include "TestLib.h"
#include "ArrayList.h"

void songTests(){
    std::cout  << "-----Song Tests-----" << std::endl;
    Song* test = new Song("Darude Sandstorm", "Darude", "3:52" );
    printAssertEquals(test->toString(),"Title: Darude Sandstorm Artist: Darude Duration: 3:52");
    printAssertEquals(test->toStringtoFile(),"Darude Sandstorm,Darude,3:52");
    printAssertEquals(test->getDurationString(),"3:52");
    printAssertEquals(test->getDuration(),232);

    Song* test2 = new Song("Darude Sandstorm,Darude,3:52");
    printAssertEquals(test2->toString(),"Title: Darude Sandstorm Artist: Darude Duration: 3:52");
    printAssertEquals(test2->toStringtoFile(),"Darude Sandstorm,Darude,3:52");
    printAssertEquals(test2->getDurationString(),"3:52");
    printAssertEquals(test2->getDuration(),232);
    delete test;
    delete test2;
}

void SongArrayListTests(){
    std::cout << "-----Song Array List Tests-----" << std::endl;
    ArrayList* test = new ArrayList(5);
    test->insertAtFront( Song("Darude Sandstorm,Darude,3:52"));
    printAssertEquals(test->getValueAt(0).toString(),"Title: Darude Sandstorm Artist: Darude Duration: 3:52");
}


int main(){
    songTests();
    SongArrayListTests();

}