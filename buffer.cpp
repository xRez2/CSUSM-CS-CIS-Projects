/**
 * Assignment 4: Producer Consumer Problem
 * @file buffer.cpp
 * @author Xavier Christopher, Blake Savell
 * @brief Implementation file for the buffer class
 * @version 0.1
 */

#include "buffer.h"
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// You must complete the all parts marked as "TODO". Delete "TODO" after you are
// done.
//  Remember to add sufficient and clear comments to your code

// TODO: Add your implementation of the buffer class here
Buffer::Buffer(int size) {
  buffArr[0] = 0;
  //buffArr = new buffer_item[size];
  buffSize = size;
  count = 0;
  front = 0;
  rear = -1;
}

Buffer::~Buffer() {  } //lol i pass cppf

bool Buffer::insert_item(buffer_item item)  //puts the item in the array
{
  if (is_full()) { //you cant put it in if its full
    return false;
  }
  //the rear is set to modulus of the buffer size
  rear = (rear + 1) % buffSize; 
  //setting item to buffer array rear
  buffArr[rear] = item;
  //increment count
  count++;
  //return true
  return true;
}

bool Buffer::remove_item(buffer_item *item) 
{

  if (is_empty()) //if the buffer is empty
  {
 //   std::cout << "this is it: "<< is_empty() ;
    return false;
  }

  *item = buffArr[front];  //set the front to item

  front = (front + 1) % buffSize;  //set front to front +1 modulus buffer size
  count--;

  return true;


}

int Buffer::get_size() { return buffSize; } //gets the size

int Buffer::get_count() { return count; } //gets cout

bool Buffer::is_empty() { //if the count is 0, its empty
  if (get_count() == 0) {
    return true;
  }
  return false;
}

bool Buffer::is_full() { //if the count = capacity its full
  if (get_count() == buffSize)   //if the get_count function is equal to buff size
  {
    return true;
  }
  return false;
}

void Buffer::print_buffer() 
{
  int j = front;
  if(is_empty())  //if empty, then the buffer cant print
  {
    std::cout << "\n-- Buffer is empty --\n\n";
  }
  else
  {
    std::cout << "["; //bracket for the array
    for(int i = 1; i <= count; i++)
    {
      if(j == rear) // only element left or last - do not show comma
        std::cout << buffArr[j]; //the last element does not show comma
      else
        std::cout << buffArr[j] << ", "; 
      j = (j + 1) % buffSize/*BUFFER_SIZE*/; 
    }
    std::cout << "]\n";
  }
}