/**
* Assignment 5: Page replacement algorithms
 * @file fifo_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the FIFO page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "fifo_replacement.h"
#include "queue"

// TODO: Add your implementation here
FIFOReplacement::FIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
        this->num_pages = num_pages;
        this->num_frames = num_frames;
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
FIFOReplacement::~FIFOReplacement() {

}

// Access an invalid page, but free frames are available
void FIFOReplacement::load_page(int page_num) 
{

        pagefaults_count++; 
       //frame_counter++; //commented out to check for double counts
        page_table[page_num].valid = true; // set the valid bit for the page
        frames.push_back(page_num); // assign the page to the next available frame
        page_table[page_num].frame_num = frame_counter;



}

// Access an invalid page and no free frames are available
int FIFOReplacement::replace_page(int page_num) 
{
          int victim = frames.front(); // the page at the front of the queue is the oldest
    page_table[victim].valid = false; // set the valid bit of the victim page to false

    frames.erase(frames.begin()); // remove it from the queue
    page_table[victim].frame_num = -1; // clear the frame number of the victim page

    page_table[page_num].valid = true; // set the valid bit of the new page to true
    page_table[page_num].frame_num = victim; // assign the victim's frame number to the new page

    frames.push_back(page_num); // add the new page to the back of the queue
    pagefaults_count++;
     pageReplacements_count++;
    return victim; // return the victim page number


}