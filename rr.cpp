/* FILENAME: rr.cpp
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * My implementation of the Round Robin Scheduling Algorithm, with variable
 * quantum.
 */

#include "analysis.h"
#include "process.h"
#include "schedulingalgorithms.h"
#include "utility.h"
#define log(x)                                                                 \
  std::cout << x << std::endl       // Utility function used to log in std_out
#define line "--------------------" // Line

std::array<float, 2> roundRobin(std::vector<process> processVector,
                                const int quantum, char v) {
  bool verbose{(v == 'Y') ? false : true};         // Verbose on or off
  const int nProcesses = processVector.capacity(); // Number of process.
  std::vector<float> rrlist;                       // Turnaround Time List
  std::vector<float> waitlist;                     // Waiting Tim eList
  std::vector<process> taskQueue;                  // Task Queue
  std::array<float, 2> returnArray;                // Same as FCFS
  process terminatorBlock(-2, -2, -2); // Used to specify empty workBlock
  process workBlock;                   // Processes being worked on
  int clock{0};                        // Clock begins at 0
  int qClock{0};                       // Time relative to quantum

  while (!processVector.empty() || !queueDone(taskQueue) ||
         workBlock.id !=
             terminatorBlock.id) { // As long as there is work to do...
    if (verbose) {
      log(line);
      log("TIME: " << clock);
      log(line);
      log("LOG:\n");
    }
    addToTaskQueue(taskQueue, processVector, clock,
                   verbose); // Add process to task queue if it is ready
    if (qClock == 0 &&
        !queueDone(taskQueue)) { // If quantum has passed, and we have processes
                                 // in task queue...
      workBlock =
          (taskQueue.front()); // WorkBlock is process at front of process queue
      taskQueue.erase(taskQueue.begin()); // Remove the task we just grabbed
      logPWT(waitlist, workBlock,
             clock); // log the wait time for the process we will work on.
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
    workBlock.load(1); // Work on  process for one second.
    if (verbose) {
      log("Worked on Process #" << workBlock.id << " for 1 millisecond.\n");
      log("Process Information to follow:\n");
      log(workBlock);
      log("\n");
    }
    clock++;  // One second has passed.
    qClock++; // One second has passed.

    if (workBlock.burstTime ==
        0) { // If processes is done, we need to update qClock
      if (verbose) {
        log("Finished Process " << workBlock.id);
        log("Turn around Time: " << clock - workBlock.arrivalTime);
      }
      logTT(rrlist, workBlock, clock);
      qClock = 0; // Will signal to take new process into work block
      workBlock = {-2, -2, -2}; // Work Block is empty
    } else {
      if (qClock == quantum) { // Time is up, we will load the process into back
                               // of taskQueue
        if (verbose)
          log("Quantum time has been reached... Will now load workBlock "
              "Processes into back of queue...");
        workBlock.loadOffTime =
            clock; // Log that at time {clock} we have loaded off process.
        addToTaskQueue(taskQueue, processVector, clock,
                       verbose); // Check for new processes at this time.
        taskQueue.push_back(workBlock);
        workBlock = {-1, -1, -1}; // Empty
        qClock = 0;               // Load new task
      }
    }
  }
  if (verbose) {
    log("Finished Round Robin in " << clock << " milliseconds.");
    log("Average Turn Around Time: " << averageTT(rrlist, nProcesses));
    log("Average Waiting Time: " << averagePWT(waitlist, nProcesses));
  }
  returnArray[0] = averageTT(rrlist, nProcesses);
  returnArray[1] = averagePWT(waitlist, nProcesses);
  return returnArray;
}
