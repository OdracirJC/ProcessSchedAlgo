/* FILENAME: schedulingalgorithms.h
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 *
 * Header file of all scheduling algorithms and necessary files and libs
 */

#include "analysis.h"
#include "process.h"
#include "utility.h"
#include <array>
#include <iostream>
#include <vector>

std::array<float, 2> firstComeFirstServe(std::vector<process> processVector,
                                         char);
std::array<float, 2>
roundRobin(std::vector<process> processVector, int,
           char); // vector of processes, quantum, and verbose char
std::array<float, 2> shortestJobFirst(std::vector<process> processVector, char);
