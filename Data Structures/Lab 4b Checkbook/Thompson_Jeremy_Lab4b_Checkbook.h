// Checkbook.h : Defines the entry point for the console application.
//"Lab 4b, The \"Checkbook.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#ifndef Checkbook_h
#define Checkbook_h

#include <iostream>
using namespace std;

template <class DataType>
class Checkbook
{
  void doubleArraySize();
  int capacity;
  int size;
  DataType* lastChecks;
  float balance;
  int numChecks; // number of checks in the array

public:
  Checkbook(){};
  Checkbook(float initBalance);
  void setBalance(float amount);
  bool writeCheck(const DataType& amount); // returns false if amount is greater than balance
  // else returns true
  void deposit(float amount);
  float getBalance() const;
  float numOfChecks() const; // getter to return number of checks
  DataType* getChecks() const; // getter returns check array
};

template <class DataType>
Checkbook<DataType>::Checkbook(float initBalance)
{
  balance = initBalance;
  size = 0;
  capacity = 2;
  lastChecks = new DataType[capacity];
}

template <class DataType>
void Checkbook<DataType>::setBalance(float amount)
{
  balance = amount;
}

template <class DataType>
bool Checkbook<DataType>::writeCheck(const DataType& amount)
{

  if (amount > balance)
    return false;
  balance -= amount;
  numChecks = size;

  if (size == capacity)
    doubleArraySize();
  lastChecks[size] = amount;
  if (size != capacity)
    size++;
  return true;
}

template <class DataType>
void Checkbook<DataType>::deposit(float amount)
{
  balance += amount;
}

template <class DataType>
float Checkbook<DataType>::getBalance() const
{
  return balance;
}

template <class DataType>
void Checkbook<DataType>::doubleArraySize()
{
  DataType* temp = new DataType[capacity * 2];
  for (int i = 0; i < capacity; i++)
    temp[i] = lastChecks[i];
  delete[] lastChecks;
  lastChecks = temp;
  capacity *= 2;
}

template <class DataType>
DataType* Checkbook<DataType>::getChecks() const // return pointer to dyamic array *temp
{
  DataType* temp = new DataType[size];
  for (int i = 0; i < size; i++)
    temp[i] = lastChecks[i];
  return temp;
}

template <class DataType>
float Checkbook<DataType>::numOfChecks() const
{
  float howManyChecks;
  howManyChecks = numChecks;
  return howManyChecks;
}

#endif