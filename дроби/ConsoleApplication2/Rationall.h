#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Rational
{
	int numerator; // Числитель дроби
	int denominator; // Знаменатель дроби
public:

	Rational(int num, int den);
	explicit Rational(int num): numerator(num),denominator(1) { }
	Rational(): numerator(0),denominator(1) { }


	Rational add(const Rational& right) const;
	Rational sub(const Rational& right) const;
	Rational mult(const Rational& right) const;
	Rational div(const Rational& right) const;
	bool equalTo(const Rational& right) const;
	bool moreThan(const Rational& right) const;
	bool lessThan(const Rational& right) const;
	bool isInteger() const;
	operator string() const;
	operator double() const;
};

istream& operator >> (istream&, Rational&);
ostream& operator << (ostream&, const Rational&);
Rational operator + (const Rational& left, const Rational& right);
void operator += (Rational& left, const Rational& right);
Rational operator - (const Rational& left, const Rational& right);
void operator -= (Rational& left, const Rational& right);
Rational operator * (const Rational& left, const Rational& right);
void operator *= (Rational& left, const Rational& right);
Rational operator / (const Rational& left, const Rational& right);
void operator /= (Rational& left, const Rational& right);
bool operator == (const Rational& left, const Rational& right);
bool operator > (const Rational& left, const Rational& right);
bool operator < (const Rational& left, const Rational& right);
bool operator >= (const Rational& left, const Rational& right);
bool operator <= (const Rational& left, const Rational& right);

