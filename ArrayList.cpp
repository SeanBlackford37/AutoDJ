//
// Created by Aidan DeBolt on 12/2/19.
//

#include "ArrayList.h"
#include <iostream>
#include "Math.h"


int genRandInt(int min, int max, int& numLinesRun){

    numLinesRun += 3;
    numLinesRun += 1; //for if statement
    numLinesRun += 1; //for first else if statement
    numLinesRun += 1; //for else statement
    if (min > max){
        numLinesRun += 5;
        int tempMax = max;
        max = min;
        min = tempMax;
        int newRandNum = rand() % ((max - min) + 1) + min;
        return newRandNum;
    }
    else if (min == max){
        numLinesRun += 1;
        return max;
    }
    else{
        numLinesRun += 2;
        int randNum = rand() % ((max - min) + 1) + min;
        return randNum;
    }
}

int* genRandArray(int size, int min, int max, int& numLinesRun){
    numLinesRun += 4; //parameters
    numLinesRun += 1; //anArray creation
    numLinesRun += 2; //if and else if statement
    int* anArray = new int[size];
    if (size < 1){
        numLinesRun += 1;
        return anArray;
    }
    else if (min > max){
        numLinesRun += 3;
        int tempMax = min;
        min = max;
        max = tempMax;

        numLinesRun += 2;
        for(int i =0; i<size; i++){
            numLinesRun += 4;
            int randomNum = rand() % ((max - min) + 1) + min;
            anArray[i] = randomNum;
        }
    }

    numLinesRun += 2;
    for(int i =0; i<size; i++){
        numLinesRun += 4;
        int randomNum = rand() % ((max - min) + 1) + min;
        anArray[i] = randomNum;
    }
    numLinesRun += 1;
    return anArray;
}

std::string toString(const int* arrayPtr, int size) {
    std::string finalString = "{";
    if (size < 1) {
        finalString = "{}";
    }
    else {
        for (int i = 0; i < size; i++) {
            finalString += std::to_string(arrayPtr[i]);

            if(size - i != 1) {
                finalString += ", ";
            }
        }
        finalString += "}";
    }
    return finalString;
}

int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    numLinesRun += 4; //parameters
    numLinesRun += 2; //for loop
    for(int i = 0; i < size; i++){
        numLinesRun += 3;
        if (arrayPtr[i] == numToFind){
            numLinesRun += 1;
            return i;
        }
    }
    numLinesRun += 2;
    int aNum = -1;
    return aNum;
}

int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun) {
    (numLinesRun) += 4; //parameters
    (numLinesRun) += 1; //latestFound declaration
    int latestFound = -1;
    (numLinesRun) += 1; //if statement
    if (size < 1) {
        (numLinesRun) += 1; //if statement execution
        return latestFound;
    }
    else {
        (numLinesRun) += 1; //else
        (numLinesRun) += 1; //found
        bool found = false;
        (numLinesRun) += 2; //for loop start
        for (int i = 0; i < size; i++) {
            (numLinesRun) += 3; //if statement + loop
            if (arrayPtr[i] == numToFind) {
                (numLinesRun) += 1; //if statement execution
                latestFound = i;
            }
        }

        (numLinesRun) += 1; //return
        return latestFound;
    }
}

int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun){
    (numLinesRun) += 3; //parameters
    (numLinesRun) += 1; //if statement
    if (size < 1){
        (numLinesRun) += 1; //if statement execution
        throw std::invalid_argument("Size must be greater than or equal to 1");
    }
    (numLinesRun) += 1; //max
    int max = arrayPtr[0];
    (numLinesRun) += 2; //for loop start
    for (int i = 0; i < size; i++){
        (numLinesRun) += 1; //if statement
        if (arrayPtr[i] > max){
            (numLinesRun) += 1; //if statement execute
            max = arrayPtr[i];
        }
    }
    (numLinesRun) += 2; //max index + return
    int maxIndex = find(arrayPtr, size, max, numLinesRun);
    return maxIndex;
}

int* copyArray(const int* arrayToCopy, int size, int& numLinesRun){
    (numLinesRun) += 3; //parameters
    (numLinesRun) += 1; //if statement
    if (size < 1){
        (numLinesRun) += 1; //if statement execution
        return nullptr;
    }
    (numLinesRun) += 1; //copyArray
    (numLinesRun) += 2; //for loop start
    int* copyArray = new int[size];
    for (int i = 0; i < size; i++){
        copyArray[i] = arrayToCopy[i];
        (numLinesRun) += 3; //for loop
    }

    (numLinesRun) += 1; //return
    return copyArray;
}

int* genShuffledArray(int size, int& numLinesRun){
    numLinesRun += 2; //declaration
    numLinesRun += 2; //int* and if statement
    int* shuffledArray = new int[size];
    if (size < 1){
        shuffledArray = nullptr;
    }
    numLinesRun += 2; //for loop start
    for (int i = 0; i < size; i++){
        numLinesRun = 3;
        shuffledArray[i] = i + 1;
    }
    numLinesRun += 2; //for loop start
    for (int h = 0; h < size; h++){
        numLinesRun += 3; //for loop/if statement
        if (shuffledArray[h] == h + 1){
            numLinesRun += 4;
            int randIndex = genRandInt(0, size - 1, numLinesRun);
            int tempInt = shuffledArray[randIndex];
            shuffledArray[randIndex] = shuffledArray[h];
            shuffledArray[h] = tempInt;
        }
    }
    numLinesRun += 1; //return
    return shuffledArray;
}

int countOccurrences(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    numLinesRun += 4; //parameters+count declaration
    int count = 0;
    numLinesRun += 2; //for loop
    for(int i = 0; i < size; i++){
        numLinesRun += 3; //for loop + if statement
        if(arrayPtr[i] == numToFind){
            numLinesRun += 1; //count++
            count++;
        }
    }
    numLinesRun += 1; //return
    return count;
}

//Bubble Sort
void sort(int* arrayToSort, int size, int& numLinesRun){
    numLinesRun += 3; //parameters
    numLinesRun += 2; //for loop
    for (int i = 0; i < size-1; i++){
        numLinesRun += 2; //for loop
        numLinesRun += 2; //for loop
        for(int j = 0; j<size-i-1; j++){
            numLinesRun += 2; //for loop
            numLinesRun += 1; //if statement
            if(arrayToSort[j]>arrayToSort[j+1]){
                numLinesRun += 3; //temp set + swap
                int temp = arrayToSort[j];
                arrayToSort[j] = arrayToSort[j+1];
                arrayToSort[j+1] = temp;
            }

        }
    }
}

int binFind(const int* const arrayPtr, const int size, const int numToFind, const int max, const int min, const int mid, int& numLinesRun){
    numLinesRun += 1; //if statement
    if (size < 1){
        return -1;
    }
    else if(min <= max){
        if(arrayPtr[mid] == numToFind){
            return mid;
        }
        else if (arrayPtr[mid] > numToFind){
            return binFind(arrayPtr,size,numToFind,mid-1,min,(min+max)/2,numLinesRun);
        }
        else{
            return binFind(arrayPtr,size,numToFind,max,mid+1,(min+max)/2,numLinesRun);
        }
    }
    return -1;
}

int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun){
    return binFind(arrayPtr, size, numToFind, size - 1, 0,floor(0 + ((size-1) - 1) / 2),numLinesRun);
}

int* merge(const int* a1, int size1, const int* a2, int size2, int& numLinesRun){
    return nullptr;
}

int* mergeSort(const int* arrayToSort, int size, int& numLinesRun){
    return nullptr;
}
