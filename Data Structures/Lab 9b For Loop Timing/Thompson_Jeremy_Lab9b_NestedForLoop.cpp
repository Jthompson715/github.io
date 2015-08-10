// NestedForLoop.cpp: Defines the entry point for the console application.
//"Lab 9b, The \"NestedForLoop.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream> // for cout and endl
#include <string> // for string
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cassert>
using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 9b, The \"NestedForLoop.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  // problem setup goes here
  // programmer customizations go here
  int n = 3000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n squared)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    // more problem setup goes here -- the stuff not timed
    srand((double)time(NULL));

    double* a = new double[n];
    for (int i = 0; i < n; i++)
      a[i] = rand();
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();

    // nested for loop as required
    for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      // swap i and j index values
    if (a[j] < a[i])
    {
      int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
    // do something where n is the "size" of the problem
    clock_t endTime = clock();

    for (int i = 1; i < n; i++) assert(a[i - 1] <= a[i]);
    // validation block -- assure that process worked
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
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  cout << "Press ENTER to continue...";
  cin.get();
}