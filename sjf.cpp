#include "analysis.h"
#include "process.h"
#include "utility.h"

void shortestJobFirst(std::vector<process> &processVector) {
  static process workBlock;
  std::vector<process> taskQueue;
  static std::vector<float> sjflist;
  static std::vector<float> waitList;
  int clock{0};

  while (!processVector.empty() || !queueDone(taskQueue)) {

    std::cout << "Clock Value is at: " << clock << std::endl << std::endl;

    addToTaskQueue(taskQueue, processVector, clock);
    if (taskQueue.capacity() != 0) {

      workBlock = *loadShortestProcess(taskQueue);
      logNPWT(waitList, workBlock, clock);
      clock += workBlock.burstTime;
      addToTaskQueue(taskQueue, processVector, clock);

      std::cout << "TurnAround Time: for process " << workBlock.id << " "
                << clock - workBlock.arrivalTime << std::endl;
      logTT(sjflist, workBlock, clock);

      workBlock.load(workBlock.burstTime);
      std::cout << "Worked on Process " << workBlock.id << " for "
                << workBlock.burstTime << " millisecond(s)" << std::endl
                << std::endl;
      std::cout << "Process will now be dumped... " << std::endl << std::endl;

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
  std::cout << "Average Wait-Time: " << averageTT(waitList) << " millisecond(s)"
            << std::endl
            << std::endl;
}
