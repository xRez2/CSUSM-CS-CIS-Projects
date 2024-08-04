/**
 * Assignment 4: Producer Consumer Problem
 * @file main.cpp
 * @author Xavier Christopher, Blake Savell
 * @brief The main program for the producer consumer problem.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are
// done.
//  Remember to add sufficient and clear comments to your code
#include "buffer.h"
#include <fcntl.h>
#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

// global buffer object
Buffer buffer;
sem_t empty, full; 
pthread_mutex_t mut;

// Producer thread function
// TODO: Add your implementation of the producer thread here
void *producer(void *param) {
  // Each producer insert its own ID into the buffer
  // For example, thread 1 will insert 1, thread 2 will insert 2, and so on.
  buffer_item item = *((int *)param);

  while (true) {
    /* sleep for a random period of time */
    usleep(rand() % 1000000);
    // TODO: Add synchronization code here.

    // wait for empty
    sem_wait(&empty);
    // acquire lock before accessing buffer
    pthread_mutex_lock(&mut);

    if (buffer.insert_item(item)) { //isert item 
      cout << "Producer " << item << ": Inserted item " << item << endl; 
      buffer.print_buffer();
    } else {
      cout << "Producer error condition" << endl; // shouldn't come here
    }
    // Release the lock after accessing the buffer
    pthread_mutex_unlock(&mut);

    // Post to full semaphore
    sem_post(&full);
  }
}

// Consumer thread function
// TODO: Add your implementation of the consumer thread here
void *consumer(void *param) { 
  buffer_item item;

  while (true) {
    /* sleep for a random period of time */
    usleep(rand() % 1000000);
    // TODO: Add synchronization code here
    sem_wait(&full);
    pthread_mutex_lock(&mut);

    if (buffer.remove_item(&item)) {
      cout << "Consumer: Removed item " << item << endl;
      buffer.print_buffer();
    } else {
      cout << "Consumer error condition" << endl; // shouldn't come here
    }


    // Release the lock after accessing the buffer
    pthread_mutex_unlock(&mut);

    // Post to full semaphore
    sem_post(&empty);
  }
}

int main(int argc, char *argv[]) {
  /* TODO: 1. Get command line arguments argv[1],argv[2],argv[3] */

  int sleeping = atoi(argv[1]);
  int pthread_num = atoi(argv[2]); // num of producers
  int cthread_num = atoi(argv[3]); // num of consumers


  /* TODO: 2. Initialize buffer and synchronization primitives */

 // buffer = Buffer();
  sem_init(&full, 0, 0);
  sem_init(&empty, 0, 5);
  //empty == sem_open("/empty_sem", O_CREAT, 0666, 5);
 // full == sem_open("/full_sem", O_CREAT, 0644, 5); //added 'buffer.get_size()', replacing 0
  pthread_mutex_init(&mut, NULL);


  /* TODO: 3. Create producer thread(s).
   * You should pass an unique int ID to each producer thread, starting from 1
   * to number of threads */



  pthread_t threadyes;
  pthread_t threadno;

  for (int i = 0; i < pthread_num; i++) 
  {
    int* id = new int;
    *id = i+1;  
    //create threads
    pthread_create(&threadyes, NULL, producer, (void*)id); 

  }

  /* TODO: 4. Create consumer thread(s) */
  for (int i = 0; i < cthread_num; i++) 
  { 
    pthread_create(&threadno, NULL, consumer, NULL);
  }

  /* TODO: 5. Main thread sleep */
  sleep(sleeping);

  /* TODO: 6. Exit */
  return 0;
}
