// Time.cpp : Defines the entry point for the console application.
//"Lab 3b, The \"Road.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#include "Thompson_Jeremy_Lab3b_Time.h"

Time::Time(double h, double m, double s)
{
  setHours(h);
  setMinutes(m);
  setSeconds(s);
}

void Time::setHours(double hour)
{
  hours = hour;
}

void Time::setMinutes(double min)
{
  minutes = min;
}

void Time::setSeconds(double second)
{
  seconds = second;
}

double Time::timeInHours() const
{
  double h = 0;
  h = (hours + (minutes) / 60 + (seconds) / 3600);
  return h;
}

double Time::timeInMinutes() const
{
  double m = 0;
  m = minutes + ((hours * 60) + (seconds) / 60);
  return m;
}

double Time::timeInSeconds() const
{
  double s = 0;
  s = ((hours * 60 * 60) + (minutes * 60) + seconds);
  return s;
}
