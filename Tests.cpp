//
// Created by Sean Blackford on 11/19/19.
//
#include "Song.h"
#include <iostream>
#include "TestLib.h"
#include "ArrayList.h"
#include "Playlist.h"
#include "Library.h"
#include "LinkedList.h"


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

    Song* test4 = new Song("Nobody's Perfect,Hannah Montana,3:21,4");
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
    List* test = new LinkedList();
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
    test->removeSong("Bag Raiders", "Shooting Stars",1);
    test->removeSong("Fall Out Boy", "w.a.m.s",1);
    test->removeSong("Rick Astley", "Never Gonna Give You Up",1);
    printAssertEquals(test->toString(), "");
    std::cout << "Copy constructor test" << std::endl;

    Playlist original = Playlist("Please");
    original.addSong("Never Gonna Give You Up,Rick Astley,3:33");
    original.addSong("Shooting Stars,Bag Raiders,3:56");
    std::cout << original.toString() << std::endl;
    Playlist copy = Playlist(original);
    std::cout << copy.toString() << std::endl;




    std::cout << "--done--" <<std::endl;


}



void libraryTests() {
    std::cout << "----Library Tests----" << std::endl;
    Library testLib =  Library();

    std::cout << "command: help" <<std::endl;
    testLib.help();

    std::cout << "\ncommand: library" <<std::endl;
    testLib.displaySongs();

    std::cout << "\ncommand: import<somesongs.txt>" <<std::endl;
    testLib.AddSongsFromFile("somesongs.txt");

    std::cout << "\ncommand: library" <<std::endl;
    testLib.displaySongs();

    std::cout << "\ncommand: artist<Fall Out Boy>" <<std::endl;
    testLib.displayArtist("Fall Out Boy");

    std::cout << "\ncommand: song<Avicii,Wake Me Up>" <<std::endl;
    testLib.displaySong("Avicii","Wake Me Up");

    std::cout << "\ncommand: discontinue<songstodelete.txt>" <<std::endl;
    testLib.discontinue("songstodelete.txt");


    std::cout << "\ncommand: playlists" <<std::endl;
    testLib.displayPlaylists();

    std::cout << "\ncommand: new<Test1>" <<std::endl;
    testLib.newPlaylist("Test1");

    std::cout << "\ncommand: playlists" <<std::endl;
    testLib.displayPlaylists();

    std::cout << "\ncommand: add<Test1,Avicii,Wake Me Up>" <<std::endl;
    testLib.addToPlaylist("Test1","Avicii","Wake Me Up");

    std::cout << "\ncommand: playlist<Test1>" <<std::endl;
    testLib.displayPlaylist("Test1");

    std::cout << "\ncommand: add<Test1,Drake,In My Feelings>" <<std::endl;
    testLib.addToPlaylist("Test1","Drake","In My Feelings");

    std::cout << "\ncommand: playlist<Test1>" <<std::endl;
    testLib.displayPlaylist("Test1");

    std::cout << "\ncommand: remove<Test1,Avicii,Wake Me Up>" <<std::endl;
    testLib.removeFromPlaylist("Test1","Avicii","Wake Me Up");

    std::cout << "\ncommand: playnext<Test1>" <<std::endl;
    testLib.playNext("Test1");

    std::cout << "\ncommand: playlist<Test1>" <<std::endl;
    testLib.displayPlaylist("Test1");

    std::cout << "\ncommand: song<Drake,In My Feelings>" <<std::endl;
    testLib.displaySong("Drake","In My Feelings");

    std::cout << "\ncommand: newrandom<Random,0:20:30>" <<std::endl;
    testLib.newRandomPlaylist("Random","0:20:30");

    std::cout << "\ncommand: playlists" <<std::endl;
    testLib.displayPlaylists();

    std::cout << "\ncommand: playlist<Random>" <<std::endl;
    testLib.displayPlaylist("Random");

    std::cout << "\ncommand: newrandom<Random2,0:20:30>" <<std::endl;
    testLib.newRandomPlaylist("Random2","0:20:30");

    std::cout << "\ncommand: playlists" <<std::endl;
    testLib.displayPlaylists();

    std::cout << "\ncommand: playlist<Random2>" <<std::endl;
    testLib.displayPlaylist("Random2");

    testLib.quit();

    Library reopen = Library();
    reopen.displaySongs();
    reopen.displayPlaylists();

}



int main(){

    //songTests();
    //SongArrayListTests();
    playlistTests();
    libraryTests();



    return 0;
}
