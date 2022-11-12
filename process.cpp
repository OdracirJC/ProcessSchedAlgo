#include "process.h"

process::process(int aT, int tR, int idNum)
    : arrivalTime{aT}, burstTime{tR}, id{idNum}, loadOffTime{-1} {}
process::process(const process &p0)
    : arrivalTime{p0.arrivalTime}, burstTime{p0.burstTime}, id{p0.id},
      loadOffTime{p0.loadOffTime} {}
void process::operator=(const process &p) {
  arrivalTime = p.arrivalTime;
  burstTime = p.burstTime;
  id = p.id;
  loadOffTime = p.loadOffTime;
}
void process::load(int workTime) {
  if (workTime >= burstTime)
    burstTime = 0;
  else
    burstTime -= workTime;
}
std::ostream &operator<<(std::ostream &out, const process &p) {
  out << "Process "
      << "ID: " << p.id << "\nArrival Time: " << p.arrivalTime
      << "\tTime Remaining: " << p.burstTime;
  return out;
}
