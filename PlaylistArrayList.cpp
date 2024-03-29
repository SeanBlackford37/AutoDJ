//
// Created by Morgan Ziegler on 12/3/19.
//

#include "PlaylistArrayList.h"

#include <iostream>



PlaylistArrayList::PlaylistArrayList(int initialCapacity) {
    if(initialCapacity < 1){
        throw std::invalid_argument("Size can't be less than 1");
    }
    else{
        this -> currCapacity = initialCapacity;
        this -> array = new Playlist[currCapacity];
        this -> currItemCount = 0;

    }

}
//assignment operator
//combining two objects listA = listB
//using destructor and copy constructor
PlaylistArrayList& PlaylistArrayList::operator=(const PlaylistArrayList& arrayListToCopy){
    if(this != &arrayListToCopy) {
        delete[] array;

        this->currCapacity = arrayListToCopy.currCapacity;
        this->array = new Playlist[currCapacity];
        for (int i = 0; i < arrayListToCopy.currItemCount; i++) {
            array[i] = arrayListToCopy.array[i];
        }
        this->currItemCount = arrayListToCopy.currItemCount;
        return *this;
    }return *this;
}
/*
//Copy constructor
PlaylistArrayList::PlaylistArrayList(const PlaylistArrayList& arrayListToCopy) {

    this -> currCapacity = arrayListToCopy.currCapacity;
    this -> array = new Playlist[currCapacity];
    for(int i = 0; i < arrayListToCopy.currItemCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
    this -> currItemCount = arrayListToCopy.currItemCount;
}
 */

//Destructor
PlaylistArrayList::~PlaylistArrayList(){
    delete[] array;
}

void PlaylistArrayList::doubleCapacity() {
    Playlist *arrayList = new Playlist[currItemCount * 2];
    currCapacity = currCapacity * 2;

    for(int i = 0; i < currItemCount;i++){
        arrayList[i] = array[i];
    }
    delete[] array;
    array = new Playlist[currItemCount*2];

    for(int i = 0; i < currItemCount;i++){
        array[i] = arrayList[i];
    }
    delete[] arrayList;
}



void PlaylistArrayList::insertAtEnd(Playlist itemToAdd) {
    currItemCount+=1;
    if (currItemCount > currCapacity){
        doubleCapacity();
    }
    array[currItemCount-1] = itemToAdd;

}

Playlist PlaylistArrayList::getValueAt(int index) {

    if(index < 0 or index >= currItemCount){
        throw std::out_of_range("e");
    }
    return array[index];
}
std::string PlaylistArrayList::toString(){
    //return ::toString(array,currItemCount);
    return "finish this";
}


bool PlaylistArrayList::isEmpty() {
    if(currItemCount < 1){
        return true;
    }
    return false;
}

int PlaylistArrayList::itemCount() {
    return currItemCount;
}

void PlaylistArrayList::clearList() {
    for(int i = 0; i < currItemCount;i++){
        removeValueAtFront();
    }
    currItemCount = 0;
}

void PlaylistArrayList::insertAtFront(Playlist itemToAdd) {
    if (currItemCount +1 > currCapacity){
        doubleCapacity();
    }

    for (int i = 0; i<currItemCount+1;i++){
        Playlist temp = array[i];
        array[i] = itemToAdd;
        itemToAdd = temp;
    }
    currItemCount ++;

}

void PlaylistArrayList::insertAt(Playlist itemToAdd, int index) {

    if (index < 0 or index > currItemCount){
        throw std::out_of_range("Bad index given to insertAt: " + std::to_string(index));
    }
    if (currItemCount +1 > currCapacity){
        doubleCapacity();
    }
    for (int i = index; i<currItemCount+1;i++){
        Playlist temp = array[i];
        array[i] = itemToAdd;
        itemToAdd = temp;
    }
    currItemCount ++;
}

Playlist PlaylistArrayList::removeValueAtEnd() {
    if(currItemCount <1){
        throw std::out_of_range("e");
    }
    currItemCount-=1;
    return array[currItemCount];
}

Playlist PlaylistArrayList::removeValueAtFront() {
    if(currItemCount<=0){
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }
    Playlist temp = array[0];
    for (int i =0; i<currItemCount-1;i++){
        array[i] = array[i+1];
    }
    currItemCount--;
    return temp;
}
Playlist PlaylistArrayList::removeValueAt(int index) {
    if(currItemCount<=0){
        throw std::out_of_range("In removeValueAtFront, List must have items");
    }
    Playlist temp = array[index];
    for (int i =index; i<currItemCount-1;i++){
        array[i] = array[i+1];
    }
    currItemCount--;
    return temp;
}

int PlaylistArrayList::find(std::string name){
    for(int i = 0; i < currItemCount;i++){
        if (array[i].getName() == name){
            return i;
        }
    }
    return -1;
}
