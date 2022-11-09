#include "utility.h"
/*Comparator*/
bool process_bt_comp(process const &lhs, process const &rhs) {
  return lhs.burstTime < rhs.burstTime;
}
bool process_at_comp(process const &lhs, process const &rhs) {
  return lhs.arrivalTime < rhs.arrivalTime;
}
/*Check if Queue is Done*/
bool queueDone(std::vector<process> &taskQueueRef) {
  for (process p : taskQueueRef) {
    if (p.burstTime != 0)
      return false;
  }
  return true;
}

/* Add to Tak Queue Subroutine */
void addToTaskQueue(std::vector<process> &taskQueueRef,
                    std::vector<process> &processVectorRef, int &clock) {

  for (auto i = 0; i < (int)processVectorRef.size(); i++) {
    if (processVectorRef.at(i).arrivalTime <= clock) {
      taskQueueRef.push_back(processVectorRef.at(i));
      std::cout << "Adding Process " << processVectorRef.at(i).id
                << " to Task Queue.\n";
      processVectorRef.erase(processVectorRef.begin() + i);
    }
  }
}

process *loadFirstProcess(std::vector<process> &taskQueueRef) {
  std::sort(taskQueueRef.begin(), taskQueueRef.end(), &process_at_comp);
  process *first = &(taskQueueRef.front());
  std::cout << "Shortest Process is process " << first->id << ".\n";
  return first;
}

process *loadShortestProcess(std::vector<process> &taskQueueRef) {
  std::sort(taskQueueRef.begin(), taskQueueRef.end(), &process_bt_comp);
  process *shortest = &(taskQueueRef.front());
  std::cout << "Shortest Process is process " << shortest->id << ".\n";
  return shortest;
}
