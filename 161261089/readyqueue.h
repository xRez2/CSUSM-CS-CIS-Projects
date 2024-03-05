/**
 * Assignment 1: priority queue of processes
 * @file readyqueue.h
 * @author ??? (to did: your name)
 * @brief ReadyQueue is a queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 * @version 0.1
 */
//You must complete the all parts marked as "to did". Delete "to did" after you are done.
// Remember to add sufficient comments to your code
#pragma once

#include "pcb.h"


/**
 * @brief A queue of PCB's that are in the READY state to be scheduled to run.
 * It should be a priority queue such that the process with the highest priority can be selected next.
 */
class ReadyQueue {
private:
    // to did: add your private member variables here
    // choose a data structure for the ReadyQueue. No STL class is allowed.
    PCB* heaparray; // pointer to the array holding the heap
    int capacity = 100;   // the capacity of the heap
    int count;      // how many elements are in the heap

public:
    /**
     * @brief Construct a new ReadyQueue object
     *
     */



    // heap stuff needed to create the readyQueue

    ReadyQueue(const ReadyQueue& other);

    //bunch of heap functions

    //corrects the heap from top to bottom
    void percolateDown(int index);

    //corrects the heap bottom to top
    void percolateUp(int index);

    //creates a heap out of an array
    void heapify();


    // equals operator
    ReadyQueue &operator=(const ReadyQueue& other);





    ReadyQueue();

    /**
     * @brief Destructor
     */

    


    ~ReadyQueue();

	// You may add additional member functions, but don't change the dfinitions of the following four member functions.

    /**
     * @brief Add a PCB representing a process into the ready queue.
     *
     * @param pcbPtr: the pointer to the PCB to be added
     */
	void addPCB(PCB* pcbPtr);

    /**
     * @brief Remove and return the PCB with the highest priority from the queue
     *
     * @return PCB*: the pointer to the PCB with the highest priority
     */
	PCB* removePCB();

    /**
     * @brief Returns the number of elements in the queue.
     *
     * @return int: the number of PCBs in the queue
     */
	int size();

     /**
      * @brief Display the PCBs in the queue.
      */
	void displayAll();

};