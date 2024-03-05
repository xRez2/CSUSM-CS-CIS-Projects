/**
 * Assignment 3: CPU Scheduler
 * @file scheduler_priority.cpp
 * @author ??? (TODO: your name)
 * @brief This Scheduler class implements the Priority scheduling algorithm.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are
// done.
//  Remember to add sufficient and clear comments to your code

#include "scheduler_priority.h"
#include <sstream>
#include <string>

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and
// member functions init, print_results, and simulate here

SchedulerPriority::SchedulerPriority() {
  vector<PCB> list;
  vector<PCB> list2;
  listOfProcesses = list;
  sortedList = list2;
  numOfProcesses = 0; // define this stuff in constructor
}

SchedulerPriority::~SchedulerPriority() { listOfProcesses.clear(); }  //destructor for priority 

void SchedulerPriority::init(std::vector<PCB> &process_list) 
{
  long unsigned int index = 0;  //setting the process list index
  while (process_list.size() > index)   //this while loop pushes the list of processes into the process list at a index
  {

    listOfProcesses.push_back(process_list[index]);
    numOfProcesses++;

    index++;
  }

  // pushes to processes to the ready queue
}

void SchedulerPriority::print_results()   //the print function that prints the average wait and average turn
{
cout << "Average turn-around time = " << avgTurn << ", "
  << "Average waiting time = " << avgWait << "\n";
  
}

void SchedulerPriority::simulate() //simulate function
{
  while (listOfProcesses.size() > 0)   //while the list of processes at sice is greater than 0. This greater while loop goes through the list of processes, which also happens 
                                      // in the loop.
  {
    //setting max and maxDex
    int max = 0;
    int maxDex = 0;

    for (long unsigned int i = 0; i < listOfProcesses.size(); i++) //i will increment throught the list of processes' size   
    {
      if (listOfProcesses[i].priority > max || listOfProcesses.size() == 1)
      {
        max = listOfProcesses[i].priority;
        maxDex = i; // simple max function
      }
    }
    //pushing back sorted list on list of processes at maxDex
    sortedList.push_back(listOfProcesses[maxDex]);

    // GET RID OF MaxDEX FROM THE VECTOR
    listOfProcesses.erase(listOfProcesses.begin() + maxDex);
  }
      for (long unsigned int i = 0; i < sortedList.size(); i++)  //this loop prints out the sorted list, it's burst time, and it's time units
    {
      cout << "Running Process " << sortedList[i].name << " for "
           << sortedList[i].burst_time << " time units \n";
    }
  //the turn time
  unsigned long int turnt = 0;
double turntacc = 0;
  //the wait time
  unsigned long int waitt = 0;
double waittacc = 0;

  string yeah[sortedList.size()]; // array of string with size of the list
  stringstream buffer;

    for (long unsigned int i = 0; i < sortedList.size(); i++) //going through the newly sorted list and calculating turn time
    {
    turnt += sortedList[i].burst_time;
    turntacc += turnt;

    

    // waiting time calc
    if (i == 0) {
      waitt += 0;
    } else {
      waitt += sortedList[i - 1].burst_time;
    }
    waittacc += waitt;
    
    
    buffer << sortedList[i].name << " turn-around time = " << turnt  //print turn around time and wait time
           << ", waiting time = " << waitt << "\n";

    yeah[sortedList[i].id] = buffer.str();  
    buffer.str("");
  }

   avgWait = waittacc/sortedList.size();
  avgTurn = turntacc/sortedList.size();
  

  // prints the strings in order

  int size = sizeof(yeah)/sizeof(yeah[0]);

  for (int i = 0; i < size; i++) {
    cout << yeah[i];
  }
  
}