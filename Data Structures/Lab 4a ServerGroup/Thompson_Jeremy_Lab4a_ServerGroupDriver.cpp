// ServerGroupDriver.cpp : Defines the entry point for the console application.
//"Lab 4a, The \"TimeDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#include <iostream>
#include <cassert>

#include "Thompson_Jeremy_Lab4a_ServerGroup.h"
#include "Thompson_Jeremy_Lab4a_ServerGroup.h" // ifndef
using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 4a, The \"ServerGroupDriver\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  cout << "***This program simulates a scenario of a group of servers.***" << endl;

  ServerGroup s(4); // makes an array of size 4 and sets elements to 0

  cout << "\nThere are 4 servers with nobody waiting to start out.\n" << endl;
  cout << "Expected: 1" << endl;
  cout << "Actual: " << s.serverFree() << endl;
  assert(true == s.serverFree());

  cout << "\nA customer comes in a wants to use a general server for 6 mins.\n" << endl;
  s.useServer(6);
  cout << "Expected: 1" << endl;
  cout << "Actual: " << s.serverFree() << endl;
  assert(true == s.serverFree());

  cout << "\nThree more customers come in and walk in and want to use the servers" << endl;
  cout << "for 4,2,9 mins, respectively.\n" << endl;
  s.serverFree();
  s.useServer(4);
  s.serverFree();
  s.useServer(2);
  s.serverFree();
  s.useServer(9);
  assert(false == s.serverFree());

  cout << "\nAll general purpose servers are currently in use now.\n" << endl;
  cout << "Expected: 0" << endl;
  cout << "Actual:" << s.serverFree() << endl;
  assert(false == s.serverFree());

  cout << "\nOne more customer walks in and wants to use the special server for 6 mins." << endl;
  cout << "Expected: 1" << endl;
  cout << "Actual: " << s.spServerFree() << endl;
  assert(true == s.spServerFree());
  s.useSpServer(6);
  cout << "Expected: 0" << endl;
  cout << "Actual: " << s.spServerFree() << endl;
  assert(false == s.spServerFree());

  cout << "\nAnother customer walks in and wants to use a general server, " << endl;
  cout << "but they are all full so he waits for 2 mins." << endl;
  cout << "Expected: 0" << endl;
  cout << "Actual: " << s.serverFree() << endl;
  assert(false == s.serverFree());
  s.decServers();
  s.decServers();

  cout << "Now that a server is free, he can use it for 3 mins\n." << endl;
  cout << "Expected: 1" << endl;
  cout << "Actual: " << s.serverFree() << endl;
  assert(true == s.serverFree());
  s.useServer(3);

  cout << "Another customer walks in and wants to use the special server." << endl;
  cout << "He will have to wait 4 mins as it is not free.\n" << endl;
  cout << "Expected: 0" << endl;
  cout << "Actual: " << s.spServerFree() << endl;
  assert(false == s.spServerFree());
  s.decServers();
  s.decServers();
  s.decServers();
  s.decServers();

  cout << "The special server is now free so he can use it for 7 mins.\n" << endl;
  cout << "Expected: 1" << endl;
  cout << "Actual: " << s.spServerFree() << endl;
  assert(true == s.spServerFree());
  s.useSpServer(7);

  //const object testing
  const ServerGroup t(6);
  t.spServerFree();

  cout << "Press ENTER to continue...";
  cin.get();

}

