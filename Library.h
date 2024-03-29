//
// Created by Morgan Ziegler on 11/19/19.
//

#ifndef CS220FINALPROEJECT_H
#define CS220FINALPROEJECT_H

#include <iostream>
#include "ArrayList.h"
#include "PlaylistArrayList.h"

class Library {
private:
    ArrayList* songs;
    PlaylistArrayList* playlists;

    /**
     * reads everything from the quite file
     * and recreates the library from the information
     * including playlists and song lists
     * probably called within the constructor
     */
    void loadLibrary();

public:
    Library();
    //destructor
    ~Library();
    /**
     * add things in alphabetical order and only songs not in the list
     * print songs that already existed in the library
     * @param filename -- name of the file we are importing from
     */
    void AddSongsFromFile(std::string file_name);


    /**
     * prints all the songs in alphabetical order
     */
    void displaySongs();

    /**
     * Remove all songs from a given file from the Library and any playlists that contained those songs
     * and print those that were not removed (weren't within the library)
     * @param filename
     */
    void discontinue(std::string file_name);




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

    /**
     * Add a song from a specific playlist
     * @param nameIn -- name of playlist
     * @param artist -- artist of song to add
     * @param titleIn -- title of song to add
     */
    void addToPlaylist(std::string nameIn, std::string artist, std::string titleIn);


    /**
     * Display all songs by a given artist
     * @param artistIn -- name of the artist to print
     */
    void displayArtist(std::string artistIn);

    /**
     * Display info for a given song
     * @param artistIn -- name of artist of song to display
     * @param titleIn -- name of title of song to display
     */
    void displaySong(std::string artistIn, std::string titleIn);

    /**
     * Display info of a given playlist
     * What songs are left and duration left
     * @param nameIn -- name of playlist to display
     */
    void displayPlaylist(std::string nameIn);

    /**
     * plays next song and prints the info
     * add to playcount for that song in the library
     * remove the playlist if it is now empty
     */
    void playNext(std::string nameIn);


    /**
     * creates a new  playlist with the name given
     * with random songs that do not repeat within it
     * and as many as possible that dont go over the duration specified
     * @param nameIn
     */
    void newRandomPlaylist(std::string nameIn, std::string duration);
    /**
     * check if songs is empty if it is then the song is added
     * if not and the song is not in the library already(a check) then the song is added
     * @param songIn
     *
     */
    void addSongToLibrary(std::string songIn);

    /**
     * displays the given UserInterface commands
     */
    void help();
    /**
     *removes the given song from all playlists this is for discontinue
     * @param artist
     * @param titleIn
     */
    void removeFromPlaylists(std::string artist, std::string titleIn);

    /**
     * removes the song from the current library
     * @param songIn
     */
    void removeSongFromLibrary(std::string songIn);

    /**
  * Writes the current library to a file to save the data when the command quit is typed
  */
    void quit();
};


#endif //CS220FINALPROEJECT_H
