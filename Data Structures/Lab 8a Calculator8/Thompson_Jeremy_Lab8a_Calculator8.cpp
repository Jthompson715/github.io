//"Lab 8a, The \"Calculator8.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#include "Thompson_Jeremy_Lab8a_Stack.h"

using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 8a, The \"Calculator8.cpp\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl;


  Stack<float> stack;
  string buf;
  float stackPush;
  float stackPop;
  float stackPeek;
  float stackCopy;

  cout << "Enter a number: " << endl;
  getline(cin, buf);
  stackPush = atof(buf.c_str());
  stack.push(stackPush);

  for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
  {
    cout << "Enter another number: " << endl;
    copy.peek(stackPeek);
    cout << stackPeek << " ";
  }

  while (buf != "Q" && buf != "q")
  {
    getline(cin, buf);
    stackPush = atof(buf.c_str());
    stack.push(stackPush);
    if (buf != "+" && buf != "-" && buf != "*" && buf != "/" && buf != "Q" && buf != "q")
    {
      cout << "Enter an operation or another number: " << endl;
      for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
      {
        copy.peek(stackPeek);
        cout << stackPeek << " ";
      }
    }

    // addition
    if (buf == "+")
    {
      if (stack.stackSize() < 2)
      {
        cout << "Enter a number to add: ";
        stack.pop(stackPop);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " ";
        }
      }

      else
      {
        stack.pop(stackPop);
        cout << "Addition result: " << endl;
        stack.peek(stackPeek); float a = stackPeek; stack.pop(stackPop);
        stack.peek(stackPeek); float b = stackPeek; stack.pop(stackPop);
        float c = a + b;
        stack.push(c);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " " << endl;
          cout << "Enter another number or 'Q'/'q' to quit." << endl;
        }
      }
    }

    // subtraction
    if (buf == "-")
    {
      if (stack.stackSize() < 2)
      {
        cout << "Enter a number: ";
        stack.pop(stackPop);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " " << endl;
        }
      }

      else
      {
        stack.pop(stackPop);
        cout << "Subtraction result: ";
        stack.peek(stackPeek); float a = stackPeek; stack.pop(stackPop);
        stack.peek(stackPeek); float b = stackPeek; stack.pop(stackPop);
        float c = a - b;
        stack.push(c);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " " << endl;
          cout << "Enter another number or 'Q'/'q' to quit." << endl;
        }
      }
    }

    // multiplication
    if (buf == "*")
    {
      if (stack.stackSize() < 2)
      {
        cout << "Enter a number: ";
        stack.pop(stackPop);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " " << endl;
          cout << "Enter another number or 'Q'/'q' to quit." << endl;
        }
      }

      else
      {
        stack.pop(stackPop);
        cout << "Multiplication result: ";
        stack.peek(stackPeek); float a = stackPeek; stack.pop(stackPop);
        stack.peek(stackPeek); float b = stackPeek; stack.pop(stackPop);
        float c = a * b;
        stack.push(c);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " " << endl;
          cout << "Enter another number or 'Q'/'q' to quit." << endl;
        }
      }
    }

    // division
    if (buf == "/")
    {
      if (stack.stackSize() < 2)
      {
        cout << "Enter a number: ";
        stack.pop(stackPop);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " " << endl;
        }
      }

      else
      {
        stack.pop(stackPop);
        cout << "Division result: ";
        stack.peek(stackPeek); float a = stackPeek; stack.pop(stackPop);
        stack.peek(stackPeek); float b = stackPeek; stack.pop(stackPop);
        float c = a / b;
        stack.push(c);
        for (Stack<float> copy = stack; !copy.isEmpty(); copy.pop(stackCopy))
        {
          copy.peek(stackPeek);
          cout << stackPeek << " " << endl;
          cout << "Enter another number or 'Q'/'q' to quit." << endl;
        }
      }
    }
  }
  cout << "Press ENTER to continue...";
  cin.get();
}