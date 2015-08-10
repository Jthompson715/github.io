// Fraction.cpp : Defines the entry point for the console application.
//"Lab 2a, The \"Fraction.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include "Thompson_Jeremy_Lab2a_Fraction.h"

// additive function
Fraction operator+(Fraction& a, Fraction& b)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator + b.numerator;
  newFraction.denominator = a.denominator + b.denominator;
  return newFraction;
}

// multiplication Fraction
Fraction operator*(Fraction& a, Fraction& b)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator * b.numerator;
  newFraction.denominator = a.denominator * b.denominator;
  return newFraction;
}

// fraction and int
Fraction operator*(Fraction& a, int x)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator * (x);
  newFraction.denominator = a.denominator * (1);
  return newFraction;
}

// int and Fraction
Fraction operator*(int y, Fraction& a)
{
  Fraction newFraction;
  newFraction.numerator = a.numerator * (y);
  newFraction.denominator = a.denominator * (1);
  return newFraction;
}

bool operator > (Fraction& a, Fraction& b)
{
  if (a.numerator > b.numerator)
    return true; return false;
}
