#include "analysis.h"
#include "process.h"
#include "schedulingalgorithms.h"
#include "utility.h"

std::array<float, 2> shortestJobFirst(std::vector<process> &processVector,
                                      char v) {
  static bool verbose{(v == 'Y') ? false : true};
  static process workBlock;
  static std::vector<process> taskQueue;
  static std::vector<float> sjflist;
  static std::vector<float> waitList;
  static std::array<float, 2> returnArray;
  static int clock{0};
  static const int nProcesses = processVector.capacity();

  while (!processVector.empty() || !queueDone(taskQueue)) {
    if (verbose)
      std::cout << "Clock Value is at: " << clock << std::endl << std::endl;

    addToTaskQueue(taskQueue, processVector, clock, verbose);
    if (taskQueue.size() != 0) {

      workBlock = *loadShortestProcess(taskQueue, verbose);
      logNPWT(waitList, workBlock, clock);
      clock += workBlock.burstTime;
      addToTaskQueue(taskQueue, processVector, clock, verbose);
      if (verbose) {
        std::cout << "Worked on Process " << workBlock.id << " for "
                  << workBlock.burstTime << " millisecond(s)" << std::endl
                  << std::endl;
        std::cout << "Process will now be dumped... " << std::endl << std::endl;
      }
      logTT(sjflist, workBlock, clock);
      workBlock.load(workBlock.burstTime);
      taskQueue.erase(taskQueue.begin());
    } else
      clock++;
  }
  if (verbose) {

    std::cout << "Finished all processes using Shortest Job First in " << clock
              << " millisecond(s)." << std::endl
              << std::endl;
    std::cout << "Average Turn-Around Time: " << averageTT(sjflist, nProcesses)
              << " millisecond(s)" << std::endl
              << std::endl;
    std::cout << "Average Wait-Time: " << averageTT(waitList, nProcesses)
              << " millisecond(s)" << std::endl;
  }
  returnArray[0] = averageTT(sjflist, nProcesses);
  returnArray[1] = averageTT(waitList, nProcesses);
  return returnArray;
}
