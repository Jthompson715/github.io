//"Lab 12a, The \"Calculator8.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

using namespace std;

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <class DataType>
class PriorityQueue
{
private:
  int capacity;
  DataType *elements; // pointer to dynamic PriorityQueue array
  int index;
  int size;

  void doubleCapacity() // doubles capacity and builds a new array
  {
    capacity = capacity * 2; // double capacity
    DataType* newElements = new DataType[capacity];
    for (int i = 0; i < size; i++) newElements[i] = elements[i]; // copy array
    delete[] elements;
    elements = newElements;
  } // end doubleCapacity()

  void halveCapacity()
  {
    capacity = capacity / 2; // halve capacity
    DataType* newElements = new DataType[capacity];
    for (int i = 0; i < size; i++) newElements[i] = elements[i]; // copy array
    delete[] elements;
    elements = newElements;
  } // end halveCapacity()

public:
  PriorityQueue() : capacity(2), elements(new DataType[capacity]), index(0), size(0) {}; // default cotr
  PriorityQueue(int initCapacity); // cotr
  ~PriorityQueue(); // dotr
  PriorityQueue(const PriorityQueue<DataType>& actualParameter); // copy cotr
  PriorityQueue<DataType>& operator=(const PriorityQueue<DataType>& right); // overloaded operator=
  bool operator< (const DataType& leftDT);
  DataType& operator[](int index) { return elements[index]; }

  // setters
  void enqueue(DataType val); // add a data item to the queue
  DataType dequeue(); // remove maximum data item and requires operator <
  void makeEmpty();

  // getters
  bool isEmpty() const{ if (size == 0) return true; return false; }
  int getSize() const { return size; } // get current size of array
  int getCapacity() const { return capacity; } // gets current capacity of array
}; // end class PriorityQueue

template <class DataType>
PriorityQueue<DataType>::PriorityQueue(int initCapacity) // cotr
:capacity((initCapacity < 1) ? 1 : initCapacity), elements(new DataType[capacity]), index(0), size(0)
{
  // empty body
} // end cotr

template <class DataType>
PriorityQueue<DataType>::~PriorityQueue() // dotr
{
  delete[] elements;
} // end dotr

template <class DataType>
PriorityQueue<DataType>::PriorityQueue(const PriorityQueue<DataType>& original) // copy cotr

  : capacity(original.capacity), elements(new DataType[capacity]), index(original.index), size(original.size)
{
  for (int i = 0; i < capacity; i++) elements[i] = original.elements[i]; // copys array
} // end copy cotr

template <class DataType>
PriorityQueue<DataType>& PriorityQueue<DataType>::operator=(const PriorityQueue<DataType>& right) // overloaded operator=
{
  if (this == &right) return *this;

  delete[] elements; // delete original elements in case right.elements < elements

  capacity = right.capacity;
  index = right.index;
  size = right.size;

  elements = new DataType[capacity];
  for (int i = 0; i < capacity; i++)
  {
    elements[i] = right.elements[i];
  } // end copy array
  return *this;
} // end operator=

template <class DataType>
bool PriorityQueue<DataType>::operator< (const DataType& leftDT)
{
  if (elements[0] < leftDT.elements[0]) return true;
  return false;
} // end operator<

// setters
template <class DataType>
void PriorityQueue<DataType>::enqueue(DataType val) // add a data item to the queue
{
  index = size; 
  if (index >= capacity) doubleCapacity(); // doubles capacity if needed

  elements[index] = val; // copy new value into array at index

  // begining of loop
  int parentIndex = (index + 1) / 2 - 1;

  if (parentIndex < 0) size++;
  else if (elements[parentIndex] >= elements[index]) size++;
  else
  {
    DataType temp;
    do // start the loop
    {
      // swap values at parentIndex and index
      temp = elements[index];
      elements[index] = elements[parentIndex];
      elements[parentIndex] = temp;

      index = parentIndex;

      // parentIndex = (((index+1) /2) -1)
      parentIndex = (index + 1) / 2 - 1;

      if (parentIndex < 0) break;
 
    } while (elements[parentIndex] < elements[index]); // repeat to top of while loop
    size++;
  } // end else
} // end enqueue()

template <class DataType>
DataType PriorityQueue<DataType>::dequeue() // remove maximum data item and requires operator <
{
  DataType toReturn = elements[0]; // save vaue at index 0 to return at end
  index = 0; // set index to zero
  int leftChildIndex;
  int rightChildIndex;
  int parentIndex;
  DataType temp;

  if (size == 0)
  {
    throw "PriorityQueue is empty, and thusly will not return a value.";
  } // end if(size == 0)

  do{
    leftChildIndex = (2 * index + 1); // index of left child
    rightChildIndex = (2 * index + 2); // index of right child

    if (leftChildIndex >= size) break;

    if (leftChildIndex == (size - 1) || elements[leftChildIndex] >= elements[rightChildIndex])
    {
      elements[index] = elements[leftChildIndex]; // sets index value to left child value
      index = leftChildIndex; // set index = index of left child
    } // end if

    else
    {
      elements[index] = elements[rightChildIndex]; // sets index value to right child value
      index = rightChildIndex; // set index = index of right child
    }
  } while (size); // repeats loop
  size--;

  if (size < (capacity / 4))
  {
    halveCapacity();
  } // end if (cap/4)

  elements[index] = elements[size]; // copy value at size into array of index

  do{ // start loop
    parentIndex = (index + 1) / 2 - 1;
    if (parentIndex < 0) break;
    if (elements[parentIndex] >= elements[index]) break;

    // swap parentIndex and index values
    temp = elements[index];
    elements[index] = elements[parentIndex];
    elements[parentIndex] = temp;

    index = parentIndex; // sets index = parentIndex
  } while (size); // repeat to top of while loop

  return toReturn; // returns the saved value
}// end dequeue

template <class DataType>
void PriorityQueue<DataType>::makeEmpty()
{
  DataType* newElements = new DataType[capacity];
  delete[] elements;
  elements = newElements;
  size=0;
  index=0;
} // end makeEmpty()

#endif