#include <iostream>
#include <string>
using namespace std;

const int N = 30;

class Test
{
private:
	int val;

public:
	// Member initializer list //OR
	// Member initialization list
	Test() :val(0)
	{
		//val = 0;
		cout << "Creating through Default constructor " << val << endl;
	}

	Test(int v) :val(v)
	{
		//val = v;
		cout << "Creating through Overloaded constructor " << val << endl;
	}

	void display()
	{
		cout << "Value is: " << val << endl;
	}

	~Test()
	{
		cout << "Destructor called on " << val << endl;
	}
}; 
 

int main()
{
	//Test t1;
	//Test t2(4); //OR //Test t3={7};
	//Test arr[5];
	Test arr[5] = { {10},{20},{30},{40},{50} };

	Test* tp = nullptr;
	tp = new Test(5);
	delete tp;
	tp = nullptr;
	// Objects created on heap destroyed only when their destructor is called
	/*tp = new Test[3];
	delete[] tp;
	tp = nullptr;*/
  	return 0;
}