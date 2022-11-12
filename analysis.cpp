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
