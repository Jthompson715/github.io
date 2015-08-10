// TimeDriver.cpp : Defines the entry point for the console application.
//"Lab 1b, The \"TimeDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include <iostream>
#include <cassert>

#include "Thompson_Jeremy_Lab1b_Time.h"
#include "Thompson_Jeremy_Lab1b_Time.h" //ifndef test

using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 1b, The \"TimeDriver\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: CodeBlocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time time;

  //  ...test all getters and setters
  time.setHours(5);
  time.setMinutes(13);
  time.setSeconds(56);

  cout << "Expect hours to be 5.2322" << endl;
  cout << "Time in hours: " << time.timeInHours() << endl;
  cout << "Expect minutes to be 313.933" << endl;
  cout << "Time in minutes: " << time.timeInMinutes() << endl;
  cout << "Expect seconds to be 18836" << endl;
  cout << "Time in seconds: " << time.timeInSeconds() << endl;
  cout << "\n" << endl;
  // object copy testing
  {
    Time copy = time;
    cout << "Time copy = time. Object copy testing." << endl;
    cout << "Expect hours to be 5.2322" << endl;
    cout << "Time in hours: " << time.timeInHours() << endl;
    cout << "Expect minutes to be 313.933" << endl;
    cout << "Time in minutes: " << time.timeInMinutes() << endl;
    cout << "Expect seconds to be 18836" << endl;
    cout << "Time in seconds: " << time.timeInSeconds() << endl;
    assert(time.timeInHours() == copy.timeInHours());
    assert(time.timeInMinutes() == copy.timeInMinutes());
    assert(time.timeInSeconds() == copy.timeInSeconds());
    cout << "\n" << endl;

    //...use getters to confirm that copy's contents match road's
  }

  // object assignment testing
  {
    Time copy; copy = time;

    cout << "Time copy; copy = time. Object assignment testing." << endl;
    cout << "Expect hours to be 5.2322" << endl;
    cout << "Time in hours: " << time.timeInHours() << endl;
    cout << "Expect minutes to be 313.933" << endl;
    cout << "Time in minutes: " << time.timeInMinutes() << endl;
    cout << "Expect seconds to be 18836" << endl;
    cout << "Time in seconds: " << time.timeInSeconds() << endl;
    assert(time.timeInHours() == copy.timeInHours());
    assert(time.timeInMinutes() == copy.timeInMinutes());
    assert(time.timeInSeconds() == copy.timeInSeconds());
    cout << "\n" << endl;

    //...use getters to confirm that copy's contents match road's
  }
  cout << "\nPress ENTER to continue...";
  cin.get();
}
