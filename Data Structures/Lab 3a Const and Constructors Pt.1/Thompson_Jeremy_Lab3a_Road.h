// Road.h : Defines the entry point for the console application.
//"Lab 3a, The \"Road.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#ifndef Road_h
#define Road_h

class Road
{
	double width;  //feet
	double length;  //miles

  public:
	  Road(double = 0, double = 0); // road constructor

	  void setWidth(double); //setter
	  void setLength(double); //setter

	  double getWidth() const; //getter
	  double getLength() const; //getter

	  double calcAsphalt(double thickness) const; //accepts thickness for finding volume and is a getter
};

#endif