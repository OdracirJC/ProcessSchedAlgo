#ifndef ANALYSIS_H
#define ANALYSIS_H
#include "process.h"
#include "utility.h"
#include <vector>

struct turnaround_waiting {
  float averageTurnAroundTime;
  float averageWaitingTime;
  std::vector<process> correspondingProcesses;
  turnaround_waiting() {}
};

void logTT(std::vector<float> &processList, process p);
void logWT(std::vector<float> &processList, process p);

#endif
