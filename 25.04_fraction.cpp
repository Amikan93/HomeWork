//main
------------------------------------------------------------------------------------
#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{

		fraction first(3, 5), second(1, 2), third;

		third = first + second;
		third.show();
		cout << third << endl << endl;

		third = first - second;
		third.show();
		cout << third << endl << endl;

		third = first * second;
		third.show();
		cout << third << endl << endl;

		third = first / second;
		third.show();
		cout << third << endl << endl;
		return 0;

}
-----------------------------------------------------------------------------------------

#pragma once
#include <iostream>
using namespace std;

class fraction
{
private:
	unsigned int numerator;
	unsigned int denominator;
public:
	fraction();
	fraction(const unsigned int num, const unsigned int den);
	fraction operator+(const fraction& obj);
	fraction operator-(const fraction& obj);
	fraction operator*(const fraction& obj);
	fraction operator/(const fraction& obj);
	fraction operator+(const int& value);
	fraction operator-(const int& value);
	operator float();
	void show();
};

---------------------------------------------------------------------------------------

#include "fraction.h"

fraction::fraction()
{
	numerator = 0;
	denominator = 0;
}

fraction::fraction(const unsigned int num, const unsigned int den)
{
	this->numerator = num;
	this->denominator = den;
}

fraction fraction::operator+(const fraction& obj)
{
	return fraction(this->numerator * obj.denominator + this->numerator * obj.denominator , this->denominator * obj.denominator);
}

fraction fraction::operator-(const fraction& obj)
{
	return fraction(this->numerator * obj.denominator - this->numerator * obj.denominator, this->denominator * obj.denominator);
}

fraction::operator float()
{
	if (numerator == 0 && denominator == 0)
		return 0;
	if (numerator == 0)
	{
		cout << "ERROR" << endl;
		return FLT_MAX;
	}

	return (float)numerator / (float)denominator;
}

void fraction::show()
{
	cout << this->numerator;
	cout << "/";
	cout << this->denominator << endl;
}

fraction fraction::operator*(const fraction& obj)
{
	return fraction(numerator* obj.numerator, denominator * obj.denominator);
}

fraction fraction::operator/(const fraction& obj)
{
	return fraction(numerator / obj.numerator, denominator / obj.denominator);
}

fraction fraction::operator+(const int& value)
{
	double x = 2. / 3;
	x = value;
	return fraction(numerator + value, numerator + value);
}

fraction fraction::operator-(const int& value)
{
	double x = 2. / 3;
	x = value;
	return fraction(numerator - value, numerator - value);
}
