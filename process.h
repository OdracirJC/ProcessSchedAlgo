/* FILENAME: process.h
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * Header File for process.cpp, defines struct process
 */
#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
struct process {   // Represents a process.
  int arrivalTime; // Time Process arrives.
  int burstTime;   // Time Remaining / Burst Time for Process.
  int id;          // ID for processes, for cout purposes.
  int loadOffTime; // Time that the processes was removed from Task Queue (only
                   // for Round Robin).
  process(int aT, int tR, int idNum); // Constructor
  process() {}                        // Constructor
  process(const process &p0);         // Cpy Constructor
  void operator=(const process &p);
  void load(int workTime); // Load Func
  friend std::ostream &
  operator<<(std::ostream &out,
             const process &p); // Print to std::out/std::cerr
};

#endif
