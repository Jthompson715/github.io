

#include <algorithm>
#include <iterator>
#include <list>

using namespace std;
#ifndef HASHTABLE_H
#define HASHTABLE_H

template <class DataType, int CAP>
class HashTable
{
private:
  const static int CAPACITY = CAP;
  typename list<DataType>::iterator currentIT; // non-const iterator used in replace, remove, insert
  int current; // iterator variable; set = -1 for NULL
  int numCollisions;
  int tableSize; // table size, up to capacity 1009
  int collisionLocations[(int)(CAP*.2)]; 
  list<DataType> data[CAP]; // data variable for chanined hash table

public:
  // Constructors and memory management
  HashTable() : current(-1), numCollisions(0), tableSize(0) {} // cotr
  ~HashTable() { for (int i = 0; i < CAP; i++) data[i].clear(); } // dotr: clears contents of list
  HashTable(const HashTable<DataType, CAP> & lCopy); // copy cotr
  HashTable<DataType, CAP> & operator=(const HashTable <DataType, CAP> & lCopy); // overloaded operator =

  // setters
  bool insert(const DataType& parameter); // bool allows for duplicate check
  bool remove(DataType& parameter); // find, retrieve, and delete matching element
  bool replace(const DataType& parameter); // replace last-found element
  void clear(); // reinitialize tracking variable

  // getters
  int getCurrent(){ return current; }
  bool isEmpty() const{ if (tableSize == 0)return true; return false; } // returns bool opposite of tableSize
  int size() const { return tableSize; } 
  int getCapacity() const{ return CAP; }
  bool retrieve(DataType& parameter) const;
  int getNumCollisions() const{ return numCollisions; }
  bool first(DataType& parameter); // get first element in array and list
  bool getNext(DataType& parameter); // get next element in array and list
}; // end Hashable Class

template <class DataType, int CAP>
HashTable<DataType, CAP>::HashTable(const HashTable<DataType, CAP>& lCopy)
: currentIT(lCopy.currentIT), current(lCopy.current), numCollisions(lCopy.numCollisions), tableSize(lCopy.tableSize) // copy ctor
{
  for (int i = 0; i < ((int)(CAP*.2)); i++) collisionLocations[i] = lCopy.collisionLocations[i]; // deep copy of array
  for (int i = 0; i < CAP; i++) data[i] = lCopy.data[i]; // deep copy of array of lists
} // end copy cotr

template <class DataType, int CAP>
HashTable<DataType, CAP>& HashTable<DataType, CAP>::operator=(const HashTable<DataType, CAP>& lCopy) // overloaded operator=
{
  if (this != &lCopy)
  {
    tableSize = lCopy.tableSize;
    numCollisions = lCopy.numCollisions;
    current = lCopy.current;
    currentIT = lCopy.currentIT;

    for (int i = 0; i < CAP; i++)
    {
      data[i].clear(); // clear existing data
      data[i] = lCopy.data[i]; // deep copy of array of lists
    } // end for of copy data

    for (int i = 0; i < ((int)(CAP*.2)); i++)
    {
      collisionLocations[i] = lCopy.collisionLocations[i]; // deep copy of array of lists
    } // end for (copy collisionLocations)
  } // end if(this != &lCopy
  return *this;
} // end operator=

// ***SETTERS AND GETTERS***
template <class DataType, int CAP>
bool HashTable<DataType, CAP>::insert(const DataType& parameter)
{
  int elementLoc = parameter.hashCode() % CAPACITY;
  if (elementLoc < 0) elementLoc += CAPACITY;
  current = elementLoc; // sets current variable to this location for query

  // ***DEBUG***
#ifdef DEBUG_HASHTABLE
  {
    // hash table size checking
    if(tableSize >= 800) thow "Table size in \"insert\" function is  > 800;
  }
#endif
  // ***END DEBUG***
  //typename list<DataType>::iterator currentIT; // non-const iterator used in replace, remove, insert
  currentIT = find(data[elementLoc].begin(), data[elementLoc].end(), parameter); // search for parameter in data[elementLoc]

  if (currentIT != data[elementLoc].end()) // if parameter is found in list, meaning its a duplicate
  {
    *currentIT = parameter; // replace
    current = -1;
    return false; // duplicate was found
  } // end if for duplicate

  if (!data[elementLoc].empty()) // if location is not empty
  {
    collisionLocations[numCollisions] = elementLoc; // store the location of collision
    numCollisions++;
  } // end if(not empty)

  data[elementLoc].push_back(parameter);
  ++tableSize; // push parameter to end of list
  return true;
} // end insert()

