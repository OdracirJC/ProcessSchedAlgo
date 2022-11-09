#include "process.h"
#include "utility.h"
#include <algorithm>
#include <vector>

void addToTaskQueue(std::vector<process> &taskQueueRef,
                    std::vector<process> &processVectorRef, int &clock);
process loadShortestProcess(std::vector<process> &taskQueueRef);

bool queueDone(std::vector<process> &taskQueueRef);

void shortestRemainingTimeFirst(std::vector<process> &processVector) {
  std::vector<process> taskQueue;
  int clock{0};
  std::cout << "Check." << std::endl;
  while (!processVector.empty() ||
         !queueDone(taskQueue)) { // Condition for when everything is done.
    std::cout << "Check." << std::endl;
    addToTaskQueue(taskQueue, processVector,
                   clock); // Looks for available processes in processes
                           // vector and loads them into task queue.
                           //
    if (taskQueue.size() != 0) {

      process currentProcess =
          loadShortestProcess(taskQueue); // Looks for shortest Remaining Time
                                          // out of Available Proceses
      currentProcess.load(1);
      if (currentProcess.burstTime < 1) {
        std::cout << "Completed Process " << currentProcess.id
                  << ". Will now dump it..." << std::endl;
        taskQueue.erase(taskQueue.begin());
      }
      std::cout << "Worked on process " << currentProcess.id
                << " for 1 millisecond." << std::endl
                << std::endl;
      ; // We work on Process for 1ms.
      std::cout << currentProcess << std::endl;
    }
    clock++; // one millisecond has passed.
  }

  std::cout << "Finished all processes using Shortest Remaining Time First in "
            << clock << " milliseconds."
            << "\n"; // Prints message to user.
}
void addToTaskQueue(std::vector<process> &taskQueueRef,
                    std::vector<process> &processVectorRef, int &clock) {
  for (int i = 0; i != processVectorRef.size(); i++) {
    if (processVectorRef.at(i).arrivalTime <= clock) {
      taskQueueRef.push_back(processVectorRef.at(i));
      std::cout << "Adding Process " << processVectorRef.at(i).id
                << " to Task Queue.\n";
      processVectorRef.erase(processVectorRef.begin() + i);
    }
  }
}
process loadShortestProcess(std::vector<process> &taskQueueRef) {
  std::sort(taskQueueRef.begin(), taskQueueRef.end(), &process_comp);
  process shortest = taskQueueRef.front();
  std::cout << "Shortest Process is process " << shortest.id << ".\n";
  return shortest;
}

bool queueDone(std::vector<process> &taskQueueRef) {
  for (process p : taskQueueRef) {
    if (p.burstTime != 0)
      return false;
  }
  return true;
}
