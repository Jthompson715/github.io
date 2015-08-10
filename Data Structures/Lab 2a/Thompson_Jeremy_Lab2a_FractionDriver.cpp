// FractionDriver.cpp : Defines the entry point for the console application.
//"Lab 2a, The \"FractionDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include <iostream>
#include <cassert>

#include "Thompson_Jeremy_Lab2a_Fraction.h"
#include "Thompson_Jeremy_Lab2a_Fraction.h" //ifndef test

using namespace std;

int main()
{
  // print my name and this assignment's title
  cout << "Lab 2a, The \"FractionDriver\" Program \n";
  cout << "Programmer: JEREMY THOMPSON\n";
  cout << "Editor(s) used: JNotePad\n";
  cout << "Compiler(s) used: CodeBlocks\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Fraction a;
  Fraction b;

  a.numerator = 6;
  a.denominator = 5;
  b.numerator = 3;
  b.denominator = 5;

  Fraction c = (a * b);
  cout << "Expect 18/25" << endl;
  cout << "Actual " << c.numerator << "/" << c.denominator << endl;
  assert(c.numerator == 18 && c.denominator == 25);

  Fraction d = (a + b);
  cout << "Expect 9/10" << endl;
  cout << "Actual " << d.numerator << "/" << d.denominator << endl;
  assert(d.numerator == 9 && d.denominator == 10);

  Fraction e = (a * 3);
  cout << "Expect 18/5" << endl;
  cout << "Actual " << e.numerator << "/" << e.denominator << endl;
  assert(e.numerator == 18 && e.denominator == 5);

  Fraction f = (5 * a);
  cout << "Expect 30/5" << endl;
  cout << "Actual " << f.numerator << "/" << f.denominator << endl;
  assert(f.numerator == 30 && f.denominator == 5);

  {
    Fraction copy = c;
    cout << "\nFraction copy = c. Object copy testing." << endl;
    cout << "Expect 18/25" << endl;
    cout << "Actual " << c.numerator << "/" << c.denominator << endl;
    assert(c.numerator == 18 && c.denominator == 25);
  }

  {
    Fraction copy; copy = e;
    cout << "\nFraction copy; copy = fraction. Object assignment testing" << endl;
    cout << "Expect 18/5" << endl;
    cout << "Actual " << e.numerator << "/" << e.denominator << endl;
    assert(e.numerator == 18 && e.denominator == 5);
  }
}
