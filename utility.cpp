#include "utility.h"
/*Comparator*/
bool process_comp(process const &lhs, process const &rhs) {
  return lhs.burstTime < rhs.burstTime;
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
