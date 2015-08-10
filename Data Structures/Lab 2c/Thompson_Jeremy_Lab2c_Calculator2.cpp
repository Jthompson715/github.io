// Calculator2.cpp : Defines the entry point for the console application.
//"Lab 2c, The \"Calculator2.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib> // for atof
using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 2c, The \"Calculator2.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: CodeBlocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;
  cout << "This is a calculator program using Reverse Polish Notation (RPN)" << endl << endl;

  stack<string> entry; // create a stack of strings to hold inputs
  string strIn; // string for holding input

  while(strIn != "q" && strIn != "Q") // quit upon entry of q or Q
  {
    // output
    stack<string> copy = entry;
    cout << "Enter: ";
    for(string str; !copy.empty(); copy.pop())
    {
      str = copy.top();
      cout << str << " ";
    }

    // input
    cin >> strIn; // input from console
    stringstream convertBackToStr (stringstream::in | stringstream::out); // convert back into a string
    double result = 0; // to hold result and initialized to zero

    if(entry.size() < 2 && (strIn == "+" || strIn == "-" || strIn == "*" || strIn == "/"))
      continue;

    else if(strIn == "+")
    {
      string temp = entry.top();
      result = atof(temp.c_str());  // convert string
      entry.pop();
      temp = entry.top();
      result = result + atof(temp.c_str());
      entry.pop();

      convertBackToStr << result;
      entry.push(convertBackToStr.str());
    }

    else if(strIn == "-")
    {
      string temp = entry.top();
      result = result + atof(temp.c_str());  // convert string
      entry.pop();
      temp = entry.top();
      result = atof(temp.c_str()) - result;
      entry.pop();

      convertBackToStr << result;
      entry.push(convertBackToStr.str());
    }

    else if(strIn == "*")
    {
      string temp = entry.top();
      result = result + atof(temp.c_str());
      entry.pop();
      temp = entry.top();
      result = atof(temp.c_str()) * result;
      entry.pop();

      convertBackToStr << result;
      entry.push(convertBackToStr.str());
    }

    else if(strIn == "/")
    {
      string temp = entry.top();
      result = result + atof(temp.c_str());
      entry.pop();
      temp = entry.top();
      result = atof(temp.c_str()) / result;
      entry.pop();

      convertBackToStr << result;
      entry.push(convertBackToStr.str());
    }

    else
      entry.push(strIn);
  }
  cin.get();
  cout << "Press ENTER to continue...";
}
