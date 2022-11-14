/* FILENAME: main.cpp
 * AUTHOR: Ricardo J. Cantarero
 * DATE: 11/13/2022
 *
 * Driver File that also handles the CLI "UI" for the program
 */

#include "process.h"
#include "schedulingalgorithms.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <random> //We use Mersenne Twister and uniform_int_distribution
#include <vector>
#define line std::cout << "=======================================" << std::endl
#define br std::cout << "\n" << std::endl

int main() {

  std::vector<process> splist; //
  int upperLim;                // Upper Limit of BurstSize/ArrivalTime
  int nop;                     // Number of Processes
  char ch;                     // Used to signal yes or no for user
  char v;                      // Used to confirm verbose or not
  /* Vars for all averages from trials */
  std::vector<float> fcfs_tt; // First Come First Served Turnaround Time
  std::vector<float> fcfs_wt; // First Come First Served Waiting Time
  std::vector<float> sjf_tt;  // Shortest Job First Turnaround Time
  std::vector<float> sjf_wt;  // Shortest Job First Waiting Time
  std::vector<float> rr_tt;   // Round Robin Turnaround Time
  std::vector<float> rr_wt;   // Round Robiin Waiting Time

  line;
  line;
  std::cout << "CPP SCHEDULING ALGORITHM PROJECT" << std::endl;
  std::cout << "Author:\t Ricardo J. Cantarero" << std::endl;
  std::cout << "Date:\t 11/12/2022" << std::endl;
  line;
  line;
  ch = 'N';
  for (;;) { // Loop asking user for input and for confirmation.
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
  for (;;) { // Loop asking for upperLimit of number generation
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

  for (int x = 0; x < 500; x++) { // We collect 500 Samples of Averages Waiting
                                  // Times, Average Turnaround Times for algos

    std::vector<process> plist; // Where we will temporarily store the proesses
    std::mt19937 mt{
        std::random_device{}()}; // We create a generator using Mersenne Twister
                                 // 32-bit with a random seed
    std::uniform_int_distribution<int> uniFormDist{
        1, nop}; // Create uniform Distribution

    plist.push_back(
        {0, uniFormDist(mt),
         0}); // First Element must be 0, otherwise nonsensical algorithm
    for (int i = 1; i < nop; i++) {
      plist.push_back(
          {uniFormDist(mt), uniFormDist(mt),
           i}); // Create random data for Process Burst Time and Arrival Time
    }
    br;
    std::cout << std::left << std::setw(25) << " " << std::left
              << std::setw(25) // Formatting
              << "Process Table" << std::left << std::setw(25) << " "
              << std::endl;
    for (int i = 0; i < 74; i++) { // Nice Line
      std::cout << "=";
    }
    /*Formatting Below for Tables*/
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
    // Make copies of plist, as we copy by ref and not by val for
    // algos.
    std::vector<process> plist_cpy_1 = plist;
    std::vector<process> plist_cpy_2 = plist;
    std::vector<process> plist_cpy_3 = plist;

    std::array<float, 2> fcfsResult =
        firstComeFirstServe(plist_cpy_1, v); // Get results from process list
    fcfs_tt.push_back(
        fcfsResult[0]); // Push back result to fcfs turnaround time list
    fcfs_wt.push_back(
        fcfsResult[1]); // Push back result to fcfs waiting time list
    std::array<float, 2> sjfResult = shortestJobFirst(plist_cpy_2, v);
    sjf_tt.push_back(sjfResult[0]); // Same as before, for sfj
    sjf_wt.push_back(sjfResult[1]);
    std::array<float, 2> rrResult = roundRobin(plist_cpy_3, 2, v);
    rr_tt.push_back(rrResult[0]);
    rr_wt.push_back(rrResult[1]);
    /*Formatting Algorithm Results for trials*/
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
  br;
  br;
  /*calculating final averages*/
  /*We use the std::reduce function to efficiently get sum of vectors given
   * iterator bounds*/
  std::cout << "Averages of Values" << std::endl;
  std::cout << "Number of Samples: 500" << std::endl;
  br;
  std::cout << std::left << std::setw(35) << "Scheduling Algorithm" << std::left
            << std::setw(35) << "Average Turn Around Time" << std::left
            << std::setw(35) << "Average Wait Time" << std::endl;

  std::cout << std::left << std::setw(35) << "First Come First Serve"
            << std::left << std::setw(35)
            << std::reduce(fcfs_tt.begin(), fcfs_tt.end()) / 500.0 << std::left
            << std::setw(35)
            << std::reduce(fcfs_wt.begin(), fcfs_wt.end()) / 500.0 << std::endl;
  std::cout << std::left << std::setw(35) << "Shortest Job First" << std::left
            << std::setw(35)
            << std::reduce(sjf_tt.begin(), sjf_tt.end()) / 500.0 << std::left
            << std::setw(35)
            << std::reduce(sjf_wt.begin(), sjf_wt.end()) / 500.0 << std::endl;
  std::cout << std::left << std::setw(35) << "Round Robin q=2" << std::left
            << std::setw(35) << std::reduce(rr_tt.begin(), rr_tt.end()) / 500.0
            << std::left << std::setw(35)
            << std::reduce(rr_wt.begin(), rr_wt.end()) / 500.0 << std::endl;
}
