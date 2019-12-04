//
// Created by Morgan Ziegler on 12/3/19.
//

#include "Playlist.h"
#include <iostream>

#ifndef CS220FINALPROJECT_PLAYLISTARRAYLIST_H
#define CS220FINALPROJECT_PLAYLISTARRAYLIST_H


class PlaylistArrayList {
    private:
        //pointer to the start of the array
        Playlist* array;
        //count of the number of valid items currently stored in the array
        int currItemCount;
        //size of the current array
        int currCapacity;

        /**
         * replaces the old array with an array twice the size
         * private method only called within ArrayList when necessary
         * @post: array points to a new array of twice the size with values copied from the old one,
         *        the old array is deleted.
         */
        void doubleCapacity();

    public:
        /**
         * Constructor
         * @throws an std::invalid_argument exception if size < 1
         */
        PlaylistArrayList(int initialCapacity);

        //Copy Constructor
        PlaylistArrayList(const ArrayList& arrayListToCopy);

        //Overloaded Assignment Operator
        PlaylistArrayList& operator=(const PlaylistArrayList& arrayListToCopy);

        //Destructor
        ~PlaylistArrayList();

        /**
         * appends the new item to the end of the list
         * @post the list has an additional value in it, at the end
         */
        void insertAtEnd(Playlist itemToAdd);

        /**
         * gets a value from the list
         * @param index the location from which to get the value
         * @return a copy of the item at index
         * @throws out_of_range exception if index is invalid
         */
        Playlist getValueAt(int index);

        /**
         * gives a string representation of the current list
         * @returns a string representing the given list in the exact format shown below
         * {1, 2, 3, 4, 5}
         */
        std::string toString();

        /**
         * checks if there are any valid items in the list
         * @return true if there are no valid items in the list, false otherwise
         */
        bool isEmpty();

        /**
         * returns a count of valid items currently in the list
         * @returns the number of valid items in the list
         */
        int itemCount();

        /**
         * makes the list empty of valid items
         * @post the list is empty, such that isEmpty() == true
         */
        void clearList();

        /**
         * appends the new item to the beginning of the list
         * @post the list has an additional value in it, at the beginning
         *    all other items are shifted down by one index
         */
        void insertAtFront(Playlist itemToAdd);

        /**
         * inserts the item into the list so that it can be found with get(index)
         * @param index the location in which to insert this item
         * @post the list has an additional value in it at the specified index,
         *        all further values have been shifted down by one index
         * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
         */
        void insertAt(Playlist itemToAdd, int index);

        /**
         * removes the item at the end of the list, and returns a copy of that item
         * @post the item at the end is removed from the list
         * @return a copy of the item at the end
         * @throws out_of_range exception if there is no item to remove
         */
        Playlist removeValueAtEnd();

        /**
         * removes the item at the front of the list, and returns a copy of that item
         * @post the item at the front is removed from the list, everything else is shifted down one
         * @return a copy of the item at index
         * @throws out_of_range exception if there is no item to remove
         */
        Playlist removeValueAtFront();

        /**
         * removes the item at index from the list, and returns a copy of that item
         * @param index the location from which to get the value
         * @post the item at index is removed from the list, everything else is shifted down one
         * @return a copy of the item at index
         * @throws out_of_range exception if index is invalid
         */
        Playlist removeValueAt(int index);

        /**
         *
         * @param name name of the playlist to find
         * @return the index of the playlist or -1 if not there
         */
        int find(std::string name);

};


#endif //CS220FINALPROJECT_PLAYLISTARRAYLIST_H
