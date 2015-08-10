//"Lab 12b, The \"PriorityQueueBigOh.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <ctime>
using namespace std;

#include "Thompson_Jeremy_Lab12a_PriorityQueue.h"
#include "Thompson_Jeremy_Lab12a_PriorityQueue.h" // ifndef testing

int main()
{
  // print my name and this assignment's title
  cout << "Lab 12b, The \"PriorityQueueBigOh.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  int N = 8000000;
  const int REPS = (N / 100); // REPS for each cycle, less than 1%
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

  for (int iteration = 1; iteration < 3; iteration++) // 2 cycles per iteration
  {
    int n = N;
    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;

    if (iteration == 1) cout << "enqueue, O(log n)" << endl;
    if (iteration == 2) cout << "\ndequeue, O(log n)" << endl;

    for (int cycle = 0; cycle < 4; cycle++, n *= 2) // runs 4 cycles and doubles n each time
    {
      // Creation of test object
      PriorityQueue<double> pQueue;

      for (int i = n; i > 0; i--) pQueue.enqueue(i); // assigning of decreasing values

      assert(pQueue.getSize() == n); // assertion to confirm n is the size of the data struct
      PriorityQueue<double> pQueueCopy(pQueue); // default priority queue

      // START TIMER
      clock_t startTime = clock();

      if (iteration == 1) for (int reps = 0; reps < REPS; reps++) pQueue.enqueue(n + reps);
      if (iteration == 2) for (int reps = 0; reps < REPS; reps++) pQueue.dequeue();

      // STOP TIMER
      clock_t endTime = clock();

      if (iteration == 1) assert(pQueue.getSize() == (n + REPS)); // assertion for size
      if (iteration == 1) assert(pQueue.getSize() == (n + REPS));

      // compute timing results
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      if (cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if (bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if (bigOh == "O(log n)")
        expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if (bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

      // reporting block
      cout << "\n  " << elapsedTimeTicks;
      if (cycle == 0) cout << " (expected " << bigOh << ')';
      else cout << " (expected " << expectedTimeTicks << ')';
      cout << " for n=" << n;
    }
  }

  cout << "\nPress ENTER to continue...";
  cin.get();
}