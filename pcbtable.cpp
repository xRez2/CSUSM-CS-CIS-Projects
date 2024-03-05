/**
 * Assignment 1: priority queue of processes
 * @file pcbtable.h
 * @author Blake Savell, Xavier Christopher 
 * @brief This is the implementation file for the PCBTable class.
 * //You must complete the all parts marked as "to did". Delete "to did" after you are done.
 * // Remember to add sufficient comments to your code
 */

#include "pcbtable.h"
#include <vector>
#include <memory>


/**
 * @brief Construct a new PCBTable object of the given size (number of PCBs)
 *
 * @param size: the capacity of the PCBTable
 */
PCBTable::PCBTable(int size) {


    table.resize(size); //constructor for vector
    
   
}

/**
 * @brief Destroy the PCBTable object. Make sure to delete all the PCBs in the table.
 *
 */
PCBTable::~PCBTable() {
   // to did: add your code here
    table.clear(); //clears out the vector
}

/**
 * @brief Get the PCB at index "idx" of the PCBTable.
 *
 * @param idx: the index of the PCB to get
 * @return PCB*: pointer to the PCB at index "idx"
 */
PCB* PCBTable::getPCB(unsigned int idx) {
    // to did: add your code here

    PCB* dummy = table.at(idx);

    return dummy;
}

/**
 * @brief Add a PCB to the PCBTable.
 *
 * @param pcb: the PCB to add
 */
void PCBTable::addPCB(PCB* pcb, unsigned int idx) {
    table.insert(table.begin() + idx , pcb); //inserts the Pcb at the specified index

    
}
