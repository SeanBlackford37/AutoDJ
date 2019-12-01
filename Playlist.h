//
// Created by Morgan Ziegler on 12/1/19.
//
#include <iostream>

#ifndef CS220FINALPROJECT_PLAYLIST_H
#define CS220FINALPROJECT_PLAYLIST_H


class Playlist {
private:
    std::string name;
    //TODO: need a list with items that are songs
    //List* songs;

public:
    /**
     * Constructor
     * @param nameIn -- name of the playlist
     */
    Playlist(std::string nameIn);

    /**
     * Destructor
     */
    ~Playlist();

    /**
     * calcs the duration of the songs left in the playlist
     * could return an int instead if we dont want to format it like 1:34:32 or something
     * @returns the duration left
     */
     std::string calcDuration();

     /**
      *
      * @return string representing all songs in the playlist
      */
     std::string toString();

     /**
      * shows the info of the song just played and removes it from the list
      * @return info of the song just played
      */
     std::string playNext();

     /**
      * adds a song to the end of the playlist
      */
     void addSong(std::string songInfo);

     /**
      * removes song from the playlist
      */
      void removeSong(std::string songInfo);
};


#endif //CS220FINALPROJECT_PLAYLIST_H