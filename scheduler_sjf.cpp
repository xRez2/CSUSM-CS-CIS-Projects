/**
 * Assignment 3: CPU Scheduler
 * @file scheduler_sjf.cpp
 * @author ??? (TODO: your name)
 * @brief This Scheduler class implements the SJF scheduling algorithm.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are
// done.
//  Remember to add sufficient and clear comments to your code

#include "scheduler_sjf.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and
// member functions init, print_results, and simulate here

SchedulerSJF::SchedulerSJF() //the constructor for SJF
{
  vector<PCB> list;
  vector<PCB> list2;
  avgTurn = 0;
  avgWait = 0;
  
  listOfProcesses = list;
  sortedList = list2;
  numOfProcesses = 0; // define this stuff in constructor
  
  
}

SchedulerSJF::~SchedulerSJF() //destructor for SJF
{
  listOfProcesses.clear();
  sortedList.clear();
}
// ---------------------------------------------------------------------
void SchedulerSJF::init(std::vector<PCB> &process_list) //pushing back list of processes onto process list
{
  long unsigned int index = 0;

  while (process_list.size() > index) {

    listOfProcesses.push_back(process_list[index]);
    numOfProcesses++;

    index++;
  }

  // the sorting happens here
  // minimum burst time index WHERE THE MIN PCB IS
}

//----------------------------------------------------------

void SchedulerSJF::print_results() //the print result function that prints the average wait and average turn
{ 
  cout << "Average turn-around time = " << avgTurn << ", "
  << "Average waiting time = " << avgWait << "\n";
}

void SchedulerSJF::simulate() //simulate function that runs through the SJF scheduler
{
  while (listOfProcesses.size() > 0) 
  { // start
    // size is
    int min = 100000000; // PROBLEMATIC

    int minDex = 0;

    // find min
    for (long unsigned int i = 0; i < listOfProcesses.size(); i++) {
      if (listOfProcesses[i].burst_time < min || listOfProcesses.size() == 1) {
        min = listOfProcesses[i].burst_time;
        minDex = i;
      }
    }
    // finds the PCB with the same burst time as the mininum
    // add MIN to SORTED vector
    sortedList.push_back(listOfProcesses[minDex]);

    // GET RID OF MINDEX FROM THE VECTOR
    listOfProcesses.erase(listOfProcesses.begin() + minDex);

  } // end of while loop

  // prints out running sjf processes

  for (long unsigned int i = 0; i < sortedList.size(); i++) 
  {
    cout << "Running Process " << sortedList[i].name << " for "
         << sortedList[i].burst_time << " time units \n";
  }
  //assigning tunr time
  unsigned long int turnt = 0;
double turntacc = 0;
  //assigning wait
  unsigned long int waitt = 0;
double waittacc = 0;



  string yeah[sortedList.size()]; // array of string with size of the list
  stringstream buffer;
  for (long unsigned int i = 0; i < sortedList.size(); i++) //this for loop will handle the turn and wait times.
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
    
    
    buffer << sortedList[i].name << " turn-around time = " << turnt
           << ", waiting time = " << waitt << "\n";

    yeah[sortedList[i].id] = buffer.str();
    buffer.str("");
  }
  //calculating the average wait and average turn
  avgWait = waittacc/sortedList.size();
  avgTurn = turntacc/sortedList.size();
  

  // prints the strings in order

  int size = sizeof(yeah)/sizeof(yeah[0]);

  for (int i = 0; i < size; i++) {
    cout << yeah[i];
  }
}