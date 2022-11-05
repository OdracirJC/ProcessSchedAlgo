/*
 *Create a process struct and declare basic functions.
 *
 *
 *
 */
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
struct process {
  float arrivalTime;
  float burstTime;
  int id;

  process(float aT, float tR, int idNum);
  void load(float workTime);
  friend std::ostream &operator<<(std::ostream &out, const process &p);
};

#endif
