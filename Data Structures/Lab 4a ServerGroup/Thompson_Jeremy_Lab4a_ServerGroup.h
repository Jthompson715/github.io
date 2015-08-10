// ServerGroup.h : Defines the entry point for the console application.
//"Lab 4a, The \"TimeDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#ifndef ServerGroup_h
#define ServerGroup_h

class ServerGroup
{
  int* servers;//pointer to dynamic array
  int spServer;
  int freeServer;
  int capacity; // number of elements in array initially
  int size;

public:
  // sets elements of the dynamic int array. i.e, the # of general purpose servers
  // sets all elements to zero including spServer
  ServerGroup(int capacity); // constructor
  bool spServerFree() const; // returns true if spServer is free
  bool serverFree(); // sets freeServer to the index of the element
  void useServer(int avTransTime); // set servers[freeServer] to avTransTime. this is the average # of clock ticks to serve someone in line
  void useSpServer(int avTransTime); // set server[spServer] to avTransTime. this is the average # of clock ticks to serve someone in line
  void decServers(); // decrement each server in the array by 1 until zero for each clock tick. also works on spServer
};

#endif