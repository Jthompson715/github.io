// GameOfLifeMap.cpp : Defines the entry point for the console application.
//"Lab 11c, The \"GameOfLifeMap.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <cstdlib>
#include <map>
#include <iostream>
using namespace std;

struct cell
{
  int row; // any value
  int column; // any value

  bool operator==(const cell& c) const { return row == c.row && column == c.column; }
  bool operator<(const cell& c) const { return(1000000 * row + column) < (1000000 * c.row + c.column); }
  int hashCode() const { return 31 * row + column; }
};

map<cell, int> grid;
map<cell, int> newGrid;

const int MINROW = -25;
const int MAXROW = 25;
const int MINCOLUMN = -35;
const int MAXCOLUMN = 35;

int neighborCount(int row, int column)
{
  cell temp;
  int count = 0;
  for (temp.row = row - 1; temp.row <= row + 1; temp.row++)
  for (temp.column = column - 1; temp.column <= column + 1; temp.column++)
  if (temp.row != row || temp.column != column)
  if (grid.find(temp) != grid.end())
    ++count;
  return count;
}

void initialize()
{
  cout << "Input the locations of living cells.";
  cout << "\nTerminate the input with a pair of -1\n";

  cell temp;
  char buf[100];
  while (true)
  {
    cin >> buf; temp.row = atoi(buf);
    cin >> buf; temp.column = atoi(buf);
    if (temp.row == -1 && temp.column == -1) break;
    grid[temp] = 1;
  }
  cin.ignore();
}

void print()
{
  cell temp = { 1 };
  cout << "Current cell config is:\n";
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.column = MINCOLUMN; temp.column <= MAXCOLUMN; temp.column++)
    if (grid.find(temp) != grid.end())
      cout << '*';
    else
      cout << ' ';
    cout << endl;
  }
  cout << endl;
}

void update()
{
  cell temp = { 1 };
  newGrid.clear();
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  for (temp.column = MINCOLUMN; temp.column <= MAXCOLUMN; temp.column++)
    switch (neighborCount(temp.row, temp.column))
  {
    case 2:
      if (grid.find(temp) != grid.end()) newGrid[temp] = 1;
      break;
    case 3:
      newGrid[temp] = 1;
  }
  grid = newGrid;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 11c, The \"GameOfLifeMap.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  initialize();
  print();

  for (int i = 1; grid.size(); i++)
  {
    cout << "Generation " << i << ". Press ENTER to continue, -1 to quit.\n";
    if (cin.get() > 31)break;
    update();
    print();
  }
  return 0;
}