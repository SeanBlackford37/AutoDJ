//
// Created by Sean Blackford on 12/3/19.
//
#include <iostream>
#include <string>
#include "Song.h"



//tail-recursive
std::string toString(const int *const arrayPtr, const int size, const int index, const std::string str) {
    if (size < 1) {
        return "{}";
    }
    if (size == index) {
        return str + "}";
    }
    std::string str1 = str;

    if (index == size - 1) {
        str1 += std::to_string(arrayPtr[index]);
    } else {
        str1 += std::to_string(arrayPtr[index]) + ", ";
    }


    return toString(arrayPtr, size, index + 1, str1);

}
std::string toString(const int *const arrayPtr, const int size) {
    return toString(arrayPtr, size, 0, "{");
}


//tail-recursive
int binFind(const int *const arrayPtr, const int size, const int numToFind, const int low, const int high,
            int &numLinesRun) {
    int mid = (low + high) / 2;
    numLinesRun += 1;

    if (numToFind == arrayPtr[mid]) {
        numLinesRun += 2;
        return mid;
    }
    if (low >= high) {
        numLinesRun += 2;
        return -1;
    } else if (numToFind < arrayPtr[mid]) {
        numLinesRun += 1;
        if (low != high) {
            numLinesRun += 2;
            return binFind(arrayPtr, size, numToFind, low, mid - 1, numLinesRun);
        }
    } else if (numToFind > arrayPtr[mid]) {
        numLinesRun += 1;
        if (low != high) {
            numLinesRun += 2;
            return binFind(arrayPtr, size, numToFind, mid + 1, high, numLinesRun);
        }
    }
    numLinesRun += 1;
    return -1;


}

int binFind(const int *const arrayPtr, const int size, const int numToFind, int &numLinesRun) {
    numLinesRun += 1;
    return binFind(arrayPtr, size, numToFind, 0, size - 1, numLinesRun);
}



int genRandInt(int min, int max, int &numLinesRun) {
    int num = max;
    numLinesRun += 1;

    if (min > max) {
        max = min;
        min = num;
        numLinesRun += 3;
    }

    int randNum = rand() % (max - min + 1) + min;
    numLinesRun += 2;
    return randNum;
}


int *genRandArray(int size, int min, int max, int &numLinesRun) {
    int num = max;
    int *myArray = new int[size];
    numLinesRun += 2;


    if (min > max) {
        max = min;
        min = num;
        numLinesRun += 3;


    }
    for (int i = 0; i < size; i++) {
        myArray[i] = genRandInt(min, max, numLinesRun);
        numLinesRun += 2;


    }
    numLinesRun += 1;
    return myArray;
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

int *copyArray(const int *arrayToCopy, int size, int &numLinesRun) {

    //Keyword new
    int *temp = new int[size];
    numLinesRun += 1;
    for (int i = 0; i < size; i++) {
        temp[i] = arrayToCopy[i];
        numLinesRun += 2;
    }
    numLinesRun += 1;
    return temp;
}


//selection sort
void sort(int *arrayToSort, int size, int &numLinesRun) {
    int *copy = copyArray(arrayToSort, size, numLinesRun);
    int count = 0;
    numLinesRun += 2;
    for (int j = 0; j < size; j++) {
        int temp = arrayToSort[j];
        count = j;
        numLinesRun += 3;
        for (int i = j + 1; i < size; i++) {
            numLinesRun += 1;
            if (arrayToSort[i] < temp) {
                temp = arrayToSort[i];
                count = i;
                numLinesRun += 3;
            }
        }
        arrayToSort[count] = arrayToSort[j];
        arrayToSort[j] = temp;
        numLinesRun += 2;


    }
    //Checks to see if the copy is equal to the original adding up
    for (int j = 0; j < size; j++) {
        int count2 = 0;
        numLinesRun += 2;

        for (int i = 0; i < size; i++) {
            numLinesRun += 1;
            if (copy[j] == arrayToSort[i]) {
                count2++;
                numLinesRun += 2;
            }
        }
        int occurrence = countOccurrences(arrayToSort, size, copy[j], numLinesRun);
        numLinesRun += 1;
        if (occurrence != count2) {
            arrayToSort[j] = 0;
            numLinesRun += 2;
        }
    }
    for (int i = 0; i < size - 1; i++) {
        numLinesRun += 1;
        if (arrayToSort[i] > arrayToSort[i + 1]) {
            arrayToSort[i] = 0;
            numLinesRun += 2;
        }
    }

}


int *merge(const int *a1, int size1, const int *a2, int size2, int &numLinesRun) {
    if (size1 + size2 < 1) {
        numLinesRun += 2;
        return nullptr;
    }
    int *copyA1 = copyArray(a1, size1, numLinesRun);
    int *copyA2 = copyArray(a2, size2, numLinesRun);
    sort(copyA1, size1, numLinesRun);
    sort(copyA2, size2, numLinesRun);

    int *finalArray = new int[size1 + size2];
    numLinesRun += 5;
    for (int i = 0; i < size1; i++) {
        finalArray[i] = copyA1[i];
        numLinesRun += 2;
    }
    for (int i = 0; i < size2; i++) {
        finalArray[size1 + i] = copyA2[i];
        numLinesRun += 2;
    }

    sort(finalArray, (size1 + size2), numLinesRun);
    numLinesRun += 2;
    return finalArray;


}

int *mergeSort(const int *arrayToSort, int size, int &numLinesRun) {
    if (size < 1) {
        numLinesRun += 2;
        return nullptr;
    }

    int *copyA1 = copyArray(arrayToSort, size, numLinesRun);
    sort(copyA1, size, numLinesRun);
    numLinesRun += 3;
    return copyA1;
}
