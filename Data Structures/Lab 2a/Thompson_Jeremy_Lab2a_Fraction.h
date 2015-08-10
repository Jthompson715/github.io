// Fraction.h : Defines the entry point for the console application.
//"Lab 2a, The \"Fraction.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
  int numerator;
  int denominator;

  Fraction operator+( const Fraction&, const Fraction&); // additive function

  Fraction operator*( const Fraction&, const Fraction&); // multiplication function

  Fraction operator*( const Fraction&, const int x); // a * 2 function

  bool operator>( const Fraction&, const Fraction&);
};

Fraction operator*(const int y, const Fraction&); // 2 * a function

#endif // FRACTION_H
