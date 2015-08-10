// HelloWorld.cpp.cpp : Defines the entry point for the console application.
// Lab 0b, The "Hello, World" Program
// Programmer: YOUR NAME HERE
// Editor(s) used:  JNotePad
// Compiler(s) used: VS++ 2012 


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 0b, The \"Hello, World\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VS++ 2012 \n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // a code block
  cout << "Press ENTER to continue..." << endl;
  cin.get();
}