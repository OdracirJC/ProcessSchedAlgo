#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H
#include "process.h"
#include "utility.h"
#include <array>
#include <iostream>
#include <vector>

std::array<float, 2> firstComeFirstServe(std::vector<process> &processVector,
                                         char v = 'y');
std::array<float, 2> roundRobin(std::vector<process> &processVector,
                                const int quantum, char v = 'y');
std::array<float, 2> shortestJobFirst(std::vector<process> &processVector,
                                      char v = 'y');
#endif
