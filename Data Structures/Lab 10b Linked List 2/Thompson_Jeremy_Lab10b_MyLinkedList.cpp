// MyLinkedList.cpp : Defines the entry point for the console application.
//"Lab 10b, The \"MyLinkedList.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";


#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
using namespace std;

#define NODE

#include"Thompson_Jeremy_Lab10a_LinkedList.h"

static string buf;
LinkedList<int> getElements();
float calcAverage(LinkedList<int> averageNumbers);
void searchFor(LinkedList<int> ar);

int main()
{
  // print my name and this assignment's title
  cout << "Lab 10b, The \"MyLinkedList.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  LinkedList<int>numbers;

  numbers = getElements();

  LinkedList<int> numbersTwo = numbers;
  float average = calcAverage(numbersTwo);
  cout << "The average of the numbers is: " << average << endl;

  // Printing of the unsorted ist
  if (numbersTwo.length() <= 0)
    cout << endl << "The list is empty." << endl << endl;
  else
  {
    cout << endl << "The list is comprised of: " << numbersTwo[0];
    for (int i = 1; i < (numbersTwo.length()); i++)
    {
      cout << ", " << numbers[i];
    }
  } // end else statement

  cout << endl;

  searchFor(numbersTwo);
} // end of main

LinkedList<int> getElements()
{
  LinkedList<int> nums;
  int userInput = 0;
  cout << "Enter a positive integer: ";

  cin >> buf;
  cin.ignore(1000, 10);
  userInput = atoi(buf.c_str());

  do{
    nums.insert(userInput);

    cout << "Enter a positive integer (enter -1 to end:";
    cin >> buf;
    cin.ignore(1000, 10);
    userInput = atoi(buf.c_str());
  } while (userInput != -1);

  return nums;
} // end getElements()


float calcAverage(LinkedList<int> averageNumbers)
{
  int sum = 0;
  for (int i = 0; i < averageNumbers.length(); i++)
    sum += averageNumbers[i];

  return sum / float(averageNumbers.length());
} // end calcAverage()


void searchFor(LinkedList<int> ar)
{
  int number =0;

  while (number != -1)
  {
    cout << endl << "Enter a number to search for or -1 to stop:";

    cin >> buf;
    cin.ignore(1000, 10);
    number = atoi(buf.c_str());

    if (number == -1)
      cout << "Exiting program." << endl;
    else // if number != -1
    {
      if (ar.find(number))
        cout << "Number " << buf << " was found in list." << endl;
      else
        cout << "Entered number was not found." << endl;
    } // end else
  } // end while()
} // end searchFor()