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
    doubleCapacity();
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

    for(int i = currItemCount; i >= 1;i--){
        array[i] = array[i-1];
    }

    currItemCount+=1;
    array[0] = itemToAdd;
    doubleCapacity();
}

void PlaylistArrayList::insertAt(Playlist itemToAdd, int index) {

    if (index < 0 or index > currItemCount) {
        throw std::out_of_range("e");
    }
    for (int i = currItemCount; i >= index; i--) {
        array[i] = array[i - 1];
    }
    currItemCount+=1;
    array[index] = itemToAdd;
    doubleCapacity();
}

Playlist PlaylistArrayList::removeValueAtEnd() {
    doubleCapacity();
    if(currItemCount <1){
        throw std::out_of_range("e");
    }
    currItemCount-=1;
    return array[currItemCount];
}

Playlist PlaylistArrayList::removeValueAtFront() {
    if(currItemCount < 0){
        throw std::out_of_range("e");
    }
    Playlist copy = array[0];
    for(int i = 1; i < currItemCount;i++){
        array[i-1] = array[i];
    }

    currItemCount--;

    return copy;
}
Playlist PlaylistArrayList::removeValueAt(int index) {
    if (index < 0 or index > currItemCount) {
        throw std::out_of_range("e");
    }
    if (currItemCount < 0) {
        throw std::out_of_range("e");
    }
    Playlist copy = array[index];
    for (int i = 0; i < index; i++) {
        array[i] = array[i];
    }
    for (int i = index + 1; i < currItemCount; i++) {
        array[i - 1] = array[i];
    }

    currItemCount--;
    return copy;
}
