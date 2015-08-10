// DvcSchedule6a.cpp : Defines the entry point for the console application.
//"Lab 6a, The \"DvcSchedule5b.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include <deque>

using namespace std;

struct SubjectCode
{
  string name;
  int count;
};

struct duplicate
{
  string term;
  string section;
};

int main()
{
  // print my name and this assignment's title
  cout << "Lab 6a, The \"DvcSchedule6a.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  deque<SubjectCode> subjectCodes;
  deque<duplicate> dup;
  duplicate currentLine;

  int size = 0, dupsize = 0;
  int i;
  int totalDuplicates = 0;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // start the timer
  clock_t startTime = clock();

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
    const string duplicate(course.begin(), course.begin() + course.find('-'));

    bool found = false;

    // store term and section for each parsed line
    currentLine.term = term;
    currentLine.section = section;

    // check if dup array contains an already seen term and section number
    for (i = 0; i < dup.size(); i++)
    {
      if (dup[i].term == currentLine.term && dup[i].section == currentLine.section)
      {
        found = true;
        totalDuplicates++;
        break;
      }
    }

    // fill dup array with currentLine object
    if (!found)
    {
      dup.push_back(currentLine);
    }

    // add to current subjectCode IF no identical subjectCode is found
    for (i = 0; i < subjectCodes.size(); i++)
    {
      if (subjectCodes[i].name == subjectCode)
      {
        found = true;
        subjectCodes[i].count++;
        break;
      }
    }

    // add to array IF NOT found
    if (!found)
    {
      SubjectCode subCode;
      subCode.name = subjectCode;
      subCode.count = 1;
      subjectCodes.push_back(subCode);
    }

    // sort the array into alphabetical order
    for (int i = 0; i < subjectCodes.size(); i++)
    {
      for (int j = i + 1; j < subjectCodes.size(); j++)
      if (subjectCodes[i].name > subjectCodes[j].name)
      {
        SubjectCode temp = subjectCodes[i];
        subjectCodes[i] = subjectCodes[j];
        subjectCodes[j] = temp;
      }
    }
  }
  // close file
  fin.close();

  // print records
  for (int k = 0; k < subjectCodes.size(); k++)
    cout << subjectCodes[k].name << ":\t" << subjectCodes[k].count << " courses" << endl;

  cout << "duplicates:" << totalDuplicates;

  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  // print the elapsed time
  cout << "\nTime of program execution: " << elapsedSeconds << " seconds." << endl;

  cout << "Press ENTER to continue...";
  cin.get();
}
