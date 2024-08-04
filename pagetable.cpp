/**
* Assignment 5: Page replacement algorithms
 * @file pagetable.cpp
 * @author ??? (TODO: your name)
 * @brief This class represents a traditional pagetable data structure.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "pagetable.h"

// TODO: Add your implementation of PageTable
// Constrcutor
// TODO: Add your code
PageTable::PageTable(int num_pages)
{
     // pages.resize(num_pages);
    for(int i=0; i < num_pages; i++)
    {
      PageEntry p;
      pages.push_back(p);
    }

}

// Destructor
// TODO: Add your code
PageTable::~PageTable() 
{


}

int PageTable::get_num_free_frames() const 
{
    int num_free_frames = 0;
    for (int i = 0; i < pages.size(); ++i) {
        if (!pages[i].valid) {
            num_free_frames++;
        }
    }
    return num_free_frames;
}

void PageTable::write_page_to_disk(int page_num)
{
    // Get the page entry for the given page number
    PageEntry& page_entry = pages[page_num];

    // Write the page to disk only if it is valid and dirty
    if (page_entry.valid && page_entry.dirty) {
        // Write the contents of the page frame to disk
        // ...
        // Set the dirty bit to false
        page_entry.dirty = false;
    }
}