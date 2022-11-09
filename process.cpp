#include "process.h"

process::process(int aT, int tR, int idNum) {
  arrivalTime = aT;
  burstTime = tR;
  id = idNum;
}
void process::load(int workTime) {
  try {
    if (workTime <= 0)
      throw "Work Time must be greater than 0!";
    if (workTime > burstTime)
      burstTime = 0;
    else
      burstTime -= workTime;
  } catch (const char *exception) {
    std::cerr << "Error: " << exception << "\n";
  }
}
std::ostream &operator<<(std::ostream &out, const process &p) {
  out << "Process "
      << "ID: " << p.id << "\nArrival Time: " << p.arrivalTime
      << "\tTime Remaining: " << p.burstTime;
  return out;
}
