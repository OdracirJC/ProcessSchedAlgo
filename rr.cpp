#include "analysis.h"
#include "process.h"
#include "schedulingalgorithms.h"
#include "utility.h"
#define log(x) std::cout << x << std::endl
#define line "--------------------"

std::array<float, 2> roundRobin(std::vector<process> &processVector,
                                const int quantum, char v) {
  static bool verbose{(v == 'Y') ? false : true};
  const int nProcesses{static_cast<int>(processVector.capacity())};
  static std::vector<float> rrlist;
  static std::vector<float> waitlist;
  static std::vector<process> taskQueue;
  static std::array<float, 2> returnArray;
  process terminatorBlock(-2, -2, -2);
  static process workBlock;
  static int clock{0}; // Clock begins at 0
  int qClock{0};

  while (!processVector.empty() || !queueDone(taskQueue) ||
         workBlock.id != terminatorBlock.id) {
    if (verbose) {
      log(line);
      log("TIME: " << clock);
      log(line);
      log("LOG:\n");
    }
    addToTaskQueue(taskQueue, processVector, clock, verbose);
    if (qClock == 0 && !queueDone(taskQueue)) {
      workBlock = (taskQueue.front());
      taskQueue.erase(taskQueue.begin());
      logPWT(waitlist, workBlock, clock);
      if (verbose) {
        log("Switched to process #" << workBlock.id << "\n");
        log("Process Information to follow:\n");
        log(workBlock);
        log("\n");
      }
    } else {
      if (verbose)
        log("Still working on Process #" << workBlock.id);
    }
    workBlock.load(1);
    if (verbose) {
      log("Worked on Process #" << workBlock.id << " for 1 millisecond.\n");
      log("Process Information to follow:\n");
      log(workBlock);
      log("\n");
    }
    clock++;
    qClock++;

    if (workBlock.burstTime == 0) {
      if (verbose) {
        log("Finished Process " << workBlock.id);
        log("Turn around Time: " << clock - workBlock.arrivalTime);
      }
      logTT(rrlist, workBlock, clock);
      qClock = 0;
      workBlock = {-2, -2, -2};
    } else {
      if (qClock == quantum) {
        if (verbose)
          log("Quantum time has been reached... Will now load workBlock "
              "Processes into back of queue...");
        workBlock.loadOffTime = clock;
        addToTaskQueue(taskQueue, processVector, clock, verbose);
        taskQueue.push_back(workBlock);
        workBlock = {-1, -1, -1};
        qClock = 0;
      }
    }
  }
  if (verbose) {
    log("Finished Round Robin in " << clock << " milliseconds.");
    log("Average Turn Around Time: " << averageTT(rrlist));
    log("Average Waiting Time: " << averagePWT(waitlist, nProcesses));
  }
  returnArray[0] = averageTT(rrlist);
  returnArray[1] = averagePWT(waitlist, nProcesses);
  return returnArray;
}
