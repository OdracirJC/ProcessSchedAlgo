#include "utility.h"

bool process_comp(process const &lhs, process const &rhs) {
  return lhs.burstTime < rhs.burstTime;
}
