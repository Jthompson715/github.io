// THOMPSON_JEREMY_LAB0c_TheBasics.cpp : Defines the entry point for the console application.
//"Programmer: JEREMY THOMPSON\n"; 
//"Editor(s) used: JNotePad\n"; 
//"Compiler(s) used: VC++ 2013\n"; 

#include <cstdlib> //atoi, atof

#include <iomanip>
using std::setprecision;

#include <iostream> 
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

int main()
{
  int x;
  double y;
  string buf;
  string name, city;

  // print my name and this assignment's title 
  cout << "Lab 0c, The \"TheBasics\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "Enter your age: " << endl;
  cin >> buf; x = atoi(buf.c_str());
  cin.ignore(256, '\n');

  cout << "Enter your name: " << endl;
  getline(cin, name);

  cout << "Enter the temperature outside right now (degrees F): " << endl;
  cin >> buf; y = atof(buf.c_str());
  cin.ignore(256, '\n');

  cout << "What city are you in right now?" << endl;
  getline(cin, city);

  cout << name << " is " << x << " years old now, and will be " << (x + 1) << " a year from now." << endl;
  cout << "It's " << y << " degrees F in " << city << " -- that's ";
  cout.setf(ios::fixed | ios::showpoint);
  cout << setprecision(1) << (y - 32)*(5.0 / 9) << " degrees C." << endl;

  cout << "Press ENTER to continue..." << endl;
  cin.get();
}