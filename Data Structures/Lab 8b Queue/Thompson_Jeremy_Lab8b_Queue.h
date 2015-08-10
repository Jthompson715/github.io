// Queue.h : Defines the entry point for the console application.
//"Lab 8b, The \"Queue.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#ifndef QUEUE_H
#define QUEUE_H

template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};

template <class DataType>
class Queue
{
private:
  Node<DataType>* front;
  Node<DataType>* back;

public:
  Queue();
  ~Queue();
  bool isEmpty() const;
  void push(const DataType&);
  bool peek(DataType&)const;
  bool pop(DataType&);
  void makeEmpty();
  Queue(const Queue<DataType>& q);
  Queue<DataType>& operator=(const Queue<DataType>& q);

};

// default cotr
template <class DataType>
Queue<DataType>::Queue()
:front(0), back(0)
{
}

// destructor
template <class DataType>
Queue<DataType>::~Queue()
{
  Node<DataType>* p;
  while (front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}

template <class DataType>
bool Queue<DataType>::isEmpty() const
{
  return 0 == front;
}

template <class DataType>
void Queue<DataType>::push(const DataType& element)
{
  Node<DataType>* node = new Node<DataType>;
  node->data = element;
  node->next = 0;
  if (back)
    back->next = node;
  else
    front = node;
  back = node;
}

template <class DataType>
bool Queue<DataType>::peek(DataType& element) const
{
  if (0 == front)
    return false; // failure
  element = front->data;
    return true; // success
}

template <class DataType>
bool Queue<DataType>::pop(DataType& element)
{
  if (0 == front)
    return false; // failure
  element = front->data;
  Node<DataType>* p = front->next;
  delete front;
  front = p;
  if (front == 0) 
    back = 0;
  return true; // success
}

template <class DataType>
void Queue<DataType>::makeEmpty()
{
  back = 0;
  Node<DataType>* p;
  while (front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}

// copy cotr
template <class DataType>
Queue<DataType>::Queue(const Queue<DataType>& q)
: front(0), back(0)
{
  Node<DataType>* p;
  for (p = q.front; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (back) 
      back->next = node;
    else 
      front = node;
    back = node;
  }
}

template <class DataType>
Queue<DataType> & Queue<DataType>::operator=(const Queue<DataType>& q)
{
  if (this != &q)
  {
    Node<DataType>* p;

    // deallocate existing queue
    back = 0;
    while (front)
    {
      p = front->next
      delete front;
      front = p;
    }

    // create new queue
    for (p = q.front; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (back) 
        back->next = node;
      else 
        front = node;
      back = node;
    }
  }
  return *this;
}

#endif