// Road.cpp : Defines the entry point for the console application.
//"Lab 3a, The \"Road.cpp\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++2013\n";

#include "Thompson_Jeremy_Lab3a_Road.h"

Road::Road(double w, double l) // constructor function
{
	setWidth(w);
	setLength(l);
}

void Road::setWidth(double w)
{
	width = w;
}

void Road::setLength(double l)
{
	length = l;
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
	volume = ((length * 5280) * (width) * (thickness * 12));
	return volume;
}
