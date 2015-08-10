//"Lab 15a, The \"GraphSearches.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

struct Vertex
{
  string name;
  bool isVisited;
  list<int> adjacentVertices;
};

void printV(Vertex v)
{
  cout << "Name:" << v.name << ", isVisisted:" << v.isVisited << ", adjacentVertices:";
  for (list<int>::iterator itV = v.adjacentVertices.begin(); itV != v.adjacentVertices.end(); itV++)
  {
    cout << *itV << ",";
  }
  cout << endl;
}

// ***BFS***
queue<int> doBreathFirstSearch(int iOriginalVertex, vector<Vertex>& database)
{
  queue<int> searchOrder; // empty queue to return at end of function
  queue<int> vertexQueue; // vertices by index

  // initialize vertices to not visited
  for (int i = 0; i < database.size(); i++) database[i].isVisited = false;
  if (iOriginalVertex < 0 || iOriginalVertex >= database.size()) return searchOrder; // empty queue; city not found

  database[iOriginalVertex].isVisited = true; // mark starting vertex as "visited"
  searchOrder.push(iOriginalVertex); // push start vertex's index onto result queue
  vertexQueue.push(iOriginalVertex); // push start vertex's index onto vertexQueue

  while (!vertexQueue.empty()) // while vertexQueue is empty
  {
    int t = vertexQueue.front(); // peek at vertex in vertexQueue
    vertexQueue.pop(); // pop vertex from vertexQueue
    for (list<int>::iterator it = database[t].adjacentVertices.begin(); it != database[t].adjacentVertices.end(); it++)
    {
      if (database[*it].isVisited == false) // if neighbor has not been visisted
      {
        database[*it].isVisited = true; // mark neighbor as visited
        searchOrder.push(*it); // push neighbor onto searchOrder queue
        vertexQueue.push(*it); // push neighbor onto vertexQueue
      } // end if neighbor not visited
    } // end for iterate each neighbor's vertex
  } // end while 
  return searchOrder;
} // end doBreathFirstSearch

// ***DFS***
queue<int> doDepthFirstSearch(int iOriginalVertex, vector<Vertex>& vertices)
{
  queue<int> searchOrder; // empty queue to return at end of function
  stack<int> vertexStack; // vertices by index

  // initialize vertices to not visited
  for (int i = 0; i < vertices.size(); i++) vertices[i].isVisited = false;
  if (iOriginalVertex < 0 || iOriginalVertex >= vertices.size()) return searchOrder; // empty queue; city not found

  vertexStack.push(iOriginalVertex); // push start vertex's index onto vertexQueue

  while (!vertexStack.empty()) // while vertexQueue is empty
  {
    int t = vertexStack.top(); // peek at vertex in vertexQueue
    vertexStack.pop(); // pop vertex from vertexQueue

    if (vertices[t].isVisited == false) // if that vertex has not been visited
    {
      vertices[t].isVisited = true; // mark as visited
      searchOrder.push(t); // push vertex onto searchOrder queue

      for (list<int>::reverse_iterator r_it = vertices[t].adjacentVertices.rbegin(); r_it != vertices[t].adjacentVertices.rend(); r_it++)
      {
        if (vertices[*r_it].isVisited == false) // if neighbor has not been visisted
          vertexStack.push(*r_it); // push neighbor onto vertexQueue
      } // end if neighbor not visited
    } // end for iterate each neighbor's vertex
  } // end while 
  return searchOrder;
} // end doBreathFirstSearch

// ***MAIN***
int main()
{
  // print my name and this assignment's title
  cout << "Lab 15a, The \"GraphSearches.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  // variable declarations
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // file processing
  vector<Vertex> database;
  while (fin.good())
  {
    string fromCity, toCity;
    int space = 0;

    // read from edge
    getline(fin, fromCity);
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());

    getline(fin, toCity);
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    fin.ignore(1000, 10); // skip the distance line
    fin.ignore(1000, 10); // skip the line separator

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
    if (database[i].name == fromCity)
      break;

    if (i == database.size()) // not found in database yet
    {
      // store vertex if its new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }

    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // seek from city
    if (database[i].name == toCity)
      break;
    if (i == database.size()) // not in vector yet
    {
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }

    iToVertex = i;

    // store the bi-directional edges
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }

  fin.close();
  cout << "Done processing input file.\n";

  while (true)
  {
    // get the start city
    string startCity;
    cout << "Enter the starting city: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // find the starting city
    int i;
    for (i = 0; i < database.size(); i++)
    if (database[i].name == startCity)
      break;

    if (i < database.size()) // skip if no match is found
    {
      // BFS first
      cout << "BFS result";
      queue<int> q = doBreathFirstSearch(i, database);
      while (!q.empty())
      {
        cout << " -> " << database[q.front()].name;
        q.pop();
      }
      cout << endl;

      cout << "\nDFS result";
      q = doDepthFirstSearch(i, database);
      while (!q.empty())
      {
        cout << " -> " << database[q.front()].name;
        q.pop();
      }
      cout << endl;
    }
  }
  cin.get();
} // end main()