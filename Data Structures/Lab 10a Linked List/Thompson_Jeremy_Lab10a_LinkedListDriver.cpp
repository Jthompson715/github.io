// LinkedListDriver.cpp : Defines the entry point for the console application.
//"Lab 10a, The \"LinkedListDriver.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";


#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#define NODE
#include "Thompson_Jeremy_Lab10a_LinkedList.h"
#include "Thompson_Jeremy_Lab10a_LinkedList.h" // ifndef test

int main()
{
  // print my name and this assignment's title
  cout << "Lab 10a, The \"LinkedListDriver.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // variable declaration
  int testInt;

  // object creation
  LinkedList<int> l_list;

  // ***Setter and Getter testing***
  // Getter test of isEmpty()
  cout << "Testing l_list.isEmpty(). (true)" << endl;
  assert(l_list.isEmpty() == 1);
  // Getter test of length()
  cout << "Testing l_list.length()" << endl;
  assert(l_list.length() == 0);

  // Setter test of insert
  cout << "Testing l_list.insert(9)" << endl;
  l_list.insert(9);
  // Getter test of isEmpty()
  cout << "Testing l_list.isEmpty(). (false)" << endl;
  assert(l_list.isEmpty() == 0);
  // Getter test of length()
  cout << "Testing l_list.length" << endl;
  assert(l_list.length() == 1);
  // Getter test of start()
  cout << "Testing l_list.start(int)" << endl;
  assert(l_list.first(testInt) == 1);
  cout << "Expect 9 for the stored int." << endl;
  cout << "Actual is: " << testInt << endl << endl;

  // Setter test of insert()
  cout << "Testing l_list.insert(13)" << endl;
  l_list.insert(13);
  // Getter test of isEmpty()
  cout << "Testing l_list.isEmpty(). (false)" << endl;
  assert(l_list.isEmpty() == 0);
  // Getter test of length()
  cout << "Testing l_list.length" << endl;
  assert(l_list.length() == 2);
  // Getter test of start()
  cout << "Testing l_list.start(int)" << endl;
  assert(l_list.first(testInt) == 1);
  cout << "Expect 13 for the stored int." << endl;
  cout << "Actual is: " << testInt << endl << endl;
  cout << "Inserting 17, 21, 25" << endl;
  l_list.insert(17), l_list.insert(21), l_list.insert(25);

  // Getter test of length
  cout << "Testing l_list.length()" << endl;
  assert(l_list.length() == 5);
  // Getter test of find()
  cout << "Testing l_list.find(21). (true)" << endl;
  assert(l_list.find(21) == 1);

  // Getter test of find ()
  cout << " Testing l_list.find(22). (false)" << endl;
  assert(l_list.find(22) == 0);
  //Getter test of operator []
  cout << "Testing l_list[2]" << endl;
  testInt = l_list[3]; // stores l_list[7] in testInt
  assert(testInt == 13);
  // Getter test of operator[]
  cout << "Testing l_ist[9]. Will error" << endl;
  try
  {
    testInt = l_list[9]; // stores the value of l_list[3] in testInt
    cout << testInt << endl << endl;
  }
  catch (const char* ex)
  {
    cout << "Found an ERROR." << ex << endl << endl;
  }

  // Setter test of remove()
  cout << "Testing l_list.remove(int). Removing 25" << endl;
  testInt = 25;
  assert(l_list.remove(testInt) == 1);
  // Getter test of length()
  cout << "Testing l_list.length()" << endl;
  assert(l_list.length() == 4);
  // Getter test of find()
  cout << "Testing l_list.find(21)" << endl;
  assert(l_list.find(21) == 1);
  // Getter test of start()
  cout << "Testing of l_list.start(int) and moving to start index" << endl;
  assert(l_list.first(testInt) == 1);
  cout << "Expect 21 for the stored int." << endl;
  cout << "Actual is: " << testInt << endl << endl;

  // Getter test of getNext()
  cout << "Testing getNext(int)" << endl;
  assert(l_list.getNext(testInt) == 1);
  assert(testInt == 17);
  cout << "Expect 17 for stored int." << endl;
  cout << "Actual is: " << testInt << endl;
  // Getter test of retrieve()
  cout << "Testing retrieve (int)" << endl;
  assert(l_list.retrieve(testInt) == 1);
  // Setter test of replace()
  cout << "Testing replace(8). Expect 1" << endl;
  cout << "Actual is: " << l_list.replace(8) << endl << endl;
  assert(l_list.replace(8) == 1);

  // Getter test of operator[] 
  cout << "Expected contents of list: 21, 8, 13, 9." << endl;
  cout << "Actual contents of list: ";
  if (l_list.length())
    cout << l_list[0];
  for (int i = 1; i < l_list.length(); i++)
  {
    cout << ", " << l_list[i];
  }
  cout << endl;

  // Setter test of makeEmpty()
  cout << "Testing of makeEmpty()" << endl;
  l_list.makeEmpty();
  // Getter test of length()
  cout << "Testing of length()" << endl;
  assert(l_list.length() == 0);


  cout << "Filling list for use in copy testing" << endl;
  cout << "Filling with: 1, 13, 21, 25, 427, 999, 1001" << endl;

  int intCopyArray[7] = { 1, 13, 21, 25, 427, 999, 1001 };
  for (int i = 7; i != 0; i--)
    l_list.insert(intCopyArray[i - 1]);

  // Getter test of operator[]
  cout << "Checking list contents: " ;
  if (l_list.length())
    cout << l_list[0];
  for (int i = 1; i < l_list.length(); i++)
    cout << ", " << l_list[i];
  cout << endl << endl;

  // Object copy testing with assignment UPON declaration
  {
    cout << "***Object copy testing with assignment UPON declaration.***" << endl;
    LinkedList<int> l_Copy = l_list;

    cout << "Testing listCopy.isEmpty()" << endl;
    assert(l_Copy.isEmpty() == 0);

    cout << "Testing listCopy.length()" << endl;
    assert(l_Copy.length() == 7);

    cout << "Testing start(int)" << endl;
    assert(l_Copy.first(testInt) == 1);
    assert(testInt == 1);

    cout << "Testing find()" << endl;
    testInt = 25;
    assert(l_Copy.find(testInt) == 1);

    cout << "Testing getNext(testInt)" << endl;
    assert(l_Copy.getNext(testInt) == 1);
    assert(testInt == 427);

    cout << "The list still contains: ";
    if (l_Copy.length())
      cout << l_list[0];
    for (int i = 1; i < l_Copy.length(); i++)
      cout << ", " << l_Copy[i];
    cout << endl << endl;
  }

  {
  // Object copy testing with assignment AFTER declaration
    cout << "***Object copy testing with assignment AFTER declaration.***" << endl;
    LinkedList<int> l_Copy; l_Copy = l_list;

    cout << "Testing listCopy.isEmpty()" << endl;
    assert(l_Copy.isEmpty() == 0);

    cout << "Testing listCopy.length()" << endl;
    assert(l_Copy.length() == 7);

    cout << "List contains : 1, 13, 21, 25, 427, 999, 1001" << endl;

    cout << "Testing start(int)" << endl;
    assert(l_Copy.first(testInt) == 1);
    assert(testInt == 1);

    cout << "Testing find()" << endl;
    testInt = 25;
    assert(l_Copy.find(testInt) == 1);

    cout << "Testing getNext(testInt)" << endl;
    assert(l_Copy.getNext(testInt) == 1);
    assert(testInt == 427);

    cout << "The list still contains: ";
    if (l_Copy.length())
      cout << l_list[0];
    for (int i = 1; i < l_Copy.length(); i++)
      cout << ", " << l_Copy[i];
    cout << endl << endl;
  }
  cout << "Press ENTER to continue...";
  cin.get();
}