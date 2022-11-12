#include "analysis.h"
#include "process.h"
#include "utility.h"

void shortestJobFirst(std::vector<process> &processVector) {
  process workBlock;
  std::vector<process> taskQueue;
  std::vector<float> sjflist;
  int clock{0};

  while (!processVector.empty() || !queueDone(taskQueue)) {

    std::cout << "Clock Value is at: " << clock << std::endl << std::endl;

    addToTaskQueue(taskQueue, processVector, clock);
    if (taskQueue.capacity() != 0) {

      workBlock = *loadShortestProcess(taskQueue);
      clock += workBlock.burstTime;
      addToTaskQueue(taskQueue, processVector, clock);
      std::cout << "Worked on Process " << workBlock.id << " for "
                << workBlock.burstTime << " millisecond(s)" << std::endl
                << std::endl;
      std::cout << "Process will now be dumped... " << std::endl << std::endl;

      std::cout << "TurnAround Time: for process " << workBlock.id << " "
                << clock - workBlock.arrivalTime << std::endl;
      logTT(sjflist, workBlock, clock);

      workBlock.load(workBlock.burstTime);
      taskQueue.erase(taskQueue.begin());
    } else {
      clock++;
    }
  }
  std::cout << "Finished all processes using Shortest Job First in " << clock
            << " millisecond(s)." << std::endl
            << std::endl;
  std::cout << "Average Turn-Around Time: " << averageTT(sjflist)
            << " millisecond(s)" << std::endl
            << std::endl;
}
