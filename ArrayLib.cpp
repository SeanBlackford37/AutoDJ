//
// Created by Sean Blackford on 12/3/19.
//
#include <iostream>
#include <string>
#include "Song.h"






int genRandInt(int min, int max) {
    if (min > max){
        int temp = max;
        max = min;
        min = temp;
    }
    int num = (rand() % (max - min + 1)) + min;
    return num;

}

