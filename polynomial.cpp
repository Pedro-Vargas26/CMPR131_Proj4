
#include "Polynomial.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Default constructor
Polynomial::Polynomial() : coefficients({ 0.0 }) {}

// Parameterized constructor
Polynomial::Polynomial(const std::vector<double>& coeffs) : coefficients(coeffs) {}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other) : coefficients(other.coefficients) {}

// Destructor
Polynomial::~Polynomial() {}

// Degree of polynomial
int Polynomial::degree() const {
    return static_cast<int>(coefficients.size()) - 1;
}

// Get coefficient for x^power
double Polynomial::getCoeff(int power) const {
    if (power < 0 || power >= (int)coefficients.size()) return 0.0;
    return coefficients[power];
}

// Set coefficient for x^power
void Polynomial::setCoeff(int power, double value) {
    if (power < 0) return;
    if (power >= (int)coefficients.size()) {
        coefficients.resize(power + 1, 0.0);
    }
    coefficients[power] = value;
}

void Polynomial::inputTerms(int numberOfTerms) {
    coefficients.clear();
    coefficients.resize(numberOfTerms, 0.0);

    for (int i = 0; i < numberOfTerms; ++i) {
        std::cout << "\tEnter the coefficient for term #" << (i + 1) << ": ";
        std::cin >> coefficients[i];  // Store normally: index 0 = x^0
    }
}


// Evaluate at x
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (size_t i = 0; i < coefficients.size(); ++i) {
        double coeff = coefficients[i];
        result += coeff * pow(x, static_cast<int>(i));
    }

    return result;
}
// Derivative
Polynomial Polynomial::derivative() const {
    std::vector<double> derivCoeffs;
    for (int i = 1; i < (int)coefficients.size(); ++i) {
        derivCoeffs.push_back(i * coefficients[i]);
    }
    return Polynomial(derivCoeffs);
}

// Integral
Polynomial Polynomial::integral() const {
    std::vector<double> integralCoeffs;
    integralCoeffs.push_back(0.0); // +C omitted
    for (int i = 0; i < (int)coefficients.size(); ++i) {
        integralCoeffs.push_back(coefficients[i] / (i + 1));
    }
    return Polynomial(integralCoeffs);
}

// Addition
Polynomial Polynomial::operator+(const Polynomial& other) const {
    std::vector<double> resultCoeffs(std::max(coefficients.size(), other.coefficients.size()), 0.0);
    for (size_t i = 0; i < resultCoeffs.size(); ++i) {
        if (i < coefficients.size()) resultCoeffs[i] += coefficients[i];
        if (i < other.coefficients.size()) resultCoeffs[i] += other.coefficients[i];
    }
    return Polynomial(resultCoeffs);
}

// Subtraction
Polynomial Polynomial::operator-(const Polynomial& other) const {
    std::vector<double> resultCoeffs(std::max(coefficients.size(), other.coefficients.size()), 0.0);
    for (size_t i = 0; i < resultCoeffs.size(); ++i) {
        if (i < coefficients.size()) resultCoeffs[i] += coefficients[i];
        if (i < other.coefficients.size()) resultCoeffs[i] -= other.coefficients[i];
    }
    return Polynomial(resultCoeffs);
}

// Multiplication
Polynomial Polynomial::operator*(const Polynomial& other) const {
    std::vector<double> resultCoeffs(coefficients.size() + other.coefficients.size() - 1, 0.0);
    for (size_t i = 0; i < coefficients.size(); ++i) {
        for (size_t j = 0; j < other.coefficients.size(); ++j) {
            resultCoeffs[i + j] += coefficients[i] * other.coefficients[j];
        }
    }
    return Polynomial(resultCoeffs);
}

// Scalar multiplication (Polynomial * scalar)
Polynomial Polynomial::operator*(double scalar) const {
    std::vector<double> result(coefficients.size());
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result[i] = coefficients[i] * scalar;
    }
    return Polynomial(result);
}

// Scalar multiplication (scalar * Polynomial)
Polynomial operator*(double scalar, const Polynomial& p) {
    return p * scalar;
}



void Polynomial::printEvaluationSteps(double x) const {
    std::cout << "\n";

    for (int i = degree(); i >= 0; --i) {
        double coeff = getCoeff(i);
        if (coeff == 0) continue;

        double termVal = coeff * std::pow(x, i);

        if (i == degree()) {
            std::cout << "         "; // align first term without '+'
        }
        else {
            std::cout << "   +     ";
        }

        std::cout << std::setw(6) << termVal << " <- " << std::setw(8)
            << std::fixed << std::setprecision(2) << coeff << "x";
        if (i > 1) std::cout << "^" << i;
        else if (i == 0) std::cout << "^0";
        std::cout << "\n";
    }

    std::cout << std::string(40, char(196)) << "\n";

    double result = evaluate(x);
    std::cout << std::setw(15) << result << "\n";
}



// Output operator
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    bool first = true;
    for (int i = p.degree(); i >= 0; --i) {
        double coeff = p.coefficients[i];
        if (coeff == 0) continue;

        if (!first) {
            if (coeff > 0) os << " + ";
            else os << " - ";
        }
        else if (coeff < 0) {
            os << "-";
        }

        double absCoeff = std::abs(coeff);

        // Print coefficient only if it is not 1 or if it's the constant term
        if (!(absCoeff == 1.0 && i != 0)) {
            os << absCoeff;
        }

        if (i > 0) {
            os << "x";
            if (i > 1) os << "^" << i;
        }

        first = false;
    }

    if (first) os << "0"; // all zero polynomial

    return os;
}