template <class DataType, int CAP>
bool HashTable<DataType, CAP>::first(DataType& parameter)
{
  assert(current >= -1 && current < this->CAPACITY);
  for (current = 0; current < CAP; current++)
  if (!data[current].empty()) break; // break if location in data[] is not empty

  if (current == CAP) current = -1;
  else parameter = data[current].front(); // sets parameter to found data item
  return (current >= 0);
}

template <class DataType, int CAP>
bool HashTable<DataType, CAP>::getNext(DataType& parameter)
{
  assert(current >= -1 && current < this->CAPACITY);
  if (current == -1) return false; // no data
  for (; current < CAP; current++)
  if (!data[current].empty()) break; // break if location in data[] is not empty

  if (current == CAP) current = -1;
  else parameter = data[current].front(); // sets parameter to found data item
  return (current >= 0);
}

template <class DataType, int CAP>
bool HashTable<DataType, CAP>::remove(DataType& parameter) // find, retrieve, and delete matching element
{
  int elementLoc = parameter.hashCode();
  elementLoc = elementLoc % CAP; // desired index
  current = elementLoc; // set current variable to this location

  // typename list<DataType>::iterator it; // non-const iterator to be used in replace, remove, and insert
  currentIT = find(data[elementLoc].begin(), data[elementLoc].end(), parameter);
  if (currentIT == data[elementLoc].end()) return false;

  // else, *currentIT is the matching element
  parameter = *currentIT;
  data[elementLoc].erase(currentIT); // remove element
  --tableSize;
  return true;
} // remove()

template <class DataType, int CAP>
bool HashTable<DataType, CAP>::replace(const DataType& parameter) // replace last-found element
{
  int elementLoc = parameter.hashCode();
  elementLoc = elementLoc % CAP; // desired index
  current = elementLoc; // set current iteraton var to this location

  //  typename list<DataType>::iterator it; // non-const iterator to be used in replace, remove, and insert
  currentIT = find(data[elementLoc].begin(), data[elementLoc].end(), parameter);
  if (currentIT == data[elementLoc].end()) return false;

  // else, *currentIt is the matching element
  *currentIT = parameter;
  return true;
} // end replace()

template <class DataType, int CAP>
bool HashTable<DataType, CAP>::retrieve(DataType& parameter) const // find and retrieve matching element
{
  int elementLoc = parameter.hashCode() % CAPACITY;
  if (elementLoc < 0) elementLoc += CAPACITY;

  int listSize = data[elementLoc].size();
  if (listSize == 0 ) return false;

  typename list<DataType>::const_iterator it; // const_iterator for retrieve
  it = find(data[elementLoc].begin(), data[elementLoc].end(), parameter);

  if (it == data[elementLoc].end()) return false;

  // else, *it is the matching element
  parameter = *it; // retrieve parameter at *it
  return true;
} // retrieve()

template <class DataType, int CAP>
void HashTable<DataType, CAP>::clear() // reinitialize tracking variable
{
  current = -1; // iteration variable. set = -1 for NULL
  for (int i = 0; i < numCollisions; i++) collisionLocations[i] = 0;
  numCollisions = 0;
  tableSize = 0;

  // reinitialize iteration of tracking variable
  {
    typename list<DataType>::iterator it;
    it = data[0].begin();
  }

  {
    typename list<DataType>::const_iterator it; // const for retrieve
    it = data[0].begin();
  }

  for (int j = 0; j < CAP; j++) data[j].clear(); // empty all the data
} // end clear()

#endif