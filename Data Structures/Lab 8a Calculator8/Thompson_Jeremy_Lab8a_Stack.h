//"Lab 8a, The \"Calculator8.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class DataType>
class Stack
{
private:
  DataType* data;
  int capacity;
  int top; // track newest value

public:
  Stack(); // default cotr
  Stack(const Stack<DataType>& a); // copy cotr
  ~Stack(); // destructor
  bool isEmpty() const; // const since nothing changes
  void push(const DataType&); // add element
  bool peek(DataType&) const; // look at element
  bool pop(DataType&); // remove element
  void makeEmpty();
  Stack<DataType>& operator=(const Stack<DataType>& a);
  int stackSize();

};
template<class DataType>
int Stack<DataType>::stackSize() { return top; }

// destructor
template <class DataType>
Stack<DataType>::~Stack()
{
  delete[] data;
}
// copy cotr
template <class DataType>
Stack<DataType>::Stack(const Stack<DataType>& a)
: capacity(a.capacity), data(0), top(a.top)
{
  if (capacity > 0)
    data = new DataType[capacity];
  for (int i = 0; i < capacity; i++)
    data[i] = a.data[i];
}
// operator =
template <class DataType>
Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& a)
{
  if (this != &a)
  {
    delete[] data;
    data = 0;
    capacity = a.capacity;
    if (capacity > 0)
      data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
    top = a.top;
  }
  return *this;
}

// default cotr
template <class DataType>
Stack<DataType>::Stack()
: capacity(2), data(new DataType[2]), top(-1){}

template <class DataType>
bool Stack<DataType>::isEmpty() const 
{
  return -1 == top; 
}

// add element
template <class DataType>
void Stack<DataType>::push(const DataType& parameter)
{
  if (++top == capacity)
  {
    DataType *tempPtr = new DataType[2 * capacity];
    for (int i = 0; i < capacity; i++)
      tempPtr[i] = data[i];
    delete[]data;
    data = tempPtr;
    capacity *= 2;
  }
    data[top] = parameter;
}

template <class DataType>
bool Stack<DataType>::peek(DataType& parameter) const
{
  if (-1 == top) return false; // failed
  parameter = data[top];
  return true; // success
}

template <class DataType>
bool Stack<DataType>::pop(DataType& parameter)
{
  if (-1 == top) return false; // failed
  parameter = data[top--];
  if (top > 2 && top < capacity / 4) 
  {//halve the capacity
    DataType *tempPtr = new DataType[capacity / 2];
    for (int i = 0; i <= top; i++)
      tempPtr[i] = data[i];
    delete[]data;
    data = tempPtr;
    capacity = capacity / 2;
  }
    return true; // success
}

template <class DataType>
void Stack<DataType>::makeEmpty() 
{
  top = -1; 
}

#endif