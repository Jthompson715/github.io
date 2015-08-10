// RoadDriver.cpp : Defines the entry point for the console application.
//"Lab 3a, The \"RoadDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#include <iostream>
#include <iomanip> // for setprecision
#include <cassert>
#include "Thompson_Jeremy_Lab3a_Road.h"
#include "Thompson_Jeremy_Lab3a_Road.h" // testing ifndef

using namespace std;

int main()
{
	// print my name and this assignment's title
	cout << "Lab 3a, The \"RoadDriver\" Program \n";
	cout << "Programmer: JEREMY THOMPSON\n";
	cout << "Editor(s) used: JNotePad\n";
	cout << "Compiler(s) used: VC++2013\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

	Road r(22, 30); // create road object r
	{
		//  ...test all getters and setters
		cout << "Expected width of 22." << endl;
		cout << "Actual width: " << r.getWidth() << endl;
		cout << "Expected length of 30." << endl;
		cout << "Actual length: " << r.getLength() << endl;
		cout << "Expected volume is 16,7270,400 cubic feet." << endl;
		cout << "Actual volume: " << setprecision(10) << r.calcAsphalt(4) << endl;
		assert(22 == r.getWidth());
		assert(30 == r.getLength());
	}

	{
		// object copy testing of road object
		Road copy = r;
		//  ...test all getters and setters
		cout << "\nRoad copy = road. Object copy testing." << endl;
		cout << "Expected width of 22." << endl;
		cout << "Actual width: " << r.getWidth() << endl;
		cout << "Expected length of 30." << endl;
		cout << "Actual length: " << r.getLength() << endl;
		cout << "Expected volume is 16,7270,400 cubic feet." << endl;
		cout << "Actual volume: " << copy.calcAsphalt(4) << endl;
		assert(22 == r.getWidth());
		assert(30 == r.getLength());
	}

	{
		// object assignment testing of road object
		Road copy(0, 0); copy = r;
		//  ...test all getters and setters
		cout << "\nRoad copy; copy = road. Object assignment testing." << endl;
		cout << "Expected width of 22." << endl;
		cout << "Actual width: " << r.getWidth() << endl;
		cout << "Expected length of 30." << endl;
		cout << "Actual length: " << r.getLength() << endl;
		cout << "Expected volume is 16,7270,400 cubic feet." << endl;
		cout << "Actual volume: " << copy.calcAsphalt(4) << endl;
		assert(22 == r.getWidth());
		assert(30 == r.getLength());
	}

	cin.get();
	cout << "Press ENTER to continue...";
}