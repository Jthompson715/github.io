// LinkedList.h : Defines the entry point for the console application.
//"Lab 10a, The \"LinkedList.h \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#ifdef NODE
//#ifndef NODE
//#define NODE
template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};
#endif

template <class DataType>
class LinkedList
{
  int size;
  int currentIndex;

  Node<DataType>* front;
  Node<DataType>* current;

public:
  LinkedList() : front(0), current(0) { currentIndex = -1; size = 0; } //  ctor
  ~LinkedList(); // dotr
  LinkedList(const LinkedList<DataType> & listCopy); // copy cotr
  LinkedList<DataType>& operator=(const LinkedList<DataType>& listCopy); // overloaded assignment operator

  // setters
  void insert(const DataType& parameter); // add to front of list
  void makeEmpty(); // empty the list
  bool remove(DataType& parameter); // find, retrieve, and delete matching element
  bool replace(const DataType& parameter); // replace last-found element
  bool find(const DataType& parameter); // true if matching element found
  bool first(DataType& parameter); // retrieve first element
  bool getNext(DataType& parameter); // retrieve next element. Increment "current", store "current" in "parameter".
  bool retrieve(DataType& parameter); // find and retrieve matching element

  // getters
  bool isEmpty() const{ return front == 0; } // return true if list is empty. // 0(1)
  int length() const{ return size; } // returns size of list
  DataType& operator[] (int index); // operator []
};

template <class DataType>
LinkedList<DataType>::~LinkedList() // dotr
{
  Node<DataType>* p;

  while (front)
  {
    p = front->next;
    delete front;
    front = p;
  }
} // end dotr

template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType> & listCopy) // copy cotr
:front(0), current(0)
{
  size = listCopy.size;
  currentIndex = listCopy.currentIndex;

  Node<DataType>* p;
  Node<DataType>* end = 0;
  for (p = listCopy.front; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end)
      end->next = node;
    else
      front = node;
    end = node;

    if (p == listCopy.current) current = node;
  }
} // end copy cotr

template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& listCopy) // overloaded operator=
{
  if (this != &listCopy)
  {
    size = listCopy.size;
    currentIndex = listCopy.currentIndex;
    current = 0;

    Node<DataType>* p;
    Node<DataType>* end = 0;

    while (front)
    {
      p = front->next;
      delete front;
      front = p;
    }

    for (p = listCopy.front; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end)
        end->next = node;
      else
        front = node;
      end = node;

      if (p == listCopy.current) current = node;
    }
  }
  return *this;
} // end overloaded assignment operator

template <class DataType>
void LinkedList <DataType>::insert(const DataType& parameter) // 0(1)
{
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = front;
  front = node;
  current = front;
  currentIndex = 0;
  size++;
} // end insert()

template <class DataType>
void LinkedList<DataType>::makeEmpty()
{
  currentIndex = -1;
  size = 0;
  while (front)
  {
    current = front->next;
    delete front;
    front = current;
  }
} // end makeEmpty()

template <class DataType>
bool LinkedList<DataType>::remove(DataType& parameter)
{
  // find node
  Node<DataType>* p;
  Node<DataType>* prev;
  for (prev = 0, p = front; p; prev = p, p = p->next)
  {
    if (p->data == parameter)
      break;
  }

  // deallocate node here
  if (!p)
    return false; // no match found
  if (prev)
    prev->next = p->next;
  else
    front = p->next;
  if (p == current) current = current->next;
  parameter = p->data;
  delete p;
  size--; // decrement size
  return true;
} // end remove()

template <class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter)
{
  if (!current) return false;
  current->data = parameter;
  return true;
} // end replace()

template <class DataType>
bool LinkedList<DataType>::find(const DataType& parameter) // O(n)
{
  Node<DataType>* restoreCurrent = current; // restore current to its previous location after search
  int restoreIndex = currentIndex; // restore index position after search

  DataType temp;
  if (first(temp))do
  {
    if (parameter == temp) return true; // found element
  } while (getNext(temp));

  // restore previous current values if no match found
  current = restoreCurrent;
  currentIndex = restoreIndex;

  return false; // no matches found
} // end find()

template <class DataType>
bool LinkedList<DataType>::first(DataType& parameter) // 0(1)
{
  if (!front) return false;
  parameter = front->data;
  current = front;
  currentIndex = 0;
  return true;
} // end first()

template <class DataType>
bool LinkedList<DataType>::getNext(DataType& parameter) // 0(1)
{
  if (!current) return false;
  if (!current->next) return false;

  current = current->next;
  currentIndex++;

  parameter = current->data;
  return true;
} // end getNext()

template <class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter) //O(n)
{
  if (!find(parameter)) return false;
  parameter = current->data; // is set in find
  return true;
} // end retrieve()

template <class DataType>
DataType& LinkedList<DataType>::operator[] (int index)
{
  int element = index;
  Node<DataType>* p;
  if (element  < 0 || element >= size) // if index is out of bounds, return dummy
  {
    Node<DataType>* dummy = new Node<DataType>;
    p = dummy;
    delete dummy;
    throw "In operator[]: index is out of bounds.";
    return p->data;
  }

  if (element >= currentIndex) // if true, start search from current index instead of front
  {
    element -= currentIndex;

    for (p = current; p; p = p->next) // iterate through list
    {
      if (element == 0) return p->data; // after element has dec'd to 0; return the data
      element--; // dec element until == 0
    }
  }

  for (p = front; p; p = p->next) // iterate through the list
  {
    if (element == 0) return p->data; // once element has dec'd to 0, return the data
    element--;
  }

  throw "Error in operator[] - reached the end of the function.";
}// end operator []

#endif