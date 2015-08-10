//"Lab 5a, The \"StaticArray.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#ifndef StaticArray_h
#define StaticArray_h

#include <string>

template<class DataType, int CAPACITY>
class StaticArray
{
  DataType dummy;
  DataType data[CAPACITY]; // denotes a static array

public:
  StaticArray(); // default constructor
  DataType& operator[](int index);
  int getCapacity() const;
  int lsearch(const DataType& value) const; // search prototype
};
// default constructor
template <class DataType, int CAPACITY>
StaticArray<DataType, CAPACITY>::StaticArray()
{
}
// capacity getter
template <class DataType, int CAPACITY>
int StaticArray<DataType, CAPACITY>::getCapacity() const
{
  return CAPACITY;
}

template <class DataType, int CAPACITY>
DataType& StaticArray<DataType, CAPACITY>::operator[](int index)
{
  if (index < 0)
    return dummy;
  if (index >= CAPACITY)
    return dummy;
  return data[index];
}
// search function
template <class DataType, int CAPACITY>
int StaticArray<DataType, CAPACITY>::lsearch(const DataType& value) const
{
  int result = -1; // not found

  for (int i = 0; i < CAPACITY; i++)
  {
    if (value == data[i])
    {
      result = i;
      break;
    }
  }
  return result;
}
#endif