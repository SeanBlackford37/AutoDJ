//
// Created by Sean Blackford on 12/3/19.
//

#ifndef CS220FINALPROJECT_ARRAYLIB_H
#define CS220FINALPROJECT_ARRAYLIB_H
#include <string>



/**
 * generates a random integer. If the user enters incorrect values (min is greater than max),
 * the function recognizes the problem and swaps values to ensure max is greater than min
 * @pre the function srand() must be called once before this function is used the first time
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return an integer between min and max inclusive (i.e., including both min and max)
 */
int genRandInt(int min, int max);


/**
 * generates an array filled with random numbers, values between min and max inclusive
 * If min > max, it switches min and max values to make them valid
 * @pre the function srand() must be called once before this function is used the first time
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int *genRandArray(int size, int min, int max, int &numLinesRun);

/**
 * creates a string representation of an int array for easy printing
 * Note: we just use this to view array contents, so we don't need to time it...
 * @return a string representing the given array in the exact format shown below
 *  {1, 2, 3, 4, 5}
 *  {} for size < 1
 */
std::string toString(const Song *arrayPtr, int size);


/**
 * generates a copy of a given array
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the copy array, which must be deleted by the user, or nullptr, if size < 1
 */
int *copyArray(const Song *arrayToCopy, int size, int &numLinesRun);

/**
 * Generates an array with all values 1 through size occurring once each, shuffled in random order
 * example: genShuffledArray(5) might yield {2, 1, 4, 5, 3}
 * @pre srand must be called once before this function is used the first time
 * @post numLinesRun is updated to add the number of lines run by this function
 * @return a pointer to the array, which must be deleted by the user, or nullptr if size < 1
 */
int *genShuffledArray(int size, int &numLinesRun);



/**
 * @param arrayPtr, the size of the array, object Song,
 * @return index of the song
 */


/**
 * uses binary search on an int array for a certain value
 * @pre the array must be sorted before this function is called
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 */
int binFind(const Song *const arrayPtr, const int size, const int numToFind, int &numLinesRun);

/**
 * returns an array that is a sorted, merged copy of arrays a1 and a2
 * Operates in O(n), linear time
 * @pre both a1 and a2 must be sorted
 * @post numLinesRun is updated to include lines run by this function
 * @return an array of size (size1+size2) that is an in-order (sorted) copy of all values from a1 and a2,
 *   to be deleted by the user, * or nullptr if (size1+size2) < 1
 */
int *merge(const Song *a1, int size1, const int *a2, int size2, int &numLinesRun);

/**
 * returns a sorted copy of the array using merge sort
 * @post numLinesRun is updated to include lines run by this function
 * @return a copy of the array sorted from min to max values, or nullptr if size < 1, to be deleted by the user
 */
int *mergeSort(const Song *arrayToSort, int size, int &numLinesRun);

#endif //CS220FINALPROJECT_ARRAYLIB_H
