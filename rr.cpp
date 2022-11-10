#include "process.h"
#include "utility.h"

void roundRobin(std::vector<process> &processVector, int quantum) {

  std::vector<process> taskQueue;
  int clock{0};

  while (processVector.empty() || !queueDone(taskQueue)) {

    std::cout << "Clock Value is at: " << clock << std::endl << std::endl;
    addToTaskQueue(taskQueue, processVector, clock);

    process *currentProcess = &(taskQueue.front());

    if (currentProcess->burstTime <= quantum) {

      int lt_or_eq_Quantum{currentProcess->burstTime};
      currentProcess->load(lt_or_eq_Quantum);
      std::cout << "Completed Process " << currentProcess->id
                << ". Will now dump it..." << std::endl;
      process currentProcess_cpy{*currentProcess};
      taskQueue.erase(taskQueue.begin());
      taskQueue.push_back(currentProcess_cpy);
      clock += lt_or_eq_Quantum;
      break;
    }
    currentProcess->load(quantum);
    std::cout << "Worked on process " << currentProcess->id << " for "
              << quantum << " millisecond." << std::endl
              << std::endl;
    std::cout << *currentProcess << std::endl << std::endl;
    process currentProcess_cpy{*currentProcess};
    taskQueue.erase(taskQueue.begin());
    taskQueue.push_back(currentProcess_cpy);
    clock += quantum;
  }
  std::cout << "Finished all processes using Round Robin (q=" << quantum
            << ") in " << clock << " milliseconds." << std::endl;
}
