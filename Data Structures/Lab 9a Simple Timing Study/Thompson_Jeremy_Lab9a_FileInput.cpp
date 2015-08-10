// FileInput.cpp : Defines the entry point for the console application.
//"Lab 9a, The \"FileInput.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

//How to perform timing studies-- 4 - cycle timing code
#include <iostream> // for cout and endl
#include <string> // for string
#include <fstream>
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 9a, The \"FileInput.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  // problem setup goes here
  // programmer customizations go here
  int n = 500; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2)
  {
    // more problem setup goes here -- the stuff not timed
    int i = 0;
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();

    // open the input file
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/O error";

    // read the input file
    while (i < n)
    {
      // read the lines
      string line;
      getline(fin, line);
      strcpy(buf, line.c_str());
      if (buf[0] == 0) continue;
      i++;
    }
    fin.close();
    // do something where n is the "size" of the problem
    clock_t endTime = clock();
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