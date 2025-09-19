#include "Complex.h"


Complex::Complex() : realFactor(0.0), imaginaryFactor(0.0) {};

Complex::Complex(rational realNum, rational imgNum) : realFactor(realNum), imaginaryFactor(imgNum) {};

Complex::Complex(const Complex& other) {
	realFactor = other.realFactor;
	imaginaryFactor = other.imaginaryFactor;
}
Complex::Complex(Complex&& other) noexcept {
	realFactor = other.realFactor;
	imaginaryFactor = other.imaginaryFactor;
	other.realFactor = 0.0;
	other.imaginaryFactor = 0.0;
}

void Complex::setRealFactor(rational nFactor) noexcept {
	realFactor = nFactor;
}
Complex::rational Complex::getRealFactor()const noexcept {
	return realFactor;
}
void Complex::setImaginaryFactor(rational imaginaryFact) noexcept {
	imaginaryFactor = imaginaryFact;
}
Complex::rational Complex::getImaginaryFactor()const noexcept {
	return imaginaryFactor;
}
// Complex-complex operators
Complex Complex::operator+(const Complex& other) const {
	return Complex(realFactor + other.realFactor,
		imaginaryFactor + other.imaginaryFactor);
}
Complex Complex::operator-(const Complex& other) const {
	return Complex(realFactor - other.realFactor,
		imaginaryFactor - other.imaginaryFactor);
}
Complex Complex::operator*(const Complex& other) const {
	return Complex((realFactor * other.realFactor) - (imaginaryFactor * other.imaginaryFactor),
		(realFactor * other.imaginaryFactor) + (imaginaryFactor * other.realFactor));
}
Complex Complex::operator/(const Complex& other) const {
	rational denom = (other.realFactor * other.realFactor) + (other.imaginaryFactor * other.imaginaryFactor);

	if (denom == 0.0) throw divisionByZero();

	return Complex((realFactor * other.realFactor + imaginaryFactor * other.imaginaryFactor) / denom,
		(imaginaryFactor * other.realFactor - realFactor * other.imaginaryFactor) / denom);
}

// Complex-constant operators
Complex Complex::operator+(rational constant) const {
	return Complex(realFactor + constant, imaginaryFactor);
}
Complex Complex::operator-(rational constant) const {
	return Complex(realFactor - constant, imaginaryFactor);
}
Complex Complex::operator*(rational constant) const {
	return Complex(realFactor * constant, imaginaryFactor * constant);
}
Complex Complex::operator/(rational constant) const {
	if (constant == 0)throw divisionByZero();
	return Complex(realFactor / constant, imaginaryFactor / constant);
}

Complex Complex::operator=(const Complex& other) noexcept {
	if (this != &other) {
		this->imaginaryFactor = other.imaginaryFactor;
		this->realFactor = other.realFactor;
	}
	return *this;
}
Complex Complex::operator=(Complex&& other) noexcept {
	if (this != &other) {
		this->imaginaryFactor = other.imaginaryFactor;
		this->realFactor = other.realFactor;
		other.realFactor = 0.0;
		other.imaginaryFactor = 0.0;
	}
	return *this;
}

bool Complex::operator==(const Complex& rhs) {
	return (this->realFactor == rhs.realFactor && this->imaginaryFactor == rhs.imaginaryFactor);
}
bool Complex::operator!=(const Complex& rhs) {
	return !(*this == rhs);
}
Complex operator+(Complex::rational constant, const Complex& obj) {
	return Complex(constant + obj.getRealFactor(), obj.getImaginaryFactor());
}

Complex operator-(Complex::rational constant, const Complex& obj) {
	return Complex(constant - obj.getRealFactor(), obj.getImaginaryFactor());
}

Complex operator*(Complex::rational constant, const Complex& obj) {
	return Complex(constant * obj.getRealFactor(), constant * obj.getImaginaryFactor());
}
Complex operator/(Complex::rational constant, const Complex& obj) {
	Complex numerator(constant, 0.0);
	return numerator / obj;
}


ostream& operator<<(ostream& os, const Complex& obj) {
	os << obj.realFactor << (obj.imaginaryFactor >= 0 ? '+' : '-') << std::abs(obj.imaginaryFactor) << 'i';
	return os;
}