/* FILENAME: utility.cpp
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * Necessary, self-written, methods used for the scheduling algorithms
 */

#include "utility.h"
/*Comparator*/
bool process_bt_comp(process const &lhs, process const &rhs) {
  return lhs.burstTime < rhs.burstTime; // used for the Sorting Algo
}
bool process_at_comp(process const &lhs, process const &rhs) {
  return lhs.arrivalTime < rhs.arrivalTime; // Used for the Sorting Algo
}
/*Check if Queue is Done*/
bool queueDone(std::vector<process> &taskQueueRef) {
  for (process p : taskQueueRef) {
    if (p.burstTime != 0)
      return false;
  }
  return true;
}

/* Add to Task Queue Subroutine */
void addToTaskQueue(std::vector<process> &taskQueueRef,
                    std::vector<process> &processVectorRef, int &clock,
                    bool &verbose) {

  for (auto i = 0; i < (int)processVectorRef.size();
       i++) { // Iterate through processVector
    if (processVectorRef.at(i).arrivalTime <=
        clock) { // If the arrival time is less than the "System Clock"
      taskQueueRef.push_back(processVectorRef.at(i)); // Add to Ready/TaskQueue
      if (verbose)
        std::cout << "Adding Process " << processVectorRef.at(i).id
                  << " to Task Queue.\n";
      processVectorRef.erase(processVectorRef.begin() +
                             i); // Remove processes from the processVector
    }
  }
}

process *loadFirstProcess(std::vector<process> &taskQueueRef, bool &verbose) {
  std::sort(taskQueueRef.begin(), taskQueueRef.end(),
            &process_at_comp); // Sorts task queue with cpp stdlib function
                               // sort, using arrival time comparator
  process *first = &(taskQueueRef.front());
  if (verbose)
    std::cout << "First Process is process " << first->id << ".\n";
  return first; // Return pointer to process
}

process *loadShortestProcess(std::vector<process> &taskQueueRef,
                             bool &verbose) {
  std::sort(taskQueueRef.begin(), taskQueueRef.end(),
            &process_bt_comp); // Uses burst time comparator instead of above.
  process *shortest = &(taskQueueRef.front()); // Pointer to first element
  if (verbose)
    std::cout << "Shortest Process is process " << shortest->id << ".\n";
  return shortest; // Return pointer to process
}
