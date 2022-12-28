#include <iostream>
using namespace std;

class Rectangle
{
private:
	double length;
	double width;
public:
	Rectangle(double = 0, double = 0);
	void setLength(double);
	void setWidth(double);
	double getLength() const;
	double getWidth() const;
	double getArea() const;
	double getPerimeter() const;
	Rectangle operator+(const Rectangle&);
	Rectangle operator-(const Rectangle&);
	Rectangle operator*(const Rectangle&);
	Rectangle operator/(const Rectangle&);
	Rectangle operator+=(const Rectangle&);
	Rectangle operator-=(const Rectangle&);
	Rectangle operator*=(const Rectangle&);
	Rectangle operator/=(const Rectangle&);
	Rectangle operator++();
	Rectangle operator++(int);
	Rectangle operator--();
	Rectangle operator--(int);
	Rectangle operator-();
	bool operator==(const Rectangle&);
	bool operator!=(const Rectangle&);
	bool operator>(const Rectangle&);
	bool operator<(const Rectangle&);
	bool operator>=(const Rectangle&);
	bool operator<=(const Rectangle&);
	friend ostream& operator<<(ostream&, const Rectangle&);
	friend istream& operator>>(istream&, Rectangle&);


};
Rectangle::Rectangle(double length, double width)
{
	this->length = length;
	this->width = width;
}

void Rectangle::setLength(double length)
{
	this->length = length;
}

void Rectangle::setWidth(double width)
{
	this->width = width;
}

double Rectangle::getLength() const
{
	return length;
}

double Rectangle::getWidth() const
{
	return width;
}

double Rectangle::getArea() const
{
	return length * width;
}

double Rectangle::getPerimeter() const
{
	return 2 * (length + width);
}

Rectangle Rectangle::operator+(const Rectangle& rect)
{
	Rectangle temp;
	temp.length = length + rect.length;
	temp.width = width + rect.width;
	return temp;
}

Rectangle Rectangle::operator-(const Rectangle& rect)
{
	Rectangle temp;
	temp.length = length - rect.length;
	temp.width = width - rect.width;
	return temp;
}

Rectangle Rectangle::operator*(const Rectangle& rect)
{
	Rectangle temp;
	temp.length = length * rect.length;
	temp.width = width * rect.width;
	return temp;
}

Rectangle Rectangle::operator/(const Rectangle& rect)
{
	Rectangle temp;
	temp.length = length / rect.length;
	temp.width = width / rect.width;
	return temp;
}

bool Rectangle::operator==(const Rectangle& rect)
{
	if (length == rect.length && width == rect.width)
		return true;
	else
		return false;
}

bool Rectangle::operator!=(const Rectangle& rect)
{
	if (*this == rect)
		return false;
	else
		return true;
}

bool Rectangle::operator>(const Rectangle& rect)
{
	if (length > rect.length && width > rect.width)
		return true;
	else
		return false;
}

bool Rectangle::operator<(const Rectangle& rect)
{
	if (length < rect.length && width < rect.width)
		return true;
	else
		return false;
}

bool Rectangle::operator>=(const Rectangle& rect)
{
	if (*this > rect || *this == rect)
		return true;
	else
		return false;
}

bool Rectangle::operator<=(const Rectangle& rect)
{
	if (*this < rect || *this == rect)
		return true;
	else
		return false;
}

Rectangle Rectangle::operator+=(const Rectangle& rect)
{
	length += rect.length;
	width += rect.width;
	return *this;
}

Rectangle Rectangle::operator-=(const Rectangle& rect)
{
	length -= rect.length;
	width -= rect.width;
	return *this;
}

Rectangle Rectangle::operator*=(const Rectangle& rect)
{
	length *= rect.length;
	width *= rect.width;
	return *this;
}

Rectangle Rectangle::operator/=(const Rectangle& rect)
{
	length /= rect.length;
	width /= rect.width;
	return *this;
}

Rectangle Rectangle::operator++()
{
	length++;
	width++;
	return *this;
}

Rectangle Rectangle::operator++(int)
{
	Rectangle temp;
	temp.length = length++;
	temp.width = width++;
	return temp;
}

Rectangle Rectangle::operator--()
{
	length--;
	width--;
	return *this;
}

Rectangle Rectangle::operator--(int)
{
	Rectangle temp;
	temp.length = length--;
	temp.width = width--;
	return temp;
}

Rectangle Rectangle::operator-()
{
	Rectangle temp;
	temp.length = -length;
	temp.width = -width;
	return temp;
}

ostream& operator<<(ostream& out, const Rectangle& rect)
{
	out << "(" << rect.length << ", " << rect.width << ")";
	return out;
}

istream& operator>>(istream& in, Rectangle& rect)
{
	cout << "\nEnter length: ";
	in >> rect.length;
	cout << "Enter width: ";
	in >> rect.width;
	return in;
}

template <class T>
T getMin(T val1, T val2)
{
	if (val1 < val2)
		return val1;
	else
		return val2;
}

template<class A>
void displayArray(const A* arr, int size)
{
	cout << "(Length , Width)" << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << endl;
	cout << endl;
}

int main()
{
	
	Rectangle r1;
	Rectangle r2;
	cout << "Enter rectangle 1: ";
	cin >> r1;
	cout << "Enter rectangle 2: ";
	cin >> r2;
	cout << "The minimum area is: " << getMin(r1, r2) << endl;

	Rectangle rect[5] = { Rectangle(1,2), Rectangle(2,3), Rectangle(3,4), Rectangle(4,5), Rectangle(5,6) };
	displayArray<Rectangle>(rect, 5);

}


