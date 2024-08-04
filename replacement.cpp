/**
* Assignment 5: Page replacement algorithms
 * @file replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A base class for different page replacement algorithms.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
#include <iostream>
#include "replacement.h"

// TODO: Add your implementation of the Replacement member functions here

// Constructor
Replacement::Replacement(int num_pages, int num_frames)
: page_table(num_pages)
{
    //TODO: Add your implementation here
  pagefaults_count = 0;
    pageReplacements_count = 0;
    num_references = 0;
    frames_limit = num_frames;
    frame_counter = 0;

    num_writes_to_disk = 0;
}

// Destructor
Replacement::~Replacement()
{
    // TOOD: Add your code here
}

// Simulate a single page access 
// @return true if it's a page fault
bool Replacement::access_page(int page_num, bool is_write)
{
   // TODO: Add your implementation here
    // If the page is valid, it calls the touch_page function. 
    // If the page is not valid but free frames are available, it calls the load_page function.
    // If the page is not valid and there is no free frame, it calls the replace_page function.

//track num references
num_references++;

if(!page_table[page_num].valid)
{
    //if page not valid, but free frames are available, it will call the load page function
        if(frame_counter < frames_limit)
        {
            load_page(page_num);
            frame_counter++;
        }
    //if page is not valid, and no free frame, call replace_page
        else
        {
            //pageReplacements_count++; //commented out to check for double counts
            replace_page(page_num);
        }
        //pagefaults_count++; //commented out to check for double count
        return true;
}
    touch_page(page_num);
  return false;
}





// Print out statistics of simulation
void Replacement::print_statistics() const {
        // TODO: print out the number of references, number of page faults and number of page replacements
        std::cout << "Number of references: \t\t" << num_references << std::endl;
        std::cout << "Number of page faults: \t\t" << pagefaults_count << std::endl;
        std::cout << "Number of page replacements: \t"  << pageReplacements_count << std::endl;
}