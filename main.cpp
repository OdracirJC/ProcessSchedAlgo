#include "process.h"
#include <iostream>
#include <vector>

#define log(x) std::cout << x << std::endl

void shortestRemainingTimeFirst(std::vector<process> &processVector);

int main() {
  process p1(0, 4, 1);
  process p2(2, 8, 2);
  process p3(4, 3, 3);
  process p4(6, 10, 4);
  std::vector<process> processes{p1, p2, p3, p4};

  shortestRemainingTimeFirst(processes);
  return 0;
}
