#include <iostream>
#include <string>
using namespace std;

const int N = 30;

class Test
{
private:
	int val;
	int* p;

public:
	// Member initializer list //OR
	// Member initialization list
	Test() :val(0)//,p(0)
	{
		//val = 0
		//p=nullptr;
		p = new int;
		*p = 0;
		cout << "Creating through Default constructor " << val << " " << *p << endl;
	}

	Test(int v1, int v2) :val(v1)
	{
		//val = v;
		p = new int;
		*p = v2;
		cout << "Creating through Overloaded constructor " << val << " " << *p << endl;
	}

	void setVal(int temp)
	{
		val = temp;
	}

	void display() const
	{
		cout << "Value is: " << val << " " << *p << endl;
	}

	~Test()
	{
		cout << "Destructor called on " << val << " " << *p << endl;
		if (p != nullptr)
		{
			delete p;
			p = nullptr;
		}
	}
};


int main()
{
	//Test t1;
	//Test t2(4); //OR //Test t3={7};
	//Test arr[5];
	/*Test arr[5] = { {10},{20},{30},{40},{50} };

	Test* tp = nullptr;
	tp = new Test(5);
	delete tp;
	tp = nullptr;*/
	// Objects created on heap destroyed only when their destructor is called
	/*tp = new Test[3];
	delete[] tp;
	tp = nullptr;*/

	//Test t1;
	//Test t2(4, 8);

	/*Test* tp = new Test(3,10);
	delete tp;
	tp = nullptr;*/

	Test* arr = new Test[5];
	for (int i = 0; i < 5; i++)
	{
		arr[i].setVal(i * 10);
	}
	for (int i = 0; i < 5; i++)
	{
		arr[i].display();
	}
	delete[] arr;
	arr = nullptr;

	return 0;
}