// RoadDriver.cpp : Defines the entry point for the console application.
//"Lab 1a, The \"RoadDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include <iostream>
#include <iomanip> // for setprecision
#include <cassert>

using namespace std;

#include "THOMPSON_JEREMY_Lab1a_Road.h"
#include "THOMPSON_JEREMY_Lab1a_Road.h" // testing ifndef

int main()
{
  // print my name and this assignment's title
  cout << "Lab 1a, The \"RoadDriver\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: CodeBlocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Road road;
  {
    //  ...test all getters and setters
    road.setWidth(10.0);
    road.setLength(7.0);

    cout << "Expected width: 10" << endl;
    cout << "Actual width: " << road.getWidth() << endl;
    cout << "Expected length: 7" << endl;
    cout << "Actual length: " << road.getLength() << endl;
    cout << "Expected volume in inches cubed: 123200" << endl;
    cout << "Actual volume: " << setprecision(10) << road.calcAsphalt(4.0) << endl;
    cout << "\n" << endl;

  }
  // object copy testing
  {
    Road copy = road;

    cout << "Road copy = road. Object copy testing." << endl;
    cout << "Expected width: 10" << endl;
    cout << "Actual width: " << road.getWidth() << endl;
    cout << "Expected length: 7" << endl;
    cout << "Actual length: " << road.getLength() << endl;
    cout << "Expected volume in inches cubed: 123200" << endl;
    cout << "Actual volume: " << setprecision(10) << road.calcAsphalt(4.0) << endl;
    assert(road.getWidth() == copy.getWidth());
    assert(road.getLength() == copy.getLength());
    cout << "\n" << endl;
    //...use getters to confirm that copy's contents match road's
  }

  // object assignment testing
  {
    Road copy; copy = road;

    cout << "Road copy; copy = road. Object assignment testing." << endl;
    cout << "Expected width: 10" << endl;
    cout << "Actual width: " << road.getWidth() << endl;
    cout << "Expected length: 7" << endl;
    cout << "Actual length: " << road.getLength() << endl;
    cout << "Expected volume in inches cubed: 123200" << endl;
    cout << "Actual volume: " << setprecision(10) << road.calcAsphalt(4.0) << endl;
    assert(road.getWidth() == copy.getWidth());
    assert(road.getLength() == copy.getLength());
    cout << "\n" << endl;

    road.setWidth(25.0);
    road.setLength(3.5);

    cout << "Expected width: 25" << endl;
    cout << "Actual width: " << road.getWidth() << endl;
    cout << "Expected length: 3.5" << endl;
    cout << "Actual length: " << road.getLength() << endl;
    cout << "Expected volume in inches cubed: 46200" << endl;
    cout << "Actual volume: " << setprecision(10) << road.calcAsphalt(1.2) << endl;

    //...use getters to confirm that copy's contents match road's

    cout << "\nPress ENTER to continue...";
    cin.get();
  }
}
