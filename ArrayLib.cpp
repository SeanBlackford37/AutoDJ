//
// Created by Sean Blackford on 12/3/19.
//
#include <iostream>
#include <string>
#include "Song.h"






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


