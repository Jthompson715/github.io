// ServerGroup.cpp : Defines the entry point for the console application.
//"Lab 4a, The \"TimeDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#include "Thompson_Jeremy_Lab4a_ServerGroup.h"

ServerGroup::ServerGroup(int capacity)
{
  servers = new int[capacity];
  size = capacity;
  for (int i = 0; i< capacity; i++)
  {
    servers[i] = 0;
  }
  spServer = 0;
}

bool ServerGroup::spServerFree() const
{
  bool result = false;
  if (spServer == 0) result = true;
  return result;
}

bool ServerGroup::serverFree()
{
  bool result = false;
  for (int i = 0; i< size; i++)
  {
    if (servers[i] == 0)
    {
      result = true;
      freeServer = i;
      break;
    }
  }
  return result;
}

void ServerGroup::useServer(int avTransTime)
{
  servers[freeServer] = avTransTime;
}

void ServerGroup::useSpServer(int avTransTime)
{
  spServer = avTransTime;
}

void ServerGroup::decServers()
{
  for (int i = 0; i < size; i++)
  {
    if (servers[i] != 0) servers[i]--;
  }
  if (spServer != 0)
    spServer--;
}

