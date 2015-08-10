//"Lab 15b, The \"GraphShortest.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;
  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost; // distance
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  queue<int> vertexQueue; // vertices by index
  list<pair<int, double> > ::iterator it; // iterate over adjacentVertices

  // set cost = 0, previous index = -1, and mark all as not visited
  for (int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }

  database[iStart].isVisited = true; // mark start vertex as visisted
  vertexQueue.push(iStart); // push start vertex onto queue

  while (!vertexQueue.empty()) // while queue is not empty
  {
    int t = vertexQueue.front(); // peek at vertexQueue
    vertexQueue.pop(); // pop vertex

    for (it = database[t].adjacentVertices.begin(); it != database[t].adjacentVertices.end(); it++)
    {
      if (database[it->first].isVisited == false) // if neighbor has not been visited
      {
        database[it->first].isVisited = true; // mark neighbor as visited
        database[it->first].cost = (database[t].cost + 1); // set neighbor's cost to 1 + vertex
        database[it->first].prev = t; // set neighbor to previous vertex
        vertexQueue.push(it->first); // push neighbor onto vertexQueue
      } // end if neighbo not visited

      if (it->first == iEnd) // if neighbor contains the index of end city
      {
        while (!vertexQueue.empty()) vertexQueue.pop(); // empty the queue
        break; // exit while loop
      } // end if (neighbor vertex == end city
    } // end for iterate each vertex's neighbor
  } // end while !vertexQueue.empty()

  result.second = database[iEnd].cost; // the routes cost equals the end vertex

  for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev) result.first.push(vertex); // build a stack of entries starting from the end
  return result;
}

// *** MAIN ***
int main()
{
  cout << "Lab 15b, The \"GraphShortest.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;


  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // read input file
  vector<Vertex> database;
  while (fin.good())
  {
    string fromCity, toCity, cost;

    // read from an edge
    getline(fin, fromCity);
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());

    getline(fin, toCity);
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

    getline(fin, cost);
    fin.ignore(1000, 10); // for skipping lines

    // add vertices for new cities
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // to city
    if (database[i].name == fromCity)
      break;
    if (i == database.size()) // not in database
    {
      // store vertex if its new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }

    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // from city
    if (database[i].name == toCity)
      break;
    if (i == database.size()) // not in database
    {
      // store vertex if its new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }

    iToVertex = i;

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  
  while (true)
  {
    string fromCity, toCity;
    cout << "Enter the starting city: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
    if (database[iFrom].name == fromCity)
      break;

    cout << "Enter the ending city: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the ending city
    int iDest;
    for (iDest = 0; iDest < database.size(); iDest++)
    if (database[iDest].name == toCity)
      break;

    if (iFrom < database.size() && iDest < database.size()) // skip if not found
    {
      pair<stack<int>, double> result = getShortestRoute(iFrom, iDest, database);
      cout << "Total edges: " << result.second;
      while (!result.first.empty()) { cout << " -> " << database[result.first.top()].name; result.first.pop(); }
      cout << endl;
    } // end if
    else { cout << "One of more cities not found!" << endl; }
  } // end while()
  cout << "Press ENTER to continue...";
  cin.get();
} // end main()