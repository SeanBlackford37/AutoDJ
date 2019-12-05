//
// Created by Sean Blackford on 10/14/19.
//

#include <iostream>
#include "ArrayList.h"
#include "ArrayLib.h"


ArrayList::ArrayList(int initialCapacity) {
    if(initialCapacity < 1){
        throw std::invalid_argument("Size can't be less than 1");
    }
    else{
        this -> currCapacity = initialCapacity;
        this -> array = new Song[currCapacity];
        this -> currItemCount = 0;

    }

}
//assignment operator
//combining two objects listA = listB
//using destructor and copy constructor
ArrayList& ArrayList::operator=(const ArrayList& arrayListToCopy){
    if(this != &arrayListToCopy) {
        delete[] array;

        this->currCapacity = arrayListToCopy.currCapacity;
        this->array = new Song[currCapacity];
        for (int i = 0; i < arrayListToCopy.currItemCount; i++) {
            array[i] = arrayListToCopy.array[i];
        }
        this->currItemCount = arrayListToCopy.currItemCount;
        return *this;
    }return *this;
}
//Copy constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy) {

    this -> currCapacity = arrayListToCopy.currCapacity;
    this -> array = new Song[currCapacity];
    for(int i = 0; i < arrayListToCopy.currItemCount; i++){
        array[i] = arrayListToCopy.array[i];
    }
    this -> currItemCount = arrayListToCopy.currItemCount;
}
//Destructor
ArrayList::~ArrayList(){
    delete[] array;
}

void ArrayList::doubleCapacity() {
    Song *arrayList = new Song[currItemCount * 2];
    currCapacity = currCapacity * 2;

    for(int i = 0; i < currItemCount;i++){
        arrayList[i] = array[i];
    }
    delete[] array;
    array = new Song[currItemCount*2];

    for(int i = 0; i < currItemCount;i++){
        array[i] = arrayList[i];
    }
    delete[] arrayList;
}



void ArrayList::insertAtEnd(Song itemToAdd) {
    currItemCount+=1;
    if (currItemCount > currCapacity){
        doubleCapacity();
    }
    array[currItemCount-1] = itemToAdd;

}

void ArrayList::insertAtAlphabetized(Song itemToAdd) {
    for(int i = 0; i < currItemCount; i++){

    }
}

Song ArrayList::getValueAt(int index) {

    if(index < 0 or index >= currItemCount){
        throw std::out_of_range("e");
    }
    return array[index];
}
std::string ArrayList::toString(){
    //return ::toString(array,currItemCount);
    return "not done yet";
}


bool ArrayList::isEmpty() {
    if(currItemCount < 1){
        return true;
    }
    return false;
}

int ArrayList::itemCount() {
    return currItemCount;
}

void ArrayList::clearList() {
    for(int i = 0; i < currItemCount;i++){
        removeValueAtFront();
    }
    currItemCount = 0;
}

void ArrayList::insertAtFront(Song itemToAdd) {

    for(int i = currItemCount; i >= 1;i--){
        array[i] = array[i-1];
    }

    currItemCount+=1;
    array[0] = itemToAdd;
    doubleCapacity();
}

int ArrayList::findArtistandTitle(const int size, std::string artistIn, std::string titleIn) {


    for(int i = 0; i < size; i++){
        if(artistIn == array[i].getArtist()){
            if(titleIn == array[i].getTitle()){
                return i;
            }
        }
    }
    return -1;
}

void ArrayList::insertAt(Song itemToAdd, int index) {

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

Song ArrayList::removeValueAtEnd() {
    doubleCapacity();
    if(currItemCount <1){
        throw std::out_of_range("e");
    }
    currItemCount-=1;
    return array[currItemCount];
}

Song ArrayList::removeValueAtFront() {
    if(currItemCount < 0){
        throw std::out_of_range("e");
    }
    Song copy = array[0];
    for(int i = 1; i < currItemCount;i++){
        array[i-1] = array[i];
    }

    currItemCount--;

    return copy;
}
Song ArrayList::removeValueAt(int index) {
    if(index < 0 or index > currItemCount){
        throw std::out_of_range("e");
    }
    if(currItemCount < 0){
        throw std::out_of_range("e");
    }
    Song copy = array[index];
    for(int i = 0; i < index;i++){
        array[i] = array[i];
    }
    for(int i = index+1; i < currItemCount;i++){
        array[i-1] = array[i];
    }

    currItemCount--;
    return copy;
}