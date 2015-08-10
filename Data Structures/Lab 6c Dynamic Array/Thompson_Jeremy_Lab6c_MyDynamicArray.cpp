//"Lab 6c, The \"MyDynamicArray.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include <string>
#include "Thompson_Jeremy_Lab6c_DynamicArray.h"

#include <cstring>

using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 6c, The \"MyDynamicArray\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // create array object with initial capacity of 10
  DynamicArray<int> a(5);
  string buf; // string for holding input
  int i = 0;

  bool input = true;

  cout << "Enter a number: ";
  cin >> buf;
  cin.ignore(1000, '\n');

  while (input) // quit upon entry of q or Q
  {

    //quit upon entry of q or Q
    if (buf == "q" || buf == "Q")
      input = false;
    else
    {
      a[i++] = atoi(buf.c_str());
      cout << "Enter a number or press Q or q to quit: ";
      cin >> buf;
      cin.ignore(1000, '\n');
    }
  }

  // output number of values before 'Q' or 'q'
  if (!input)
    cout << "Number of values entered: " << i << endl;

  // output unsorted list of entered values
  // comma or space-delimited
  for (int j = 0; j < i; j++)
  {
    cout << a[j] << ", ";
  }

  // search loop for an element using lsearch function
  bool search = true;
  while (search)
  {
    cout << "\nEnter an element to search for: ";
    cin >> buf;

    // quit upon entry of q or Q
    if (buf == "q" || buf == "Q")
      search = false;
    else
    {
      int j = atoi(buf.c_str());
      cout << "Entered value was found at index: " << a.lsearch(j) << endl;
      cin.get();
    }
  }

  cout << "Press ENTER to continue...";
  cin.get();
}

