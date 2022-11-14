/* FILENAME: analysis.cpp
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * cpp file of function definitions used to return turnaround time and waiting
 * time.
 *
 */

#include "analysis.h"

void logTT(std::vector<float> &processList, process &p, int clock) {
  processList.push_back(
      clock -
      p.arrivalTime); // update processList with turnaround time (current time -
                      // arrival time of finished process).
}
float averageTT(std::vector<float> &processList,
                int nProcesses) { // Simple average function.
  float sum{0};
  for (int i : processList)
    sum += i;
  return sum / nProcesses;
}

void logNPWT(std::vector<float> &processList, process &p, int clock) {
  int loadTime{
      clock}; // For Non-Preemptive, we specify loadTime as the clock time.
  processList.push_back(loadTime - p.arrivalTime);
}
void logPWT(std::vector<float> &processList, process &p, int clock) {
  int loadTime{clock};
  if (p.loadOffTime == -1) // We have not had to place the process in the ready
                           // queue more than once.
  {
    processList.push_back(loadTime -
                          p.arrivalTime); // If this is the first time its being
                                          // offloaded, we use arrival time.
  } else {
    processList.push_back(loadTime -
                          p.loadOffTime); // If it is NOT the first time, use
                                          // last time it was loaded off.
  }
}
float averagePWT(std::vector<float> &processList,
                 int nProcesses) { // Simple average, but ask for nProcesses --
                                   // might be many entries != nProcess.
  float sum{0};
  for (int i : processList)
    sum += i;
  return sum / nProcesses;
}
