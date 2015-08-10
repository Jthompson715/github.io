// Fraction.h : Defines the entry point for the console application.
//"Lab 3c, The \"Fraction.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
  int numerator;
  int denominator;
};

Fraction operator+(const Fraction&, const Fraction&); // additive function

Fraction operator*(const Fraction&, const Fraction&); // multiplication function

Fraction operator*(const Fraction&, const int&); // a * 2 function

Fraction operator*(const int&, const Fraction&); // 2 * a function

bool operator>(const Fraction&, const Fraction&);

#endif // FRACTION_H
