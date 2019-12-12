//
// Created by Toby Dragon on 10/30/18.
//

#include "LinkedList.h"

/**
     * Constructor
     *
     * O(1)
     */
LinkedList::LinkedList(){
    currItemCount = 0;
    front = nullptr;
}

//Destructor
// O(n)
LinkedList::~LinkedList(){
    while (front != nullptr){
        LinkedNode* temp = front->getNext();
        delete front;
        front = temp;
    }
    currItemCount = 0;
}

/**
 * appends the new item to the end of the list
 * @post the list has an additional value in it, at the end
 *
 * O(n)
 */
void LinkedList::insertAtEnd(Song itemToAdd){
    if (currItemCount == 0){
        front = new LinkedNode(itemToAdd);
        currItemCount++;
    }
    else {
        LinkedNode* index = front;
        while (index->getNext() != nullptr) {
            index = index->getNext();
        }
        index->setNext(new LinkedNode(itemToAdd));
        currItemCount++;
    }
}

/**
 * gets a value from the list
 * @param index the location from which to get the value
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 *
 * O(n)
 */
Song LinkedList::getValueAt(int index){
    if (index >= currItemCount or index < 0){
        throw std::out_of_range("Bad index given to getValueAt: " + std::to_string(index));
    }
    else {
        LinkedNode *temp = front;
        for (int i = 0; i < index; i++) {
            temp = temp->getNext();
        }
        return temp->getItem();
    }
}

/**
 * gives a string representation of the current list
 * @returns a string representing the given list in the exact format shown below
 * {1, 2, 3, 4, 5}
 *
 * O(n)
 */
std::string LinkedList::toString(){
    std::string listStr = "\t";
    if (!this->isEmpty()) {
        LinkedNode *temp = front;
        while (temp!= nullptr) {
            listStr += temp->getItem().toString();
            if (temp->getNext() != nullptr){
                listStr += "\n\t";
            }
            temp = temp->getNext();
        }
    }
    return listStr;
}

/**
 * checks if there are any valid items in the list
 * @return true if there are no valid items in the list, false otherwise
 *
 * O(1)
 */
bool LinkedList::isEmpty(){
    if (currItemCount==0){
        return true;
    }
    else{
        return false;
    }
}

/**
 * returns a count of valid items currently in the list
 * @returns the number of valid items in the list
 *
 * O(1)
 */
int LinkedList::itemCount(){
    return currItemCount;
}

/**
 * makes the list empty of valid items
 * @post the list is empty, such that isEmpty() == true
 *
 * O(n)
 */
void LinkedList::clearList(){
    while (front != nullptr){
        LinkedNode* temp = front->getNext();
        delete front;
        front = temp;
    }
    currItemCount = 0;
}

/**
 * Searches an int array for a certain value
 * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
 *
 * O(n)
 */
int LinkedList::find(Song numToFind){
    LinkedNode* temp = front;
    int index = 0;
    while (temp != nullptr){
        if (temp->getItem().getArtist() == numToFind.getArtist() && temp->getItem().getTitle() == numToFind.getTitle()){
            return index;
        }
        else{
            temp = temp->getNext();
            index++;
        }
    }
    return -1;
}




/**
 * appends the new item to the beginning of the list
 * @post the list has an additional value in it, at the beginning
 *    all other items are shifted down by one index
 *
 *    O(1)
 */
void LinkedList::insertAtFront(Song itemToAdd){
    LinkedNode* temp = new LinkedNode(itemToAdd);
    temp->setNext(front);
    front = temp;
    currItemCount++;
}

/**
 * inserts the item into the list so that it can be found with get(index)
 * @param index the location in which to insert this item
 * @post the list has an additional value in it at the specified index,
 *        all further values have been shifted down by one index
 * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
 *
 * O(n)
 */
void LinkedList::insertAt(Song itemToAdd, int index){
    if (index < 0 or index > currItemCount){
        throw std::out_of_range("Index is invalid");
    }
    else if (index == 0){
        LinkedNode* temp = new LinkedNode(itemToAdd);
        temp->setNext(front);
        front = temp;
        currItemCount++;
    }
    else{
        LinkedNode* beforeIndex = front;
        LinkedNode* atIndex = front->getNext();
        for (int i =0; i < index-1; i++){
            beforeIndex = beforeIndex->getNext();
            atIndex = atIndex->getNext();
        }
        beforeIndex->setNext(new LinkedNode(itemToAdd));
        beforeIndex->getNext()->setNext(atIndex);
        currItemCount++;
    }

}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 *
 * O(n)
 */
Song LinkedList::removeValueAtEnd(){
    Song val;
    if (currItemCount < 1){
        throw std::out_of_range("In removeValueAtEnd, List must have items");
    }
    else {
        LinkedNode *temp = front;
        if (currItemCount == 1){
            val = temp->getItem();
            delete temp;
            front = nullptr;
            currItemCount--;
            return val;
        }
        while (temp->getNext()->getNext() != nullptr) {
            temp = temp->getNext();
        }
        val = temp->getNext()->getItem();
        delete temp->getNext();
        temp->setNext(nullptr);
        currItemCount--;
        return val;
    }
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 *
 * O(1)
 */
Song LinkedList::removeValueAtFront(){
    if (currItemCount == 0){
        throw std::out_of_range("There is no item to remove");
    }
    else {
        LinkedNode *temp = front->getNext();
        Song item = front->getItem();
        delete front;
        front = temp;
        currItemCount--;
        return item;
    }

}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 *
 * O(n)
 */
Song LinkedList::removeValueAt(int index){
    Song val = Song();
    if (index < 0 or index > currItemCount){
        throw std::out_of_range("Index is invalid");
    }
    else if (index ==0){
        LinkedNode* temp = front->getNext();
        val = front->getItem();
        delete front;
        front = temp;
        currItemCount--;
    }
    else{
        LinkedNode* beforeIndex = front;
        LinkedNode* atIndex = front->getNext();
        for (int i =0; i < index-1; i++){
            beforeIndex = beforeIndex->getNext();
            atIndex = atIndex->getNext();
        }
        beforeIndex->setNext(atIndex->getNext());
        val = atIndex->getItem();
        delete atIndex;
        currItemCount--;
    }
    return val;
}