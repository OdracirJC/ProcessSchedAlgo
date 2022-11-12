#include "process.h"
#include <iostream>
#include <vector>
#define line std::cout << "=============" << std::endl

void start() {
  line;
  std::cout << "CPP SCHEDULING ALGORITHM PROJECT" << std::endl;
  std::cout << "Author: \t Ricardo J. Cantarero" << std::endl;
  std::cout << "Date  \t 11/12/2022" << std::endl;
  line;
  char confirm;
  int x;
  switch (confirm) {
  case 'Y':
  case 'y':
    break;
  default:
    std::cout << "How many processes would you like? " << std::endl;
    std::cin >> x;
    std::cout << "You selected " << x << "process(es)" << std::endl;
    std::cout << "Press Y/y to confirm: " << std::endl;
  }
}
