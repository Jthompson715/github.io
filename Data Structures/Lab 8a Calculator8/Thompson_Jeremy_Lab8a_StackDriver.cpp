//"Lab 8a, The \"StackDriver8a.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include "Thompson_Jeremy_Lab8a_Stack.h"
#include "Thompson_Jeremy_Lab8a_Stack.h" // ifndef test

using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 8a, The \"StackDriver8a.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;

  Stack <int> myStack;
  // create a stack of 30 elements
  // test push function
  for (int i = 0; i < 20; i++)
  {
    myStack.push(i);
  }
  int stackPeek, stackCopy, stackS;
  for (Stack<int> copy = myStack; !copy.isEmpty(); copy.pop(stackCopy))
  {
    copy.peek(stackPeek);
    cout << stackPeek << " ";
  }
  // test isEmpty function
  if (myStack.isEmpty() == true)
    cout << "\nThe isEmpty function IS NOT working." << endl;
  else
    cout << "\nThe isEmpty function IS working." << endl;

  // pop function testing
  if (myStack.pop(stackS) == true)
    cout << "The pop function IS working." << endl;
  else
    cout << "The pop function IS NOT working." << endl;

  // peek function testing
  if (myStack.peek(stackPeek) == true)
  {
    cout << "Expected output is 18." << endl;
    cout << "Actual output is " << stackPeek << endl;
  }
  else
    cout << "The peek function is not working." << endl;

  // makeEmpty function testing
  myStack.makeEmpty();
  if (myStack.isEmpty() == true)
    cout << "The makeEmpty function IS working as the stack is empty." << endl;
  else
    cout << "The makeEmpty function IS NOT working as the stack is empty." << endl;

  {
    Stack <int> myStack1;
    for (int i = 0; i < 20; i++)
    {
      myStack1.push(i);
    }

    // object assignment testing with assignment UPON declaration
    const Stack<int> copy = myStack1;

    // isEmpty
    cout << "\nObject copy testing with assignment UPON declaration." << endl;
    if (copy.isEmpty() == true)
      cout << "The isEmpty function IS NOT working as there are elements in the stack." << endl;
    else
      cout << "The isEmpty function IS working as there are elements in the stack." << endl;

    // peek
    int stackPeek;
    if (copy.peek(stackPeek) == true)
    {
      cout << "Expected output is 19." << endl;
      cout << "Actual output is " << stackPeek << endl;
    }
  }
  // object copy testing, with assignment AFTER declaration
  {
    Stack<int> myStack1;
    for (int i = 0; i < 20; i++)
    {
      myStack1.push(i);
    }
    Stack<int> copy = myStack1;
    cout << "\nObject copy testing with assignment AFTER declaration." << endl;

    if (copy.isEmpty() == true)
      cout << "The isEmpty function IS NOT working." << endl;
    else
      cout << "The isEmpty function IS working." << endl;

    // pop
    int stackPeek;
    if (copy.pop(stackPeek) == true)
      cout << "The pop function IS working." << endl;
    else 
      cout << "The pop function IS NOT working." << endl;
    
    // peek
    if (copy.peek(stackPeek) == true)
    {
      cout << "Expect output is 18." << endl;
      cout << "Actual output is " << stackPeek << endl;
    }

    // makeEmpty
    copy.makeEmpty();
    if (copy.isEmpty() == true)
      cout << "The makeEmpty function IS working as the stack is empty." << endl;
    else 
      cout << "The makeEmpty function IS NOT working as the stack is empty." << endl;
  }

  cout << "Press ENTER to continue...";
  cin.get();
}