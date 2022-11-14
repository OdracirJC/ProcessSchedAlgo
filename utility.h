/* FILENAME: utility.h
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * Header File for utility.cpp
 */

#ifndef UTILITY_H
#define UTILITY_H
#include "process.h"
#include <algorithm> //Used for the sort algorithm to sort for Shortest Job First
#include <array>     //Used to return array info
#include <vector> //Used as DS for TaskQueue/ReadyQueue, ProcessesQueue/Vector
bool process_bt_comp(process const &lhs,
                     process const &rhs); // method that compares vectors based
                                          // on burstTime for SJF

bool process_at_comp(process const &lhs,
                     process const &rhs); // Method that compares vectors based
                                          // on Arrivaltime for FCFS
bool queueDone(std::vector<process> &taskQueueRef); // method that informs that
                                                    // the taskQueue is empty.
void addToTaskQueue(std::vector<process> &taskQueueRef,
                    std::vector<process> &processVectorRef, int &clock,
                    bool &verbose); // Method to add to taskqueue
process *loadFirstProcess(
    std::vector<process> &taskQueueRef,
    bool &verbose); // Load the first processes (looks at arrival time)
process *loadShortestProcess(
    std::vector<process> &taskQueueRef,
    bool &verbose); // Load the shortest process (look at burst time)
#endif
