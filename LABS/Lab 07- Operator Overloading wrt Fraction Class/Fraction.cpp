#include "Fraction.h"

Fraction::Fraction()
{
	//cout << "Default Constructor.\n";
	numerator = 0;
	denominator = 1;
}

Fraction::Fraction(int a_nmrator, int a_dnmnator)
{
	//cout << "Parameterized Constructor.\n";
	numerator = a_nmrator;
	denominator = a_dnmnator;
}

Fraction::Fraction(Fraction& a_Frac)
{
	numerator = a_Frac.numerator;
	denominator = a_Frac.denominator;
}

Fraction::~Fraction() 
{
	//cout << "Destructor.\n";
}

void Fraction::setDenominator(int a_dnmnator)
{
	denominator = a_dnmnator;
}

void Fraction::setNumerator(int a_nmrator)
{
	numerator = a_nmrator;
}

int Fraction::getDenominator() const
{
	return denominator;
}

int Fraction::getNumerator() const
{
	return numerator;
}

Fraction Fraction::reduce()
{
    if (numerator % denominator == 0)
		{
			numerator = numerator / denominator;
			denominator = 1;
		}
		for (int i = 2; i <= 10; i++)
		{
			if (denominator % i == 0 && numerator % i == 0)
			{
				denominator = denominator / i;
				numerator = numerator / i;
			}
		}

		return *this;
}

Fraction Fraction::operator+(const Fraction& f) 
{
	Fraction sum;
	if (denominator == f.denominator)
	{
		sum.numerator = numerator + f.numerator;
		sum.denominator = denominator;
	}
	else
	{
		sum.numerator = (numerator * f.denominator) + (f.numerator * denominator);
		sum.denominator = denominator * f.denominator;
	}
	return sum;
}


Fraction Fraction::operator-(const Fraction& f)
{
	Fraction subtract;
	if (denominator == f.denominator)
	{
		subtract.numerator = numerator - f.numerator;
		subtract.denominator = denominator;
	}
	else
	{
		subtract.numerator = (numerator * f.denominator) - (f.numerator * denominator);
		subtract.denominator = denominator * f.denominator;
	}
	return subtract;
}

Fraction Fraction::operator*(const Fraction& f)
{
	Fraction product;
	product.numerator = numerator * f.numerator;
	product.denominator = denominator * f.denominator;

	return product;
}

Fraction Fraction::operator/(const Fraction& f)
{
	Fraction div;
	div.numerator = numerator * f.denominator;
	div.denominator = denominator * f.numerator;

	return div;
}

bool Fraction::operator==(const Fraction& f)
{
	if (numerator == f.numerator && denominator == f.denominator)
		return true;
	else
		return false;
}

bool Fraction::operator!=(const Fraction& f1)
{
	if (*this == f1)  
		return false;
	else
		return true;
}

bool Fraction::operator<(const Fraction& f)
{
	if ((numerator / denominator) < (f.numerator / f.denominator))
		return true;
	else
		return false;
}

bool Fraction::operator>(const Fraction& f)
{
	if (*this < f || *this == f)
		return false;
	else
		return true;
}

bool Fraction::operator<=(const Fraction& f)
{
	if (*this < f || *this == f)
		return true;
	else
		return false;
}

bool Fraction::operator>=(const Fraction& f)
{
	if (*this > f || *this == f)
		return true;
	else
		return false;
}

Fraction Fraction::operator++()
{
	numerator = numerator + denominator;
	return *this;
}

Fraction Fraction::operator++(int)
{
	Fraction temp = *this;
	numerator = numerator + denominator;
	return temp;
}

Fraction Fraction::operator--()
{
	numerator = numerator - denominator;
	return *this;
}

Fraction Fraction::operator--(int)
{
	Fraction temp = *this;
	numerator = numerator - denominator;
	return temp;
}

Fraction Fraction::operator+=(const Fraction& f)
{
	*this = *this + f;
	return *this;
}

Fraction Fraction::operator-=(const Fraction& f)
{
	*this = *this - f;
	return *this;
}

Fraction Fraction::operator*=(const Fraction& f)
{
	*this = *this * f;
	return *this;
}

Fraction Fraction::operator/=(const Fraction& f)
{
	*this = *this / f;
	return *this;
}

Fraction Fraction::operator-()
{
	Fraction temp;
	temp.numerator = -numerator;
	temp.denominator = denominator;
	return temp;
}

Fraction Fraction::operator^(int n)
{
    Fraction f2;
	f2.numerator = pow(numerator, n);
	f2.denominator = pow(denominator, n);
	return f2;
}

int Fraction::gcd()
{
	int hcf=0;
	for (int i = 10; i >= 2; i--)
	{
		if (denominator % i == 0 && numerator % i == 0)
			return i;
	}
}


