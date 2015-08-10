//"Lab 15c, The \"GraphCheapest\" Program \n";
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
#include <utility>
using namespace std;

#include <cstdlib>

struct VertexContainer
{
  int vertex; // database array index
  int prev; // database array index
  double cost;

  bool operator<(const VertexContainer& v) const { return cost > v.cost; }
};

struct Vertex
{
  string name;
  bool isVisited;
  list < pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};


pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  list<pair<int, double> > ::iterator it; // iterate over adjacentVertices

  // set cost = 0, previous index = -1, and mark all as not visited
  for (int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }

  priority_queue<VertexContainer> vertexPriorityQueue; // creation of PriorityQueue

  VertexContainer startVertex; // container object for start vertex
  startVertex.cost = 0;
  startVertex.prev = -1;
  startVertex.vertex = iStart;

  vertexPriorityQueue.push(startVertex);

  while (!vertexPriorityQueue.empty()) // while queue is not empty
  {
    VertexContainer t = vertexPriorityQueue.top(); // peek at vertexQueue
    vertexPriorityQueue.pop(); // pop vertex

    if (database[t.vertex].isVisited == true) continue; // if the object has been visited


    database[t.vertex].isVisited = true; // mark contained object as visited
    database[t.vertex].cost = t.cost; // set object's cost to the containers
    database[t.vertex].prev = t.prev; // set objects prev to the containers

    if (t.vertex == iEnd) break;
    // ok below************************************************
    // for each unvisited neighbor
    for (it = database[t.vertex].adjacentVertices.begin(); it != database[t.vertex].adjacentVertices.end(); ++it)
    {
      int thisNeighborsIndex = it->first;
      double thisNeighborsCost = it->second;

      VertexContainer neighborsContainer; // creation of container for neighbor
      neighborsContainer.vertex = thisNeighborsIndex; // the vertex of neighbor
      neighborsContainer.cost = (t.cost + thisNeighborsCost); // edge + vertex cost
      neighborsContainer.prev = t.vertex; // set previous to vertex

      vertexPriorityQueue.push(neighborsContainer); // push container onto priorityqueue
    } // end for
  } // end while !vertexPriorityQueue.empty()

  pair<stack<int>, double> result;
  stack<int> resultInts;
  int vertex = iEnd;

  result.second = database[iEnd].cost; // routes cost = end vertex's

  while (vertex != -1)
  {
    resultInts.push(vertex);
    vertex = database[vertex].prev;
  } // end while()
  result.first = resultInts;
  return result;
}

// *** MAIN ***
int main()
{
  // print my name and this assignment's title
  cout << "Lab 15c, The \"GraphCheapest.cpp\" Program \n";
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
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

    // add vertices for new cities
    int iToVertex = -1;
    int iFromVertex = -1;
    int i;

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
    string fromCity, endCity;
    int iFromCity = -1;
    int iEndCity = -1;

    cout << "\nEnter the starting city: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    cout << "Enter the ending city: ";
    getline(cin, endCity);
    if (endCity.length() == 0) break;

    for (int i = 0; i < database.size(); i++)
    {
      if (fromCity == database[i].name) iFromCity = i;
      if (endCity == database[i].name) iEndCity = i;
    } // end for()

    // get cheapest
    if (iFromCity >= 0 && iEndCity >= 0)
    {
      pair<stack<int>, double> result = getCheapestRoute(iFromCity, iEndCity, database);
      cout << "Total miles: " << result.second;
      while (!result.first.empty())
      {
        cout << " -> " << database[result.first.top()].name;
        result.first.pop();
      } // end while
    } // end if
    else { cout << "One or more cities not found!" << endl; }
  } // end while()
  cout << "Press ENTER to continue...";
  cin.get();
} // end main()