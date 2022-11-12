#include "analysis.h"
#include "utility.h"

void firstComeFirstServe(std::vector<process> &processVector) {
  static process workBlock;
  std::vector<process> taskQueue;
  static std::vector<float> ttList;
  static std::vector<float> wtList;
  int clock{0};
  while (!processVector.empty() || !queueDone(taskQueue)) {
    std::cout << "Clock Value is " << clock << std::endl << std::endl;
    addToTaskQueue(taskQueue, processVector, clock);
    if (taskQueue.size() != 0) {
      workBlock = *loadFirstProcess(taskQueue);
      logNPWT(wtList, workBlock, clock);
      clock += workBlock.burstTime;

      std::cout << "Worked on Process " << workBlock.id << " for "
                << workBlock.burstTime << " millisecond(s)" << std::endl
                << std::endl;
      std::cout << "Process will now be dumped..." << std::endl << std::endl;
      logTT(ttList, workBlock, clock);
      workBlock.load(workBlock.burstTime);
      taskQueue.erase(taskQueue.begin());
    } else
      clock++;
  }
  std::cout << "Finished all processes using First Come First Serve in "
            << clock << " millisecond(s)." << std::endl
            << std::endl;
  std::cout << "Average Turn Around Time: " << averageTT(ttList) << std::endl
            << std::endl;
  std::cout << "Average Wait-Time: " << averageTT(wtList) << std::endl
            << std::endl;
}
