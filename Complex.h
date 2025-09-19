#include <ostream>
#include <exception>

#pragma once
using std::ostream;
using std::exception;
class Complex
{
public:
	typedef double rational;
	Complex();
	Complex(rational, rational);
	Complex(const Complex&);
	Complex(Complex&&) noexcept;

	void setRealFactor(rational) noexcept;
	rational getRealFactor()const noexcept;
	void setImaginaryFactor(rational) noexcept;
	rational getImaginaryFactor()const noexcept;

	Complex operator+(const Complex&) const;
	Complex operator+(rational) const;
	Complex operator-(const Complex&) const;
	Complex operator-(rational) const;
	Complex operator*(const Complex&) const;
	Complex operator*(rational) const;
	Complex operator/(const Complex&) const;
	Complex operator/(rational) const;
	bool operator==(const Complex&);
	bool operator!=(const Complex&);

	Complex operator=(const Complex&) noexcept;
	Complex operator=(Complex&&) noexcept;

	friend ostream& operator<<(ostream&, const Complex&);
private:

	class divisionByZero :public exception {
	public:
		divisionByZero() :msg("ERROR: DIVISION BY ZERO ATTEMPTED. ") {};
		divisionByZero(const char* nMsg) : msg(nMsg) {};
		const char* what() const noexcept override {
			return msg;
		}
	private:
		const char* msg;
	};

	rational realFactor;
	rational imaginaryFactor;
};

Complex operator+(Complex::rational , const Complex& );
Complex operator-(Complex::rational , const Complex&);
Complex operator*(Complex::rational, const Complex&);
Complex operator/(Complex::rational, const Complex&);

ostream& operator<<(ostream& os, const Complex& obj);
