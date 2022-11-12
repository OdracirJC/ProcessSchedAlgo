#include "analysis.h"

struct turnaround_waiting;

void logTT(std::vector<float> &processList, process &p, int clock) {
  processList.push_back(clock - p.arrivalTime);
}
float averageTT(std::vector<float> &processList) {
  float sum{0};
  for (int i : processList)
    sum += i;
  return sum / processList.capacity();
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
    processList.push_back(loadTime - p.arrivalTime);
  } else {
    processList.push_back(loadTime - p.loadOffTime);
  }
}
float averagePWT(std::vector<float> &processList, int nProcesses) {
  float sum{0};
  for (int i : processList)
    sum += i;
  return sum / nProcesses;
}
