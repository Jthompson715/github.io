// Time.h : Defines the entry point for the console application.
//"Lab 1b, The \"Road.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: CodeBlocks\n";

#ifndef Time_h
#define Time_h

class Time
{
  double hours;
  double minutes;
  double seconds;

public:
  void setHours(double hour);
  void setMinutes(double min);
  void setSeconds(double second);

  double timeInHours() const;
  double timeInMinutes() const;
  double timeInSeconds() const;

};

#endif // TIME_H

