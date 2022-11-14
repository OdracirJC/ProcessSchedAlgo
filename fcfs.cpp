/* FILENAME: fcfs.cpp
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * My implementation of the First Come First Serve Algorithm
 *
 */

#include "schedulingalgorithms.h" // Contains necessary headerFiles, structs, etc.

std::array<float, 2> firstComeFirstServe(std::vector<process> processVector,
                                         char v) {
  bool verbose{(v == 'Y') ? false : true}; // Used to turn off messages to user.
  process workBlock;                       // Process that we will work on.
  std::vector<process> taskQueue;   // Seperate Queue that contains avaiable
                                    // processes (arrival time <= clock).
  std::vector<float> ttList;        // List of turnaround times
  std::vector<float> wtList;        // List of Waiting Times
  std::array<float, 2> returnArray; // returnArray[0] = averageTurnaround,
                                    // returnArray[1] = averageWaitingTime
  int clock{0};                     // System Clock
  const int nProcesses =
      processVector.capacity(); // Number of Processes we have.

  while (!processVector.empty() ||
         !queueDone(taskQueue)) { // While there are still processing waiting
    if (verbose)
      std::cout << "Clock Value is " << clock << std::endl << std::endl;

    addToTaskQueue(taskQueue, processVector, clock,
                   verbose); // Add to Task Queue if it is available.

    if (taskQueue.size() != 0) {

      workBlock = *loadFirstProcess(
          taskQueue, verbose); // Load the processes that has come first.
      logNPWT(wtList, workBlock, clock); // Since we finish the process in one
                                         // go, calculate waiting time.
      clock += workBlock.burstTime;      // Increment clock .
      addToTaskQueue(
          taskQueue, processVector, clock,
          verbose); // Check for more processes now that time has passed
                    //
      if (verbose) {
        std::cout << "Worked on Process " << workBlock.id << " for "
                  << workBlock.burstTime << " millisecond(s)" << std::endl
                  << std::endl;
        std::cout << "Process will now be dumped..." << std::endl << std::endl;
      }

      logTT(ttList, workBlock,
            clock); // Log turnaround time, now that clock has been updated.
      workBlock.load(workBlock.burstTime); // finish process
      taskQueue.erase(taskQueue.begin());  // Erase processes from queue
    } else
      clock++; // If nothing yet increment.
  }
  if (verbose) { // If specified by verbose char, give more info to user.
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
  return returnArray; // Returns found averages.
}
