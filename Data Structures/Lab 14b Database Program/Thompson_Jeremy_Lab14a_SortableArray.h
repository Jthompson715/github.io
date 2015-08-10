// SortableArray.cpp : Defines the entry point for the console application.
//"Lab 14a, The \"SortableArray.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <string>
using namespace std;

#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H

// Error Codes
// 0 = No error.
// 1 = Nonpositive size passed into cotr.
// 2 = Invalid index was used.
// 3 = Nonpositive new size passed into changeSize().

template <class DataType>
class SortableArray
{
public:
  SortableArray(int size); // cotr
  DataType& operator[](int index){ return elements[index]; }
  void changeSize(int newSize); // will only change values if newSize is smaller than current
  int length() const { return capacity; } // returns current capacity of array
  string err() const; // returns error messages 
  int lsearch(const DataType& data, int e = -1) const; // linear search
  int bsearch(const DataType& data, int e = -1) const; // binary search

  void sort(int e = -1);

  SortableArray(const SortableArray<DataType>& actualParameter); // copy cotr
  ~SortableArray(); // dotr
  SortableArray<DataType>& operator=(const SortableArray<DataType>& right); // overloaded assignment operator

private:
  int capacity;
  DataType dud; // returned from operator[] if index error occurs
  int errorCode; // contains code for error if array misuse occurs
  DataType *elements; // points to dynamic array

  // Private member functions
  void deepCopy(const SortableArray<DataType>& original) // pass-by-value and can throw exceptions if not enough heap memory
  {
    capacity = original.capacity;
    errorCode = original.errorCode;
    elements = new DataType[capacity];
    for (int i = 0; i < capacity; i++) elements[i] = original.elements[i];
  } // end deepCopy()

  void heapInsert(DataType insertThis, int s, int e) // "a" = DataType array; "insertThis" = DataType value; "s" = starting index; "e" = ending index
  {
    int i = s;
    while (true)
    {
      // indexes i's children for heap starting with s
      int iLeft = 2 * i + 1; // left-side child if present
      int iRight = 2 * i + 2; // right-side child if present
      if (iLeft > e) // if i is sterile
      {
        elements[i] = insertThis;
        break;
      }

      else if (iLeft == e) // if i has one child
      {
        if (insertThis < elements[iLeft]) // promote the only child
        {
          elements[i] = elements[iLeft];
          elements[iLeft] = insertThis;
        }

        else elements[i] = insertThis; // insert ahead of lesser child
        break;
      }

      else if (elements[iLeft] < insertThis && elements[iRight] < insertThis)
      {
        elements[i] = insertThis; // reinsert above lesser children
        break;
      }

      else if (elements[iLeft] < elements[iRight]) // figure out which to promote
      {
        elements[i] = elements[iRight]; // promote child
        i = iRight;
      }

      else
      {
        elements[i] = elements[iLeft]; // promote child
        i = iLeft;
      }
    } // end while()
  } // end heapInsert()

  DataType bsearch2(const DataType* a, const int & value, int s, int e) const // e = DataType[], value = key, s = startIndex, e = endIndex
  {
    int m = (s + e) / 2; // middle element

    if (value == a[m]) return m; // got lucky -- return index of found element (matches)

    else if (s == e) return -1; // only element in 1-element array did not match

    else if (value < a[m]) // look between s and m-1
    {
      if (s == m)return -1; // but that range if empty; no match
      else return bsearch2(a, value, s, m - 1); // look in s to m-1
    }

    else // look between m+1 and e
    {
      if (m == e)return -1; // but range if empty; no match
      else return bsearch2(a, value, m + 1, e); // look m-1 to e
    }
  } // end bsearch2()
}; // end sortableArray class

template <class DataType>
SortableArray<DataType>::SortableArray(int size)
:capacity((size < 1) ? 1 : size), errorCode((size < 1) ? 1 : 0), elements(new DataType[capacity])
{
  // empty cotr body since initializer list handles the assignments
}

template <class DataType>
SortableArray<DataType>::SortableArray(const SortableArray<DataType>& actualParameter) { deepCopy(actualParameter); }

template <class DataType>
SortableArray<DataType>::~SortableArray() { delete[] elements; }

template <class DataType>
SortableArray<DataType>& SortableArray<DataType>::operator=(const SortableArray<DataType> & right)
{
  if (this == &right) return *this;
  delete[] elements;
  deepCopy(right);
  return *this;
} // end operator =

template <class DataType>
void SortableArray<DataType>::changeSize(int newSize)
{
  if (newSize < 1)
  {
    errorCode |= 3; // nonpositive new size
    return;
  }

  DataType *newArray = new DataType[newSize];

  int limit = (newSize > capacity) ? capacity : newSize;

  for (int i = 0; i < limit; i++)
    newArray[i] = elements[i];

  delete[] elements;
  elements = newArray;
  capacity = newSize;
} // end changeSize()

template <class DataType>
string SortableArray<DataType>::err() const
{
  if (errorCode == 0)
    return "No error.\n";
  string errorMessage = "";
  if (errorCode & 1) // nonpositive size
  {
    errorMessage += "Nonpositive size was passed into the cotr\n";
    errorMessage += "so the capacity was set to 1 by default.\n";
  }

  if (errorCode & 2) // invalid index
  {
    errorMessage += "Index is out of range.\n";
  }

  if (errorCode & 3) // nonpositive new size in changeSize()
  {
    errorMessage += "Nonpositive size passed into changeSize()\n";
    errorMessage += "The size of the array was not changed.\n";
  }

  return errorMessage;
}

template <class DataType>
int SortableArray<DataType>::lsearch(const DataType& data, int e) const // linear search
{
  if (e == -1)e = capacity; // sorts entire array if called for, otherwise uses e
  e--; // decrement to e to change syntax to location

  int result = -1; // set default to -1 in case no match is found
  for (int i = 0; i <= e; i++)
  {
    if (elements[i] == data) result = i;
  }
  return result;
} // end lsearch()

template <class DataType>
int SortableArray<DataType>::bsearch(const DataType& data, int e) const // binary search
{
  // array must be sorted prior to calling a binary search
  if (e == -1) e = capacity; // sorts entire array if called for, otherwise uses e
  e--; // decrement to e to change syntax to location

  int result = bsearch2(elements, data, 0, e); // recursive function to return index of search data
  return result;
} // end bsearch()

template <class DataType>
void SortableArray<DataType>::sort(int e)
{
  if (e == -1) e = capacity; // sorts entire array if called for, otherwise uses e
  e--; // decrement to e to change syntax to location

  int s;
  for (s = (e + 1) / 2 - 1; s >= 0; s--)
  {
    DataType removed = elements[s];
    heapInsert(removed, s, e);
  }

  // sorting
  e++; // restores e to capacity
  for (s = 0; s < e; s++)
  {
    int c = e - s - 1;
    DataType removed = elements[c];
    elements[c] = elements[0];
    heapInsert(removed, 0, c - 1);
  } // end for()
} // end sort()

#endif