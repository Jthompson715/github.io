// HashTableDriver.cpp : Defines the entry point for the console application.
//"Lab 11a, The \"HashTableDriver.cpp \" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#include "Thompson_Jeremy_Lab11a_HashTable.h"
#include "Thompson_Jeremy_Lab11a_HashTable.h" // ifndef test

// ***CONSTS***
const int CAP = 1009;
int tracking = 0;

// ***STRUCTS***
struct SubjectCode
{
  string course;
  string term;
  string section;
  string instructor;
  string subjectCode;
  int classCount; 

  // functions
  bool operator< (const SubjectCode& sc) const
  {
    if (course.compare(sc.course) < 0) return true;
    if (term.compare(sc.term) < 0) return true;
    if (section.compare(sc.section) < 0)  return true;
    return false;
  } // end operator<

  bool operator==(const SubjectCode& sc) const
  {
    bool result = false;
    if (!course.compare(sc.course))
    if (!term.compare(sc.term))
    if (!section.compare(sc.section))result = true;
    return result;
  } // end operator==

  int hashCode() const // create hash code int
  {
    int elementLoc = 0;
    string key = (term + section); // key allows hashCode() to sum ASCII vals

    for (int i = 0; i < key.length(); i++){ elementLoc += (int)key[i]; }
    return elementLoc;
  } // end hashCode()
}; // end struct SubjectCode

struct Subjects
{
  string subjectCode;
  int classCount; // count of how many classes there are

  // functions
  bool operator< (const Subjects& s) const  { if (subjectCode.compare(s.subjectCode) < 0) return true; return false; }
  bool operator==(const Subjects& s) const  { if (subjectCode.compare(s.subjectCode) == 1) return true; return false; } // end operator==
}; // end struct Subjects

// ***PRINT FUNCTIONS***

void printSC(const SubjectCode& sc) // print subject codes
{
  cout << " " << sc.subjectCode << ", ";
  int sLength = sc.subjectCode.length(); sLength = 6 - sLength;
  for (int n = 0; n < sLength; n++) { cout << ' '; } // format spacing
  cout << sc.classCount;
  if (sc.classCount < 10) cout << ' '; // format spacing
  if (sc.classCount < 100) cout << ' '; // format spacing
  if (sc.classCount < 1000) cout << ' '; // format spacing
  cout << " classes." << endl;
} // end printSC()

void printSC(const Subjects& sc) // overloaded print subject codes
{
  cout << " " << sc.subjectCode << ", ";
  int sLength = sc.subjectCode.length(); sLength = 6 - sLength;
  for (int n = 0; n < sLength; n++) { cout << ' '; } // format spacing
  cout << sc.classCount;
  if (sc.classCount < 10) cout << ' '; // format spacing
  if (sc.classCount < 100) cout << ' '; // format spacing
  if (sc.classCount < 1000) cout << ' '; // format spacing
  cout << " classes." << endl;
} // end printSC()

