//
// Created by Sean Blackford on 12/3/19.
//
#include <iostream>
#include <string>
#include "Song.h"






int genRandInt(int min, int max) {
    int num = max;

    if (min > max) {
        max = min;
        min = num;
    }

    int randNum = rand() % (max - min + 1) + min;
    return randNum;
}


