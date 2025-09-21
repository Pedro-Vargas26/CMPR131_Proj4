
#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H

#include <exception>
#include <iostream>
#include <list>
#include <cmath>
#include <string>
using std::to_string;
using std::exception;
using std::ostream;
using namespace std;

/*


class for a rational number.

side note, to normalize a value, first change the
desired value, such as the numerator, then call the
normalize function to update the GCF.

When changing the denominator, if zero if entered,
an exception will be thrown!
*/
class Rational {
private:
	short numerator;
	short denominator;


	/*
@brief uses the euclidian method of obtaining the gcf between two
numbers.
@param short - the higher value between the two.
@param short - the lower value between the two.
@return short - gcf of the interval. */
	short getGcf(short a, short b) {
		while (b != 0) {
			short temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	}

public:


	/*
	@brief exception class to be thrown if division by zero is
	attempted. */
	class divisionByZero :public exception {
	private:
		const char* msg;
	public:
		divisionByZero(const char* msg) : msg(msg) {};

		const char* what() const noexcept override {
			return msg;
		}
	};



	Rational() {
		numerator = 0;
		denominator = 1;
	}
	//copy constructor
	Rational(const Rational& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}

	Rational(Rational&& other)noexcept {
		denominator = other.denominator;
		numerator = other.numerator;
		other.denominator = 1;
		other.numerator = 1;
	}
	//@param short - numerator to set.
	void setNumerator(short numer) {
		numerator = numer;

	};

	// Constructor from ints (allow making Rational(3) -> 3/1)
	Rational(int numer, int denom = 1) {
		if (denom == 0) throw divisionByZero("ERROR: Denominator zero in constructor");
		// Note: narrowing to short; if your values can exceed short range, change types.
		numerator = static_cast<short>(numer);
		denominator = static_cast<short>(denom);
		normalize();
	}

	//@param short - denominator to set.
	//@brief throws an exception in denominator is 0. 
	void setDenominator(short denom) {
		if (denom == 0) {
			throw divisionByZero("\tERROR: DIVISION BY ZERO ATTEMPTED. ");
		}
		else {
			denominator = denom;
		}
	}
	//@return short - numerator of current Rational instance. 
	short getNumerator()const {
		return numerator;
	}

	//@return short - denominator of current Rational instance. 
	short getDenominator()const {
		return denominator;
	}

	/*
	@brief simplifies the instance. */
	void normalize() {
		bool denomIsNeg = false;
		bool numeIsNeg = false;

		short newNumerator = getNumerator();
		short newDenominator = getDenominator();

		if (newNumerator < 0 && newDenominator < 0) {
			newNumerator *= -1;
			newDenominator *= -1;
		}
		else if (newNumerator < 0) {
			numeIsNeg = true;
			newNumerator *= -1;
		}
		else if (newDenominator < 0) {
			denomIsNeg = true;
			newDenominator *= -1;
		}

		short lowerValue = ((newNumerator <= newDenominator) ? newNumerator : newDenominator);
		short biggerValue = ((newNumerator >= newDenominator) ? newNumerator : newDenominator);

		short gcf = getGcf(lowerValue, biggerValue);

		newNumerator /= gcf;
		newDenominator /= gcf;


		if (numeIsNeg || denomIsNeg) {
			newNumerator *= -1;
		}

		numerator = newNumerator;
		denominator = newDenominator;
	}


	//@return float - numerator divided by the denominator (denominator is non-zero).
	decltype(numerator / (float)denominator) getResult()const {
		return numerator / (float)denominator;
	}


	
	bool operator<(const Rational& other) const {
		return static_cast<int>(numerator) * other.denominator
			< static_cast<int>(other.numerator) * denominator;
	}
	bool operator>(const Rational& other) const {
		return static_cast<int>(numerator) * other.denominator
	> static_cast<int>(other.numerator) * denominator;
	}
	bool operator<=(const Rational& other) const {
		return !((*this) > other);
	}
	bool operator>=(const Rational& other) const {
		return !((*this) < other);
	}



	/*
	@param const Rational& - the other to copy from. no move sematics involved.
	@return Rational& - address of the current object returned. */
	Rational& operator=(const Rational& other) {
		if (this != &other) {
			this->numerator = other.numerator;
			this->denominator = other.denominator;
		}
		return *this;
	}

	/*
	@param const pair <short, short>& - the numerator and denominator pair.
	@return Rational& - the address of the Rational object mutated. */
	Rational& operator=(const std::pair<short, short>& pair) {
		setNumerator(pair.first);
		setDenominator(pair.second);
	}
	/*
	@param Rational&& - RValue of a Rational instance to move data from.
	@return Rational& - the address from current mutated object. */
	Rational& operator= (Rational&& other)noexcept {
		if (this != &other) {
			this->numerator = other.numerator;
			other.numerator = 1;
			this->denominator = other.denominator;
			other.denominator = 1;
		}
		return *this;
	}

	// Precondition: r1 and r2 are defined
	// Postcondition: Addition of r1 and r2, ensuring they stay in int form
	Rational operator+(const Rational& other) const
	{
		int num = static_cast<int>(numerator) * other.denominator
			+ static_cast<int>(other.numerator) * denominator;
		int den = static_cast<int>(denominator) * other.denominator;
		Rational r;
		r.setNumerator(static_cast<short>(num));
		r.setDenominator(static_cast<short>(den));
		r.normalize();
		return r;
	}
	// Precondition: r1 and r2 are defined
	// Postcondition: Subtraction of r1 and r2, ensuring they stay in int form
	Rational operator-(const Rational& other) const
	{
		int num = static_cast<int>(numerator) * other.denominator
			- static_cast<int>(other.numerator) * denominator;
		int den = static_cast<int>(denominator) * other.denominator;
		Rational r;
		r.setNumerator(static_cast<short>(num));
		r.setDenominator(static_cast<short>(den));
		r.normalize();
		return r;
	}

	Rational operator-() const 
	{
		Rational result(*this);            // make a copy
		result.setNumerator(-result.getNumerator());
		// don't call normalize()
		return result;
	}

	// Precondition: r1 and r2 are defined
	// Postcondition: Multiplication of r1 and r2, ensuring they stay in int form
	Rational operator*(const Rational& other) const
	{
		int num = static_cast<int>(numerator) * other.numerator;
		int den = static_cast<int>(denominator) * other.denominator;
		Rational r;
		r.setNumerator(static_cast<short>(num));
		r.setDenominator(static_cast<short>(den));
		r.normalize();
		return r;
	}
	// Precondition: r1 and r2 are defined
	// Postcondition: Division of r1 and r2, ensuring they stay in int form
	Rational operator/(const Rational& other) const
	{
		if (other.numerator == 0) {
			throw divisionByZero("ERROR: Division by zero Rational attempted.");
		}
		int num = static_cast<int>(numerator) * other.denominator;
		int den = static_cast<int>(denominator) * other.numerator;
		Rational r;
		r.setNumerator(static_cast<short>(num));
		r.setDenominator(static_cast<short>(den));
		r.normalize();
		return r;
	}
	/*
	@param const Rational& - other instance to compare if not equal.
	@return bool - true if they're equal. */
	bool operator!=(const Rational& other) const {
		return !((*this) == other);
	}
	/*
	@param const Rational& - other instance to compare.
	@return bool - true if they're equal. */
	bool operator==(const Rational& other) {
		if (this->denominator == other.denominator && this->numerator == other.numerator) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(const Rational& other) const {
		if (this->denominator == other.denominator && this->numerator == other.numerator)
			return true;
		return false;
	}
	/*
	#param ostream& - output stream buffer to insert data into.
	@param const Rational& - Rational instance to display.
	@return ostream& - output stream with data stored. */

	friend ostream& operator<<(ostream& os, const Rational& obj) {
		os << obj.numerator << "/" << obj.denominator;
		return os;

	}

	operator std::string() const {
		return (to_string(numerator) + "/" + to_string(denominator));
	}
	operator double() const {
		return getResult();
	}



};

// Non-member arithmetic for mixing ints and Rationals

inline Rational operator*(int lhs, const Rational& r) {
	Rational tmp;
	tmp.setNumerator(static_cast<short>(lhs * static_cast<int>(r.getNumerator())));
	tmp.setDenominator(r.getDenominator());
	tmp.normalize();
	return tmp;
}

inline Rational operator*(const Rational& r, int rhs) {
	return rhs * r; // reuse
}

inline Rational operator/(const Rational& r, int rhs) {
	if (rhs == 0) throw Rational::divisionByZero("ERROR: division by zero int");
	Rational tmp;
	tmp.setNumerator(r.getNumerator());
	tmp.setDenominator(static_cast<short>(r.getDenominator() * rhs));
	tmp.normalize();
	return tmp;
}

// If you want int / Rational (e.g. 3 / (r1 + r2)):
inline Rational operator/(int lhs, const Rational& r) {
	if (r.getNumerator() == 0) throw Rational::divisionByZero("ERROR: division by zero rational");
	Rational tmp;
	tmp.setNumerator(static_cast<short>(lhs * static_cast<int>(r.getDenominator())));
	tmp.setDenominator(r.getNumerator());
	tmp.normalize();
	return tmp;
}

// Rational + int
inline Rational operator+(const Rational& r, int c) {
	int num = r.getNumerator() + c * r.getDenominator();
	int den = r.getDenominator();
	Rational result;
	result.setNumerator(static_cast<short>(num));
	result.setDenominator(static_cast<short>(den));
	result.normalize();
	return result;
}

// int + Rational
inline Rational operator+(int c, const Rational& r) {
	return r + c; // reuse
}

// Rational - int
inline Rational operator-(const Rational& r, int c) {
	int num = r.getNumerator() - c * r.getDenominator();
	int den = r.getDenominator();
	Rational result;
	result.setNumerator(static_cast<short>(num));
	result.setDenominator(static_cast<short>(den));
	result.normalize();
	return result;
}

// int - Rational
inline Rational operator-(int c, const Rational& r) {
	int num = c * r.getDenominator() - r.getNumerator();
	int den = r.getDenominator();
	Rational result;
	result.setNumerator(static_cast<short>(num));
	result.setDenominator(static_cast<short>(den));
	result.normalize();
	return result;
}

#endif
