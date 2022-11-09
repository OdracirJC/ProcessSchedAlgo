#include "process.h"
#include <iostream>
#include <vector>

#define log(x) std::cout << x << std::endl

void shortestRemainingTimeFirst(std::vector<process> &processVector);
void firstComeFirstServe(std::vector<process> &processVector);
void shortestJobFirst(std::vector<process> &processVector);
int main() {
  process p1(0, 4, 1);
  process p2(2, 8, 2);
  process p3(4, 3, 3);
  process p4(6, 10, 4);

  process p5(0, 4, 1);
  process p6(2, 8, 2);
  process p7(4, 3, 3);
  process p8(6, 10, 4);

  process p9(0, 4, 1);
  process p10(2, 8, 2);
  process p11(4, 3, 3);
  process p12(6, 10, 4);

  std::vector<process> processes{p1, p2, p3, p4};
  std::vector<process> processes_2{p5, p6, p7, p8};
  std::vector<process> processes_3{p9, p10, p11, p12};

  shortestRemainingTimeFirst(processes);
  log("");
  log("");
  log("");
  firstComeFirstServe(processes_2);
  log("");
  log("");
  log("");
  shortestJobFirst(processes_3);
  return 0;
}
