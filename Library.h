//
// Created by Morgan Ziegler on 11/19/19.
//

#ifndef CS220FINALPROEJECT_H
#define CS220FINALPROEJECT_H

#include <iostream>

class Library {
private:
    //TODO: Add someones list files to the project, and decide whether to work with arrays or linked lists
    List* songs;
    List* playlists;

public:
    Library();
    ~Library();
    /**
     * add things in alphabetical order and only songs not in the list
     * print songs that already existed in the library
     * @param filename -- name of the file we are importing from
     */
    void AddSongsFromFile(std::string filename);

    //add song normal

    /**
     * prints all the songs in alphabetical order
     */
    void displaySongs();

    /**
     * Remove all songs from a given file from the Library and any playlists that contained those songs
     * and print those that were not removed (weren't within the library)
     * @param filename
     */
    void discontinue(std::string filename);

    /**
     * Writes the current library to a file to save the data when the command quit is typed
     */
    void saveLibrary();

    /**
     * display all names of all playlists and their durations
     */
    void displayPlaylists();

    /**
     * Create a new playlist and add to list of playlists
     * @param nameIn
     */
    void newPlaylist(std::string nameIn);

    /**
     * Removes a song from a specific playlist
     * @param nameIn -- name of playlist
     * @param artist -- artist of song to remove
     * @param titleIn -- title of song to remove
     */
    void removeFromPlaylist(std::string nameIn, std::string artist, std::string titleIn);






};


#endif //CS220FINALPROEJECT_H
