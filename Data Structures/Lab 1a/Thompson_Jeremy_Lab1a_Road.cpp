// Road.cpp : Defines the entry point for the console application.
//"Lab 1a, The \"Road.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include "THOMPSON_JEREMY_Lab1a_Road.h"

void Road::setWidth(double wid)
{
  width = wid;
}

void Road::setLength(double len)
{
  length = len;
}

double Road::getWidth() const
{
  return width;
}

double Road::getLength() const
{
  return length;
}

double Road::calcAsphalt(double thickness) const
{
  double volume = 0;
  volume = ((length * 5280) * (width)* (thickness / 12));
  return volume;
}
