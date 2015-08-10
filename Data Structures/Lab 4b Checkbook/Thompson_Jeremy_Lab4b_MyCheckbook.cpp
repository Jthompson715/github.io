// MyCheckbook.cpp : Defines the entry point for the console application.
//"Lab 4b, The \"MyCheckbook.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include <iomanip>

#include "Thompson_Jeremy_Lab4b_Checkbook.h"

using namespace std;

int menu();

const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, GETCHECKS = 4, QUIT = 5;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 4b, The \"MyCheckbook\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: VC++ 2013\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  float balance;
  cout << "Enter the initial balance: $";
  cin >> balance;
  Checkbook<float> c(balance);
  float amount;
  int choice;
  bool checkAccepted = false;

  choice = menu();
  while (choice != QUIT)
  {
    if (choice == CHECK) // choice 1
    {
      cout << "Enter check amount: $";
      cin >> amount;

      if (c.writeCheck(amount))
      {
        checkAccepted = true;
      }
      else
      {
        cout << "Your balance is not high enough for that check." << endl;
      }
    }

    else if (choice == DEPOSIT) // choice 2
    {
      cout << "Enter deposit amount: $";
      cin >> amount;
      c.deposit(amount);
      cout << "Deposit accepted." << endl;
    }

    else if (choice == BALANCE)
    {
      amount = c.getBalance();
      cout << "Your balance is: $" << amount;
    }

    else if (choice == GETCHECKS)
    {
      float *x = c.getChecks();
      cout << "Check history: ";

      if (c.numOfChecks() > 0)
      {
        for (int i = 0; i <= c.numOfChecks(); i++)
        {
          cout << "$" << x[i] << ", ";
        }
        delete[] x; // deallocate memory
      }
    }
    choice = menu();
  }
  cout << "Press ENTER to continue...";
  cin.get();
}



int menu()
{
  int choice;

  cout << endl;
  cout << "1.  Write a check" << endl;
  cout << "2.  Make a deposit" << endl;
  cout << "3.  Get the balance" << endl;
  cout << "4.  Display all checks" << endl;
  cout << "5.  Quit" << endl << endl;
  cout << "Enter a number between 1 and 5: ";
  cin >> choice;

  return choice;
}

