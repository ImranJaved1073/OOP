
#include <iostream>
#include "Fraction.h"
using namespace std;

ostream& operator<<(ostream& output, const Fraction& f)
{
	output << f.numerator << "/" << f.denominator << endl;
	return output;
}

istream& operator>>(istream& input, Fraction& f)
{
	cout << "Enter numerator: ";
	input >> f.numerator;
	cout << "Enter denominator: ";
	input >> f.denominator;
	return input;
}

void GCD(Fraction& f)
{
	cout << f.gcd();
}

int main()
{
	Fraction f1;
	Fraction f2(14, 10);
	Fraction f3(f2);
	Fraction f4;
	f4.setNumerator(4);
	f4.setDenominator(5);
	cout << "Enter values for fraction 1: " << endl;
	cin >> f1;
	cout << "F1: " << f1;
	cout << "F2: " << f2;
	cout << "F3: " << f3;
	cout << "F4: " << f4;
	f1.reduce(); f2.reduce(); f3.reduce();

	f4 = f1 + f2; f4.reduce();
	cout << "Addition of f1 & f2: " << f4;
	f4 = f1 - f2; f4.reduce();
	cout << "Subtraction of f1 & f2: " << f4;
	f4 = f1 * f2; f4.reduce();
	cout << "Multiplication of f1 & f2: " << f4;
	f4 = f1 / f2;  f4.reduce();
	cout << "Division of f1 & f2: " << f4;
	f4.setNumerator(76);
	f4.setDenominator(16);
	GCD(f4);
	cout << endl;

	cout << "F1 after reduction: " << f1.reduce() << endl;
	if (f2 == f3) cout << "F3 & F2 are equal" << endl;
	else cout << "F3 & F2 are not equal" << endl;
	if (f1 != f3) cout << "F3 & F1 are not equal" << endl;
	else cout << "F3 & F1 are not equal" << endl;
	if (f1 < f2) cout << "F1 is less than F2" << endl;
	else cout << "F1 is greater than F2" << endl;
	f4 = -f3;
	cout << "Negation of F3: " << f4;
	f4 = ++f3;
	cout << "F4 after pre increment: " << f4;
	cout << "F3 after pre increment: " << f3;
	f4 = f3++;
	cout << "F4 after post increment: " << f4;
	cout << "F3 after post increment: " << f3;
	f4 = f2 ^ 3;
	cout << "F2 raised to power 3: " << f4;
	f2 += f2;
	cout << "F2 after combined operator += : " << f2;
	
	

	//menu driven program to perform operations on fractions
	int choice;
	do
	{
		system("pause");
		system("cls");
		cout << "1. Add" << endl;
		cout << "2. Subtract" << endl;
		cout << "3. Multiply" << endl;
		cout << "4. Divide" << endl;
		cout << "5. power" << endl;
		cout << "6. use combined operator (+=)" << endl;
		cout << "7. use pre increment (++f)" << endl;
		cout << "8. use post increment (f++)" << endl;
		cout << "9. use negation (-f)" << endl;
		cout << "10. use equality (==)" << endl;
		cout << "11. use inequality (!=)" << endl;
		cout << "12. use less than (<)" << endl;
		cout << "13. use greater than (>)" << endl;
		cout << "14. use less than or equal to (<=)" << endl;
		cout << "15. use greater than or equal to (>=)" << endl;
		cout << "16. use combined operator (-=)" << endl;
		cout << "17. use combined operator (*=)" << endl;
		cout << "18. use combined operator (/=)" << endl;
		cout << "19. use pre decrement (--f)" << endl;
		cout << "20. use post decrement (f--)" << endl;
		cout << "21. calculate GCD of fraction." << endl;
		cout << "22. reduce fraction." << endl;
		cout << "23. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		system("cls");
		
		if (choice != 23)
		{
			Fraction f1, f2, f3;
			cout << "Enter values for fraction 1: " << endl;
			cin >> f1;
			cout << "Enter values for fraction 2: " << endl;
			cin >> f2;
		}

		switch (choice)
		{
		case 1:
			f3 = f1 + f2;
			cout << "Addition of f1 & f2: " << f3;
			break;
		case 2:
			f3 = f1 - f2;
			cout << "Subtraction of f1 & f2: " << f3;
			break;
		case 3:
			f3 = f1 * f2;
			cout << "Multiplication of f1 & f2: " << f3;
			break;
		case 4:
			f3 = f1 / f2;
			cout << "Division of f1 & f2: " << f3;
			break;
		case 5:
			int power;
			cout << "Enter power: ";
			cin >> power;
			f3 = f1 ^ power;
			cout << "F1 raised to power " << power << ": " << f3;
			f3 = f2 ^ power;
			cout << "F2 raised to power " << power << ": " << f3;
			break;

		case 6:
			f1 += f2;
			cout << "F1 after combined operator += : " << f1;
			break;
		case 7:
			f1 = ++f2;
			cout << "F1 after pre increment: " << f1;
			cout << "F2 after pre increment: " << f2;
			break;
		case 8:
			f1 = f2++;
			cout << "F1 after post increment: " << f1;
			cout << "F2 after post increment: " << f2;
			break;
		case 9:
			f1 = -f2;
			cout << "Negation of F2: " << f1;
			break;
		case 10:
			if (f1 == f2) cout << "F1 & F2 are equal" << endl;
			else cout << "F1 & F2 are not equal" << endl;
			break;
		case 11:
			if (f1 != f2) cout << "F1 & F2 are not equal" << endl;
			else cout << "F1 & F2 are equal" << endl;
			break;
		case 12:
			if (f1 < f2) cout << "F1 is less than F2" << endl;
			else cout << "F1 is either greater or equal to than F2" << endl;
			break;
		case 13:
			if (f1 > f2) cout << "F1 is greater than F2" << endl;
			else cout << "F1 is either less or equal to than F2" << endl;
			break;
		case 14:
			if (f1 <= f2) cout << "F1 is less than or equal to F2" << endl;
			else cout << "F1 is greater than F2" << endl;
			break;
		case 15:
			if (f1 >= f2) cout << "F1 is greater than or equal to F2" << endl;
			else cout << "F1 is less than F2" << endl;
			break;
		case 16:
			f1 -= f2;
			cout << "F1 after combined operator -= : " << f1;
			break;
		case 17:
			f1 *= f2;
			cout << "F1 after combined operator *= : " << f1;
			break;
		case 18:
			f1 /= f2;
			cout << "F1 after combined operator /= : " << f1;
			break;
		case 19:
			f1 = --f2;
			cout << "F1 after pre decrement: " << f1;
			cout << "F2 after pre decrement: " << f2;
			break;
		case 20:
			f1 = f2--;
			cout << "F1 after post decrement: " << f1;
			cout << "F2 after post decrement: " << f2;
			break;
		case 21:
			cout << "GCD of F1 : ";
			GCD(f1);
			cout << "GCD of F2 : ";
			GCD(f2);
		case 22:
			f1.reduce();
			f2.reduce();
			cout << "F1 after reduction: " << f1;
			cout << "F2 after reduction: " << f2;
			break;
		case 23:
			exit(0);
		}
	} while (choice != 23);

	return 0;
}