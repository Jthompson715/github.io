// Time.h : Defines the entry point for the console application.
//"Lab 3b, The \"Road.h\" Program \n";
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

  Time(){}; // passes no parameters and does nothing
  Time(double, double, double); // constructor for initializing h, m, s

  void setHours(double);
  void setMinutes(double);
  void setSeconds(double);

  double timeInHours() const;
  double timeInMinutes() const;
  double timeInSeconds() const;

};

#endif // TIME_H

