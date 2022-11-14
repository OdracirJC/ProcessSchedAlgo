/* FILENAME: analysis.h
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * Header file of function definitions for analysis.cpp
 *
 */

#ifndef ANALYSIS_H
#define ANALYSIS_H
#include "process.h"
#include "utility.h"
#include <vector>

void logTT(std::vector<float> &processList, process &p,
           int clock); // Used by scheduling algorithms to log turnaround time
                       // for finished process.
float averageTT(std::vector<float> &processList,
                int nProcesses); // Used to calculate the average Turnaround and
                                 // Non-preemptive average waiting time.
void logNPWT(std::vector<float> &processList, process &p,
             int clock); // Logs Non-preemptive Waiting Time.

void logPWT(std::vector<float> &processList, process &p,
            int clock); // Logs preemtive Waiting Time.
float averagePWT(std::vector<float> &processList,
                 int nProcesses); // Averages Preemptive Waiting Time.
#endif
