// Rectangle.h : Defines the entry point for the console application.
//"Lab 3c, The \"Rectangle.h\" Program \n";
//"Programmer: JEREMY THOMPSON\n";
//"Editor(s) used: JNotePad\n";
//"Compiler(s) used: VC++ 2013\n";

#ifndef Rectangle_h
#define Rectangle_h

template <class DataType>

class Rectangle
{
  DataType width;
  DataType length;

public:

  Rectangle() {}; // passes no parameters and does nothing
  Rectangle(const DataType&, const DataType&);

  void setLength(const DataType&); // length setter
  void setWidth(const DataType&); // width setter

  DataType getWidth() const { return width; }
  DataType getLength() const { return length; }

  DataType getArea() const; // area getter
  DataType getPerimeter() const; // perimeter getter

  bool isLengthGreaterThanWidth(const DataType&, const DataType&)
  {
    if (length > width)
      return true; return false;
  }
};

// Rectangle constructor
template<class DataType>
Rectangle<DataType>::Rectangle(const DataType& l, const DataType& w)
{
  setLength(l);
  setWidth(w);
}

// template for width
template <class DataType>
void Rectangle<DataType>::setWidth(const DataType& w)
{
  width = w;
}

// template for length
template <class DataType>
void Rectangle<DataType>::setLength(const DataType& l)
{
  length = l;
}

// template for area
template <class DataType>
DataType Rectangle<DataType>::getArea() const
{
  DataType area;
  area = (length * width);
  return area;
}

// template for perimeter
template <class DataType>
DataType Rectangle<DataType>::getPerimeter() const
{
  DataType perimeter;
  perimeter = 2 * (length + width);
  return perimeter;
}

#endif 