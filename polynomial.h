
#pragma once
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

class Polynomial {
private:

    std::vector<double> coefficients; // coefficients[i] is the coefficient for x^i


public:
    // Constructors
   
    //precondition : none 
    //postcondition : sets to 0
    Polynomial(); // Default constructor
    
    //precondition: coeff contaims coefficients for idex starts at 0 
    //postcondition: polynomial is initialized with coeffs
    Polynomial(const std::vector<double>& coeffs); // Parameterized
    
    //precondition: polynomial is valid
    //postcondition : creaates a copy of polynomial 
    Polynomial(const Polynomial& other); // Copy constructor
    
    //precondition: polynomial exists
    //postcondition: clears 
    ~Polynomial(); // Destructor

    // Accessors

    //precondition: power is initialized 
    //post : returns highest power coefficient
    int degree() const; // Returns degree of polynomial
    
    //pre:  power>= 0
    //post returns coefficent for power
    double getCoeff(int power) const;

    // Mutators
    //pre:  power >= 0
    //post : sets coefficient for x to value
    void setCoeff(int power, double value);
   
     //pre: numofterms > 0 
    //post : sccepts user input to set coefficents for terms 
    void inputTerms(int numberOfTerms); // Accept user input


    // Evaluation
    // pre: polynomial exits 
    //post: returns value of the polynomal evaluated
    double evaluate(double x) const; // Evaluates the polynomial at x

    // Calculus
    //pre: polynomial exists 
    //post: returns polynomial derivative
    Polynomial derivative() const; // Returns derivative polynomial
   
    //pre : polynomial exists 
    //post : returns polynomial integral 
    Polynomial integral() const;   // Returns indefinite integral polynomial (without +C)

    // Arithmetic operators
    // pre : polynomial exist
    //post  returns a new polynomial 
    Polynomial operator+(const Polynomial& other) const;
   
    //pre :polynomial exits 
    // post : returns a new polynomial
    Polynomial operator-(const Polynomial& other) const;
    
    // pre: polynomial exits 
    //post returns a new polynomial 
    Polynomial operator*(const Polynomial& other) const;
    
    //pre : polynomial exits 
    //post : returns a new polynomial multiolied by scalar 
    Polynomial operator*(double scalar) const; // Scalar multiplication

    // pre : polynomial exits 
    //post outputs ste by step evaluation
    void printEvaluationSteps(double x) const;

    //pre: polynomual exists 
    // post: returns scalar multiplied by polynomial
    // Friend for scalar * Polynomial (left multiplication)
    friend Polynomial operator*(double scalar, const Polynomial& p);

    // Output operator
    //pre: polynomial p exists 
    //post outputs polynomial to the stream
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
};

#endif
