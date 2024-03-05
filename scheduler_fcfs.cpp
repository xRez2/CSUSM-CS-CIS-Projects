/**
 * Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author Blake Savell, Xavier Christopher
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */
// You must complete the all parts marked as "TODO". Delete "TODO" after you are
// done.
//  Remember to add sufficient and clear comments to your code

#include "scheduler_fcfs.h"

// DOTO: add implementation of SchedulerFCFS constructor, destrcutor and
// member functions init, print_results, and simulate here

SchedulerFCFS::SchedulerFCFS() //FCFS constructor
{
  vector<PCB> list;
  listOfProcesses = list;
  numOfProcesses = 0; // define this stuff in constructor
}

SchedulerFCFS::~SchedulerFCFS() //destructor for FCFS 
{ 
  listOfProcesses.clear(); 
}

void SchedulerFCFS::init(std::vector<PCB> &process_list) {
  long unsigned int index = 0;
  while (process_list.size() > index) {

    // ready queue

    listOfProcesses.push_back(process_list[index]);
    numOfProcesses++;

    index++;
  }

  
}

void SchedulerFCFS::print_results() 
{

  for (unsigned long int i = 0; i < listOfProcesses.size(); i++) {
    // because FCFS takes into account arrival time, and all arrival times are
    // 0, we can just do the processes as they come
  }
  //assigning the turn around time 
  unsigned long int turnt = 0;
double turntacc = 0;

  //assigning the wait time
  unsigned long int waitt = 0;
double waittacc = 0;

  //these are the turn around average and wait average variables
  float turntavg;
  float waittavg;
  
  for (unsigned long int i = 0; i < listOfProcesses.size(); i++) {
    // turnover time calc
    turnt += listOfProcesses[i].burst_time;

    // waiting time calc
    if (i == 0) {
      waitt += 0;
    } else {
      waitt += listOfProcesses[i - 1].burst_time;
    }

    // adds it up
    turntacc += turnt;
    waittacc += waitt;
  }
  //calculating the turn average and wait average
  turntavg = turntacc / numOfProcesses;
  waittavg = waittacc / numOfProcesses;
  
  //print out the average turn and wait
  cout << "Average turn-around time = " << turntavg
       << ", Average waiting time = " << waittavg << " \n ";
}

void SchedulerFCFS::simulate() 
{
  for (unsigned long int i = 0; i < listOfProcesses.size(); i++) {
    // because FCFS takes into account arrival time, and all arrival times are
    // 0, we can just do the processes as they come
    cout << "Running Process " << listOfProcesses[i].name << " for "
         << listOfProcesses[i].burst_time << " time units \n";
  }
  //the turn time for simulate functiond
  unsigned long int turnt = 0;
  unsigned long int turntacc = 0;
  
  //turn wait time for simulate function
  unsigned long int waitt = 0;
  unsigned long int waittacc = 0;

  //the average variables for turn and wait
  double turntavg;
  double waittavg;
  
  for (unsigned long int i = 0; i < listOfProcesses.size(); i++) {
    // turnover time calc
    turnt += listOfProcesses[i].burst_time;

    // waiting time calc
    if (i == 0) {
      waitt += 0;
    } else {
      waitt += listOfProcesses[i - 1].burst_time;
    }

    cout << listOfProcesses[i].name << " turn-around time = " << turnt
         << ", waiting time = " << waitt << "\n";

    // adds it up
  }
}
