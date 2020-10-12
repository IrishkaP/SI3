#include "Rationall.h"
#include "functions.h"
#include "Bad_area.h"

Rational::Rational(int num, int den) {
	if (den == 0) throw Bad_area();
	int n = NOD(num, den);
	while (n != 1) {
		num /= n;
		den /= n;
		n = NOD(num, den);
	}
	if (num > 0 && den > 0 || num < 0 && den < 0) {
		numerator = abs(num);
		denominator = abs(den);
		return;
	}
	numerator = -abs(num);
	denominator = abs(den);
}

Rational Rational::add(const Rational& right) const {
	int num1 = numerator * right.denominator;
	int num2 = right.numerator * denominator;
	int den = denominator * right.denominator;
	int num = num1 + num2;
	int d = NOD(num, den);
	return Rational(num / d, den / d);
}
Rational Rational::sub(const Rational& right) const {
	int num1 = numerator * right.denominator;
	int num2 = right.numerator * denominator;
	int den = denominator * right.denominator;
	int num = num1 - num2;
	int d = NOD(num, den);
	return Rational(num / d, den / d);
}
Rational Rational::mult(const Rational& right) const {
	return Rational(numerator * right.numerator, denominator * right.denominator);
}
Rational Rational::div(const Rational& right) const {
	return Rational(numerator * right.denominator, denominator * right.numerator);
}
bool Rational::equalTo(const Rational& right) const {
	if (numerator == right.numerator && denominator == right.denominator)
		return true;
	else
		return false;
}
bool Rational::moreThan(const Rational& right) const {
	int num1 = numerator * (NOK(denominator, right.denominator) / right.denominator);
	int num2 = right.numerator * (NOK(denominator, right.denominator) / denominator);
	int d = NOK(denominator, right.denominator);
	if (num1 > num2)
		return true;
	else
		return false;

}
bool Rational::lessThan(const Rational& right) const {
	int num1 = numerator * (NOK(denominator, right.denominator) / right.denominator);
	int num2 = right.numerator * (NOK(denominator, right.denominator) / denominator);
	int d = NOK(denominator, right.denominator);
	if (num1 < num2)
		return true;
	else
		return false;
}
bool Rational::isInteger() const {
	if (denominator == 1)
		return true;
	else
		return false;
}
Rational::operator string() const {
	string result = to_string(numerator);
	if (denominator == 1) 
		return result;
	result += "/" + to_string(denominator);
	return result;
}
Rational::operator double() const {
	return numerator / denominator;
}


//istream& operator >> (istream& is, Rational& a) {

//	return is;
//}

ostream& operator << (ostream& os, const Rational& a) {
	string s = string(a);
	os << s;
	return os;
}

Rational operator + (const Rational& left, const Rational& right) {
	Rational result = left.add(right);
	return result;
}

void operator += (Rational& left, const Rational& right) {
	left = left.add(right);
}

Rational operator - (const Rational& left, const Rational& right) {
	Rational result = left.sub(right);
	return result;
}

void operator -= (Rational& left, const Rational& right) {
	left = left.sub(right);
}

Rational operator * (const Rational& left, const Rational& right) {
	Rational result = left.mult(right);
	return result;
}

void operator *= (Rational& left, const Rational& right) {
	left = left.mult(right);
}

Rational operator / (const Rational& left, const Rational& right) {
	Rational result = left.div(right);
	return result;
}

void operator /= (Rational& left, const Rational& right) {
	left = left.div(right);
}

bool operator == (const Rational& left, const Rational& right) {
	if (left.equalTo(right) == true)
		return true;
	else
		return false;
}

bool operator > (const Rational& left, const Rational& right) {
	if (left.moreThan(right) == true)
		return true;
	else
		return false;
}

bool operator < (const Rational& left, const Rational& right) {
	if (left.lessThan(right) == true)
		return true;
	else
		return false;
}

bool operator >= (const Rational& left, const Rational& right) {
	if (left.moreThan(right) == true || left.equalTo(right) == true)
		return true;
	else
		return false;
}

bool operator <= (const Rational& left, const Rational& right) {
	if (left.lessThan(right) == true || left.equalTo(right) == true)
		return true;
	else
		return false;
}