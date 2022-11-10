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

  process(int aT, int tR, int idNum);
  process(const process &p0);
  void load(int workTime);
  friend std::ostream &operator<<(std::ostream &out, const process &p);
};

#endif
