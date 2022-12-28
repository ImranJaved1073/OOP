#include <iostream>
using namespace std;

template <class T>
class Calculator
{
	T result;
	char opCode;
public:
	
	Calculator() : result(0), opCode('+') {}
	Calculator(T r, char o) : result(r), opCode(o) {}
	void setOpCode(char);
	char getOpCode() const;
	
    T calculate(T a, T b, char op);
    void showResult() const;
    T getResult() const;
    char getOp() const;
    void setOp(char );
    ~Calculator();

	T factorial(T, char);
};

template <class T>
void Calculator<T>::setOpCode(char o)
{
	opCode = o;
}

template <class T>
char Calculator<T>::getOpCode() const
{
	return opCode;
}

template <class T>
T Calculator<T>::calculate(T a, T b, char op)
{
    switch (op)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    default:
        break;
    }
    return result;
}

template <class T>
void Calculator<T>::showResult() const
{
	cout << "Result: " << result << endl;
}

template <class T>
T Calculator<T>::getResult() const
{
	return result;
}

template <class T>
char Calculator<T>::getOp() const
{
	return opCode;
}

template <class T>
void Calculator<T>::setOp(char o)
{
	opCode = o;
}

template <class T>
Calculator<T>::~Calculator()
{
	//cout << "Destructor.\n";
}

template <class T>
T Calculator<T>::factorial(T n, char op)
{
	//n = static_cast<long long int>(n);
	if (op == '!')
	{
		if (n == 0)
			return 1;
		else
			return n * factorial(n - 1, op);
	}
	else
		return 0;
}

int main()
{
	Calculator<int> calc;// here you can put any primitive data type
	char choice='y';
	while (choice == 'y' || choice == 'Y')
	{
		int a, b;// here data type can also change
		char op = '@';
		cout << "Enter operation: ";
		while (op != '+' && op != '-' && op != '*' && op != '/' && op != '!')
		{
			cin >> op;
			if (op != '+' && op != '-' && op != '*' && op != '/' && op != '!')
				cout << "Please Enter Valid Operator: ";
		}
		calc.setOpCode(op);

		if (op == '!')
		{
			cout << "Enter number: ";
			cin >> a;
			if (a < 0)
			{
				cout << "Factorial of negative number is not possible.\n";
			}
			else if (a != (int)a)
			{
				cout << "Factorial operator (!) can only be applied on integer values.\n\n";
			}
			else
				cout << "Result: " << static_cast<long long int>(calc.factorial(a, calc.getOpCode())) << endl;
		}
		else
		{
			cout << "Enter first number: ";
			cin >> a;
			cout << "Enter second number: ";
			cin >> b;
			calc.setOpCode(op);
			cout << "Result: " << calc.calculate(a, b, calc.getOpCode()) << endl;
		}
		cout << "\n\nDo you want to perform another Calculation.\nEnter (y/Y) for continue and any other key to EXIT. ";
		cin.ignore(100, '\n');
		cin >> choice;
		system("cls");
	}
	
	
	return 0;
}