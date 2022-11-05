#include "process.h"
#define log(x) std::cout << x << std::endl

int main() {
  process p1(0, 4, 1);
  process p2(2, 8, 2);
  process p3(4, 3, 3);
  process p4(6, 10, 4);
  process pBlock[] = {p1, p2, p3, p4};
  for (int i = 0; i < 4; i++) {
    log(pBlock[i]);
    log("-------------");
  }

  return 0;
}
