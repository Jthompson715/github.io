// Road.h : Defines the entry point for the console application.
//"Lab 1a, The \"Road.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#ifndef Road_h
#define Road_h


class Road
{
  double width;  //feet
  double length;  //miles

public:
  void setWidth(double wid); //setter
  void setLength(double len); //setter

  double getWidth() const; //getter
  double getLength() const; //getter

  double calcAsphalt(double thickness) const; //accepts thickness for finding volume, in inches

};

#endif
