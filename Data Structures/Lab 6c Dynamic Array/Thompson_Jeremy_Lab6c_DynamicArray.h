//"Lab 6c, The \"DynamicArray.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#ifndef DynamicArray_h
#define DynamicArray_h

template <class DataType>
class DynamicArray
{
  DataType* data;
  int capacity;
public:
  DynamicArray(int initialCapacity);
  ~DynamicArray();                                                    // destructor
  void changeCapacity(int newCapacity);
  int getCapacity()const{ return capacity; }
  DynamicArray(const DynamicArray<DataType>& a);                      // copy constructor
  DynamicArray<DataType>& operator=(const DynamicArray<DataType>& a); // assignment operator
  int lsearch(const DataType& value) const;

  DataType & operator[](int index); //rw
  DataType const & operator[](int index)const; //r
};
// constructor
template <class DataType>
DynamicArray<DataType>::DynamicArray(int initialCapacity)
{
  capacity = initialCapacity;

  if (capacity <= 0)
    data = 0;
  else
    data = new DataType[capacity];
}
// destructor
template <class DataType>
DynamicArray<DataType>::~DynamicArray()
{
  delete[] data;
}

template <class DataType>
void DynamicArray<DataType>::changeCapacity(int newCapacity)
{
  if (newCapacity <= 0)
  {
    delete[] data;
    data = 0;
    capacity = newCapacity;
  }
  else
  {
    DataType* newData =
      new DataType[newCapacity];
    int limit = newCapacity > capacity ?
    capacity : newCapacity;
    for (int i = 0; i < limit; i++)
      newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCapacity;
  }
}
// copy constructor
template <class DataType>
DynamicArray<DataType>::DynamicArray(const DynamicArray<DataType>& a)
{
  capacity = a.capacity;
  data = 0;

  if (capacity > 0)
  {
    data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
}
// overloaded assignment operator
template <class DataType>
DynamicArray<DataType>& DynamicArray<DataType>::operator=(const DynamicArray<DataType>& a)
{
  if (this == &a)
    return *this;

  delete[] data;
  capacity = a.capacity;
  data = 0;

  if (capacity > 0)
  {
    data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
  return *this;
}
// search function
template <class DataType>
int DynamicArray <DataType>::lsearch(const DataType& value) const
{
  int result = -1; // not found

  for (int i = 0; i < capacity; i++)
  {
    if (value == data[i])
    {
      result = i;
      break;
    }
  }

  return result;

}
template <class DataType>
DataType & DynamicArray<DataType>::operator[](int index)
{
  // check index in range
  // if is, return
  return data[index];
}
template <class DataType>
DataType const & DynamicArray<DataType>::operator[](int index)const //r
{
  return data[index];
}

#endif