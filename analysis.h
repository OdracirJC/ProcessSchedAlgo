#ifndef ANALYSIS_H
#define ANALYSIS_H
#include "process.h"
#include "utility.h"
#include <vector>

void logTT(std::vector<float> &processList, process &p, int clock);
float averageTT(std::vector<float> &processList, int nProcesses);
void logNPWT(std::vector<float> &processList, process &p, int clock);
void logPWT(std::vector<float> &processList, process &p, int clock);
float averagePWT(std::vector<float> &processList, int nProcesses);
#endif
