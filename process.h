/*
 *Create a process struct and declare basic functions.
 */

#ifndef PROCESS_H
#define PROCESS_H
#include <iostream>
struct process {
  int arrivalTime;
  int burstTime;
  int id;
  int loadOffTime;
  process(int aT, int tR, int idNum);
  process() {}
  process(const process &p0);
  void operator=(const process &p);
  void load(int workTime);
  friend std::ostream &operator<<(std::ostream &out, const process &p);
};

#endif
