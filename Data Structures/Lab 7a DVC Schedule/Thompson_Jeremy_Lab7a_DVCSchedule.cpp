// DVCSchedule7a.cpp : Defines the entry point for the console application.
//"Lab 7a, The \"DvcSchedule7a.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;

// the data element
struct SubjectCode
{
  string name;
  int count;
  string termNum; 
  string classDate; 
};

//the linked-list node
struct Node
{
  SubjectCode data;
  Node* next;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 7a, The \"DvcSchedule7a\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  SubjectCode currentLine, myCurrentLine;

  Node* start = NULL;
  Node* startDup = NULL;
  Node* nextLine;
  Node* nextLines;
  Node* end;
  Node* endDup;

  int duplicate = 0;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // start the timer
  clock_t startTime = clock();

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    bool found = false;

    currentLine.name = subjectCode;
    myCurrentLine.classDate = term;
    myCurrentLine.termNum = section;

    // duplicate checking
    for (Node* j = startDup; j; j = j->next)
    {
      if (j->data.classDate == myCurrentLine.classDate && j->data.termNum == myCurrentLine.termNum)
      {
        duplicate++;
        found = true;
        break;
      }
    }

    if (!found)
    {
      nextLines = new Node;
      nextLines->data.classDate = myCurrentLine.classDate;
      nextLines->data.termNum = myCurrentLine.termNum;
      nextLines->next = startDup;
      if (!startDup) endDup = nextLines;
        startDup = nextLines;
    }

    // adding to current course total
    if (!found)
    {
      for (Node* j = start; j; j = j->next)
      {
        if (j->data.name == currentLine.name)
        {
          j->data.count++;
          found = true;
          break;
        }
      }
    }

    // add new course
    if (!found)
    {
      
      currentLine.count = 1;
      nextLine = new Node;
      nextLine->data.name = currentLine.name;
      nextLine->data.count = currentLine.count;
      nextLine->next = start;

      if (!start) end = nextLine;
        start = nextLine;
      
    }

  } // end while loop

  // nested for-loop for sorting
  for (Node* p = start; p; p = p->next)
  {
    for (Node* q = p->next; q; q = q->next)
    {
      if (p->data.name.compare(q->data.name) > 0)
      {
        SubjectCode temp = p->data;
        p->data = q->data;
        q->data = temp;
      }
    }
  }

    // close file
    fin.close();

  //// end clock timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  // print the elapsed time
  cout << "\nElapsed Time: " << elapsedSeconds << " seconds." << endl;

  // print the courses
  for (Node* j = start; j; j = j->next)
  {
    cout << " " << j->data.name << ":\t" << j->data.count << endl;
  }
  cout << "Total duplicates: " << duplicate << endl;

  // deallocate memory
  Node* p;
  Node* q;
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }

  while (startDup)
  {
    q = startDup->next;
    delete startDup;
    startDup = q;
  }
  cout << "Press ENTER to continue...";
  cin.get();
}