// Fraction.cpp : Defines the entry point for the console application.
//"Lab 3c, The \"Fraction.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#include "Thompson_Jeremy_Lab3c_Fraction.h"

// additive function
Fraction operator+(const Fraction& a, const Fraction& b)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator + b.numerator;
  newFraction.denominator = a.denominator + b.denominator;
  return newFraction;
}

// multiplication Fraction
Fraction operator*(const Fraction& a, const Fraction& b)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator * b.numerator;
  newFraction.denominator = a.denominator * b.denominator;
  return newFraction;
}

// fraction and int
Fraction operator*(const Fraction& a, const int& x)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator * (x);
  newFraction.denominator = a.denominator * (1);
  return newFraction;
}

// int and Fraction
Fraction operator*(const int& y, const Fraction& a)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator * (y);
  newFraction.denominator = a.denominator * (1);
  return newFraction;
}

bool operator > (const Fraction& a, const Fraction& b)
{
  if (a.numerator > b.numerator)
    return true; return false;
}
