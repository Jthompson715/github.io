// DvcSchedule14b.cpp : Defines the entry point for the console application.
//"Lab 14b, The \"DvcSchedule14b.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

// The duplicate check comes up 16 short, but i'm not entirely sure how to fix it. It is fast however...

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include <ctime>
#include <cstring>

#include "Thompson_Jeremy_Lab14a_SortableArray.h"

// ***Structs***
struct SubjectCode
{
  int classCount;
  string name;
  string section;
  string term;
};

char noFlagSet()
{
  cout << endl << "A flag should have been set. Enter \'q\' to QUIT or \'c\' to CONTINUE.";
  char a;
  cin >> a;
  cout << endl;
  return a; // returns character for above check
} 

void printSC(const SubjectCode& sc) // print subject codes
{
  cout << " " << sc.name << " ";
  int sLength = sc.name.length(); sLength = 6 - sLength;
  for (int n = 0; n < sLength; n++)
  {
    cout << ' ';
  }
  cout << sc.classCount;
  if (sc.classCount < 10) cout << ' '; // format spacing
  if (sc.classCount < 100) cout << ' '; // format spacing
  if (sc.classCount < 1000) cout << ' '; // format spacing
  cout << " classes." << endl;
} // end printSC()

bool operator < (const SubjectCode& leftSC, const SubjectCode& rightSC)
{
  if (leftSC.name.compare(rightSC.name) < 0) return true;
  return false;
}

int main()
{
  // print my name and this assignment's title
  cout << "Lab 14b, The \"DvcSchedule14b.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // variable declarations
  bool switchFlag = 0, flagStop = 0;
  int count = 0, scCount = 0;

  SortableArray<SubjectCode> subjectCodes(200);
  SubjectCode tempSC[2]; // initial array size of 2

  vector<string> dupCheck(1, "abc"); // vector of strings used for comparing terms/sections

  // file reading
  ifstream fin; // file reading object
  char *token;
  char buf[1000];
  const char *const tab = "\t";

  // populate subjectCodes[0] with duplicates
  tempSC[0].classCount = 0; tempSC[1].classCount = 0; // initializes new data with a size of zero
  tempSC[switchFlag].name = "DUPLICATES"; tempSC[switchFlag].term = "Spring 2015"; tempSC[switchFlag].section = "0000";
  subjectCodes[scCount] = tempSC[switchFlag]; // assign dups to subjectCodes[0]

  cout << "Working: "; // progress indication

  // START TIMER
  clock_t startTime = clock();

  // open input file
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // ***File Reading***
  while (fin.good())
  {
    if (count % 1000 == 0) cout << "."; count++; // progress indication
    flagStop = 0; // reset flagStop
    switchFlag = !switchFlag;

    // read the lines
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

    // populate tempSC[switchFlag] with data
    tempSC[switchFlag].name = subjectCode;
    tempSC[switchFlag].section = section;
    tempSC[switchFlag].term = term;

    // ***Duplicate Check
    if (tempSC[switchFlag].section.compare(tempSC[!switchFlag].section) == 0)
    {
      if (tempSC[switchFlag].term.compare(tempSC[!switchFlag].term) == 0)
      {
        subjectCodes[0].classCount++; // increment duplicate count for given term/section combo
        flagStop = 1; // stop other operations
      } // end if for duplicate
    } // end if section == section

    // ***Check if Not New
    if (flagStop == 0)
    {
      for (int i = 1; i <= scCount; i++) // move through array
      {
        if (subjectCodes[i].name.compare(tempSC[switchFlag].name) == 0) // if subjectCode is found
        {
          subjectCodes[i].classCount++; // increment
          flagStop = 1; // flag as non-new and skip new code below
          i = scCount + 1;
        } // end if(subjectCode found)
      } // end for
    } // end if(non-new)

    // ***New SubjectCode
    if (flagStop == 0)
    {
      scCount++; // increment the searchable index
      subjectCodes[scCount] = tempSC[switchFlag]; 
      subjectCodes[scCount].classCount = 1;
      flagStop = 1;
    }

    if (flagStop == 0) // error
    {
      if (noFlagSet() == 'q') break;
    }// end if
  } // end while()

  fin.close();
  subjectCodes.changeSize(scCount + 1); // change array size to final size needed
  cout << endl;

  // *** Sort and Print
  SortableArray<SubjectCode> printSCs((subjectCodes.length() - 1)); // copy over for printing w/o duplicating
  for (int i = 0; i < printSCs.length(); i++) printSCs[i] = subjectCodes[i + 1]; // copy everything but subjectCodes

  printSCs.sort();

  // STOP TIMER
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  // PRINT
  cout << "There are " << scCount << " class codes, as follows:" << endl;
  for (int i = 0; i < printSCs.length(); i++) printSC(printSCs[i]);

  // print duplicates
  cout << "  " << subjectCodes[0].name << ": " << subjectCodes[0].classCount << endl;
  cout << "File processing and sorting took: " << elapsedSeconds << " seconds." << endl;

  cout << "Press ENTER to continue...";
  cin.get();
}