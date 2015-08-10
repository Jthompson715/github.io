// MySortableArray.cpp : Defines the entry point for the console application.
//"Lab 14a, The \"MySortableArray.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include "Thompson_Jeremy_Lab14a_SortableArray.h"
#include "Thompson_Jeremy_Lab14a_SortableArray.h" //ifndef

// Function ProtoTypes
static string buf; // input
SortableArray<int> getElements();
float calcAverage(SortableArray<int> avnums);
void searchFor(const SortableArray<int>& ar);
void bSearchFor(const SortableArray<int>& ar);
void print(SortableArray<int>& nums);

int main()
{
  // print my name and this assignment's title
  cout << "Lab 14a, The \"MySortableArray\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // variable declaration
  SortableArray<int> nums(2);

  nums = getElements();
  cout << endl;
  print(nums);
  float average = calcAverage(nums);
  cout << " The average is:" << average << "." << endl;

  searchFor(nums);

  // sort section
  cout << "Enter up to the index you wish to sort to. Pressing ENTER w/o any numbers";
  cout << " inputted will default to sorting all numbers in the array." << endl;

  buf = "0"; // clear the string buffer
  getline(cin, buf);
  int userInput = atoi(buf.c_str());
  cout << endl;

  if (!userInput) nums.sort(); // default sort if nothing entered
  else nums.sort(userInput); // else use the supplied quantity

  for (int i = 0; i < userInput - 1; i++) assert(nums[i] <= nums[i + 1]); // resizing check

  print(nums);
  bSearchFor(nums); // binary search call
  cout << endl;
} // end main()

// functions
SortableArray<int> getElements()
{
  SortableArray<int> numbers(2);
  int i = 0;
  cout << "Enter a positive integer or -1 for 255 random numbers:";

  cin >> buf; cin.ignore(1000, 10); 
  int userInput = atoi(buf.c_str());

  if (userInput == -1)
  {
    i = 255;
    srand(time(0)); // initialize random seed
    int prime = rand(); // call rand once to prime the sequence
    numbers.changeSize(i);

    for (int j = 0; j < i; j++) numbers[j] = (int)(rand() % (999 + 1));
  } // end if

  else
  {
    numbers[i] = userInput;

    while (numbers[i] != -1)
    {
      i++;
      if (i == numbers.length()) numbers.changeSize(i * 2);

      cout << "Enter a positive integer or -1 to stop: ";
      cin >> buf; cin.ignore(1000, 10); 
      numbers[i] = atoi(buf.c_str());
    } // end while()

    numbers.changeSize(i);
  } // end else

  return numbers;
} // end getElements()

float calcAverage(SortableArray<int> avnums)
{
  int sum = 0;
  for (int i = 0; i < avnums.length(); i++) sum += avnums[i];

  return sum / float(avnums.length());
} // end calcAverage()

void searchFor(const SortableArray<int>& ar)
{
  bool sentinel = 0;
  int result;
  int number;

  while (sentinel == 0)
  {
    cout << endl << "Enter an integer to search for in the SortableArray or -1 to stop: ";

    cin >> buf; cin.ignore(1000, 10);
    number = atoi(buf.c_str());

    if (number == -1)
    {
      cout << "Ending search function." << endl;
      sentinel = 1;
    } // end if sentinel

    else // if number != -1
    {
      result = ar.lsearch(number); // store index of found number in result
      if (result < 0) cout << " Number not found." << endl;
      else cout << "Value " << number << " found at index " << result << "." << endl;
    } // end else
  } // end while
} // end searchFor()

void print(SortableArray<int>& nums)
{
  // prints the unsorted list, on a single line
  if (nums.length() <= 0) cout << "The array is empty." << endl;
  else
  {
    cout << "The array currently holds: " << endl << nums[0];
    for (int i = 1; i < (nums.length()); i++) cout << ", " << nums[i];
  } // end else
  cout << endl;
} // end print()

void bSearchFor(const SortableArray<int>& ar)
{
  bool sentinel = 0;
  int result;
  int number;

  while (sentinel == 0)
  {
    cout << endl << "Enter a number to binary-search the array for or -1 to stop: ";
    cin >> buf; cin.ignore(1000, 10);
    number = atoi(buf.c_str());

    if (number == -1)
    {
      cout << "Exiting the search function." << endl;
      sentinel = 1;
    } // end if sentinel

    else // if number != -1
    {
      result = ar.bsearch(number); //store index value of found number
      if (result < 0) cout << "Number was not found." << endl;
      else cout << "Value  " << number << " found at index " << result << "." << endl;
    } // end else
  } // end while
} // end searchFor()

