/**
* Assignment 5: Page replacement algorithms
 * @file lifo_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the LIFO page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lifo_replacement.h"
#include <queue>
#include <stack>
#include <vector>

// TODO: Add your implementation here
LIFOReplacement::LIFOReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Add additional implementation code
        this->num_pages = num_pages;
        this->num_frames = num_frames;
}

// TODO: Add your implementations for desctructor, load_page, replace_page here
LIFOReplacement::~LIFOReplacement() {
    // TODO: Add necessary code here
}

// Access an invalid page, but free frames are available
void LIFOReplacement::load_page(int page_num) 
{
  pagefaults_count++;
page_table[page_num].valid = true;
frames.push(page_num);
page_table[page_num].frame_num = frame_counter;
//frame_counter++;
    // TODO: Add necessary code here
}

// Access an invalid page and no free frames are available
int LIFOReplacement::replace_page(int page_num) 
{
 int victim = frames.top();
page_table[victim].valid = false;
frames.pop();
page_table[victim].frame_num = -1;
page_table[page_num].valid = true;
page_table[page_num].frame_num = victim;
frames.push(page_num);
pagefaults_count++;
pageReplacements_count++;
return victim;
    // TODO: Add necessary code here
    //return 0;
}