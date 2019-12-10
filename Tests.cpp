//
// Created by Sean Blackford on 11/19/19.
//
#include "Song.h"
#include <iostream>
#include <fstream>
#include "TestLib.h"
#include "ArrayList.h"
#include "Playlist.h"
#include "Library.h"
<<<<<<< HEAD

=======
>>>>>>> d682478fd38a9b61a1c948a417361c7ca359babb

void songTests(){
    std::cout  << "-----Song Tests-----" << std::endl;
    Song* test = new Song("Darude Sandstorm", "Darude", "3:52" );
    printAssertEquals(test->toString(),"Title: Darude Sandstorm Artist: Darude Duration: 3:52 Play Count: 0");
    printAssertEquals(test->toStringtoFile(),"Darude Sandstorm,Darude,3:52");
    printAssertEquals(test->getDurationString(),"3:52");
    printAssertEquals(test->getDuration(),232);

    Song* test2 = new Song("Darude Sandstorm,Darude,3:52");
    printAssertEquals(test2->toString(),"Title: Darude Sandstorm Artist: Darude Duration: 3:52 Play Count: 0");
    printAssertEquals(test2->toStringtoFile(),"Darude Sandstorm,Darude,3:52");
    printAssertEquals(test2->getDurationString(),"3:52");
    printAssertEquals(test2->getDuration(),232);

    Song* test3 = new Song("Party Rock Anthem", "", "6:16" );
    printAssertEquals(test3->toString(),"Title: Party Rock Anthem Artist: Unknown Duration: 6:16 Play Count: 0");

    Song* test4 = new Song("Nobody's Perfect,Hannah Montana,3:21, 4");
    printAssertEquals(test4->toString(),"Title: Nobody's Perfect Artist: Hannah Montana Duration: 3:21 Play Count: 4");
    printAssertEquals(test4->getDurationString(),"3:21");
    printAssertEquals(test4->getDuration(),201);


    delete test;
    delete test2;
    delete test3;
    delete test4;
    std::cout << "--done--" <<std::endl;
}

void SongArrayListTests(){
    std::cout << "-----Song Array List Tests-----" << std::endl;
    ArrayList* test = new ArrayList(5);
    test->insertAtFront( Song("Darude Sandstorm,Darude,3:52"));
    printAssertEquals(test->getValueAt(0).toString(),"Title: Darude Sandstorm Artist: Darude Duration: 3:52 Play Count: 0");
    test->insertAtFront( Song("Wake Me Up,Avicii,4:32"));
    printAssertEquals(test->getValueAt(0).toString(),"Title: Wake Me Up Artist: Avicii Duration: 4:32 Play Count: 0");
    printAssertEquals(test->getValueAt(1).toString(),"Title: Darude Sandstorm Artist: Darude Duration: 3:52 Play Count: 0");
    std::cout << "--done--" <<std::endl;
}

void playlistTests() {
    std::cout << "-----Playlist Tests-----" << std::endl;
    Playlist *test = new Playlist("Dance Party");
    test->addSong("Shooting Stars,Bag Raiders,3:56");


    printAssertEquals(test->toString(), "Title: Shooting Stars Artist: Bag Raiders Duration: 3:56 Play Count: 0\n");

    test->addSong("Never Gonna Give You Up,Rick Astley,3:33");


    printAssertEquals(test->toString(),
                      "Title: Shooting Stars Artist: Bag Raiders Duration: 3:56 Play Count: 0\nTitle: Never Gonna Give You Up Artist: Rick Astley Duration: 3:33 Play Count: 0\n");

    printAssertEquals(test->toString(),"Title: Shooting Stars Artist: Bag Raiders Duration: 3:56 Play Count: 0\nTitle: Never Gonna Give You Up Artist: Rick Astley Duration: 3:33 Play Count: 0\n");

    printAssertEquals(test->toString(),"Title: Shooting Stars Artist: Bag Raiders Duration: 3:56 Play Count: 0\nTitle: Never Gonna Give You Up Artist: Rick Astley Duration: 3:33 Play Count: 0\n");
    test->addSong("w.a.m.s,Fall Out Boy,4:38");
    printAssertEquals("0:12:7",test->calcDuration());
    test->removeSong("Bag Raiders", "Shooting Stars");
    test->removeSong("Fall Out Boy", "w.a.m.s");
    test->removeSong("Rick Astley", "Never Gonna Give You Up");
    printAssertEquals(test->toString(), "");
    std::cout << "--done--" <<std::endl;


}
void LibraryTests() {
    std::cout << "-----Library Tests-----" << std::endl;
}

void libraryTests(){
    std::cout << "----Library Tests----" << std::endl;
    Library* testLib = new Library();
    testLib->addSongToLibrary("Never Gonna Give You Up,Rick Astley,3:33");
    testLib->addSongToLibrary("Wake Me Up,Avicii,4:32,3");
    testLib->addSongToLibrary("Hey Brother,Avicii,4:23");
    testLib->addSongToLibrary("Hey Brother,Avicii,4:23,3");
    testLib->displaySongs();



    std::cout << "--done--" <<std::endl;
}


int main(){
<<<<<<< HEAD
    //songTests();
    //SongArrayListTests();
    //playlistTests();
    LibraryTests();
=======
    songTests();
    SongArrayListTests();
    playlistTests();
    libraryTests();
>>>>>>> d682478fd38a9b61a1c948a417361c7ca359babb

}