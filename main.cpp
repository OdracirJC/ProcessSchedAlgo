#include "process.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>
#define line std::cout << "=======================================" << std::endl
#define br std::cout << "\n" << std::endl
extern void firstComeFirstServe(std::vector<process> &processVector);
extern void shortestJobFirst(std::vector<process> &processVector);
extern void roundRobin(std::vector<process> &processVector, int quantum);

int main() {
  std::vector<process> plist;
  int upperLim;
  int nop;
  char ch;
  line;
  line;
  std::cout << "CPP SCHEDULING ALGORITHM PROJECT" << std::endl;
  std::cout << "Author:\t Ricardo J. Cantarero" << std::endl;
  std::cout << "Date:\t 11/12/2022" << std::endl;
  line;
  line;
  ch = 'N';
  for (;;) {
    std::cout << "Please enter the Number of Processes: " << std::endl;
    std::cin >> nop;
    std::cout << "You have entered a value of: " << nop << std::endl;
    std::cout << "Do you accept?\t(Y/y) " << std::flush;
    std::cin >> ch;
    ch = toupper(ch);
    if (ch == 'Y')
      break;
  }
  ch = 'N';
  std::cout << "Number of Processes: " << nop << std::endl;
  br;
  std::cout << "We will now randomly generate the pertinent attributes of the "
               "Processes.\n(Arrival Time and Burst Time)"
            << std::endl;
  br;
  for (;;) {
    std::cout << "Select max of number generation:(default is 10) "
              << std::flush;
    std::cin >> upperLim;
    std::cout << "You have entered a value of: " << upperLim << std::endl;
    std::cout << "Do you accept?\t(Y/y) " << std::flush;
    std::cin >> ch;
    ch = toupper(ch);
    if (ch == 'Y')
      break;
  }
  std::mt19937 randGen;
  std::uniform_int_distribution<> urand(1, upperLim);
  for (int i = 0; i < nop; i++) {
    plist.push_back({urand(randGen), urand(randGen), i});
  }
  br;
  std::cout << std::left << std::setw(25) << " " << std::left << std::setw(25)
            << "Process Table" << std::left << std::setw(25) << " "
            << std::endl;
  br;
  for (int i = 0; i < 74; i++) {
    std::cout << "=";
  }
  br;
  std::cout << std::left << std::setw(25) << "Process ID#" << std::left
            << std::setw(25) << "Arrival Time" << std::left << std::setw(25)
            << "Burst Time" << std::endl;
  for (int i = 0; i < nop; i++) {
    std::cout << std::left << std::setw(25) << plist[i].id << std::left
              << std::setw(25) << plist[i].arrivalTime << std::left
              << std::setw(25) << plist[i].burstTime << std::endl;
  }
  br;
  std::cout << std::left << std::setw(25) << " " << std::left << std::setw(25)
            << "Scheduling Algorithm Results" << std::left << std::setw(25)
            << " " << std::endl;
  br;
  for (int i = 0; i < 74; i++) {
    std::cout << "=";
  }

  std::cout << " " << std::endl;

  std::cout << std::left << std::setw(25) << "First Come First Serve"
            << std::endl;
  firstComeFirstServe(plist);
  std::cout << std::left << std::setw(25) << "Shortest Job First" << std::endl;
  shortestJobFirst(plist);
  std::cout << std::left << std::setw(25) << "Round Robin" << std::endl;
  roundRobin(plist, 2);
}
