// TimeDriver.cpp : Defines the entry point for the console application.
//"Lab 3b, The \"TimeDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include <iostream>
#include <cassert>

#include "Thompson_Jeremy_Lab3b_Time.h"
#include "Thompson_Jeremy_Lab3b_Time.h" //ifndef test

using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 3b, The \"TimeDriver\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: CodeBlocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time time(5, 13, 56);
  //  ...test all getters and setters

  cout << "Expect hours to be 5.2322" << endl;
  cout << "Time in hours: " << time.timeInHours() << endl;
  cout << "Expect minutes to be 313.933" << endl;
  cout << "Time in minutes: " << time.timeInMinutes() << endl;
  cout << "Expect seconds to be 18836" << endl;
  cout << "Time in seconds: " << time.timeInSeconds() << endl;

  // object copy testing
  {
    Time copy = time;
    cout << "\nRoad copy = road. Object copy testing." << endl;
    cout << "Expect hours to be 5.2322" << endl;
    cout << "Time in hours: " << time.timeInHours() << endl;
    cout << "Expect minutes to be 313.933" << endl;
    cout << "Time in minutes: " << time.timeInMinutes() << endl;
    cout << "Expect seconds to be 18836" << endl;
    cout << "Time in seconds: " << time.timeInSeconds() << endl;
    assert(time.timeInHours() == copy.timeInHours());
    assert(time.timeInMinutes() == copy.timeInMinutes());
    assert(time.timeInSeconds() == copy.timeInSeconds());

    //...use getters to confirm that copy's contents match road's
  }

  // object assignment testing
  {
    Time copy; copy = time;

    cout << "\nRoad copy; copy = road. Object assignment testing." << endl;
    cout << "Expect hours to be 5.2322" << endl;
    cout << "Time in hours: " << time.timeInHours() << endl;
    cout << "Expect minutes to be 313.933" << endl;
    cout << "Time in minutes: " << time.timeInMinutes() << endl;
    cout << "Expect seconds to be 18836" << endl;
    cout << "Time in seconds: " << time.timeInSeconds() << endl;
    assert(time.timeInHours() == copy.timeInHours());
    assert(time.timeInMinutes() == copy.timeInMinutes());
    assert(time.timeInSeconds() == copy.timeInSeconds());

    //...use getters to confirm that copy's contents match road's
  }
  cin.get();
  cout << "Press ENTER to continue...";
}
