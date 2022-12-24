#include <iostream>
using namespace std;

class Counter
{
private:
	int i;

public:
	Counter();
	Counter(int a_val);
	~Counter();

	void setCounter(int a_intgr);
	void reset();
	int getCounter() const;

	void increment();
	void increment(int a_val);

	void decrement();
	void decrement(int a_val);

	void PrintNumsInRange();
};


Counter::Counter() 
{
	i = 0;
}

Counter::Counter(int a_val)
{
	i = a_val;
}

Counter::~Counter()
{
	cout << "Object is destroyed.\n";
}

void Counter::setCounter(int a_intgr)
{
	i = a_intgr;
}

void Counter::reset()
{
	i = 0;
}

int Counter::getCounter() const
{
	return i;
}

void Counter::increment()
{
	i += 1;
}

void Counter::increment(int a_val)
{
	i += a_val;
}

void Counter::decrement()
{
	i -= 1;
}

void Counter::decrement(int a_val)
{
	i -= a_val;
}

void Counter::PrintNumsInRange()
{

	int n1{}, n2{};

	cout << "Where to start: ";
	cin >> n1;

	cout << "Where to end: ";
	cin >> n2;

	Counter showNum(n1);

	for (; showNum.getCounter() <= n2; showNum.increment())
	{
		cout << showNum.getCounter() << "\t";
	}
}

int main()
{
	int length, width;
	cout << "Enter length of rectangle: ";
	cin >> length;
	cout << "Enter width of rectangle: ";
	cin >> width;

	for (Counter c; c.getCounter() < length; c.increment())
	{
		for (Counter a; a.getCounter() < width; a.increment())
		{
			cout << "*";
		}
		
	}
	Counter obj;
	obj.PrintNumsInRange();

	return 0;
}


