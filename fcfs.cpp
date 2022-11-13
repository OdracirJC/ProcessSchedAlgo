#include "analysis.h"
#include "process.h"
#include "schedulingalgorithms.h"
#include "utility.h"

std::array<float, 2> firstComeFirstServe(std::vector<process> &processVector,
                                         char v) {
  static bool verbose{(v == 'Y') ? false : true};
  static process workBlock;
  static std::vector<process> taskQueue;
  static std::vector<float> ttList;
  static std::vector<float> wtList;
  static std::array<float, 2> returnArray;
  static int clock{0};
  static const int nProcesses = processVector.capacity();

  while (!processVector.empty() || !queueDone(taskQueue)) {
    if (verbose)
      std::cout << "Clock Value is " << clock << std::endl << std::endl;

    addToTaskQueue(taskQueue, processVector, clock, verbose);
    if (taskQueue.size() != 0) {

      workBlock = *loadFirstProcess(taskQueue, verbose);
      logNPWT(wtList, workBlock, clock);
      clock += workBlock.burstTime;
      addToTaskQueue(taskQueue, processVector, clock, verbose);
      if (verbose) {
        std::cout << "Worked on Process " << workBlock.id << " for "
                  << workBlock.burstTime << " millisecond(s)" << std::endl
                  << std::endl;
        std::cout << "Process will now be dumped..." << std::endl << std::endl;
      }
      logTT(ttList, workBlock, clock);
      workBlock.load(workBlock.burstTime);
      taskQueue.erase(taskQueue.begin());
    } else
      clock++;
  }
  if (verbose) {
    std::cout << "Finished all processes using First Come First Serve in "
              << clock << " millisecond(s)." << std::endl
              << std::endl;
    std::cout << "Average Turn Around Time: " << averageTT(ttList, nProcesses)
              << std::endl
              << std::endl;
    std::cout << "Average Wait-Time: " << averageTT(wtList, nProcesses)
              << std::endl
              << std::endl;
  }
  returnArray[0] = averageTT(ttList, nProcesses);
  returnArray[1] = averageTT(wtList, nProcesses);
  return returnArray;
}
