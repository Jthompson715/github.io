// Rectangle.h : Defines the entry point for the console application.
//"Lab 2b, The \"Rectangle.h\" Program \n";
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
	
    void setLength(DataType); // length setter
		void setWidth(DataType); // width setter

		DataType getWidth()  { return width; }
		DataType getLength() { return length; }

    DataType getArea(); // area getter
    DataType getPerimeter(); // perimeter setter

    bool isLengthGreaterThanWidth(DataType length, DataType width)
    {
      if (length > width)
        return true; return false;
    }

};

// template for width
template <class DataType>
void Rectangle<DataType>::setWidth(DataType w)
{
	width = w;
}

// template for length
template <class DataType>
void Rectangle<DataType>::setLength(DataType l)
{
	length = l;
}

// template for area
template <class DataType>
DataType Rectangle<DataType>::getArea()
{
  DataType area;
  area = (length * width);
  return area;
}

// template for perimeter
template <class DataType>
DataType Rectangle<DataType>::getPerimeter()
{
  DataType perimeter;
  perimeter = 2 * (length + width);
  return perimeter;
}

#endif 