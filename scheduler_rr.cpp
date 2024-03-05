/**
* Assignment 3: CPU Scheduler
 * @file scheduler_rr.h
 * @author ??? (TODO: your name)
 * @brief This Scheduler class implements the RoundRobin (RR) scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code
//

#include "scheduler_rr.h"
#include <queue>

// TODO: add implementation of SchedulerFCFS constructor, destrcutor and 
// member functions init, print_results, and simulate here

SchedulerRR:: SchedulerRR(int time_quantum) 
{
  queue<PCB> que;
  myQueue = que;
  numProcesses = 0;
  
  
}

SchedulerRR:: ~SchedulerRR()
{
  //might not need 
}

void SchedulerRR::init(std::vector<PCB>& process_list)   
{
  for (int i = 0; i< process_list.size(); i++)
    {
      myQueue.push(process_list[i]);
    }
}

void SchedulerRR:: print_results()
{
  
}

void SchedulerRR:: simulate()
{
  
}