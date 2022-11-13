#include "process.h"
#include "schedulingalgorithms.h"
#include "utility.h"

/*Main Function for Algorithm*/
void shortestRemainingTimeFirst(std::vector<process> &processVector) {
  static std::vector<process> taskQueue;
  static bool verbose = true;
  static int clock{0};

  while (!processVector.empty() || !queueDone(taskQueue)) {

    std::cout << "Clock Value is at: " << clock << std::endl << std::endl;
    addToTaskQueue(taskQueue, processVector, clock, verbose);
    if (taskQueue.size() != 0) {

      process *currentProcess = loadShortestProcess(taskQueue, verbose);
      currentProcess->load(1);
      if (currentProcess->burstTime == 0) {
        std::cout << "Completed Process " << currentProcess->id
                  << ". Will now dump it..." << std::endl;
        taskQueue.erase(taskQueue.begin());
      }
      std::cout << "Worked on process " << currentProcess->id
                << " for 1 millisecond." << std::endl
                << std::endl;
      std::cout << *currentProcess << std::endl << std::endl;
    }
    clock++; // one millisecond has passed.
  }

  std::cout << "Finished all processes using Shortest Remaining Time First in "
            << clock << " milliseconds."
            << "\n"; // Prints message to user.
}

/* Load Shortest Process Subroutine */
