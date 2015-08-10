// RectangleDriver.cpp : Defines the entry point for the console application.
//"Lab 2b, The \"RectangleDriver.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#include <iostream>
#include <cassert>

#include "Rectangle.h"
#include "Rectangle.h" // ifndef test
#include "Fraction.h"

using namespace std;

int main()
{
	// print my name and this assignment's title
	cout << "Lab 2b, The \"RectangleDriver\" Program \n";
	cout << "Programmer: JEREMY THOMPSON\n";
	cout << "Editor(s) used: JNotePad\n";
	cout << "Compiler(s) used: VC++ 2013\n";
	cout << "File: " << __FILE__ << endl;
	cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Rectangle<float> a;
  Rectangle<Fraction> r;

   // float setters
   a.setLength(5.1);
   a.setWidth(10.2);

   cout << "Expect length of 5.1" << endl;
   cout << "Actual length: " << a.getLength() << endl;
   cout << "Expect width of 10.2" << endl;
   cout << "Actual width: " << a.getWidth() << endl;
   cout << "Expect area of 50.02" << endl;
   cout << "Actual area: " << a.getArea() << endl;
   cout << "Expect perimeter of 30.6" << endl;
   cout << "Actual perimeter: " << a.getPerimeter() << endl;

   // bool testing of > and <
   cout << "Expect length > width return '0'" << endl;
   cout << "Actual result of length > width " << (a.getLength() > a.getWidth()) << endl;
   cout << "Expect length < width return '1'" << endl;
   cout << "Actual result of length < width " << (a.getLength() < a.getWidth()) << endl;

   // Fraction setters
   Fraction w = { 3, 4 }; // width
   Fraction x = { 5, 6 }; // length

   r.setWidth(w);
   r.setLength(x);

   Fraction y = r.getArea();
   Fraction z = r.getPerimeter();

   cout << "\nExpect width of 3/4" << endl;
   cout << "Actual width: " << w.numerator << "/" << w.denominator << endl;
   cout << "Expect length of 5/6" << endl;
   cout << "Actual length: " << x.numerator << "/" << x.denominator << endl;
   cout << "Expect area of 15/24" << endl;
   cout << "Actual area: " << y.numerator << "/" << y.denominator << endl;
   cout << "Expect perimeter of 16/10" << endl;
   cout << "Actual perimeter: " << z.numerator << "/" << z.denominator << endl;

   {
     // object copy testing float
     Rectangle<float> copy = a;
     cout << "\nRectangle copy = rectangle. Object copy testing." << endl;
     cout << "Expect length of 5.1" << endl;
     cout << "Actual length: " << a.getLength() << endl;
     cout << "Expect width of 10.2" << endl;
     cout << "Actual width: " << a.getWidth() << endl;
     cout << "Expect area of 50.02" << endl;
     cout << "Actual area: " << a.getArea() << endl;
     cout << "Expect perimeter of 30.6" << endl;
     cout << "Actual perimeter: " << a.getPerimeter() << endl;
     assert(a.getLength() == copy.getLength() && a.getWidth() == copy.getWidth());
     assert(a.getArea() == copy.getArea() && a.getPerimeter() == copy.getPerimeter());
   }

   {
     // object copy testing of Fraction
     Rectangle<Fraction> copy = r;
     Fraction y = r.getArea();
     Fraction z = r.getPerimeter();
     cout << "\nExpect width of 3/4" << endl;
     cout << "Actual width: " << w.numerator << "/" << w.denominator << endl;
     cout << "Expect length of 5/6" << endl;
     cout << "Actual length: " << x.numerator << "/" << x.denominator << endl;
     cout << "Expect area of 15/24" << endl;
     cout << "Actual area: " << y.numerator << "/" << y.denominator << endl;
     cout << "Expect perimeter of 16/10" << endl;
     cout << "Actual perimeter: " << z.numerator << "/" << z.denominator << endl;
     assert(w.numerator == 3 && w.denominator == 4);
     assert(x.numerator == 5 && x.denominator == 6);
     assert(y.numerator == 15 && y.denominator == 24);
     assert(z.numerator == 16 && z.denominator == 10);
   }

   {
     // object assignment testing of float
     Rectangle<float> copy; copy = a;
     cout << "\nRectange copy; copy = rectangle. Object assignment testing." << endl;
     cout << "Expect length of 5.1" << endl;
     cout << "Actual length: " << a.getLength() << endl;
     cout << "Expect width of 10.2" << endl;
     cout << "Actual width: " << a.getWidth() << endl;
     cout << "Expect area of 50.02" << endl;
     cout << "Actual area: " << a.getArea() << endl;
     cout << "Expect perimeter of 30.6" << endl;
     cout << "Actual perimeter: " << a.getPerimeter() << endl;
     assert(a.getLength() == copy.getLength() && a.getWidth() == copy.getWidth());
     assert(a.getArea() == copy.getArea() && a.getPerimeter() == copy.getPerimeter());
   }

   {
     // object assignment testing of Fraction
     Rectangle<Fraction> copy; copy = r;
     Fraction y = r.getArea();
     Fraction z = r.getPerimeter();
     cout << "\nExpect width of 3/4" << endl;
     cout << "Actual width: " << w.numerator << "/" << w.denominator << endl;
     cout << "Expect length of 5/6" << endl;
     cout << "Actual length: " << x.numerator << "/" << x.denominator << endl;
     cout << "Expect area of 15/24" << endl;
     cout << "Actual area: " << y.numerator << "/" << y.denominator << endl;
     cout << "Expect perimeter of 16/10" << endl;
     cout << "Actual perimeter: " << z.numerator << "/" << z.denominator << endl;
     assert(w.numerator == 3 && w.denominator == 4);
     assert(x.numerator == 5 && x.denominator == 6);
     assert(y.numerator == 15 && y.denominator == 24);
     assert(z.numerator == 16 && z.denominator == 10);
   }
   cout << "\n\nPress ENTER to continue...";
   cin.get();
}
  



