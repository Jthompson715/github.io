// QueueDriver.cpp : Defines the entry point for the console application.
//"Lab 8b, The \"QueueDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include "Thompson_Jeremy_Lab8b_Queue.h"
#include "Thompson_Jeremy_Lab8b_Queue.h" //ifndef test
using namespace std;

int main()
{
    // print my name and this assignment's title
  cout << "Lab 8b, The \"QueueDriver.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  // create the queue
  Queue <int> myQueue;
  for (int i = 0; i < 12; i++)
  {
    myQueue.push(i);
  }
  int queuePeek;
  int queueCopy;
  int queuePop;
  // display queue contents
  cout << "The queue currently contains the following elements: " << endl;
  for (Queue<int> copy = myQueue; !copy.isEmpty(); copy.pop(queueCopy))
  {
    copy.peek(queuePeek);
    cout << queuePeek << " ";
  }

  if (myQueue.isEmpty() == true)
    cout << "\nThe isEmpty function IS NOT working as the queue is NOT empty." << endl;
  else
    cout << "\nThe isEmpty function IS working properly as the queue is NOT empty." << endl;

  if (myQueue.pop(queuePop) == true)
    cout << "The pop function IS working as there ARE elements in the queue." << endl;
  else
    cout << "The pop function IS NOT working as there ARE elements in the queue to pop." << endl;

  if (myQueue.peek(queuePeek) == true)
  {
    cout << "Expected 'peek' output is 1." << endl;
    cout << "Actual 'peek' output is: " << queuePeek << endl;
  }

  myQueue.makeEmpty();
  if (myQueue.isEmpty() == true)
    cout << "The makeEmpty function IS working as the queue is now empty." << endl;
  else
    cout << "The makeEmpty function IS NOT working as the queue is now empty." << endl;

  {
    Queue <int> myQueue1;
    for (int i = 0; i < 12; i++)
    {
      myQueue.push(i);
    }
    // object testing with assignment UPON declaration
    const Queue<int> copy = myQueue;

    cout << "\nObject copy test with assignment UPON declaration";

    if (copy.isEmpty() == true)
      cout << "\nThe isEmpty function IS NOT working as there are elements in the queue." << endl;
    else
      cout << "\nThe isEmpty function IS working as there are elements in the queue." << endl;

    int queuePeek;
    if (copy.peek(queuePeek) == true)
    {
      cout << "Expected 'peek' output is 0." << endl;
      cout << "Actual 'peek' output is: " << queuePeek << endl;
    }
  }
  // object testing with assignment AFTER declaration
  {
    Queue <int> myQueue1;
    for (int i = 0; i < 12; i++)
    {
      myQueue.push(i);
    }
    Queue<int> copy = myQueue;
    cout << "\nObject copy test with assignment AFTER declaration";

    if (copy.isEmpty() == true)
      cout << "\nThe isEmpty function IS NOT working as elements are in the queue." << endl;
    else
      cout << "\nThe isEmpty function IS working as there are elements in the queue." << endl;

    int queuePop;
    if (copy.pop(queuePop) == true)
      cout << "The pop function IS working as there are elements to pop." << endl;
    else  
      cout << "The pop function IS NOT working as there are elements to pop." << endl;

    if (copy.peek(queuePop) == true)
    {
      cout << "Expected 'peek' output is 1." << endl;
      cout << "Actual 'peek' output is: " << queuePeek << endl;
    }

    copy.makeEmpty();
    if (copy.isEmpty() == true)
      cout << "The makeEmpty function IS working as the queue is now empty." << endl;
    else
      cout << "The makeEmpty function IS NOT working as the queue is now empty." << endl;
  }
  cout << "\nPress ENTER to continue...";
  cin.get();
}