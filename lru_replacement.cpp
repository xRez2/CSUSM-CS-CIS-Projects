/**
* Assignment 5: Page replacement algorithms
 * @file lru_replacement.cpp
 * @author ??? (TODO: your name)
 * @brief A class implementing the LRU page replacement algorithms
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "lru_replacement.h"
#include <queue>
#include <stack>
#include <vector>

// TODO: Add your implementation here
LRUReplacement::LRUReplacement(int num_pages, int num_frames)
: Replacement(num_pages, num_frames)
{
    // TODO: Complete this constructor
        this->num_pages = num_pages;
        this->num_frames = num_frames;
}

// TODO: Add your implementations for desctructor, touch_page, load_page, replace_page here
LRUReplacement::~LRUReplacement()
{
    // TODO: Add necessary code here
}

// Accesss a page alreay in physical memory
void LRUReplacement::touch_page(int page_num)
{
  // Find the frame that contains the page and move it to the top of the stack
    int frame_num = page_table[page_num].frame_num;
    frames.push(frame_num);

    // Remove the frame from its current position in the stack
    std::stack<int> temp_stack;
    while (frames.top() != frame_num) {
        temp_stack.push(frames.top());
        frames.pop();
    }
    frames.pop();

    // Put the frame back at the top of the stack
    while (!temp_stack.empty()) {
        frames.push(temp_stack.top());
        temp_stack.pop();
    }
    // TODO: Update your data structure LRU replacement
}

// Access an invalid page, but free frames are available
void LRUReplacement::load_page(int page_num) 
{
  std::stack<int> free_frames;
 // If there are free frames, assign the page to an available frame
    if (free_frames.size() > 0) {
        int frame_num = free_frames.top();
        free_frames.pop();

        page_table[page_num].valid = true;
        page_table[page_num].frame_num = frame_num;
        frames.push(frame_num);
    }
    // Otherwise, replace the least recently used page with the new page
    else {
        int victim_page_num = frames.top();
        frames.pop();
        page_table[victim_page_num].valid = false;

        page_table[page_num].valid = true;
        page_table[page_num].frame_num = page_table[victim_page_num].frame_num;
        frames.push(page_table[victim_page_num].frame_num);
    }

    // TODO: Update your data structure LRU replacement and pagetable
}

// Access an invalid page and no free frames are available
int LRUReplacement::replace_page(int page_num) 
{
   // Find the least recently used page and replace it with the new page
    int victim_page_num = frames.top();
    frames.pop();
    page_table[victim_page_num].valid = false;

    page_table[page_num].valid = true;
    page_table[page_num].frame_num = page_table[victim_page_num].frame_num;
    frames.push(page_table[victim_page_num].frame_num);

    return victim_page_num;
    // TODO: Update your data structure LRU replacement and pagetable
   // return 0;
}