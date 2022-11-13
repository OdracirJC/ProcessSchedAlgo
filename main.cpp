#include "process.h"
#include "schedulingalgorithms.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#define line std::cout << "=======================================" << std::endl
#define br std::cout << "\n" << std::endl

int main() {

  std::vector<process> splist;
  int upperLim;
  int nop;
  char ch;
  char v;
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
  br;
  std::cout << "Output for the Scheduling Algorithms will be VERY verbose."
            << std::endl;
  std::cout << "Would you like to turn verbose output off?(Y/y)" << std::flush;
  std::cin >> v;
  v = toupper(v);

  std::vector<float> fcfs_tt;
  std::vector<float> fcfs_wt;
  std::vector<float> sjf_tt;
  std::vector<float> sjf_wt;
  std::vector<float> rr_tt;
  std::vector<float> rr_wt;

  for (int x = 0; x < 50; x++) {

    std::vector<process> plist;
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution<int> uniFormDist{1, nop};

    plist.push_back({0, uniFormDist(mt), 0});
    for (int i = 1; i < nop; i++) {
      plist.push_back({uniFormDist(mt), uniFormDist(mt), i});
    }
    br;
    std::cout << std::left << std::setw(25) << " " << std::left << std::setw(25)
              << "Process Table" << std::left << std::setw(25) << " "
              << std::endl;
    for (int i = 0; i < 74; i++) {
      std::cout << "=";
    }
    std::cout << " " << std::endl;
    std::cout << std::left << std::setw(25) << "Process ID#" << std::left
              << std::setw(25) << "Arrival Time" << std::left << std::setw(25)
              << "Burst Time" << std::endl;
    for (int i = 0; i < nop; i++) {
      std::cout << std::left << std::setw(25) << plist[i].id << std::left
                << std::setw(25) << plist[i].arrivalTime << std::left
                << std::setw(25) << plist[i].burstTime << std::endl;
    }
    for (int i = 0; i < 74; i++) {
      std::cout << "=";
    }
    br;
    br;
    std::cout << std::left << std::setw(25) << " " << std::left << std::setw(25)
              << "Scheduling Algorithm Results" << std::left << std::setw(25)
              << std::endl;
    std::cout << "(Measured in milliseconds)" << std::endl;
    for (int i = 0; i < 74; i++) {
      std::cout << "=";
    }
    std::cout << " " << std::endl;
    std::vector<process> plist_cpy_1 = plist;
    std::vector<process> plist_cpy_2 = plist;
    std::vector<process> plist_cpy_3 = plist;
    std::array<float, 2> fcfsResult = firstComeFirstServe(plist_cpy_1, v);
    fcfs_tt.push_back(fcfsResult[0]);
    fcfs_wt.push_back(fcfsResult[1]);
    std::array<float, 2> sjfResult = shortestJobFirst(plist_cpy_2, v);
    sjf_tt.push_back(sjfResult[0]);
    sjf_wt.push_back(sjfResult[1]);
    std::array<float, 2> rrResult = roundRobin(plist_cpy_3, 2, v);
    rr_tt.push_back(rrResult[0]);
    rr_wt.push_back(rrResult[1]);
    std::cout << std::left << std::setw(35) << "Scheduling Algorithm"
              << std::left << std::setw(35) << "Average Turn Around Time"
              << std::left << std::setw(35) << "Average Wait Time" << std::endl;

    std::cout << std::left << std::setw(35) << "First Come First Serve"
              << std::left << std::setw(35) << fcfsResult[0] << std::left
              << std::setw(35) << fcfsResult[1] << std::endl;
    std::cout << std::left << std::setw(35) << "Shortest Job First" << std::left
              << std::setw(35) << sjfResult[0] << std::left << std::setw(35)
              << sjfResult[1] << std::endl;
    std::cout << std::left << std::setw(35) << "Round Robin q=2" << std::left
              << std::setw(35) << rrResult[0] << std::left << std::setw(35)
              << rrResult[1] << std::endl;
    for (int i = 0; i < 74; i++) {
      std::cout << "=";
    }
    for (int i = 0; i < 74; i++) {
      std::cout << "=";
    }
    br;
  }
  br;
  std::cout << "Averages of Values" << std::endl;
  br;
  std::cout << std::left << std::setw(35) << "Scheduling Algorithm" << std::left
            << std::setw(35) << "Average Turn Around Time" << std::left
            << std::setw(35) << "Average Wait Time" << std::endl;

  std::cout << std::left << std::setw(35) << "First Come First Serve"
            << std::left << std::setw(35)
            << std::reduce(fcfs_tt.begin(), fcfs_tt.end()) / 50.0 << std::left
            << std::setw(35)
            << std::reduce(fcfs_wt.begin(), fcfs_wt.end()) / 50.0 << std::endl;
  std::cout << std::left << std::setw(35) << "Shortest Job First" << std::left
            << std::setw(35) << std::reduce(sjf_tt.begin(), sjf_tt.end()) / 50.0
            << std::left << std::setw(35)
            << std::reduce(sjf_wt.begin(), sjf_wt.end()) / 50.0 << std::endl;
  std::cout << std::left << std::setw(35) << "Round Robin q=2" << std::left
            << std::setw(35) << std::reduce(rr_tt.begin(), rr_tt.end()) / 50.0
            << std::left << std::setw(35)
            << std::reduce(rr_wt.begin(), rr_wt.end()) / 50.0 << std::endl;
}
