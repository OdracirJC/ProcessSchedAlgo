/* FILENAME: sjf.cpp
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 *My implementation of the Shortest Job First Scheduling Algorithm
 */

#include "analysis.h"
#include "process.h"
#include "schedulingalgorithms.h"
#include "utility.h"

std::array<float, 2> shortestJobFirst(std::vector<process> processVector,
                                      char v) {
  bool verbose{(v == 'Y') ? false : true};         // Verbose on or off.
  process workBlock;                               // Processes to be worked on.
  std::vector<process> taskQueue;                  // taskQueue/readyQueue
  std::vector<float> sjflist;                      // Turnaround Time list
  std::vector<float> waitList;                     // Waiting Time List
  std::array<float, 2> returnArray;                // See fcfs.cpp
  int clock{0};                                    // "System" Clock
  const int nProcesses = processVector.capacity(); // Number of processes

  while (!processVector.empty() ||
         !queueDone(taskQueue)) { // While there are processes to handle...
    if (verbose)
      std::cout << "Clock Value is at: " << clock << std::endl << std::endl;

    addToTaskQueue(taskQueue, processVector, clock,
                   verbose);     // Take out next ready processes
    if (taskQueue.size() != 0) { // If we have processes to work on...

      workBlock = *loadShortestProcess(
          taskQueue, verbose); // Load the SHORTEST available process
      logNPWT(waitList, workBlock,
              clock);               // Log the wait time for process loaded
      clock += workBlock.burstTime; // Add time to clock
      addToTaskQueue(taskQueue, processVector, clock,
                     verbose); // Check for new processes
      if (verbose) {
        std::cout << "Worked on Process " << workBlock.id << " for "
                  << workBlock.burstTime << " millisecond(s)" << std::endl
                  << std::endl;
        std::cout << "Process will now be dumped... " << std::endl << std::endl;
      }
      logTT(sjflist, workBlock,
            clock); // Log turnaround time, now that clock is updated
      workBlock.load(workBlock.burstTime); // We reduce processes time to 0
      taskQueue.erase(taskQueue.begin());  // Erase processes
    } else
      clock++; // Or wait another ms
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
