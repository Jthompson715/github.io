//"Lab 12a, The \"PriorityQueue.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
using namespace std;

#include "Thompson_Jeremy_Lab12a_PriorityQueue.h"
#include "Thompson_Jeremy_Lab12a_PriorityQueue.h" // ifndef test

int main()
{
  // print my name and this assignment's title
  cout << "Lab 12a, The \"PriorityQueue.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  int tempInt(0), largestInt(0);
  int randMax = 1000;

  srand(time(0)); // initialization of random seed
  double prime = (rand() % randMax + 1); // call rand once after srand to "prime" the sequence

  // create test object
  PriorityQueue<int> pQueue(128); // default pQueue

  cout << "PriorityQueue object has been created...(hopefully)" << endl << endl;

  // ***Testing***
  // Testing of GETTER isEmpty()
  cout << "1 Testing pQueue.isEmpty() (true)" << endl;
  assert(pQueue.isEmpty() == 1);
  // Testing of GETTER getSize()
  cout << "2 Testing of pQueue.getSize()" << endl;
  assert(pQueue.getSize() == 0);
  // Testing of GETTER getCpacity()
  cout << "3 Testing of pQueue.getCpacity()" << endl;
  assert(pQueue.getCapacity() == 128);

  // Testing of SETTER enqueue(DataType val)
  cout << "4 Testing pq.enqueue(555)..." << endl;
  pQueue.enqueue(427);
  // Testing of GETTER isEmpty()
  cout << "5 Testing pq.isEmpty() (FALSE)" << endl;
  assert(pQueue.isEmpty() == 0);
  // Testing of GETTER getSize()
  cout << "6 Testing pq.getSize()" << endl << endl;
  assert(pQueue.getSize() == 1);


  // Testing of SETTER enqueue(DataType val)
  cout << "7 Testing of enqueue. Enqueueing 100 random numbers." << endl;
  for (int i = 0; i < 100; i++) pQueue.enqueue((rand() % randMax));

  // Testing of operator[]
  cout << "8 Testing of operator []. Moving through array to find the largest int." << endl;
  for (int i = 0; i < 101; i++) if (pQueue[i] > largestInt) largestInt = pQueue[i]; // assigns the largest number
  cout << "The largestInt is: " << largestInt << endl;

  // Testing of GETTER isEmpty()
  cout << "\n9 Testing pQueue.isEmpty() on a non-empty queue. (false)" << endl;
  assert(pQueue.isEmpty() == 0);
  // Testing of GETTER getSize()
  cout << "10 Testing pQueue.getSize()" << endl;
  assert(pQueue.getSize() == 101);

  // Testing of SETTER dequeue(DataType& parameter)
  cout << "11 Testing pQueue.dequeue()" << endl;
  tempInt = pQueue.dequeue();
  cout << "LargestInt should have been removed (" << largestInt << ")." << endl;
  assert(largestInt == tempInt);
  // Testing of GETTER getSize()
  cout << "12 Testing pQueue.getSize(100)" << endl;
  assert(pQueue.getSize() == 100);

  cout << "Building an intArray[10] using dequeue" << endl;
  int intArray[10];
  for (int i = 0; i < 10; i++) intArray[i] = pQueue.dequeue();
  // Testing of GETTER getSize()
  cout << "13 Testing pQueue.getSize(100)" << endl;
  assert(pQueue.getSize() == 90);
  cout << "Array is in decending order: ";
  for (int i = 0; i < 9; i++) cout << intArray[i] << ", ";
  cout << intArray[9] << endl;
  cout << "Making sure that the value in the array is >= anything in the pQueue" << endl;
  for (int i = 0; i < 90; i++) assert(intArray[0] >= pQueue[i]);

  // Testing of SETTER makeEmpty()
  cout << "14 Testing pQueue.makeEmpty(). (expect \"ERROR\")" << endl;
  pQueue.makeEmpty();
  assert(pQueue.getSize() == 0);
  try { tempInt = pQueue.dequeue(); }
  catch (const char* ex) { cout << " Error found:" << ex << endl; }

  cout << "Destructor test:" << endl;
  {
    PriorityQueue<float> pQueue2(10);
  }

  cout << "Refiling list for use with copy testing" << endl;
  cout << "... and testing the dynamic resizing of the array." << endl << endl;
  for (int i = 0; i < 500; i++) pQueue.enqueue((rand() % randMax));
  assert(pQueue.getCapacity() == 512);

  // Copy testing of object with assignment upon declaration:
  {
    cout << "Copying object with assignment UPON declaration" << endl;
    PriorityQueue<int> copy = pQueue;

    cout << "1 Testing of GETTER isEmpty()" << endl;
    assert(copy.isEmpty() == 0);

    cout << "2 Testing of GETTER getSize()" << endl;
    assert(copy.getSize() == 500);
  } // end copy testing


  // Copy testing of object with assignment after declaration:
  {
  cout << "\nCopying object with assignment AFTER declaration" << endl;
  PriorityQueue<int> copy; copy = pQueue;

  cout << "1 Testing of GETTER copy.isEmpty()" << endl;
  assert(copy.isEmpty() == 0);

  cout << "2 Testing of GETTER getSize()" << endl;
  assert(copy.getSize() == 500);

  for (int i = 0; i < 500; i++) assert(copy[i] == pQueue[i]);
  }

  // Const object testing
  cout << "Copying const object with assignment upon declaration" << endl;
  const PriorityQueue<int> copy = pQueue;

  cout << "1 Testing of GETTER copy.isEmpty()" << endl;
  assert(copy.isEmpty() == 0);

  cout << "2 Testing of GETTER getSize()" << endl;
  assert(copy.getSize() == 500);

  cout << "Press ENTER to continue...";
  cin.get();
}