// ***MAIN***
int main()
{

  // print my name and this assignment's title
  cout << "Lab 11a, The \"HashTableDriver.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // Variable Declaration
  int linesToRead = 350;
  int count = 0, scCount = 0;

  // ***DRIVER TESTING***
  {
    // Operator == Testing
    SubjectCode sc1; // duplicate SubjectCode struct (outside of linked list)
    sc1.classCount = 5; sc1.subjectCode = "ENGL"; // define SubjectCode sc1
    sc1.course = "Odyssey"; sc1.instructor = "Roberts"; // define SubjectCode sc1
    sc1.term = "Fall 2012"; sc1.section = "0000"; // define SubjectCode duplicates

    SubjectCode sc2; // duplicate SubjectCode struct (outside of linked list)
    sc2.classCount = 10; sc2.subjectCode = "MATH"; // define SubjectCode sc2
    sc2.course = "Calculus"; sc2.instructor = "Roberts"; // define SubjectCode sc2
    sc2.term = "Fall 2012"; sc2.section = "0000"; // define SubjectCode duplicates

    SubjectCode sc3; // duplicate SubjectCode struct (outside of linked list)
    sc3.classCount = 15; sc3.subjectCode = "COMSC"; // define SubjectCode sc3
    sc3.course = "Java"; sc3.instructor = "Duplicates"; // define SubjectCode sc3
    sc3.term = "Fall 2012"; sc3.section = "0000"; // define SubjectCode duplicates

    SubjectCode sc4; // duplicate SubjectCode struct (outside of linked list)
    sc4.classCount = 20; sc4.subjectCode = "ENGL"; // define SubjectCode sc4
    sc4.course = "Odyssey"; sc4.instructor = "Roberts";  // define SubjectCode sc4
    sc4.term = "Fall 2012"; sc4.section = "0000"; // define SubjectCode duplicates

    SubjectCode sc5; // duplicate SubjectCode struct (outside of linked list)
    sc5.classCount = 10; sc5.subjectCode = "ENGL"; // define SubjectCode sc4
    sc5.course = "Illiad"; sc5.instructor = "Roberts";  // define SubjectCode sc4
    sc5.term = "Fall 2012"; sc5.section = "0000"; // define SubjectCode duplicates

    assert((sc1 == sc1) == 1); assert((sc1 == sc2) == 0); assert((sc1 == sc3) == 0); assert((sc1 == sc4) == 1); assert((sc1 == sc5) == 0);
    assert((sc2 == sc1) == 0); assert((sc2 == sc2) == 1); assert((sc2 == sc3) == 0); assert((sc2 == sc4) == 0); assert((sc2 == sc5) == 0);
    assert((sc3 == sc1) == 0); assert((sc3 == sc2) == 0); assert((sc3 == sc3) == 1); assert((sc3 == sc4) == 0); assert((sc3 == sc5) == 0);
    assert((sc4 == sc1) == 1); assert((sc4 == sc2) == 0); assert((sc4 == sc3) == 0); assert((sc4 == sc4) == 1); assert((sc4 == sc5) == 0);
    assert((sc5 == sc1) == 0); assert((sc5 == sc2) == 0); assert((sc5 == sc3) == 0); assert((sc5 == sc4) == 0); assert((sc5 == sc5) == 1);

    // End Operator== Testing

    HashTable<SubjectCode, CAP> h_table; // hash table of SubjectCodes
    cout << "HashTable <SubjectCode, CAP> created." << endl << endl;

    // Testing of GETTER isEmpty()
    cout << "1: Testing h_table.isEmpty()" << endl;
    assert(h_table.isEmpty() == 1);
    // Testing of GETTER getCapacity()
    cout << "2: Testing h_table.getCapacity()" << endl << endl;
    assert(h_table.getCapacity() == CAP);

    // Testing of SETTER insert(const DataType& element)
    cout << "3: Testing h_table.insert(sc1)" << endl;
    h_table.insert(sc1);
    // Testing of GETTER isEmpty()
    cout << "4: Testing h_table.isEmpty() (FALSE)" << endl;
    assert(h_table.isEmpty() == 0);
    // Testing of GETTER size()
    cout << "5: Adding more and testing h_table.size() and duplicate check" << endl;
    h_table.insert(sc2); h_table.insert(sc3);
    assert(h_table.insert(sc3) == 0); // duplicate
    assert(h_table.size() == 3);
    // Testing of GETTER retrieve (DataType& parameter)
    cout << "6: Testing h_table.retrieve(SubjectCode)" << endl << endl;
    assert(h_table.retrieve(sc2) == 1); // sc2 is found in ht

    // Testing of SETTER replace(const DataType& parameter)
    cout << "7: Test h_table.replace(sc5) & (sc1)" << endl;
    assert(h_table.replace(sc5) == 0); assert(h_table.replace(sc1) == 1);
    // Testing of SETTER remove(const DataType& parameter)
    cout << "8: Test h_table.remove(sc5) & (sc3)" << endl << endl;
    assert(h_table.remove(sc5) == 0); assert(h_table.remove(sc3) == 1);

    SubjectCode s_Col; // collision with sc5
    s_Col.classCount = 5; s_Col.subjectCode = "LENG"; // define SubjectCode duplicates
    s_Col.course = "OdysseyS"; s_Col.instructor = "Roberts"; // define SubjectCode duplicates
    s_Col.term = "Fell 2012"; s_Col.section = "0000"; // define SubjectCode duplicates

    // Testing of GETTER getNumCollisions()
    cout << "9: Repopulating, then testing h_table.getNumCollisions()" << endl;
    h_table.insert(sc1); h_table.insert(sc2); h_table.insert(sc3); h_table.insert(sc4); h_table.insert(sc5);
    assert(h_table.getNumCollisions() == 4);
    cout << "10: Inserting scCol, (a non-duplicate collision)" << endl;
    assert(h_table.insert(s_Col) == 1); // not a duplicate.
    assert(h_table.getNumCollisions() == 4); // should have 1 collision now
    // Testing of GETTER size()
    cout << "11: Testing h_table.size()" << endl;
    assert(h_table.size() == 5);

    cout << endl << endl;

    // ***OBJECT COPY TESTING***
    {// object copy testing, with assignment UPON declaration
      SubjectCode scTest1; SubjectCode scTest2;
      cout << "Copying object with assignment UPON declaration" << endl;
      HashTable<SubjectCode, CAP> hashTableCopy = h_table;

      cout << "1: Testing of hashTableCopy.isEmpty()" << endl;
      assert(hashTableCopy.isEmpty() == false);
      cout << "2: Testing of hashTableCopy.size()" << endl;
      assert(hashTableCopy.size() == 5);
      cout << "3: Testing of hashTableCopy.retrieve()" << endl;
      assert(hashTableCopy.retrieve(sc2) == 1); // sc2 should be in hashTable Copy
      cout << "4: Testing of hashTableCopy.getCurrent() == " << hashTableCopy.getCurrent() << endl << endl;
      assert(hashTableCopy.getCurrent() == h_table.getCurrent()); // copy == h_table)

      cout << "5: Testing of first()" << endl;
      hashTableCopy.first(scTest1); // set scTest1 to first item in copy data
      printSC(scTest1); // print item
      h_table.first(scTest2);
      assert(scTest1 == scTest2); // set scTest1 to first item in copy data

      cout << "6: Testing of getNext()" << endl;
      hashTableCopy.getNext(scTest1); // set scTest1 to first item in copy data
      printSC(scTest1); // print item
      h_table.getNext(scTest2);
      assert(scTest1 == scTest2); // set scTest1 to first item in copy data

      cout << endl << endl;
    }

    { // object copy testing, with assignment AFTER declaration
      cout << "Copying object with assignment AFTER declaration" << endl;
      HashTable<SubjectCode, CAP> hashTableCopy; hashTableCopy = h_table;
      SubjectCode scTest1; SubjectCode scTest2;


      cout << "1: Testing of hashTableCopy.isEmpty()" << endl;
      assert(hashTableCopy.isEmpty() == false);
      cout << "2: Testing of hashTableCopy.size()" << endl;
      assert(hashTableCopy.size() == 5);
      cout << "3: Testing of hashTableCopy.retrieve()" << endl;
      assert(hashTableCopy.retrieve(sc2) == 1); // sc2 should be in hashTable Copy
      cout << "4: Testing of hashTableCopy.getCurrent() == " << hashTableCopy.getCurrent() << endl << endl;
      assert(hashTableCopy.getCurrent() == h_table.getCurrent()); // copy == h_table)

      cout << "5: Testing of first()" << endl;
      hashTableCopy.first(scTest1); // set scTest1 to first item in copy data
      printSC(scTest1); // print item
      h_table.first(scTest2);
      assert(scTest1 == scTest2); // set scTest1 to first item in copy data

      cout << "6: Testing of getNext()" << endl;
      hashTableCopy.getNext(scTest1); // set scTest1 to first item in copy data
      printSC(scTest1); // print item
      h_table.getNext(scTest2);
      assert(scTest1 == scTest2); // set scTest1 to first item in copy data

      cout << endl << endl;
    }

    {
      // CONST object copy testing, with assignment UPON declaration
      cout << "Copying CONST object with assignment UPON declaration" << endl;
      const HashTable<SubjectCode, CAP> hashTableCopy = h_table;
      SubjectCode scTest1; SubjectCode scTest2;

      cout << "1: Testing of hashTableCopy.isEmpty()" << endl;
      assert(hashTableCopy.isEmpty() == false);
      cout << "2: Testing of hashTableCopy.size()" << endl;
      assert(hashTableCopy.size() == 5);
      cout << "3: Testing of hashTableCopy.retrieve()" << endl;
      assert(hashTableCopy.retrieve(sc2) == 1); // sc2 should be in hashTable Copy
    }
  } // end driver testing

  cout << "Press ENTER to continue...";
  cin.get();

  cout << endl << endl << endl;

  //************************************************************

  // ***FILE READING***
  cout << "Begining file reading..." << endl;

  int duplicates = 0;

  vector<Subjects> vectorOfSubjects; // vector of subjects used to track courses
  HashTable<SubjectCode, CAP> h_table; // creation of hashTable object

  // file reading
  ifstream fin; // create a file-reading object
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // START TIMER
  clock_t startTime = clock();

  // open the input file
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the the file
  while (fin.good() && linesToRead)
  {
    linesToRead--; // decrement linesToRead until 0 at which point the program quits
    bool insertStatus; // insertion status

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

    // populate the hash table
    SubjectCode s_Code; s_Code.course = course; s_Code.term = term; s_Code.section = section;
    s_Code.instructor = instructor; s_Code.subjectCode = subjectCode; s_Code.classCount = 1;

    // insert into h_tabe and capture status
    insertStatus = h_table.insert(s_Code); // FALSE == duplicate

    if (!insertStatus) duplicates++; // increment the duplicates struct

    else // if not a duplicate
    {
      if (vectorOfSubjects.size() == 0) // if vector is empty
      {
        Subjects newSubjects;
        newSubjects.subjectCode = subjectCode;
        newSubjects.classCount = 1;
        vectorOfSubjects.push_back(newSubjects); // add the new subject to the vector
      } // end if (vector is empty)

      else // if vector is NOT empty
      {
        bool exitFlag = 0;
        for (int i = 0; i < vectorOfSubjects.size(); i++)
        {
          if (vectorOfSubjects[i].subjectCode.compare(subjectCode) == 0) // if the subjectCode is found
          {
            vectorOfSubjects[i].classCount++;
            exitFlag = 1;
          } // end if (subjectCode is found)

          if (exitFlag == 1) break;
        } // end for (iterate vectorOfSubjects

        if (exitFlag == 0) // if not exiting
        {
          Subjects newSubjects;
          newSubjects.subjectCode = subjectCode;
          newSubjects.classCount = 1;
          vectorOfSubjects.push_back(newSubjects); // add the new subject to the vector
          tracking++;
        } // end else
      } // end else for vector is not empty
    } // end else for not a duplicate

  } // end while(fin.good())
  fin.close();

  int h_tableSize = h_table.size();
  sort(vectorOfSubjects.begin(), vectorOfSubjects.end()); // sort array based on subjectCodes

  // ***Re-Reading of File***

  linesToRead = 350;
  duplicates = 0;
  tracking = 0;

  // START TIMER
  startTime = clock();

  // open the input file
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good() && linesToRead)
  {
    linesToRead--; // dec linesToRead until 0 upon which the program will quit
    bool removeStatus; // status removal

    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;

    // Parse the line
    const string term(token = strtok(buf, tab)); 
    const string section(token = strtok(0, tab)); 
    const string course((token = strtok(0, tab)) ? token : ""); 
    const string instructor((token = strtok(0, tab)) ? token : ""); 
    const string whenWhere((token = strtok(0, tab)) ? token : ""); 
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    // populate the hash table
    SubjectCode s_Code; s_Code.course = course; s_Code.term = term; s_Code.section = section;
    s_Code.instructor = instructor; s_Code.subjectCode = subjectCode; s_Code.classCount = 1;

    // remove s_Code
    removeStatus = h_table.remove(s_Code); // False == new

    if (!removeStatus) duplicates++; // increment the duplicates struct
  } // end while(fin.good())
  fin.close(); // close file

  sort(vectorOfSubjects.begin(), vectorOfSubjects.end()); // sort array based on subjectCodes
  cout << endl << endl;

  // STOP TIMER
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  int h_tableNewSize = h_table.size();

  // print
  cout << "There are " << vectorOfSubjects.size() << " class codes, which are listed below:" << endl;
  for (int i = 0; i < vectorOfSubjects.size(); i++)
    printSC(vectorOfSubjects[i]);

  // print duplicates
  cout << " DUPLICATES: " << duplicates << endl << endl;

  cout << "Size of the hash table after INSERTION was: " << h_tableSize << endl;
  cout << "Size of the hash table after DELETION was:  " << h_tableNewSize << endl;

  cout << "Press ENTER to continue...";
  cin.get();
}