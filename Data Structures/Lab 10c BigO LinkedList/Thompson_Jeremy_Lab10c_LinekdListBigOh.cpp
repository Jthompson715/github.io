// LinkedListBigOh.cpp : Defines the entry point for the console application.
//"Lab 10c, The \"LinkedListBigOh.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";


#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <ctime>
using namespace std;

#define NODE
#include "Thompson_Jeremy_Lab10a_LinkedList.h"

int main()
{
  // print my name and this assignment's title
  cout << "Lab 10c, The \"LinkedListBigOh\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // variable declaration
  int testInt;
  int M = 10000;
  int randMax = 1000;
  const int REPS = 60000;

  srand(time(0)); // intialize random
  double prime = (rand() % randMax + 1); // call rand once to prime sequence

  for (int iterator = 1; iterator < 5; iterator++) // 4 iterations for each cycle
  {
    int m = M;
    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;

    if (iterator == 1)
      cout << "operator[] assignment at zeroth index, O(1)" << endl;
    if (iterator == 2)
      cout << "operator[] assignment at 100th index, O(1)" << endl;
    if (iterator == 3)
      cout << "iteration from first to last using operator[], O(n)" << endl;
    if (iterator == 4)
      cout << "length, O(1)" << endl;

    // cycle start
    for (int cycle = 0; cycle < 4; cycle++, m *= 2) // runs 4 cycles while doubling p each time
    {
      // test object creation
      LinkedList<double> l_list;

      // value assignment to list
      for (int i = 0; i < m; i++)
        l_list.insert((rand() % randMax)); // assignment of random values to list

      assert(l_list.length() == m);

      // timing
      string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

      // START timer
      clock_t startTime = clock();

      // TEST 1
      if (iterator == 1) // operator[] assignment at zeroth index, O(1)
      {
        for (int p = 0; p < REPS; p++)
          l_list[0] = (rand() % randMax); // assign random value to p nodes // reps
      } // end if (iterator1)

      // TEST 2
      if (iterator == 2) // operator[] assignment at 100th index, O(1)
      {
        for (int p = 0; p < REPS; p++)
          l_list[100] = (rand() % randMax); // assign random value to p nodes
      } // end if (iterator2)

      // TEST 3
      if (iterator == 3) // iteration from first to last using operator[], O(n)
      {
        bigOh = "O(n)";
        for (int i = 0; i < l_list.length(); l_list[i], i++);
      } // end if (iterator3)

      // TEST 4
      if (iterator == 4) // length, O(1)
      {
        for (int q = 0; q < REPS; q++)
          testInt = l_list.length();
      } // end if (iterator4)

      // STOP timer
      clock_t endTime = clock();

      // compute timing results
      long elapsedTimeTicks = (long)(endTime - startTime);
      double factor = pow(2.0, cycle);
      if (cycle == 0)
        elapsedTimeTicksNorm = elapsedTimeTicks;
      else if (bigOh == "O(1)")
        expectedTimeTicks = elapsedTimeTicksNorm;
      else if (bigOh == "O(log n)")
        expectedTimeTicks = log(double(m)) / log(m / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n)")
        expectedTimeTicks = factor * elapsedTimeTicksNorm;
      else if (bigOh == "O(n log n)")
        expectedTimeTicks = factor * log(double(m)) / log(m / factor) * elapsedTimeTicksNorm;
      else if (bigOh == "O(n squared)")
        expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

      // reporting block
      cout << "  " << elapsedTimeTicks;;
      if (cycle == 0) 
        cout << " (expected " << bigOh << ')';
      else 
        cout << " (expected " << expectedTimeTicks << ')';
      cout << " for m =" << m << endl;
    } // end for (cycles)
  } // end for iterations
  cout << "Press ENTER to continue...";
  cin.get();
} // end main