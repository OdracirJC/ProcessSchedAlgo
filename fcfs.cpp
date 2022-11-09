#include "utility.h"

void firstComeFirstServe(std::vector<process> &processVector) {
  std::vector<process> taskQueue;
  int clock{0};
  while (!processVector.empty() || !queueDone(taskQueue)) {
    std::cout << "Clock Value is " << clock << std::endl << std::endl;
    addToTaskQueue(taskQueue, processVector, clock);
    if (taskQueue.size() != 0) {
      process *currentProcess = loadFirstProcess(taskQueue);
      clock += currentProcess->burstTime;

      std::cout << "Worked on Process " << currentProcess->id << " for "
                << currentProcess->burstTime << " millisecond(s)" << std::endl
                << std::endl;
      std::cout << "Process will now be dumped..." << std::endl << std::endl;
      currentProcess->load(currentProcess->burstTime);
      taskQueue.erase(taskQueue.begin());
    } else
      clock++;
  }
  std::cout << "Finished all processes using First Come First Serve in "
            << clock << " millisecond(s)." << std::endl
            << std::endl;
}
