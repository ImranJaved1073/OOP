#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
	int gcd();

public:
	Fraction();
	Fraction(int a_nmrator, int a_dnmnator);
	Fraction(Fraction& a_Frac);
	~Fraction();

	void setDenominator(int a_dnmnator);
	void setNumerator(int a_nmrator);
	int getDenominator() const;
	int getNumerator() const;
	Fraction reduce();

	Fraction operator+(const Fraction&);
	Fraction operator-(const Fraction&);
	Fraction operator*(const Fraction&);
	Fraction operator/(const Fraction&);
	bool operator==(const Fraction&);
	bool operator<(const Fraction&);
	bool operator!=(const Fraction&);
	bool operator>(const Fraction&);
	bool operator<=(const Fraction&);
	bool operator>=(const Fraction&);
	Fraction operator+=(const Fraction&);
	Fraction operator-=(const Fraction&);
	Fraction operator*=(const Fraction&);
	Fraction operator/=(const Fraction&);

	Fraction operator-();
	Fraction operator++();
	Fraction operator++(int);
	Fraction operator--();
	Fraction operator--(int);

	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);
	
	Fraction operator^(int);
    friend void GCD(Fraction& f);
};


#endif // !FRACTION_H


