#include <iostream>
#include "readyqueue.h"
#include "pcb.h"
using namespace std;

//You must complete the all parts marked as "to did". Delete "to did" after you are done.
// Remember to add sufficient comments to your code


/**
 * @brief Constructor for the ReadyQueue class.
 */


/* HEAP STUFF*/



 ReadyQueue::ReadyQueue()  { //constructor
     
     heaparray = new PCB[capacity];
     count = 0;
 }

 ReadyQueue:: ~ReadyQueue() { //destructor 
     delete[] heaparray;
 }

 void ReadyQueue::percolateDown(int index) {
     int childIndex = 2 * index + 1; //child is 2n+1, 2n+2
     int value = heaparray[index].getPriority();

     while (childIndex < count) { //finds the max value of the 2 children
         int maxValue = value;
         int maxIndex = -1;
         for (int i = 0; i < 2 && i + childIndex < count; i++)
         {
             if (heaparray[i + childIndex].getPriority() > maxValue)
             {
                 maxValue = heaparray[i + childIndex].getPriority();
                 maxIndex = i + childIndex;
             }
         }

         if (maxValue == value)
         {
             return;
         }
         else //swaps them if they are wrong, as in child is bigger than parent
         {
             //swap(heaparray[index], heaparray[maxIndex]);

             PCB temp = heaparray[index];
             heaparray[index] = heaparray[maxIndex];
             heaparray[maxIndex] = temp;


             index = maxIndex;
             childIndex = (2 * index) + 1;
         }
     }
 }

 void ReadyQueue:: percolateUp(int index) {

     // yeebambay: check the value of the parents of index in the heap and swap them if they are smaller

     int intdex = index;

     while (intdex > 0) {
         int parent = (intdex - 1) / 2; //the parent is (n-1)/2
         if (heaparray[intdex].getPriority() <= heaparray[parent].getPriority()) { //when its correct, its done
             return;
         }
         else {
             //swap(heaparray[intdex], heaparray[parent]); 
             PCB temp = heaparray[intdex];
             heaparray[intdex] = heaparray[parent];
             heaparray[parent] = temp;

             intdex = parent;
         }
     }



 }


 void ReadyQueue:: heapify() {

     for (int i = (count - 1); i >= 0; i--) { //goes to all values, and perc down
         percolateDown(i);
     }
 }


 ReadyQueue::ReadyQueue(const ReadyQueue& other) {
     capacity = other.capacity; //copies its attributes
     heaparray = new PCB[capacity];
     count = other.count;

     for (int i = 0; i < count; i++) {

         heaparray[i] = other.heaparray[i]; //fills the array with the exact same data values
     }

 }

 ReadyQueue& ReadyQueue::operator=(const ReadyQueue& other) {

     if (&other != this) { //if the stack is NOT already equal

         delete[] heaparray; // deallocates array

         heaparray = new PCB[other.capacity]; //do our copy constructor
         capacity = other.capacity;
         count = other.count;

         for (int i = 0; i < other.count; i++)
         {
             heaparray[i] = other.heaparray[i];
         }

     }
     return *this; //returns the new and equal array
 }



/**
 * @brief Add a PCB representing a process into the ready queue.
 *
 * @param pcbPtr: the pointer to the PCB to be added
 */
void ReadyQueue::addPCB(PCB* pcbPtr) {
    //to did: add your code here
    // When adding a PCB to the queue, you must change its state to READY.

    if (sizeof(heaparray) == count) { //doubles size of array if the number of elements in the array equals the capacity
        PCB* new_array = new PCB[capacity * 2];
        for (int i = 0; i < count; i++) {
            new_array[i] = heaparray[i];
        }
        capacity *= 2;
        delete[] heaparray;
        heaparray = new_array;
    }

    pcbPtr->state = ProcState::READY;
    heaparray[count] = *pcbPtr; //the last element is the new value


    count++; //increments count as we are inserting

    percolateUp(count - 1); //corrects the heap




  
}

/**
 * @brief Remove and return the PCB with the highest priority from the queue
 *
 * @return PCB*: the pointer to the PCB with the highest priority
 */
PCB* ReadyQueue::removePCB() {
    
    //to did: add your code here
    // When removing a PCB from the queue, you must change its state to RUNNING.



    PCB* removed = new PCB(heaparray[0].getID(), heaparray[0].getPriority(), ProcState::RUNNING);   //stores what we are going to delete


    PCB replaceValue = heaparray[count - 1]; //finds the last element in the heap
    count--; //decrements count

    if (count > 0) {
        heaparray[0] = replaceValue; //replaces the max with the new value
        percolateDown(0); //corrects for it by percolating down
    }

    return removed; //returns what we removed

}

/**
 * @brief Returns the number of elements in the queue.
 *
 * @return int: the number of PCBs in the queue
 */
int ReadyQueue::size() {
    //to did: add your code here
    return count; //size
} 

/**
 * @brief Display the PCBs in the queue.
 */
void ReadyQueue::displayAll() {
    //to did: add your code here
    for (int i = 0; i < count; i++) {
        
        heaparray[i].display(); //for every part of the array, display each isntance of PCB
        
    }

}

